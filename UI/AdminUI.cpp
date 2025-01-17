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
    Date birthday (day, month, year);
    cout <<"Is Worker Admin?: ";
    cin >> is_Admin;
    Employee newWorker(id, email, password, first_name, last_name, position, birthday, initials, salary, is_Admin);
    workers.push_back(newWorker);
    employeeController.create_employee(newWorker);
}

void AdminUI::update_worker() {
    int id;
    cout << "Worker's id to update: ";
    cin >> id;

    for (auto& worker: workers) {
        if (worker.get_id() == id){
            string new_position;
            float new_salary;
            bool new_is_admin;
            cout << "New position: " << endl;
            cin >> new_position;
            cout << "New salary: " << endl;
            cin >> new_salary;
            cout << "Is this worker now admin?: " << endl;
            cin >> new_is_admin;
            worker.set_position(new_position);
            worker.set_salary(new_salary);
            worker.set_admin(new_is_admin);
            cout << "Worker updated!" << endl;

            break;
        } else {
            cout << "Worker with given id not found!" << endl;
        }
    }
}

void AdminUI::activate_worker() {
//    int id;
//    cout << "Worker's id to activate: ";
//    cin >> id;
//
//    for (auto& worker: workers) {
//        if (worker.get_id() == id){
//            worker.activate(true);
//            cout << "Worker activated!" << endl;
//            break;
//        } else {
//            cout << "Worker with given id not found!" << endl;
//        }
//    }
}

void AdminUI::deactivate_worker() {
//    int id;
//    cout << "Worker's id to deactivate: ";
//    cin >> id;
//
//    for (auto& worker: workers) {
//        if (worker.get_id() == id){
//            worker.deactivate(false);
//            cout << "Worker deactivated!" << endl;
//            break;
//        } else {
//            cout << "Worker with given id not found!" << endl;
//        }
//    }
}

void AdminUI::delete_worker() {
    int id;
    cout << "Worker's id to delete: ";
    cin >> id;
    for (auto worker = workers.begin(); worker != workers.end(); worker++){
        if (worker->get_id() == id) {
            workers.erase(worker);
            cout << "Worker deleted!" << endl;
            break;
        } else {
            cout << "Worker with given id not found!" << endl;
        }
    }
}

void AdminUI::give_admin_rights() {
    int id;
    cout << "Worker's id to give admin rights to: ";
    cin >> id;

    for (auto& worker: workers) {
        if (worker.get_id() == id){
            worker.set_admin(true);
            cout << "Worker is now admin!" << endl;
            break;
        } else {
            cout << "Worker with given id not found!" << endl;
        }
    }
}

void AdminUI::worker_salary() {
    int id;
    cout << "Worker's id to view salary: ";
    cin >> id;

    for (auto& worker: workers) {
        if (worker.get_id() == id){
            cout << "Worker's salary: " << worker.get_salary() << endl;
            break;
        } else {
            cout << "Worker with given id not found!" << endl;
        }
    }
}

void AdminUI::change_worker_salary() {
    int id;
    cout << "Worker's id to change salary: ";
    cin >> id;
    float new_salary;

    for (auto& worker: workers) {
        if (worker.get_id() == id){
            cout << "Enter new salary: ";
            cin >> new_salary;
            worker.set_salary(new_salary);
            cout << "Worker's salary has been updated!" << endl;
            break;
        } else {
            cout << "Worker with given id not found!" << endl;
        }
    }
}

void AdminUI::show_all_workers() {
    std::cout << "List of all workers:" << endl;
    for (auto& worker : workers) {
        std::cout << "Name: " << worker.get_first_name() << " " << worker.get_last_name() << endl;
    }
}