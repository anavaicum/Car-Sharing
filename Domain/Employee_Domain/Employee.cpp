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

void Employee::save_to_CSV(const string &filename) {
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

        file << get_id() << ","
             << get_email() << ","
             << get_password() << ","
             << get_first_name() << ","
             << get_last_name() << ","
             << position << ","
             << birthday.getDay() << "/" << birthday.getMonth() << "/" << birthday.getYear() << ","
             << initials << ","
             << salary << ","
             << is_admin << "\n";

    file.close();
}

Employee Employee::From_String_To_Object(const string &string_of_obj) {
    stringstream ss(string_of_obj);
    string id_string, email_string, pass_string, f_name, l_name, pos, birth, init, sal, admin;
    bool admin_bool;
    int id_int;
    float sal_num;

    getline(ss, id_string,',');
    getline(ss, email_string,',');
    getline(ss, pass_string,',');
    getline(ss, f_name,',');
    getline(ss, l_name,',');
    getline(ss, pos,',');
    getline(ss, birth,',');
    getline(ss, init,',');
    getline(ss, sal,',');
    getline(ss, admin,',');

    admin_bool = (admin == "1");
    id_int = stoi(id_string);
    sal_num = stof(sal);

    stringstream DateStream(birth);
    string part;
    vector<string> Date_string;
    while(getline(DateStream, part, '/')){
        Date_string.push_back(part);
    }
    Date birth_d(Date_string);
    Employee e(id_int, email_string, pass_string, f_name, l_name, pos,
               birth_d, init, sal_num, admin_bool);
    return e;
}

