//
// Created by Alexia on 5/20/2024.
//
#include <iostream>
using namespace std;
#include "AdminUI.h"
void AdminUI::create_worker() {
    int id;
    string first_name, last_name, email, password, position, initials;
    float salary;
    int day, month, year;
    Date birthday (day, month, year);
    bool is_Admin;

    cout <<"Worker's id: ";
    cin >> id;
    cout <<"Worker's first name: ";
    cin >> first_name;
    cout <<"Worker's last name: ";
    cin >> last_name;
    cout <<"Worker's email: ";
    cin >> email;
    cout <<"Worker's password: ";
    cin >> password;
    cout <<"Worker's position: ";
    cin >> position;
    cout <<"Worker's initials: ";
    cin >> initials;
    cout <<"Worker's salary: ";
    cin >> salary;
    cout <<"Worker's birthday: ";
    cin >> day;
    cin >> month;
    cin >> year;
    //birthday(day, month, year);
    cout <<"Is Worker Admin?: ";
    cin >> is_Admin;

}
void activateWorker() {}
void deactivateWorker() {}
void deleteWorker() {}
void giveAdminRights() {}
void workerSalary() {}
void changeWorkerSalary() {}