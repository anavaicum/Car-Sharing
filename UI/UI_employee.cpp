#include "UI_employee.h"

using namespace std;
#include <iostream>


UI_employee::UI_employee() {
    employeeController = EmployeeController();
    customerController = CustomerController();
    orderController = Order_Controller();
    carController = Car_Controller();
}

void UI_employee::show_menu_employee(int employeeId) {
    int option;
    cout << "Choose next!\n"
            "1. Show all employees\n"
            "2. Search employee\n"
            "3. Change employee password\n"
            "4. Customer modifications\n"
            "5. Anonymise GDPR\n"
            "6. Show all customers sorted by name\n"
            "7. Search customer\n"
            "8. Car modifications\n"
            "9. Show deactivated car\n"
            "10. Show complete order\n"
            "11. Take an order\n"
            "12. Give an order\n"
            "13. Reservation modifications\n"
            "14. Search order by ID\n"
            "15. Add Order\n"
            "0. Exit\n"
            "Enter your choice: ";
    cin >> option;
    switch (option) {
        case 1:
            show_all_employees();
            break;
        case 2:
            search_employee();
            break;
        case 3:
            show_change_employee_password(employeeId);
            break;
        case 4:
            customer_modifications();
            break;
        case 5:
            anonymise_GDPR();
            break;
        case 6:
            show_all_customers_sorted_by_name();
            break;
        case 7:
            search_customer();
            break;
        case 8:
            car_modifications();
            break;
        case 9:
            show_deactivated_car();
            break;
        case 10:
            show_complete_order();
            break;
        case 11:
            show_take_order();
            break;
        case 12:
            show_give_order();
            break;
        case 13:
            reservation_modifications(employeeId);
            break;
        case 14:
            search_order_by_id();
            break;
        case 15:
            show_add_order(employeeId);
            break;
        case 0:
            cout << "Goodbye";
            break;
        default:
            cout << "Invalid option";
            break;
    }
}

