#include "UI.h"
#include <iostream>
using namespace std;

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
//    controller.login(email, password); //functie din controller
    if (validate_login(email, password)) {
        determine_user_type_and_show_menu(email);
    } else {
        std::cout << "Invalid email or password!" << std::endl;
    }
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

void UI::show_customer_menu() {
    CustomerUI customer;
    customer.show_customer_menu();
}

void UI::show_employee_menu() {

}

void UI::show_admin_menu() {

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
