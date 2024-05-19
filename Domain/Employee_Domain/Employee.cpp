#include "Employee.h"

Employee::Employee(int _id, const std::string &_email, const std::string &_password, const std::string &_first_name,
                   const std::string &_last_name) {}

const string& Employee::get_position() const { return position; }
void Employee::set_position(const string& _position) { position = _position; }

const string& Employee::get_birthday() const { return birthday; }
void Employee::set_birthday(const string& _birthday) { birthday = _birthday; }

const string& Employee::get_initials() const { return initials; }
void Employee::set_initials(const string& _initials) { initials = _initials; }

float Employee::get_salary() const { return salary; }
void Employee::set_salary(float _salary) { salary = _salary; }

bool Employee::is_administrator() const { return is_admin; }
void Employee::set_admin(bool _is_admin) { is_admin = _is_admin; }

User::User() {}
