#include "Employee.h"

//Employee::Employee(int _id, const std::string &_email, const std::string &_password, const std::string &_first_name,
//                   const std::string &_last_name) {}

Employee::Employee(int id, const string &email, const string &password, const string &firstName, const string &lastName,
                   const string &position, const Date &birthday, const string &initials, float salary, bool isAdmin)
        : User(id, email, password, firstName, lastName), position(position), birthday(birthday), initials(initials),
          salary(salary), is_admin(isAdmin) {}

const string& Employee::get_position() const { return position; }
void Employee::set_position(const string& _position) { position = _position; }

//const string& Employee::get_birthday() const { return birthday; }
//void Employee::set_birthday(const string& _birthday) { birthday = _birthday; }

const string& Employee::get_initials() const { return initials; }
void Employee::set_initials(const string& _initials) { initials = _initials; }

float Employee::get_salary() const { return salary; }
void Employee::set_salary(float _salary) { salary = _salary; }

bool Employee::is_administrator() const { return is_admin; }
void Employee::set_admin(bool _is_admin) { is_admin = _is_admin; }

const Date &Employee::getBirthday() const { return birthday; }

void Employee::setBirthday(const Date &_birthday) { Employee::birthday = _birthday; }

User::User() {}

void Employee::save_to_CSV(const vector<Employee>& data, const string& filename) {
    ofstream file(filename);
    //file.open(filename, ios::app);

    if(!file.is_open()) {
        return;
    }

//    bool file_exists = filesystem::exists(filename);
//    if(!file_exists) {
//        file << "ID,email,password,first name,last name,position,birthday,initials,salary,is admin\n";
//    }

    file << "ID,email,password,first name,last name,position,birthday,initials,salary,is admin\n";

    for(const auto& obj : data) {
        file << obj.get_id() << ","
             << obj.get_email() << ","
             << obj.get_password() << ","
             << obj.get_first_name() << ","
             << obj.get_last_name() << ","
             << obj.position << ","
             << obj.birthday.getDay() << "/" << obj.birthday.getMonth() << "/" << obj.birthday.getYear() << ","
             << obj.initials << ","
             << obj.salary << ","
             << obj.is_admin << "\n";
    }
    file.close();
}
