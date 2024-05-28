#ifndef PROIECT_COLECTIV_UI_EMPLOYEE_H
#define PROIECT_COLECTIV_UI_EMPLOYEE_H
#include <vector>
using namespace std;

class UI_employee {
private:
    Controller controller;
public:
    void show_menu_employee();
    void show_all_employees();
    void search_employee();
    void show_change_employee_password();
    void customer_modifications();
    void show_anonymise_GDPR();
    void show_all_customers_sorted_by_name();
    void search_customer();
    void car_modifications();
    void show_deactivated_car();
    void show_add_order();
    void show_make_reservation_to_order();
    void show_update_order();
    void show_complete_order();
    void show_take_order();
    void show_give_order();
    void reservation_modifications();
    void show_all_orders_between_dates();
    void search_order_by_id();
    bool validate_date();
};
#endif //PROIECT_COLECTIV_UI_EMPLOYEE_H