void UI_employee::show_all_employees() {
    cout << "The list of all the employees: " << endl;
    for(const auto& employee : employeeController.get_all_employees()){
        cout << employee.get_id() << " " << employee.get_first_name() << " " << employee.get_last_name() << "\n";
    }
}
void UI_employee::search_employee() {
    int opt;

    if (opt == 1){
        string email;
        cout << "Enter the employee's email: ";
        cin >> email;
        for(const auto& employee : employeeController.search_by_email(email)){
            cout << employee.get_id() << " " << employee.get_first_name() << " " << employee.get_last_name() << "\n";
        }
    }
    else if (opt == 2){
        string first_name, last_name;
        cout << "Enter the employee's first name: ";
        cin >> first_name;
        cout << "Enter the employee's last name: ";
        cin >> last_name;
        for(const auto& employee : employeeController.search_by_full_name(first_name, last_name)){
            cout << employee.get_id() << " " << employee.get_first_name() << " " << employee.get_last_name() << "\n";
        }
    }
    else if (opt == 3){
        int day, month, year;
        cout << "Enter the employee's day of birth: ";
        cin >> day;
        cout << "Enter the employee's month of birth: ";
        cin >> month;
        cout << "Enter the employee's year of birth";
        cin >> year;
        for(const auto& employee : employeeController.search_by_birth_date(Date(day, month, year))){
            cout << employee.get_id() << " " << employee.get_first_name() << " " << employee.get_last_name() << "\n";
        }
    }
}
void UI_employee::show_change_employee_password(int employee_id) {
    string current_password, new_password, confirm_password;
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


    if (employeeController.change_employee_password(employee_id, new_password)) {
        cout << "Password changed successfully!" << endl;
    }
    else {
        cout << "Error: Invalid current password or unable to update password." << endl;
    }
}
void UI_employee::customer_modifications(){
    int opt;
    cout << "1 - Create Customer\n"
            "2 - Update Customer\n"
            "3 - Delete Customer\n";
    cin >> opt;
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
        customerController.create_customer(email, password, first_name,
                                           last_name, phone, address);
    }
    else if (opt == 2){
        int id;
        cout << "Enter the id of the customer account you want to update: ";
        cin >> id;
        string email;
        string new_password;
        string new_first_name;
        string new_last_name;
        string new_phone;
        string new_address;

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

        customerController.update_customer(id, email, new_password,
                                           new_first_name, new_last_name, new_phone, new_address);
    }
    else if (opt == 3){
        int id;
        cout << "Enter the id of the customer you want to delete: ";
        cin >> id;

        customerController.delete_customer(id);
    }
}
void UI_employee::search_customer(){
    int opt;
    cout << "1 - Search by email\n"
            "2 - Search by phone number\n"
            "3 - Search by name\n"
            "4 - Search by car id\n"
            "Enter your option: ";
    cin >> opt;
    if (opt == 1){
        string email;
        cout << "Search a customer by email: ";
        cin >> email;
        for(auto customer: customerController.search_by_email(email)){
            cout << customer.get_id() << " "
            << customer.get_email() << " "
            << customer.get_first_name() << " "
            << customer.get_last_name() << '\n';
        }
    }
    else if (opt == 2){
        string phone;
        cout << "Search a customer by phone number: ";
        cin >> phone;
        for(auto customer: customerController.search_by_phone(phone)){
            cout << customer.get_id() << " "
                 << customer.get_email() << " "
                 << customer.get_phone() << " "
                 << customer.get_first_name() << " "
                 << customer.get_last_name() << '\n';
        }
    }
    else if (opt == 3){
        string f_name, l_name;
        cout << "Search a customer by first_name: ";
        cin >> f_name;
        cout << "Search a customer by last name: ";
        cin >> l_name;
        for(auto customer: customerController.search_by_name(f_name, l_name)){
            cout << customer.get_id() << " "
                 << customer.get_email() << " "
                 << customer.get_first_name() << " "
                 << customer.get_last_name() << '\n';
        }
    }
    else if (opt == 4) {
        int car_id;
        cout << "Enter the ID of the ordered car: ";
        cin >> car_id;
        for(auto customer: orderController.get_customers_by_ordered_car(car_id)){
            cout << customer.get_id() << " "
                 << customer.get_email() << " "
                 << customer.get_first_name() << " "
                 << customer.get_last_name() << '\n';
        }
    }
}
void UI_employee::car_modifications() {
    int opt;
    cout << "Car Modifications Menu:\n"
            "1. Create Car\n"
            "2. Update Car\n"
            "3. Delete Car\n"
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
        carController.create_car(license_plate, model, brand, fuel_type,
                                 transmission, color, year, mileage, price_per_day);
    }
    else if (opt == 2) {
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

        cout << "Enter license plate of the car you want to update: ";
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

        carController.update_car(license_plate, model, brand, fuel_type, transmission,
                                 color, year, mileage, price_per_day);
    }
    else if (opt == 3) {
        int id;
        cout << "Enter id of car you want to delete: ";
        cin >> id;
        carController.delete_car(id);
    }
}

void UI_employee::show_deactivated_car() {
//    string license_plate;
//    cout << "Enter license plate of the deactivated car: ";
//    cin >> license_plate;
//
//    Car car = controller.get_car_by_license_plate(license_plate);
//    if (car.get_license_plate().empty() || !car.is_deactivated()) {
//        cout << "Car with license plate '" << license_plate << "' not found or active." << endl;
//        return;
//    }
//
//    cout << "Car Details (Deactivated):" << endl;
//    cout << "License Plate: " << car.get_license_plate() << endl;
//    cout << "Model: " << car.get_model() << endl;
//    cout << "Brand: " << car.get_brand() << endl;
//    cout << "Year: " << car.get_year() << endl;
//    cout << "Mileage: " << car.get_mileage() << " km" << endl;
//    cout << "Price per Day: " << car.get_price_per_day() << " $" << endl;
//    cout << "Fuel Type: " << car.get_fuel_type() << endl;
//    cout << "Transmission: " << car.get_transmission() << endl;
//    cout << "Color: " << car.get_color() << endl;
//    cout << "Remarks: " << car.get_remarks() << endl;

    cout << "To be implemented...";
}

