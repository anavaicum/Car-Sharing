#ifndef CUSTOMER_UI_H
#define CUSTOMER_UI_H

#include <vector>
#include <string>
#include "../Domain/Car_Domain/Car.h"
#include "../Domain/Order_Domain/Order.h"
#include "../Domain/Customer_Domain/Customer.h"
#include "../Controller/Customer_Controller/CustomerController.h"
#include "../Controller/Car_Controller/CarController.h"

class CustomerUI {
private:
    std::vector<Customer> customers;
    std::vector<Order> orders;
    CustomerController customercontroller;
    //Car_Controller carcontroller;

public:
    CustomerUI();

    void show_cars(const std::vector<Car>& cars);
    void show_cars_between_dates(const std::vector<Car>& cars, int startYear, int endYear);
    void search_car_by_license_plate(const std::vector<Car>& cars, const std::string& licensePlate);
    void show_ordered_cars_sorted(const std::vector<Car>& cars);
    void show_delete_reservation();
    void show_make_reservation();
    void show_update_reservation();
    void show_all_orders_sorted_by_price();
    void show_search_by_order_id();
    void show_change_password(Customer& customer, const std::string& newPassword);
    void show_change_remarks(Car& car, const std::vector<std::string>& newRemarks);
    void show_add_car_to_favorites(Customer& customer, const Car& car);
    void show_delete_car_from_favorites(Customer& customer, const Car& car);
    void show_favorites(const Customer& customer);
};

#endif // CUSTOMER_UI_H
