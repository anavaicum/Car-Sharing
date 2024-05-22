//
// Created by Cosmin on 5/14/2024.
//

#include "User.h"
#include "../Entity.h"

User::User(int _id, const string& _email, const string& _password, const string& _first_name, const string& _last_name)
        : id(_id), email(_email), password(_password), first_name(_first_name), last_name(_last_name) {}

const int Entity::get_id() const { return id; }
void Entity::set_id(int _id) { id = _id; }

const string& User::get_email() const { return email; }
void User::set_email(const string& _email) { email = _email; }

const string& User::get_password() const { return password; }
void User::set_password(const string& _password) { password = _password; }

const string& User::get_first_name() const { return first_name; }
void User::set_first_name(const string& _first_name) { first_name = _first_name; }

const string& User::get_last_name() const { return last_name; }
void User::set_last_name(const string& _last_name) { last_name = _last_name; }

void User::set_salary(double salary) { /* Add implementation for setting salary */ }

const vector<string>& User::get_remarks() const { return remarks; }
void User::add_remark(const string& remark) { remarks.push_back(remark); }