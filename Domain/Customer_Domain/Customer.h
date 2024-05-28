//
// Created by Cosmin on 5/14/2024.
//

#ifndef OOPCOLECTIV_CUSTOMER_H
#define OOPCOLECTIV_CUSTOMER_H

using namespace std;
#include "../User_Domain/User.h"
#include "../Car_Domain/Car.h"


class Customer : public User {
private:
    string phone;
    string address;
    bool GDPRdeleted;
    vector<Car> favorites;

public:
    Customer(int id, const string &email, const string &password, const string &firstName, const string &lastName,
             const string &phone, const string &address, bool gdpRdeleted, const vector<Car>& favorites);

    const string& get_phone() const;
    void set_phone(const string& _phone);

    const string& get_address() const;
    void set_address(const string& _address);

    bool is_GDPRdeleted() const;
    void set_GDPRdeleted(bool _GDPRdeleted);

    const vector<Car>& get_favorites() const;
    void add_favorite(const Car& favorite);

    string to_CSV() const;

    string favoritesToString() const;

    Customer From_String_To_Object(const string& string_of_obj, char delim=',');

    string Customer_To_String() const;

    Customer();
};


#endif //OOPCOLECTIV_CUSTOMER_H
