#ifndef CUSTOMER_UI_H
#define CUSTOMER_UI_H

#include <vector>
#include <string>
#include "../Domain/Car_Domain/Car.h"
#include "../Domain/Order_Domain/Order.h"
#include "../Domain/Customer_Domain/Customer.h"
#include "../Controller/Customer_Controller/CustomerController.h"
#include "../Controller/Car_Controller/CarController.h"
#include "../Controller/Order_Controller//OrderController.h"

class CustomerUI {
private:
    std::vector<Customer> customers;
    std::vector<Order> orders;
    CustomerController customercontroller;
    Car_Controller carcontroller;
    Order_Controller orderController;

public:
    CustomerUI();

    void show_cars();
    void show_cars_between_dates();
    void search_car_by_license_plate();
    void show_ordered_cars_sorted();
    void show_delete_reservation();
    void show_make_reservation();
    void show_update_reservation();
    void show_all_orders_sorted_by_price();
    void show_search_by_order_id();

    void show_change_password(int id);
    void show_change_remarks();
    void show_add_car_to_favorites(int id);
    void show_delete_car_from_favorites(int id);
    void show_favorites(int id);
    void show_customer_menu(int id);

};

#endif // CUSTOMER_UI_H
