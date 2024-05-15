#ifndef PROIECT_COLECTIV_UI_H
#define PROIECT_COLECTIV_UI_H
#include <vector>
using namespace std;

class UI {
private:
    Controller controller;
public:
    void run();
    void show_menu();
    void show_login();
    void show_signup();
    void show_all_cars_between_dates();
    void show_search_car_by_license_plate();
    void show_ordered_cars_by_customer();
};


#endif //PROIECT_COLECTIV_UI_H
