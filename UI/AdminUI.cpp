//
// Created by Alexia on 5/20/2024.
//
#include <iostream>
#include <vector>
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
    Employee newWorker(id, email, password, first_name, last_name, position, birthday, initials, salary, is_Admin);
    workers.push_back(newWorker);
}
void AdminUI::activate_worker() {
    string email;
    cout << "Worker's email to activate: ";
    cin >> email;

    for (auto& worker: workers) {
        if (worker.get_email() == email){
            worker.setActive(true);
            cout << "Worker activated!" << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}
void AdminUI::deactivate_worker() {
    string email;
    cout << "Worker's email to activate: ";
    cin >> email;

    for (auto& worker: workers) {
        if (worker.get_email() == email){
            worker.setActive(false);
            cout << "Worker activated!" << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}
void AdminUI::delete_worker() {
    string email;
    cout << "Worker's email to activate: ";
    cin >> email;
    for (auto worker = workers.begin(); worker != workers.end(); worker++){
        if (worker->get_email() == email) {
            workers.erase(worker);
            cout << "Worker deleted!" << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}
void AdminUI::give_admin_rights() {}
void AdminUI::worker_salary() {}
void AdminUI::change_worker_salary() {}