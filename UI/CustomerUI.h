#ifndef CUSTOMERUI_H
#define CUSTOMERUI_H

#include <vector>
#include <string>
#include "../Domain/Car_Domain/Car.h"
#include "../Controller/Customer_Controller/CustomerController.h"
class CustomerUI {
public:
    CustomerUI();

    void show_cars(const std::vector<Car> &cars);
    void show_cars_between_dates(const std::vector<Car> &cars, int startYear, int endYear);
    void search_car_by_license_plate(const std::vector<Car> &cars, const std::string &licensePlate);
    void show_ordered_cars_sorted(const std::vector<Car> &cars);
    void show_delete_reservation();
    void show_make_reservation();
    void show_update_reservation();
    void show_all_orders_sorted_by_price(const std::vector<Car> &cars);
    void show_search_by_order_id();
    void show_change_password();
    void show_change_remarks();
    void show_add_car_to_favorites();
    void show_delete_car_from_favorites();
    void show_favorites();
    void show_customer_menu();
};

#endif // CUSTOMERUI_H
