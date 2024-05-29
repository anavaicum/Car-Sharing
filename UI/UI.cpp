#include "UI.h"
#include "CustomerUI.h"
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
            "3. Exit\n";
}

void UI::show_user_type() {
    cout << "What do you want to log in as:\n"
            "1 - Customer\n"
            "2 - Employee\n";
}

int UI::login_customer() {
    string email;
    string password;

    while(true) {
        cout << "Enter your email: ";
        cin >> email;
        cout << "\nEnter your password: ";
        cin >> password;
        if(validate_login_customer(email, password)!=-1){
            return validate_login_customer(email, password);
        }
        cout << "\nIncorrect Information\n";
    }
}

int UI::login_employee() {
    string email;
    string password;

    while(true) {
        cout << "Enter your email: ";
        cin >> email;
        cout << "\nEnter your password: ";
        cin >> password;
        if(validate_login_employee(email, password) != -1){
            return validate_login_employee(email, password);
        }
        cout << "\nIncorrect Information\n";
    }
}


int UI::validate_login_customer(string email, string password) {

    for(auto customer : customers){
        if(customer.get_email() == email && customer.get_password() == password){
            return customer.get_id();
        }
    }
    return -1;
}

int UI::validate_login_employee(string email, string password) {

    for(auto employee: employees){
        if(employee.get_email() == email && employee.get_password() == password){
            return employee.get_id();
        }
    }
    return -1;
}

void UI::show_signup() {
    int opt = 0;
    cout << "1. Customer\n"
            " 2. Worker\n"
            "Enter your choice: ";
    cin >> opt;
    switch(opt) {
        case 1:
            signup_customer();
            break;
        case 2:
            signup_employee();
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
    }
}


void UI::show_customer_menu(int customerId) {
    CustomerUI customer;
    customer.show_customer_menu(customerId);
}

void UI::show_employee_menu(int employeeID) {
    UI_employee employee;
    employee.show_menu_employee(employeeID);
}

void UI::show_admin_menu() {

}


int UI::choosing_user_type() {
    int user_type_choice;
    while(true) {
        cin >> user_type_choice;
        if (user_type_choice == 1|| user_type_choice == 2) {
            return user_type_choice;
        } else
            cout << "Please pick a proper option\n";
    }
}

void UI::signup_customer() {
    string email, password, first_name, last_name, phone, address;
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
    //cin >> address;
    // Clear the input buffer before using getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, address);
    cus_controller.create_customer(email, password, first_name, last_name, phone, address);
}

void UI::signup_employee() {
    string email, password, first_name, last_name, phone, address, position;
    int day, month, year;
    float salary;
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
    //cin >> address;
    // Clear the input buffer before using getline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, address);
    cout << "Enter your position: ";
    cin >> position;
    // Validate day input
    while (true) {
        cout << "Enter your day of birth: ";
        cin >> day;
        if (cin.fail() || day < 1 || day > 31) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cout << "Invalid day. Please enter a number between 1 and 31.\n";
        } else {
            break;
        }
    }

    // Validate month input
    while (true) {
        cout << "Enter your month of birth: ";
        cin >> month;
        if (cin.fail() || month < 1 || month > 12) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cout << "Invalid month. Please enter a number between 1 and 12.\n";
        } else {
            break;
        }
    }

    // Validate year input
    while (true) {
        cout << "Enter your year of birth: ";
        cin >> year;
        if (cin.fail() || year < 1900 || year > 2024) { // Assuming year range
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cout << "Invalid year. Please enter a valid year.\n";
        } else {
            break;
        }
    }

    // Validate salary input
    while (true) {
        cout << "Enter your salary: ";
        cin >> salary;
        if (cin.fail() || salary < 0) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the rest of the input
            cout << "Invalid salary. Please enter a positive number.\n";
        } else {
            break;
        }
    }
    emp_controller.create_employee(email, password, first_name,
                                   last_name, phone, address, position,
                                   salary, day, month, year);
}


void UI::run() {
    while(true) {
        show_menu();
        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            show_user_type();
            int user_type = choosing_user_type();
            if(user_type == 1){
                int customerId = login_customer();
                customerUi.show_customer_menu(customerId);
            }
            else{
                int employee_id = login_employee();
                employeeUi.show_menu_employee(employee_id);
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











