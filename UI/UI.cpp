#include "UI.h"
#include <iostream>


using namespace std;


UI::UI() {
    cus_controller = CustomerController();
    emp_controller = EmployeeController();
    employees = emp_controller.get_all_employees();
    customers = cus_controller.get_all_customers();
}

void UI::show_menu() {
    cout << "Welcome!\n"
            "1. Log in\n"
            "2. Sign up\n"
            "3. Exit";
}

void UI::show_user_type() {
    cout << "What do you want to log in as:\n"
            "1 - Customer\n"
            "2 - Employee\n";
}

void UI::login_customer() {
    string email;
    string password;

    while(true) {
        cout << "Enter your mail: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
        if(validate_login_customer(email, password)){
            return;
        }
        cout << "Incorrect Information\n";
    }
}

void UI::login_employee() {
    string email;
    string password;

    while(true) {
        cout << "Enter your mail: ";
        cin >> email;
        cout << "Enter your password: ";
        cin >> password;
        if(validate_login_employee(email, password)){
            return;
        }
        cout << "Incorrect Information\n";
    }
}


bool UI::validate_login_customer(string email, string password) {

    for(auto customer : customers){
        if(customer.get_email() == email && customer.get_password() == password){
            return true;
        }
    }
    return false;
}

bool UI::validate_login_employee(string email, string password) {

    for(auto employee: employees){
        if(employee.get_email() == email && employee.get_password() == password){
            return true;
        }
    }
    return false;
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
        //controller.customer_signup(email, password, first_name, last_name, phone, address); // din controller
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
        //controller.worker_signup(email, password, first_name, last_name, phone, address, position, birthday) // din controller
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


int UI::choosing_user_type() {
    int user_type_choice;
    while(true) {
        cin >> user_type_choice;
        if (user_type_choice == 1) {
            return 1;
        } else {
            if (user_type_choice == 2) {
                return 2;
            } else {
                cout << "Please pick a proper option\n";
            }
        }
    }
}


void UI::run() {
    while(true) {
        show_menu();
        int choice;
        int user_type;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            show_user_type();
            user_type = choosing_user_type();
            if(user_type == 1){
                login_customer();
                //customerUi.show_customer_menu();
            }
            else{
                login_employee();

            }

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
    //controller.search_by_license_plate(license_plate);
}

void UI::show_ordered_cars_by_customer() {
    int id;
    cout << "Customers's Id: " << endl;
    cin >> id;
    //controller.car_repository; // functie pentru afisarea masinilor din repo
    }
