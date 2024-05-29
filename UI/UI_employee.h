#ifndef PROIECT_COLECTIV_UI_EMPLOYEE_H
#define PROIECT_COLECTIV_UI_EMPLOYEE_H
#include <vector>
#include "../Controller/Employee_Controller/EmployeeController.h"
#include "../Controller/Customer_Controller/CustomerController.h"
#include "../Controller/Order_Controller/OrderController.h"
#include "../Controller/Car_Controller/CarController.h"
using namespace std;

class UI_employee {
protected:
    EmployeeController employeeController;
    CustomerController customerController;
    Order_Controller orderController;
    Car_Controller carController;
public:

    UI_employee();
    void show_menu_employee(int employeeId);
    void show_all_employees();
    void search_employee();
    void show_change_employee_password(int employee_id);
    void customer_modifications();
    void anonymise_GDPR();
    void show_all_customers_sorted_by_name();
    void search_customer();
    void car_modifications();
    void show_deactivated_car();
    void show_add_order(int employee_id);
    void show_make_reservation_to_order();
    void show_update_order();
    void show_complete_order();
    void show_take_order();
    void show_give_order();
    void reservation_modifications(int employee_id);
    void show_all_orders_between_dates();
    void search_order_by_id();
    bool validate_date(int day, int month, int year);
};
#endif //PROIECT_COLECTIV_UI_EMPLOYEE_H
