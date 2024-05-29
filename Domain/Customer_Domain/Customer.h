#ifndef OOPCOLECTIV_CUSTOMER_H
#define OOPCOLECTIV_CUSTOMER_H

using namespace std;
#include "../User_Domain/User.h"
#include "../Car_Domain/Car.h"

/**
 * @brief Represents a Customer entity.
 */
class Customer : public User {
private:
    string phone;
    string address;
    bool GDPRdeleted;
    vector<Car> favorites;

public:

    /**
     * @brief Constructs a Customer object.
     */
    Customer(int id, const string &email, const string &password, const string &firstName, const string &lastName,
             const string &phone, const string &address, bool gdpRdeleted, const vector<Car>& favorites);

    const string& get_phone() const;
    void set_phone(const string& _phone);

    const string& get_address() const;
    void set_address(const string& _address);

    /**
     * @brief Checks if the customer is GDPR deleted.
     *
     * @return GDPR deletion status.
     */
    bool is_GDPRdeleted() const;

    /**
     * @brief Sets the GDPR deletion status.
     *
     * @param _GDPRdeleted New GDPR deletion status.
     */
    void set_GDPRdeleted(bool _GDPRdeleted);

    /**
     * @brief Gets the list of favorite cars.
     *
     * @return List of favorite cars.
     */
    const vector<Car>& get_favorites() const;

    /**
     * @brief Adds a car to the favorites list.
     *
     * @param favorite Car to add to favorites.
     */
    void add_favorite(const Car& favorite);

    /**
     * @brief Removes a car from the favorites list by ID.
     *
     * @param id Car ID to remove from favorites.
     */
    void remove_favorite(int id);

    /**
     * @brief Converts the Customer object to a CSV string.
     *
     * @return CSV representation of the customer.
     */
    string to_CSV() const;

    /**
     * @brief Converts the list of favorite cars to a string.
     *
     * @return String representation of favorite cars.
     */
    string favoritesToString() const;

    /**
     * @brief Creates a Customer object from a string.
     *
     * @param string_of_obj String representation of the customer.
     * @param delim Delimiter used in the string.
     * @return Customer object.
     */
    Customer From_String_To_Object(const string& string_of_obj, char delim=',');

    /**
     * @brief Converts the Customer object to a string.
     *
     * @return String representation of the customer.
     */
    string Customer_To_String() const;

    /**
     * @brief Default constructor.
     */
    Customer();
};


#endif //OOPCOLECTIV_CUSTOMER_H