void UI_employee::show_add_order(int employee_id) {
    int car_id, customer_id;
    int start_day;
    int start_month;
    int start_year;
    int end_day;
    int end_month;
    int end_year;
    string status;

    cout << "Enter customer id: ";
    cin >> customer_id;

    cout << "Enter car id: ";
    cin >> car_id;

    cout << "Enter status: ";
    cin >> status;
    do {
        cout << "Enter start date (DD MM YYYY): ";
        cin >> start_day >> start_month >> start_year;
    } while (!validate_date(start_day, start_month, start_year));

    do {
        cout << "Enter end date (DD MM YYYY): ";
        cin >> end_day >> end_month >> end_year;
    } while (!validate_date(end_day, end_month, end_year));

   orderController.create_order(Date(start_day, start_month, start_year),
                                status,
                                Date(start_day, start_month, start_year),
                                Date(end_day, end_month, end_year), 0,
                                car_id, employee_id, customer_id);
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

void UI_employee::reservation_modifications(int employee_id) {
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
        int car_id, customer_id;

        cout << "Enter customer id: ";
        cin >> customer_id;

        cout << "Enter car id: ";
        cin >> car_id;

        do {
            cout << "Enter start date (DD MM YYYY): ";
            cin >> start_day >> start_month >> start_year;
        }while(!validate_date(start_day, start_month, start_year));

        do {
            cout << "Enter end date (DD MM YYYY): ";
            cin >> end_day >> end_month >> end_year;
        }while(!validate_date(end_day, end_month, end_year));
        orderController.create_reservation(Date(start_day, start_month, start_year),
                                           Date(start_day, start_month, start_year),
                                           Date(end_day, end_month, end_year),
                                           car_id, employee_id, customer_id);

    } else if (opt == 2) {
    }
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
    while (!validate_date(end_day, end_month, end_year));

    vector<Order> orders = orderController.get_orders_between_dates(
            Date(start_day, start_month, start_year),
            Date(end_day, end_month, end_year));
    if (orders.empty()) {
        cout << "No orders found between the specified dates.\n";
    } else {
        cout << "List of orders between " << start_day << "/" << start_month << "/" << start_year << " and " << end_day << "/" << end_month << "/" << end_year << ":\n";
        for(auto o : orders){
            cout << o.get_id() << ' ' << o.getStat() << ' ' << o.getTotalPrice() << '\n';
        }
    }
}

void UI_employee::search_order_by_id() {
    int order_id;
    cout << "Enter order ID: ";
    cin >> order_id;

    Order o = orderController.get_by_id(order_id);
    cout << o.get_id() << ' ' << o.getTotalPrice() << ' ' << o.getStat() << '\n';
}

void UI_employee::anonymise_GDPR() {
    int id;
    cout << "Enter customer id to anonymise: ";
    cin >> id;

    if(customerController.update_customer(id, false)){
        cout << "Great Success!";
    }
    else{
        cout << "Invalid";
    }
}

void UI_employee::show_all_customers_sorted_by_name() {
    for(auto customer : customerController.get_all_customers_sorted()){
        cout << customer.get_id() << ' '
            << customer.get_first_name() << ' '
            << customer.get_last_name() << '\n';
    }
}

void UI_employee::show_complete_order() {
    cout << "Enter id of Order that needs to be completed: ";
    int id;
    cin >> id;
    orderController.complete_order(id);

}

void UI_employee::show_take_order() {
    cout << "To be implemented";
}

void UI_employee::show_give_order() {
    cout << "To be implemented";
}


