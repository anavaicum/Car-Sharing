//
// Created by Cosmin on 5/14/2024.
//

#ifndef OOPCOLECTIV_COWORKER_H
#define OOPCOLECTIV_COWORKER_H

using namespace std;
#include "../User_Domain/User.h"
#include "../Date.h"
#include <iomanip>

class Employee : public User {
private:
    string position;
    Date birthday;
    string initials;
    float salary;
    bool is_admin;

public:
//    Employee(int _id, const string& _email, const string& _password, const string& _first_name, const string& _last_name);

    Employee(int _id, const string &_email, const string &_password, const string &_firstName, const string &_lastName,
             const string &_position, const Date &_birthday, const string &_initials, float _salary, bool _isAdmin);

    const string& get_position() const;
    void set_position(const string& _position);

//    const string& get_birthday() const;
//    void set_birthday(const string& _birthday);
    const Date &getBirthday() const;
    void setBirthday(const Date &_birthday);

    const string& get_initials() const;
    void set_initials(const string& _initials);

    float get_salary() const;
    void set_salary(float _salary);

    bool is_administrator() const;
    void set_admin(bool _is_admin);

    void save_to_CSV(const string &filename);

    Employee From_String_To_Object(const string& string_of_obj, char delim=',');

    string Employee_To_string() const;

    Employee();

};


#endif //OOPCOLECTIV_COWORKER_H
