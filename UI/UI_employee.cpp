#include "UI_employee.h"
#include "EmployeeController.h"
using namespace std;
#include <iostream>

void UI_employee::show_menu_employee() {
    cout << "Choose next!\n"
            "1. Show all employees\n"
            "2. Search employee\n"
            "3. Change employee password\n";
            "4. Customer modifications\n";
            "5. Anonymise GDPR";
            "6. Show all customers sorted by name\n";
            "7. Search customer\n";
            "8. Car modifications\n";
            "9. Show deactivated car\n";
            "10. Show complete order\n";
            "11. Take an order\n";
            "12. Validate date\n"
            "13. Give an order\n";
            "14. Reservation modifications\n";
            "15. Search order by ID\n";
            "16. Exit";
            "Enter your choice: ";
}

void UI_employee::show_all_employees() {
    string all_employees;
    cout << "The list of all the eomplyees: " << endl;
    cin >> all_employees; //vector dinamic din controller
    controller.employee_repository;
}
void UI_employee::search_employee() {
    int opt;
    if (opt == 1){
        string email;
        cout << "Enter the employee's email: ";
        cin >> email;
        controller.employee_repository;
    }
    else if (opt == 2){
        string full_name;
        cout << "Enter the employee's full name: ";
        cin >> full_name;
        controller.employee_repository;
    }
    else if (opt == 3){
        string birthday;
        cout << "Enter the employee's birthday: ";
        cin >> birthday;
        controller.employee_repository;
    }
}
void UI_employee::show_change_employee_password() {
    string current_password;
    string new_password;
    string confirm_password;
    cout << "Enter your current password: ";
    cin >> current_password;
    do {
        cout << "Enter your new password: ";
        cin >> new_password;
        cout << "Confirm your new password: ";
        cin >> confirm_password;

        if (new_password != confirm_password) {
            std::cout << "Passwords do not match. Please re-enter." << std::endl;
        }
    }
    while (new_password != confirm_password);
    if (controller.change_employee_password(current_password, new_password)) {
        cout << "Password changed successfully!" << endl;
    }
    else {
        cout << "Error: Invalid current password or unable to update password." << endl;
    }
}
void UI_employee::customer_modifications(){
    int opt;
    if (opt == 1){
        string email;
        string password;
        string first_name;
        string last_name;
        string phone;
        string address;
        cout << "Enter customer's mail: ";
        cin >> email;
        cout << "Enter customer's password: ";
        cin >> password;
        cout << "Enter customer's first name: ";
        cin >> first_name;
        cout << "Enter customer's last name: ";
        cin >> last_name;
        cout << "Enter customer's phone number: ";
        cin >> phone;
        cout << "Enter customer's address: ";
        cin >> address;
        controller.customer_signup(email, password, first_name, last_name, phone, address);
    }
    else if (opt == 2){
        string email;
        cout << "Enter the email of the customer account you want to update: ";
        cin >> email;
        string new_password;
        string new_first_name;
        string new_last_name;
        string new_phone;
        string new_address;
        bool update_all = false;

        cout << "Update all fields (y/n)?" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y') {
            update_all = true;

            cout << "Enter new password (leave blank to keep old): ";
            cin >> new_password;

            cout << "Enter new first name: ";
            cin >> new_first_name;

            cout << "Enter new last name: ";
            cin >> new_last_name;

            cout << "Enter new phone number: ";
            cin >> new_phone;

            cout << "Enter new address: ";
            cin >> new_address;
        }
        controller.customer_update(email, update_all, new_password, new_first_name,
                                   new_last_name, new_phone, new_address);
        break;
    }
    else if (opt == 3){
        string email;
        cout << "Enter the email of the customer account you want to delete: ";
        cin >> email;

        controller.customer_delete(email);
        break;
    }
}
void UI_employee::search_customer(){
    int opt;
    if (opt == 1){
        string email;
        cout << "Search a customer by email: ";
        cin >> email;
        controller.search_customer_by_email;
    }
    else if (opt == 2){
        string phone;
        cout << "Search a customer by phone number: ";
        cin >> phone;
        controller.search_customer_by_phone;
    }
    else if (opt == 3){
        string name;
        cout << "Search a customer by name: ";
        cin >> name;
        controller.search_customer_by_name;
    }
    else if (opt == 4) {
        string car_id;
        cout << "Enter the ID of the ordered car: ";
        cin >> car_id;
        controller.search_customer_by_ordered_car(car_id);
    }
}
void UI_employee::car_modifications() {
    int opt;
    cout << "Car Modifications Menu:\n";
            "1. Create Car\n" << std::endl;
            "2. Update Car\n" << std::endl;
            "3. Delete Car\n" << std::endl;
            "Enter your choice: ";
    cin >> opt;
    if (opt == 1){
        string license_plate;
        string model;
        string brand;
        string fuel_type;
        string transmission;
        string color;
        string remarks;
        int year;
        double mileage;
        double price_per_day;

        cout << "Enter license plate: ";
        cin >> license_plate;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter year of first registration: ";
        cin >> year;
        cout << "Enter mileage: ";
        cin >> mileage;
        cout << "Enter price per day: ";
        cin >> price_per_day;
        cout << "Enter color: ";
        cin >> color;
        cout << "Enter remarks (optional): ";
        cin >> remarks;

        controller.create_car(license_plate, model, brand, year, mileage,
                              price_per_day, fuel_type, transmission, color, remarks);
    }
    else if (opt == 2) {
        string license_plate;
        string update_field;
        string new_value;

        cout << "Enter license plate of the car to update: ";
        cin >> license_plate;

        cout << "Enter the field you want to update (license_plate, model, brand, year, mileage, price, fuel_type, transmission, color, remarks): ";
        cin >> update_field;
        cout << "Enter the new value for the field: ";
        controller.update_car_field(license_plate, update_field, new_value);
    }
    else if (opt == 3) {
        string license_plate;
        cout << "Enter license plate of the car you want to delete: ";
        cin >> license_plate;
        controller.delete_car(license_plate);
    }
}

