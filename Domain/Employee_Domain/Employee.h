#ifndef OOPCOLECTIV_COWORKER_H
#define OOPCOLECTIV_COWORKER_H

using namespace std;
#include "../User_Domain/User.h"
#include "../Date.h"
#include <iomanip>

/**
 * @brief Represents an Employee entity.
 */
class Employee : public User {
private:
    string position;
    Date birthday;
    string initials;
    float salary;
    bool is_admin;

public:
//    Employee(int _id, const string& _email, const string& _password, const string& _first_name, const string& _last_name);

    /**
     * @brief Constructs an Employee object.
     */
    Employee(int _id, const string &_email, const string &_password, const string &_firstName, const string &_lastName,
             const string &_position, const Date &_birthday, const string &_initials, float _salary, bool _isAdmin);

    const string& get_position() const;
    void set_position(const string& _position);

    const Date &get_Birthday() const;
    void set_Birthday(const Date &_birthday);

    const string& get_initials() const;
    void set_initials(const string& _initials);

    float get_salary() const;
    void set_salary(float _salary);

    /**
     * @brief Checks if the employee is an administrator.
     *
     * @return Admin status.
     */
    bool is_administrator() const;

    /**
     * @brief Sets the admin status.
     *
     * @param _is_admin New admin status.
     */
    void set_admin(bool _is_admin);

    /**
     * @brief Converts the Employee object to a CSV string.
     *
     * @return CSV representation of the employee.
     */
    string to_CSV() const;

    /**
     * @brief Creates an Employee object from a string.
     *
     * @param string_of_obj String representation of the employee.
     * @param delim Delimiter used in the string.
     * @return Employee object.
     */
    Employee From_String_To_Object(const string& string_of_obj, char delim=',');

    /**
     * @brief Converts the Employee object to a string.
     *
     * @return String representation of the employee.
     */
    string Employee_To_string() const;

    /**
     * @brief Default constructor.
     */
    Employee();

};


#endif //OOPCOLECTIV_COWORKER_H
