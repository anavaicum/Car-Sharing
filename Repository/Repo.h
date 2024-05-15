//
// Created by Cristina.
//

#ifndef PROIECT_COLECTIV_REPO_H
#define PROIECT_COLECTIV_REPO_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

// each class T should provide the methods:
// get_CSV_header (first line in the file labeling each column),
// to_CSV (a CSV representation of the object's data)

template<class T>
class Repo{
private:
     const string filename;
     vector<T> entities;
//    IValidator<T>& validator;  // implemented in domain

    bool ID_is_unique(const T& t) {
        for (const auto& e : entities) {
            if (e.get_Id() == t.get_Id()) { //identification of each objects
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

        // Write header
        file << T::get_CSV_header() << endl;

        // Write data
        for (const auto &obj: entities) {
            file << obj.to_CSV() << endl;
        }

        file.close();
    }

public:
    void add(T t){
        if (!ID_is_unique(t)) {
            throw exception(); // object already in repo
        }

//        if (!validator.isValid(t)) {
//            throw exception(); // entity is not valid
//        }

        this->entities.push_back(t);
        save_to_CSV(this->filename);
    }

};

#endif //PROIECT_COLECTIV_REPO_H
