#include "OrderController.h"

Order_Controller::Order_Controller(const std::string& type) : type(type) {}

bool Order_Controller::create_order(const Order& order) {
    // Dummy implementation, always return true
    return true;
}