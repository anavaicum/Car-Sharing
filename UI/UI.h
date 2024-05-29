#ifndef PROIECT_COLECTIV_UI_H
#define PROIECT_COLECTIV_UI_H
#include <vector>
#include "../Repository/Repo.h"
#include "../Controller/Car_Controller/CarController.h"
#include "../Controller/Order_Controller/OrderController.h"
#include "../Controller/Customer_Controller/CustomerController.h"
#include "../Controller/Employee_Controller/EmployeeController.h"
#include "CustomerUI.h"
#include "UI_employee.h"

using namespace std;

class UI {
private:
    CustomerUI customerUi;
    UI_employee employeeUi;
    EmployeeController emp_controller;
    CustomerController cus_controller;
    vector <Customer> customers;
    vector <Employee> employees;
public:
    UI();
    void run();
    void show_user_type();
    int choosing_user_type();
    void show_menu();
    int login_customer();
    int login_employee();
    void show_signup();
    void signup_customer();
    void signup_employee();
    void show_customer_menu(int customerId);
    void show_employee_menu(int employeeId);
    void show_all_cars_between_dates();
    void show_search_car_by_license_plate();
    void show_ordered_cars_by_customer();
    void redirect_menu();
    int validate_login_employee(string email, string password);
    int validate_login_customer(string email, string password);
    void determine_user_type_and_showMenu(string email);

    void show_admin_menu();
};


#endif //PROIECT_COLECTIV_UI_H
