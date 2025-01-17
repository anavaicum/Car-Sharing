
#include <algorithm>
#include "OrderController.h"

Order_Controller::Order_Controller() {
    order_repo = make_shared<Repo<Order>>("../Repository/OrderRepo.txt");
    customer_repo = make_shared<Repo<Customer>>("../Repository/CustomerRepo.txt");
    car_repo = make_shared<Repo<Car>>("../Repository/CarRepo.txt");
    employee_repo = make_shared<Repo<Employee>>("../Repository/EmployeeRepo.txt");
}

bool Order_Controller::create_order(const Order& order) {
    try {
        order_repo->add(order);
        return true;
    } catch (...) {
        return false;
    }
}



// Function to update an existing order
bool Order_Controller::update_order(const Order& existing_order, const Order& new_order) {
    vector<Order> orders = order_repo->get_all();
    for (auto& order : orders) {
        if (order.get_id() == existing_order.get_id()) {
            order = new_order;
            return true; // Return true if order is updated successfully
        }
    }
    return false; // Return false if order with the given order number is not found
}

// Function to mark an order as completed
bool Order_Controller::complete_order(int id) {
    vector<Order> orders = order_repo->get_all();
    for (auto& o : orders) {
        if (o.get_id() == id) {
            o.setStat("Completed");
            return true; // Return true if order is marked as completed successfully
        }
    }
    return false; // Return false if order with the given order number is not found
}

// Function to mark an order as taken over
//bool Order_Controller::take_over_order(Order& order) {
//    vector<Order> orders = order_repo->get_all();
//    for (auto& o : orders) {
//        if (o.getOrderId() == order.getOrderId()) {
//            o.setStat("Taken Over");
//            //o.stat = 'Reserved';
//            return true; // Return true if order is marked as taken over successfully
//        }
//    }
//    return false; // Return false if order with the given order number is not found
//}

//void Order_Controller::setStatus(const string& status) {
//    this->status = status;
//}

Order Order_Controller::get_by_id(int id) const {
    return order_repo->get_by_Id(id);

}


float Order_Controller::get_total_price_year(int year) const {
    float total_price = 0.0;
    vector<Order> orders = order_repo->get_all();
    for (const auto& order : orders) {
        if(order.getOrderDate().getYear() == year){
            total_price += order.getTotalPrice();
        }
    }
    return total_price;
}

float Order_Controller::get_total_price_month(int month) const {
    float total_price = 0.0;
    vector<Order> orders = order_repo->get_all();
    for (const auto& order : orders) {
        if(order.getOrderDate().getMonth() == month){
            total_price += order.getTotalPrice();
        }
    }
    return total_price;
}


bool Order_Controller::update_reservation(const Order& updated_order) {
    try {
        order_repo->update(updated_order.get_id(), updated_order);
        return true;
    } catch (const std::exception& e) {
        return false;
    }
}


bool Order_Controller::give_order_to_coworker(Order& order) {
    try {
        Date birthday(1, 1, 1990); // Exemplu de dată de naștere
        Employee* coworker = new Employee(1, "coworker@example.com", "password", "John", "Doe", "Technician", birthday, "JD", 3000.0f, false);
        order.setEmployee(*coworker);

        order_repo->update(order.get_id(), order);

        delete coworker; // Eliberarea memoriei alocate
        return true;
    } catch (const std::exception& e) {
        //std::cerr << "Failed to assign order to coworker: " << e.what() << std::endl;
        return false;
    }
}


std::vector<Order> Order_Controller::get_orders_between_dates(const Date& start_date, const Date& end_date) const {
    auto orders = order_repo->get_all();
    std::vector<Order> filtered_orders;

    for (const auto& order : orders) {
        Date order_date = order.getOrderDate();
        if (order_date >= start_date && order_date <= end_date) {
            filtered_orders.push_back(order);
        }
    }

    return filtered_orders;
}

std::vector<Order> Order_Controller::get_orders_sorted_by_price() const {
    auto orders = order_repo->get_all();
    std::sort(orders.begin(), orders.end(), [](const Order &a, const Order &b) {
        return a.getTotalPrice() < b.getTotalPrice();
    });
    return orders;
}




bool Order_Controller::delete_reservation(int id) {
    Order order = order_repo->get_by_Id(id);

    try {
        order.setIsReserved(false);

        // Creare obiect Customer gol
        Customer empty_customer;
        order.setCustomer(empty_customer);

        order_repo->update(order.get_id(), order);

        return true;
    } catch (const std::exception& e) {
        //std::cerr << "Failed to delete reservation: " << e.what() << std::endl;
        return false;
    }
}

bool Order_Controller::make_reservation(int orderId, int customerId) {
    Order order = order_repo->get_by_Id(orderId);
    Customer customer = customer_repo->get_by_Id(customerId);

    try {
        order.setCustomer(customer);
        order.setIsReserved(true);

        order_repo->update(order.get_id(), order);

        return true;
    } catch (const std::exception& e) {
        //std::cerr << "Failed to make reservation: " << e.what() << std::endl;
        return false;
    }
}

vector<Customer> Order_Controller::get_customers_by_ordered_car(int car_id) {
    vector<Customer> result;
    for(auto order : order_repo->get_all()){
        for(auto c : order.getCar()){
            if(c.get_id() == car_id){
                result.push_back(order.getCustomer());
                break;
            }
        }
    }
    return result;
}

bool Order_Controller::create_reservation(Date o_date, Date b_date, Date e_date, int car_id, int emp_id,
                                          int cus_id) {
    vector<Car> cars;
    for(auto car : car_repo->get_all()){
        if(car.get_id() == car_id){
            cars.push_back(car);
        }
    }
    Employee emp;
    for(auto employee : employee_repo->get_all()){
        if(emp_id == employee.get_id()){
            emp = employee;
        }
    }

    Customer cus;
    for(auto customer : customer_repo->get_all()){
        if(cus_id == customer.get_id()){
            cus = customer;
        }
    }
    Order o = Order(find_next_id(), o_date, "Reserved", b_date, e_date,true, cars, emp, cus);
    order_repo->add(o);
    return true;
}

int Order_Controller::find_next_id() {
    int max = 0;
    for(auto o : order_repo->get_all()){
        if(o.get_id() > max){
            max = o.get_id();
        }
    }
    return max + 1;
}

bool
Order_Controller::create_order(Date o_date, string stat, Date b_date, Date e_date, float tot_price, int car_id,
                               int emp_id, int cus_id) {

    vector<Car> cars;
    for(auto car : car_repo->get_all()){
        if(car.get_id() == car_id){
            cars.push_back(car);
        }
    }
    Employee emp;
    for(auto employee : employee_repo->get_all()){
        if(emp_id == employee.get_id()){
            emp = employee;
        }
    }

    Customer cus;
    for(auto customer : customer_repo->get_all()){
        if(cus_id == customer.get_id()){
            cus = customer;
        }
    }

    Order o = Order(find_next_id(), o_date, stat, b_date, e_date,false, cars, emp, cus);
    order_repo->add(o);
    return false;
}

