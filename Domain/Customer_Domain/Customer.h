//
// Created by Cosmin on 5/14/2024.
//

#ifndef OOPCOLECTIV_CUSTOMER_H
#define OOPCOLECTIV_CUSTOMER_H

using namespace std;
#include <string>
#include <vector>
#include "../User_Domain/User.h"
class Car{//masina
};

class Customer : public User {
private:
    string phone;
    string address;
    bool GDPRdeleted;
    vector<Car> favorites;

public:
    Customer(int _id, const string& _email, const string& _password, const string& _first_name, const string& _last_name);

    const string& get_phone() const;
    void set_phone(const string& _phone);

    const string& get_address() const;
    void set_address(const string& _address);

    bool is_GDPRdeleted() const;
    void set_GDPRdeleted(bool _GDPRdeleted);

    const vector<Car>& get_favorites() const;
    void add_favorite(const Car& favorite);
};


#endif //OOPCOLECTIV_CUSTOMER_H
