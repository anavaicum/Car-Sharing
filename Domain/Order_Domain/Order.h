#ifndef PROIECT_COLECTIV_ORDER_H
#define PROIECT_COLECTIV_ORDER_H
#include "../Car_Domain/Car.h"
#include "../Employee_Domain//Employee.h"
#include "../Customer_Domain/Customer.h"
#include <string>
#include <vector>
using namespace std;

class Order {
private:

    int order_id;
    Date order_date;
    enum status { Reserved, Ordered, Completed, Canceled};
    Date begin_date;
    Date end_date;
    float total_price;
    vector <string> remarks;
    bool is_reserved;
    Car* car;
    Customer* customer;
    Employee* employee;

public:

    Order(int orderId, const Date &orderDate, const Date &beginDate, const Date &endDate, float totalPrice,
          const vector<string> &remarks, bool isReserved, Car *car, Customer *customer, Employee *employee);

    Car *getCar() const;

    void setCar(Car *car);

    int getOrderId() const;

    void setOrderId(int orderId);

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

    Customer *getCustomer() const;

    void setCustomer(Customer *customer);

    Employee *getEmployee() const;

    void setEmployee(Employee *employee);

};


#endif //PROIECT_COLECTIV_ORDER_H
