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

void AdminUI::update_worker() {
    string email;
    cout << "Worker's email to update: ";
    cin >> email;

    for (auto& worker: workers) {
        if (worker.get_email() == email){
            //TODO: WHAT DO I UPDATE? :((
            cout << "Worker updated!" << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}

void AdminUI::activate_worker() {
    string email;
    cout << "Worker's email to activate: ";
    cin >> email;

    for (auto& worker: workers) {
        if (worker.get_email() == email){
            worker.activate(true);
            cout << "Worker activated!" << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}

void AdminUI::deactivate_worker() {
    string email;
    cout << "Worker's email to deactivate: ";
    cin >> email;

    for (auto& worker: workers) {
        if (worker.get_email() == email){
            worker.deactivate(false);
            cout << "Worker deactivated!" << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}

void AdminUI::delete_worker() {
    string email;
    cout << "Worker's email to delete: ";
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

void AdminUI::give_admin_rights() {
    string email;
    cout << "Worker's email to give admin rights to: ";
    cin >> email;

    for (auto& worker: workers) {
        if (worker.get_email() == email){
            worker.set_admin(true);
            cout << "Worker is now admin!" << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}

void AdminUI::worker_salary() {
    string email;
    cout << "Worker's email to view salary: ";
    cin >> email;

    for (auto& worker: workers) {
        if (worker.get_email() == email){
            cout << "Worker's salary: " << worker.get_salary() << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}

void AdminUI::change_worker_salary() {
    string email;
    cout << "Worker's email to change salary: ";
    cin >> email;
    float new_salary;

    for (auto& worker: workers) {
        if (worker.get_email() == email){
            cout << "Enter new salary: ";
            cin >> new_salary;
            worker.set_salary(new_salary);
            cout << "Worker's salary has been updated!" << endl;
            break;
        } else {
            cout << "Worker with given email not found!" << endl;
        }
    }
}