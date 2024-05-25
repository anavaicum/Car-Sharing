#include "Order.h"

Order::Order(int _id, const Date &orderDate, status stat, const Date &beginDate, const Date &endDate,
             float totalPrice,
             const vector<string> &remarks, bool isReserved, vector<Car> cars, Employee employee, Customer customer)
        : Entity(_id), order_date(orderDate), stat(stat), begin_date(beginDate), end_date(endDate), total_price(totalPrice),
          remarks(remarks), is_reserved(isReserved), car(cars), employee(employee), customer(customer) {
}

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

vector<Car> Order::getCar() const {
    return car;
}

void Order::setCar(vector<Car> c) {
    Order::car = c;
}

Customer Order::getCustomer() const {
    return customer;
}

void Order::setCustomer(Customer Customer) {
    Order::customer = Customer;
}

Employee Order::getEmployee() const {
    return employee;
}

void Order::setEmployee(Employee Employee) {
    Order::employee = Employee;
}

Order::status Order::getStat() const {
    return stat;
}

void Order::setStat(Order::status Stat) {
    Order::stat = Stat;
}

string Order::to_CSV() const {

    //bool fileExists = filesystem::exists(filename);


    // Write the header only if the file does not exist
//    if (!fileExists) {
//        file << "Order ID,order Date,status,begin date,end date,total price,is reserved,car,customer,employee,remarks\n";
//    }

//    "Order ID,order Date,status,begin date,end date,total price,remarks,is reserved,car license plate,customer id,employee id,car license plate,customer id,employee id\n";


    stringstream ss;
    ss << order_id << ","
        << order_date.getDay() << "/" << order_date.getMonth() << "/" << order_date.getYear() << ","
        << statusToString(stat) << ","
        << begin_date.getDay() << "/" << begin_date.getMonth() << "/" << begin_date.getYear() << ","
        << end_date.getDay() << "/" << end_date.getMonth() << "/" <<end_date.getYear() << ","
        << fixed << setprecision(2) << total_price << ","
        << vectorToString(remarks) << ","
        << is_reserved << ","
        << CarsToString() << ","
        << customer.Customer_To_String() << ","
        << employee.Employee_To_string() << "\n";

   return ss.str();
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
            ss << ";"; // Use semicolon and space as separator for readability for vector
        }
    }
    return ss.str();
}

string Order::CarsToString() const {
    stringstream ss;
    for(int i = 0; i < car.size(); i++){
        ss << car[i].getLicensePlate() << "!"
           << car[i].getModel() << "!"
           << car[i].getBrand() << "!"
           << car[i].getYearOfFirstReg() << "!"
           << car[i].getMileage() << "!"
           << car[i].getPricePerDay() << "!"
           << car[i].fuelTypeToString(car[i].getFuel()) << "!"
           << car[i].transmissionToString(car[i].getTrans()) << "!"
           << car[i].getColor() << "!"
           << car[i].vectorToString(car[i].getRemarks());

        if (i != car.size() - 1) {
            ss << " | "; // Use vertical bar as separator for readability
        }
    }

    return ss.str();
}

Order Order::From_String_To_Object(const string &string_of_obj) {

    stringstream ss(string_of_obj);
    string id_string, ord_date, status, bg_date, e_date, tot_price,
    rm_vec, reserve, cars_vec, emp_string, cus_string;

    int id;
    Date o_date, b_date, date_end;
    vector<Car> cars;
    Employee emp;
    Customer cus;
    Order::status sa;
    bool res;
    float t_price;

    getline(ss, id_string, ',');
    getline(ss, ord_date, ',');
    getline(ss, status, ',');
    getline(ss, bg_date, ',');
    getline(ss, e_date, ',');
    getline(ss, tot_price, ',');
    getline(ss, rm_vec, ',');
    getline(ss, reserve, ',');
    getline(ss, cars_vec, ',');
    getline(ss, cus_string, ',');
    getline(ss, emp_string, ',');

    res = (reserve == "1");
    id = stoi(id_string);

    stringstream DateStream(ord_date);
    std::string part;
    vector<std::string> Date_string;
    while(getline(DateStream, part, '/')){
        Date_string.push_back(part);
    }
    o_date = Date(Date_string);

    Date_string = vector<std::string>();
    part = "";
    DateStream = stringstream(bg_date);
    while(getline(DateStream, part, '/')){
        Date_string.push_back(part);
    }
    b_date = Date(Date_string);

    Date_string = vector<std::string>();
    part = "";
    DateStream = stringstream(e_date);
    while(getline(DateStream, part, '/')){
        Date_string.push_back(part);
    }
    date_end = Date(Date_string);

    stringstream remarksStream(rm_vec);
    string remark;
    vector<string> remark_vector;
    while(getline(remarksStream, remark, ';')){
        remark_vector.push_back(remark);
    }


    stringstream CarStream(cars_vec);
    std::string car_string;
    while(getline(CarStream, car_string, '|')){
        cars.push_back(Car().From_String_To_Object(car_string, '!'));
    }

    cus = Customer().From_String_To_Object(cus_string, '!');
    emp = Employee().From_String_To_Object(emp_string, '!');
    sa = stringToStatusEnum(status);
    t_price = stof(tot_price);
    return Order(id, o_date, sa, b_date, date_end, t_price, remark_vector, res, cars, emp, cus);
}

Order::Order() {

}

Order::status Order::stringToStatusEnum(string status_string) {
    auto it = stringToStatus.find(status_string);
    if (it != stringToStatus.end()) {
        return it->second;
    }
    return Unknown;
}

