#ifndef PROIECT_COLECTIV_ORDERCONTROLLER_H
#define PROIECT_COLECTIV_ORDERCONTROLLER_H


#include "../../Domain/Order_Domain/Order.h"
#include "../../Repository/IRepo.h"
#include "../../Repository/Repo.h"
#include <vector>

class Order_Controller {
private:
    shared_ptr<IRepo<Order>> order_repo;
    std::string type; // Field to store type of controller

public:
    Order_Controller(const std::string& type); // Constructor

    // Function to create an order
    bool create_order(const Order& order);

    // Function to update an existing order
    bool update_order(const Order& existing_order, const Order& new_order);

    // Function to mark an order as completed
    bool complete_order(Order& order);

    // Function to mark an order as taken over
    bool take_over_order(Order& order);

    // Function to assign an order to a coworker
    bool give_order_to_coworker(Order& order);

    // Function to delete a reservation
    bool delete_reservation(Order& order);

    // Function to make a reservation for a customer
    bool make_reservation(Order& order, Customer& customer);

    // Function to update a reservation
    void update_reservation(Order& order, const Order& new_order);

    // Function to get orders between two dates
    std::vector<Order> get_orders_between_dates(const Date& start_date, const Date& end_date) const;

    // Function to get an order by its ID
    Order get_by_id(int id) const;

    // Function to calculate the total price of orders for a specific criteria
    float get_total_price(int year, int month, const Car& car, const Customer& customer, const Employee& coworker) const;

    // Method to set the status of the order
    void setStatus(const std::string& status);
};


#endif //PROIECT_COLECTIV_ORDERCONTROLLER_H
