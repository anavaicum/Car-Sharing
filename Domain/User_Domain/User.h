//
// Created by Cosmin on 5/14/2024.
//

#ifndef OOPCOLECTIV_USER_H
#define OOPCOLECTIV_USER_H
using namespace std;
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem>
#include "../Entity.h"

class User: public Entity {
private:
    string email;
    string password;
    string first_name;
    string last_name;
    vector<string> remarks;

public:
    User(int _id, const string& _email, const string& _password, const string& _first_name, const string& _last_name);

    User();

    const string& get_email() const;
    void set_email(const string& _email);

    const string& get_password() const;
    void set_password(const string& _password);

    const string& get_first_name() const;
    void set_first_name(const string& _first_name);

    const string& get_last_name() const;
    void set_last_name(const string& _last_name);

    const vector<string>& get_remarks() const;
    void add_remark(const string& remark);
};


#endif //OOPCOLECTIV_USER_H
