
#include "OrderController.h"

Order_Controller::Order_Controller(const std::string& type) : type(type) {
    this->order_repo = make_shared<Repo<Order>>("../../Repository/OrderRepo.txt");
}

bool Order_Controller::create_order(const Order& order) {
    try {
        order_repo.add(order);
        return true;
    } catch (...) {
        return false;
    }
}

// Function to update an existing order
bool Order_Controller::update_order(const Order& existing_order, const Order& new_order) {
    for (auto& order : orders) {
        if (order.getOrderId() == existing_order.getOrderId()) {
            order = new_order;
            return true; // Return true if order is updated successfully
        }
    }
    return false; // Return false if order with the given order number is not found
}

// Function to mark an order as completed
bool Order_Controller::complete_order(Order& order) {
    for (auto& o : orders) {
        if (o.getOrderId() == order.getOrderId()) {
            o.setStatus("Completed");
            return true; // Return true if order is marked as completed successfully
        }
    }
    return false; // Return false if order with the given order number is not found
}

// Function to mark an order as taken over
bool Order_Controller::take_over_order(Order& order) {
    for (auto& o : orders) {
        if (o.getOrderId() == order.getOrderId()) {
            o.setStatus("Taken Over");
            o.status = 'Reserved';
            return true; // Return true if order is marked as taken over successfully
        }
    }
    return false; // Return false if order with the given order number is not found
}

void Order_Controller::setStatus(const string& status) {
    this->status = status;
}

Order Order_Controller::get_by_id(int id) const {
    for (const auto& order : orders) {
        if (order.getOrderId() == id) {
            return order;
        }
    }
}


float Order_Controller::get_total_price(int year, int month, const Car& car, const Customer& customer, const Employee& employee) const {
    float total_price = 0.0;
    for (const auto& order : orders) {
        if (order.getCar()->getLicensePlate() == car.getLicensePlate()) {
            total_price += order.getTotalPrice();
        }
    }
    return total_price;
}
