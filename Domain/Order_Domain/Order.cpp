#include "Order.h"

Order::Order(int orderId, const Date &orderDate, const Date &beginDate, const Date &endDate, float totalPrice,
             const vector<string> &remarks, bool isReserved, Car *car, Customer *customer, Employee *employee)
        : order_id(orderId), order_date(orderDate), begin_date(beginDate), end_date(endDate), total_price(totalPrice),
          remarks(remarks), is_reserved(isReserved), car(car), customer(customer), employee(employee) {}

int Order::getOrderId() const {
    return order_id;
}

void Order::setOrderId(int orderId) {
    order_id = orderId;
}

const Date &Order::getOrderDate() const {
    return order_date;
}

void Order::setOrderDate(const Date &orderDate) {
    order_date = orderDate;
}

const Date &Order::getBeginDate() const {
    return begin_date;
}

void Order::setBeginDate(const Date &beginDate) {
    begin_date = beginDate;
}

const Date &Order::getEndDate() const {
    return end_date;
}

void Order::setEndDate(const Date &endDate) {
    end_date = endDate;
}

float Order::getTotalPrice() const {
    return total_price;
}

void Order::setTotalPrice(float totalPrice) {
    total_price = totalPrice;
}

const vector<string> &Order::getRemarks() const {
    return remarks;
}

void Order::setRemarks(const vector<string> &remarks) {
    Order::remarks = remarks;
}

bool Order::isReserved() const {
    return is_reserved;
}

void Order::setIsReserved(bool isReserved) {
    is_reserved = isReserved;
}

Car *Order::getCar() const {
    return car;
}

void Order::setCar(Car *car) {
    Order::car = car;
}

Customer *Order::getCustomer() const {
    return customer;
}

void Order::setCustomer(Customer *customer) {
    Order::customer = customer;
}

Employee *Order::getEmployee() const {
    return employee;
}

void Order::setEmployee(Employee *employee) {
    Order::employee = employee;
}


Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

bool Date::operator<(const Date &rhs) const {


    if(year < rhs.year) {
        return true;
    }
    if(year == rhs.year && month < rhs.month) {
        return true;
    }
    if(year == rhs.year && month == rhs.month && day < rhs.day) {
        return true;
    }
    return false;

}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}
