#ifndef PROIECT_COLECTIV_UI_H
#define PROIECT_COLECTIV_UI_H
#include <vector>
#include "../Repository/Repo.h"
#include "../Controller/Car_Controller/CarController.h"
#include "../Controller/Order_Controller/OrderController.h"
#include "../UI/CustomerUI.h"
#include "../UI/AdminUI.h"
using namespace std;

class UI {
private:
    Controller controller;
    vector <Customer> customers;
    vector <Employee> workers;
public:
    void run();
    void show_menu();
    void show_login();
    void show_signup();
    bool validate_login(string email, string password);
    void determine_user_type_and_show_menu(string email);
    void show_customer_menu();
    void show_employee_menu();
    void show_admin_menu();
};


#endif //PROIECT_COLECTIV_UI_H
