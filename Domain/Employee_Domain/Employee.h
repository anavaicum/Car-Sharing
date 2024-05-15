//
// Created by Cosmin on 5/14/2024.
//

#ifndef OOPCOLECTIV_COWORKER_H
#define OOPCOLECTIV_COWORKER_H

using namespace std;
#include <string>
#include "../User_Domain/User.h"

class Employee : public User {
private:
    string position;
    string birthday; //TODO: asdf @cosmin refactor to separate date structure
    string initials;
    float salary;
    bool is_admin;

public:
    Employee(int _id, const string& _email, const string& _password, const string& _first_name, const string& _last_name);

    const string& get_position() const;
    void set_position(const string& _position);

    const string& get_birthday() const;
    void set_birthday(const string& _birthday);

    const string& get_initials() const;
    void set_initials(const string& _initials);

    float get_salary() const;
    void set_salary(float _salary);

    bool is_administrator() const;
    void set_admin(bool _is_admin);
};


#endif //OOPCOLECTIV_COWORKER_H
