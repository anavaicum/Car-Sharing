//
// Created by Cosmin on 5/14/2024.
//

#include "Customer.h"

Customer::Customer(int _id, const string& _email, const string& _password, const string& _first_name, const string& _last_name)
        : User(_id, _email, _password, _first_name, _last_name) {}

const string& Customer::get_phone() const { return phone; }
void Customer::set_phone(const string& _phone) { phone = _phone; }

const string& Customer::get_address() const { return address; }
void Customer::set_address(const string& _address) { address = _address; }

bool Customer::is_GDPRdeleted() const { return GDPRdeleted; }
void Customer::set_GDPRdeleted(bool _GDPRdeleted) { GDPRdeleted = _GDPRdeleted; }

const vector<Car>& Customer::get_favorites() const { return favorites; }
void Customer::add_favorite(const Car& favorite) { favorites.push_back(favorite); }