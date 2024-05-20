#include "Order.h"

Order::Order(int orderId, const Date &orderDate, status stat, const Date &beginDate, const Date &endDate, float totalPrice,
             const vector<string> &remarks, bool isReserved, Car *car, Customer *customer, Employee *employee)
        : order_id(orderId), order_date(orderDate), stat(stat), begin_date(beginDate), end_date(endDate), total_price(totalPrice),
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

void Order::setRemarks(const vector<string> &Remarks) {
    Order::remarks = Remarks;
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

void Order::setCar(Car *Car) {
    Order::car = Car;
}

Customer *Order::getCustomer() const {
    return customer;
}

void Order::setCustomer(Customer *Customer) {
    Order::customer = Customer;
}

Employee *Order::getEmployee() const {
    return employee;
}

void Order::setEmployee(Employee *Employee) {
    Order::employee = Employee;
}

Order::status Order::getStat() const {
    return stat;
}

void Order::setStat(Order::status Stat) {
    Order::stat = Stat;
}

void Order::save_to_CSV(const vector<Order>& data, const string &filename) const {
    ofstream file(filename);
    //bool fileExists = filesystem::exists(filename);

    //file.open(filename, std::ios::app);

    if (!file.is_open()) {
        return;
    }

    // Write the header only if the file does not exist
//    if (!fileExists) {
//        file << "Order ID,order Date,status,begin date,end date,total price,is reserved,car,customer,employee,remarks\n";
//    }

    file << "Order ID,order Date,status,begin date,end date,total price,remarks,is reserved,car license plate,customer id,employee id,car license plate,customer id,employee id\n";

    for(const auto& obj : data) {
        file << obj.order_id << ","
             << obj.order_date.getDay() << "/" << obj.order_date.getMonth() << "/" << obj.order_date.getYear() << ","
             << statusToString(obj.stat) << ","
             << obj.begin_date.getDay() << "/" << obj.begin_date.getMonth() << "/" << obj.begin_date.getYear() << ","
             << obj.end_date.getDay() << "/" << obj.end_date.getMonth() << "/" << obj.end_date.getYear() << ","
             << obj.total_price << ","
             << vectorToString(obj.remarks) << ","
             << obj.is_reserved << ","
             << obj.car->getLicensePlate() << ","
             << obj.customer->get_id() << ","
             << obj.employee->get_id() << "\n";
    }
    file.close();
}

string Order::statusToString(Order::status s) {
    switch (s) {
        case Reserved: return "Reserved";
        case Ordered: return "Ordered";
        case Completed: return "Completed";
        case Canceled: return "Canceled";
        default: return "Unknown";
    }
}

string Order::vectorToString(const vector<string> &vec) {
    stringstream ss;
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i != vec.size() - 1) {
            ss << "; "; // Use semicolon and space as separator for readability for vector
        }
    }
    return ss.str();
}
