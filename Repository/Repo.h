#ifndef PROIECT_COLECTIV_REPO_H
#define PROIECT_COLECTIV_REPO_H

#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "IRepo.h"


using namespace std;

// each class T should provide the methods:
// get_CSV_header (first line in the file labeling each column),
// to_CSV (a CSV representation of the object's data)

template<class T>
class Repo : public IRepo<T>{
private:
     const string filename;
     vector<T> entities;

    bool ID_is_unique(const T& t) {
        for (const auto& e : entities) {
            if (e.get_id() == t.get_id()) { //identification of each objects
                return false;
            }
        }
        return true;
    }

    void save_to_CSV(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            throw exception();
        }

        // Write data
        for (const auto &obj: entities) {
            file << obj.to_CSV() << endl;
        }

        file.close();
    }

public:

    Repo(const string& f_name) : filename(f_name){
        read_from_file();
    }

    vector<T> get_all() override{
        read_from_file();
        return entities;
    }

    T get_by_Id(int id) override{
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].get_id() == id){
                return entities[i];
            }
        }

        throw exception(); // Object with that id was not found
    }

    void delete_by_id(int id) override{
        vector<T> new_data;
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].get_id() != id){
                new_data.push_back(entities[i]);
            }
        }
        entities = new_data;

        ofstream clearFile;
        clearFile.open(filename, ios::out | ios::trunc); //Deletes all the data in the persistent Repo
        clearFile.close();

        for(int i = 0; i < entities.size(); i++){
            add(entities[i]);
        }
    }

    bool add(T t) override{
        if (!ID_is_unique(t)) {
            throw exception(); // object already in repo
        }

        this->entities.push_back(t);
        save_to_CSV(this->filename);
    }

    void read_from_file(){
        vector<T> data;
        ifstream readFile(filename);

        string line;
        while(getline(readFile, line)){
            T object;
            object = object.From_String_To_Object(line); //sends line with all the attributes
            data.push_back(object);
        }
        readFile.close();
        entities = data;
    }

    void update(int id, const T& new_entity) override{
        bool found = false;
        for (auto& entity : entities) {
            if (entity.get_id() == id) {
                entity = new_entity;
                found = true;
                break;
            }
        }
        if (!found) {
            throw exception(); // or handle the case where the entity is not found
        }
        save_to_CSV(this->filename); // Save the updated list to the file
    }


};

#endif //PROIECT_COLECTIV_REPO_H
