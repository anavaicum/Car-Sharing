#ifndef PROIECT_COLECTIV_ORDER_H
#define PROIECT_COLECTIV_ORDER_H
#include "../Car_Domain/Car.h"
#include "../Employee_Domain//Employee.h"
#include "../Customer_Domain/Customer.h"
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * @brief Represents an Order entity.
 */
class Order:public Entity {
public:

    /**
     * @brief Enum representing order status.
     */
    enum status { Reserved, Ordered, Completed, Canceled, Unknown};

private:

    Date order_date;
    status stat;
    Date begin_date;
    Date end_date;
    float total_price;
    vector <string> remarks;
    bool is_reserved;
    vector<Car> car;
    Customer customer;
    Employee employee;

    unordered_map<string, status> stringToStatus{
            {"Reserved", Reserved},
            {"Ordered", Ordered},
            {"Completed", Completed},
            {"Canceled", Canceled}
    };

    status stringToStatusEnum(string status_string);

public:
    /**
     * @brief Constructs an Order object.
     */
    Order(int orderId, const Date &orderDate, status stat, const Date &beginDate, const Date &endDate, float totalPrice,
          const vector<string> &remarks, bool isReserved, vector<Car> cars, Employee employee, Customer customer);

    /**
     * @brief Constructs an Order object.
     */
    Order(int id, Date o_date, string st, Date b_date, Date e_date,bool reserved, vector<Car> cars, Employee  emp, Customer cus);

    vector<Car> getCar() const;

    void setCar(vector<Car> new_cars);

    const Date &getOrderDate() const;

    void setOrderDate(const Date &orderDate);

    const Date &getBeginDate() const;

    void setBeginDate(const Date &beginDate);

    const Date &getEndDate() const;

    void setEndDate(const Date &endDate);

    float getTotalPrice() const;

    void setTotalPrice(float totalPrice);

    const vector<string> &getRemarks() const;

    void setRemarks(const vector<string> &remarks);

    bool isReserved() const;

    void setIsReserved(bool isReserved);

    Customer getCustomer() const;

    void setCustomer(Customer customer);

    Employee getEmployee() const;

    void setEmployee(Employee employee);

    status getStat() const;

    void setStat(status stat);

    void setStat(string st);

    /**
     * @brief Converts the Order object to a CSV string.
     *
     * @return CSV representation of the order.
     */
    string to_CSV() const;

    /**
     * @brief Converts status enum to string.
     *
     * @param s Status enum.
     * @return String representation of status.
     */
    static string statusToString(status s);

    /**
     * @brief Converts vector of strings to a single comma-separated string.
     *
     * @param vec Vector of strings.
     * @return Comma-separated string.
     */
    static string vectorToString(const vector<string>& vec);

    /**
     * @brief Converts list of cars to a string.
     *
     * @return String representation of cars in the order.
     */
    string CarsToString() const;

    /**
     * @brief Creates an Order object from a string.
     *
     * @param string_of_obj String representation of the order.
     * @return Order object.
     */
    Order From_String_To_Object(const string& string_of_obj);

    /**
     * @brief Default constructor.
     */
    Order();

};


#endif //PROIECT_COLECTIV_ORDER_H