void UI_employee::show_deactivate_car() {
    string license_plate;
    cout << "Enter license plate of the deactivated car: ";
    cin >> license_plate;

    Car car = controller.get_car_by_license_plate(license_plate);
    if (car.get_license_plate().empty() || !car.is_deactivated()) {
        cout << "Car with license plate '" << license_plate << "' not found or active." << endl;
        return;
    }

    cout << "Car Details (Deactivated):" << endl;
    cout << "License Plate: " << car.get_license_plate() << endl;
    cout << "Model: " << car.get_model() << endl;
    cout << "Brand: " << car.get_brand() << endl;
    cout << "Year: " << car.get_year() << endl;
    cout << "Mileage: " << car.get_mileage() << " km" << endl;
    cout << "Price per Day: " << car.get_price_per_day() << " $" << endl;
    cout << "Fuel Type: " << car.get_fuel_type() << endl;
    cout << "Transmission: " << car.get_transmission() << endl;
    cout << "Color: " << car.get_color() << endl;
    cout << "Remarks: " << car.get_remarks() << endl;
}

void UI_employee::show_add_order() {
    string customer_email;
    string license_plate;
    int start_day;
    int start_month;
    int start_year;
    int end_day;
    int end_month;
    int end_year;

    cout << "Enter customer email: ";
    cin >> customer_email;

    cout << "Enter car license plate: ";
    cin >> license_plate;

    do {
        cout << "Enter start date (DD MM YYYY): ";
        cin >> start_day >> start_month >> start_year;
    } while (!validate_date(start_day, start_month, start_year));

    do {
        cout << "Enter end date (DD MM YYYY): ";
        cin >> end_day >> end_month >> end_year;
    } while (!validate_date(end_day, end_month, end_year) || !is_date_after(start_day, start_month, start_year, end_day, end_month, end_year));

    controller.add_order(customer_email, license_plate, start_day, start_month, start_year, end_day, end_month, end_year);
}


bool UI_employee::validate_date(int day, int month, int year) {
    if (month < 1 || month > 12) {
        return false;
    }

    int max_days = 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        max_days = 30;
    }
    else if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            max_days = 29;
        }
        else {
            max_days = 28;
        }
    }

    if (day < 1 || day > max_days) {
        return false;
    }
    return true;
}

void UI_employee::reservation_modifications() {
    int opt;
    cout << "Reservation Modifications Menu:\n";
    cout << "1. Add Reservation\n";
    cout << "2. Update Reservation\n";
    cout << "3. Delete Reservation\n";
    cout << "Enter your choice: ";
    cin >> opt;

    if (opt == 1) {
        string customer_email, license_plate;
        int start_day, start_month, start_year;
        int end_day, end_month, end_year;

        cout << "Enter customer email: ";
        cin >> customer_email;

        cout << "Enter car license plate: ";
        cin >> license_plate;

        do {
            cout << "Enter start date (DD MM YYYY): ";
            cin >> start_day >> start_month >> start_year;
        } while (!validate_date(start_day, start_month, start_year));

        do {
            cout << "Enter end date (DD MM YYYY): ";
            cin >> end_day >> end_month >> end_year;
        } while (!validate_date(end_day, end_month, end_year) || !is_date_after(start_day, start_month, start_year, end_day, end_month, end_year));
        
        controller.create_reservation(customer_email, license_plate, start_day, start_month, start_year, end_day, end_month, end_year);
    }
    else if (opt == 2) {
    }

void UI_employee::show_all_orders_between_dates() {
    int start_day, start_month, start_year;
    int end_day, end_month, end_year;

    do {
        cout << "Enter start date (DD MM YYYY): ";
        cin >> start_day >> start_month >> start_year;
    } while (!validate_date(start_day, start_month, start_year));

    do {
        cout << "Enter end date (DD MM YYYY): ";
        cin >> end_day >> end_month >> end_year;
    }
    while (!validate_date(end_day, end_month, end_year) || !is_date_after(start_day, start_month, start_year, end_day, end_month, end_year));

    vector<Order> orders = controller.get_orders_between_dates(start_day, start_month, start_year, end_day, end_month, end_year);
    if (orders.empty()) {
        cout << "No orders found between the specified dates.\n";
    } else {
        cout << "List of orders between " << start_day << "/" << start_month << "/" << start_year << " and " << end_day << "/" << end_month << "/" << end_year << ":\n";
        for (const Order& order : orders) {
            cout << order << endl;
        }
    }
}

void UI_employee::search_order_by_id() {
    int order_id;
    cout << "Enter order ID: ";
    cin >> order_id;

    Order order = controller.get_order_by_id(order_id);
    if (order.get_id() == -1) {
        cout << "Order with ID " << order_id << " not found.\n";
    }
    else {
        cout << "Order details:\n" << order << endl;
    }
}