#include "UI.h"
using namespace std;
#include <iostream>

void UI::show_menu() {
    cout << "Welcome!\n"
            "1. Log in\n"
            "2. Sign up\n"
            "3. Exit";
}

void UI::show_login() {
    string email;
    string password;
    cout << "Enter your mail: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> password;
    controller.login(email, password); //functie din controller
}

void UI::show_signup() {
    int opt = 0;
    cout << "1. Customer\n"
            "2. Worker\n";
    cin >> opt;
    if (opt == 1){
        string email;
        string password;
        string first_name;
        string last_name;
        string phone;
        string address;
        cout << "Enter your mail: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Enter your first name: ";
        cin >> first_name;
        cout << "Enter your last name: ";
        cin >> last_name;
        cout << "Enter your phone number: ";
        cin >> phone;
        cout << "Enter your address: ";
        cin >> address;
        controller.customer_signup(email, password, first_name, last_name, phone, address); // din controller
    }
    if (opt == 2){
        string email;
        string password;
        string first_name;
        string last_name;
        string phone;
        string address;
        string position;
        string birthday;
        cout << "Enter your mail: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Enter your first name: ";
        cin >> first_name;
        cout << "Enter your last name: ";
        cin >> last_name;
        cout << "Enter your phone number: ";
        cin >> phone;
        cout << "Enter your address: ";
        cin >> address;
        cout << "Enter your position: ";
        cin >> position;
        cout << "Enter your birthday: ";
        cin >> birthday;
        controller.worker_signup(email, password, first_name, last_name, phone, address, position, birthday) // din controller
    }

}

void UI::run() {
    while(true) {
        show_menu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            show_login();
        } else if (choice == 2) {
            show_signup();
        } else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Try again!\n";
        }
    }

}

void UI::show_search_car_by_license_plate() {
    string license_plate;
    cout << "Write the license plate: " << endl;
    cin >> license_plate;
    controller.search_by_license_plate(license_plate);
}

void UI::show_ordered_cars_by_customer() {
    int id;
    cout << "Customers's Id: " << endl;
    cin >> id;
    controller.car_repository; // functie pentru afisarea masinilor din repo
    }

void UI::show_all_workers() {
        string all_employees;
        cout << "The list of the workers: " << endl;
        cin >> all_workers; //vector dinamic din controller
        controller.worker_repository;
    }
void UI::search_worker() {
    int opt;
    if (opt == 1){
        string email;
        cout << "Enter the worker's email: ";
        cin >> email;
        controller.worker_repository;
    }
    if (opt == 2){
        string full_name;
        cout << "Enter the worker's full name: ";
        cin >> full_name;
        controller.worker_repository;
    }
    if (opt == 3){
        string birthday;
        cout << "Enter the worker's birthday: ";
        cin >> birthday;
        controller.worker_repository;
    }
}
void UI::show_change_worker_password() {
    string password;
    string new_password;

}
void UI::customer_modifications(){
    int opt;
    if (opt == 1){
        string email;
        string password;
        string first_name;
        string last_name;
        string phone;
        string address;
        cout << "Enter your mail: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Enter your first name: ";
        cin >> first_name;
        cout << "Enter your last name: ";
        cin >> last_name;
        cout << "Enter your phone number: ";
        cin >> phone;
        cout << "Enter your address: ";
        cin >> address;
        controller.customer_signup(email, password, first_name, last_name, phone, address);
    }
    if (opt == 2){
        //update customer
        controller.customer_repository;
    }
    if (opt == 3){
        //delete customer
        controller.customer_repository;
    }
}
void search_customer(){
    int opt;
    if (opt == 1){
        string email;
        cout << "Enter the customer's email: ";
        cin >> email;
        controller.customer_repository;
    }
    if (opt == 2){
        string phone;
        cout << "Enter the customer's phone number: ";
        cin >> phone;
        controller.customer_repository;
    }
    if (opt == 3){
        string name;
        cout << "Enter the customer's name: ";
        cin >> name;
        controller.customer_repository;
    }
}


string license_plate;
cout << "Write the license plate: " << endl;
cin >> license_plate;
controller.search_by_license_plate(license_plate);
"10. Show anonymise GDPR\n"
"14. Show customer by ordered car\n"
"15. Show create car\n"
"16. Show update car\n"
"17. Show delete car\n"
"18. Show deactivate car\n"