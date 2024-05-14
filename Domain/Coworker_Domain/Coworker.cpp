//
// Created by Cosmin on 5/14/2024.
//

#include "Coworker.h"

CoWorker::CoWorker(int _id, const string& _email, const string& _password, const string& _first_name, const string& _last_name)
        : User(_id, _email, _password, _first_name, _last_name) {}

const string& CoWorker::get_position() const { return position; }
void CoWorker::set_position(const string& _position) { position = _position; }

const string& CoWorker::get_birthday() const { return birthday; }
void CoWorker::set_birthday(const string& _birthday) { birthday = _birthday; }

const string& CoWorker::get_initials() const { return initials; }
void CoWorker::set_initials(const string& _initials) { initials = _initials; }

float CoWorker::get_salary() const { return salary; }
void CoWorker::set_salary(float _salary) { salary = _salary; }

bool CoWorker::is_administrator() const { return is_admin; }
void CoWorker::set_admin(bool _is_admin) { is_admin = _is_admin; }