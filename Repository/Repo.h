#ifndef PROIECT_COLECTIV_REPO_H
#define PROIECT_COLECTIV_REPO_H

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "IRepo.h"

using namespace std;

/**
 * @brief Template class for managing a collection of entities with file-based persistence.
 * @tparam T The type of entities being managed. Each entity should provide methods: get_CSV_header, to_CSV, get_id, and From_String_To_Object.
 */
template<class T>
class Repo : public IRepo<T>{
private:
     const string filename;
     vector<T> entities;

    /**
    * @brief Checks if an entity's ID is unique within the repository.
    * @param t The entity to check for uniqueness.
    * @return true if the entity's ID is unique, false otherwise.
    */
    bool ID_is_unique(const T& t) {
        for (const auto& e : entities) {
            if (e.get_id() == t.get_id()) { //identification of each objects
                return false;
            }
        }
        return true;
    }

    /**
     * @brief Saves the current collection of entities to a CSV file.
     * @param filename The name of the file to save the data to.
     */
    void save_to_CSV(const string& filename) {
        ofstream file(filename);

        // Write data
        for (const auto &obj: entities) {
            file << obj.to_CSV();
        }

        file.close();
    }

public:

    /**
     * @brief Constructs a Repo object and initializes it with data from a file.
     * @param f_name The name of the file to read data from.
     */
    Repo(const string& f_name) : filename(f_name){
        read_from_file();
    }

    /**
     * @brief Retrieves all entities in the repository.
     * @return A vector containing all entities.
     */
    vector<T> get_all() override{
        read_from_file();
        return entities;
    }

    /**
     * @brief Retrieves an entity by its ID.
     * @param id The ID of the entity to retrieve.
     * @return The entity with the specified ID.
     * @throws exception if the entity with the specified ID is not found.
     */
    T get_by_Id(int id) override{
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].get_id() == id){
                return entities[i];
            }
        }

        throw exception(); // Object with that id was not found
    }

    /**
     * @brief Deletes an entity by its ID.
     * @param id The ID of the entity to delete.
     * @return true if the entity was found and deleted, false otherwise.
     */
    bool delete_by_id(int id) override{
        bool found=false;
        vector<T> new_data;
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].get_id() != id){
                new_data.push_back(entities[i]);
            }
            else
            {
                found=true;
            }
        }
        entities = new_data;

        ofstream clearFile;
        clearFile.open(filename, ios::out | ios::trunc); //Deletes all the data in the persistent Repo
        clearFile.close();

        for(int i = 0; i < entities.size(); i++){
            add(entities[i]);
        }
        return found;
    }


    /**
     * @brief Adds a new entity to the repository.
     * @param t The entity to add.
     * @return true if the entity was added successfully, false if the ID is not unique.
     */
    bool add(T t) override{
        if (!ID_is_unique(t)) {
            return false;
        }

        this->entities.push_back(t);
        save_to_CSV(this->filename);
        return true;
    }

    /**
     * @brief Reads data from the file and populates the repository.
     */
    void read_from_file(){
        vector<T> data;
        ifstream readFile(filename);

        string line;
        while(getline(readFile, line)){
            if(line == ""){
                break;
            }
            T object;
            object = object.From_String_To_Object(line); //sends line with all the attributes
            data.push_back(object);
        }
        readFile.close();
        entities = data;
    }

    /**
     * @brief Updates an entity in the repository.
     * @param id The ID of the entity to update.
     * @param new_entity The new entity data to replace the old one.
     * @return true if the entity was found and updated, false otherwise.
     */
    bool update(int id, const T& new_entity) override{
        for (auto& entity : entities) {
            if (entity.get_id() == id) {
                entity = new_entity;
                save_to_CSV(this->filename); // Save the updated list to the file
                return true;
            }
        }
        return false; // or handle the case where the entity is not found

    }


};

#endif //PROIECT_COLECTIV_REPO_H
