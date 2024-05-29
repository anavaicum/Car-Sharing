#include "CustomerUI.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

CustomerUI::CustomerUI() {
    this->customercontroller=CustomerController();
    this->carcontroller=Car_Controller();
}

void CustomerUI::show_cars() {
    cout << "List of Cars:\n";
    std::vector<Car> cars = carcontroller.get_ordered_cars();
    for (const auto& car : cars) {
        cout << "License Plate: " << car.getLicensePlate()
             << ", Model: " << car.getModel()
             << ", Brand: " << car.getBrand()
             << ", Year: " << car.getYearOfFirstReg()
             << ", Mileage: " << car.getMileage()
             << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
    }
}

void CustomerUI::show_cars_between_dates() {
    int startYear, endYear;
    cout<< "Give start year for search : \n";
    cin>>startYear;
    cout<< "\nGive end year for search";
    cin>>endYear;
    cout << "Cars between " << startYear << " and " << endYear << ":\n";
    std::vector<Car> cars = carcontroller.get_cars_between_dates(startYear,endYear);
    for (const auto& car : cars) {
        if (car.getYearOfFirstReg() >= startYear && car.getYearOfFirstReg() <= endYear) {
            cout << "License Plate: " << car.getLicensePlate()
                 << ", Model: " << car.getModel()
                 << ", Brand: " << car.getBrand()
                 << ", Year: " << car.getYearOfFirstReg()
                 << ", Mileage: " << car.getMileage()
                 << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
        }
    }
}

void CustomerUI::search_car_by_license_plate() {
    std::string licensePlate;
    cout<<"Enter license plate \n";
    cin>>licensePlate;
    try {
    Car car = carcontroller.search_by_license_plate(licensePlate);
        cout << "Car found with license plate " << licensePlate << ":\n";
        cout << "Model: " << car.getModel()
             << ", Brand: " << car.getBrand()
             << ", Year: " << car.getYearOfFirstReg()
             << ", Mileage: " << car.getMileage()
             << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
    } catch (exception &e) {
        cout << "Car with license plate " << licensePlate << " not found.\n";
    }
}

void CustomerUI::show_ordered_cars_sorted() {
    cout << "List of Cars:\n";
    std::vector<Car> cars = carcontroller.get_ordered_cars();
    for (const auto& car : cars) {
        cout << "License Plate: " << car.getLicensePlate()
             << ", Model: " << car.getModel()
             << ", Brand: " << car.getBrand()
             << ", Year: " << car.getYearOfFirstReg()
             << ", Mileage: " << car.getMileage()
             << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
    }
}

void CustomerUI::show_delete_reservation() {
    int reservationID;
    cout << "Enter Reservation ID to delete: ";
    cin >> reservationID;

    bool status = orderController.delete_reservation(reservationID);

    if (status) {
        cout << "Reservation with ID " << reservationID << " has been deleted.\n";
    } else {
        cout << "Reservation with ID " << reservationID << " not found.\n";
    }
}

void CustomerUI::show_make_reservation() {
    int customerId, orderId;
    cout<<"Please insert customerId";
    cin>>customerId;
    cout<<"Please insert orderId";
    cin>>orderId;
    bool status = orderController.make_reservation(orderId,customerId);

    if(status)
        cout << "Reservation created successfully.\n";
    else
        cout<<"Reservation not created.\n";
}

void CustomerUI::show_all_orders_sorted_by_price() {
    cout<<"List of orders";
    std::vector<Order> sortedOrders = orderController.get_orders_sorted_by_price();
    cout << "All Orders Sorted by Price:\n";
    for (const auto& order : sortedOrders) {
        cout << "Order ID: " << order.get_id()
             << ", Total Price: " << fixed << setprecision(2) << order.getTotalPrice() << endl;
    }
}

void CustomerUI::show_search_by_order_id() {
    int orderID;
    cout << "Enter Order ID to search: ";
    cin >> orderID;

    try{
    Order order = orderController.get_by_id(orderID);
        cout << "Order found with ID " << orderID << ":\n";
        cout << "Order Date: " << order.getOrderDate().getDay() << "/" << order.getOrderDate().getMonth() << "/" << order.getOrderDate().getYear()
             << ", Status: " << Order::statusToString(order.getStat())
             << ", Begin Date: " << order.getBeginDate().getDay() << "/" << order.getBeginDate().getMonth() << "/" << order.getBeginDate().getYear()
             << ", End Date: " << order.getEndDate().getDay() << "/" << order.getEndDate().getMonth() << "/" << order.getEndDate().getYear()
             << ", Total Price: " << fixed << setprecision(2) << order.getTotalPrice() << endl;
    } catch(exception &e) {
        cout << "Order with ID " << orderID << " not found.\n";
    }
}

void CustomerUI::show_change_password(int id) {
    std::string newPass;
    cout<<"Enter new password";
    cin>>newPass;
    Customer customer = customercontroller.get_by_id(id);
    customer.set_password(newPass);
    cout << "Password updated successfully.\n";
}

void CustomerUI::show_change_remarks() {
    std::string newRemarks;
    int carId;
    cout<<"Enter new remarks";
    getline(cin,newRemarks);
    cout<<"Enter car id";
    cin>>carId;
    Car car = carcontroller.get_by_id(carId);
    car.setRemarks(newRemarks);
    cout << "Remarks updated successfully.\n";
}

void CustomerUI::show_add_car_to_favorites(int customerId) {
    Customer customer = customercontroller.get_by_id(customerId);
    int carId;
    cout<<"Give the car id to favourite";
    cin>>carId;
    Car car = carcontroller.get_by_id(carId);
    customer.add_favorite(car);
    cout << "Car added to favorites successfully.\n";
}

void CustomerUI::show_delete_car_from_favorites(int customerId) {
    Customer customer = customercontroller.get_by_id(customerId);
    int carId;
    cout<<"Give the car id to remove from favourite";
    cin>>carId;
    customer.remove_favorite(carId);
}

void CustomerUI::show_favorites(int customerId) {
    Customer customer = customercontroller.get_by_id(customerId);
    const auto& favorites = customer.get_favorites();
    cout << "Favorite Cars:\n";
    for (const auto& car : favorites) {
        cout << "License Plate: " << car.getLicensePlate()
             << ", Model: " << car.getModel()
             << ", Brand: " << car.getBrand()
             << ", Year: " << car.getYearOfFirstReg()
             << ", Mileage: " << car.getMileage()
             << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
    }
}


void CustomerUI::show_customer_menu(int id) {
    int customerId = id;
    int choice;
    int choice2;
    do {
        cout << "1. Reservations and Orders" << endl;
        cout << "2. Cars" << endl;
        cout << "3. Change password" << endl;
        cout << "4. Change remarks" << endl;
        cout << "Enter your choice: " << endl;

        cin >> choice;

        switch (choice){
            case 1:
                cout << "1. Make a reservation" << endl;
                cout << "2. Cancel a reservation" << endl;
                cout << "3. Update a reservation" << endl;
                cout << "4. All ordered cars sorted by price" << endl;
                cout << "5. Search order by id" << endl;
                cout << "Enter your choice: " << endl;
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        show_make_reservation();
                    case 2:
                        show_delete_reservation();
                    case 3:
                        show_update_reservation();
                    case 4:
                        show_all_orders_sorted_by_price();
                    case 5:
                        show_search_by_order_id();
                }
            case 2:
                cout << "1. See cars" << endl;
                cout << "2. See cars between two dates" << endl;
                cout << "3. Search car by license plate" << endl;
                cout << "4. See favorite cars" << endl;
                cout << "5. Add car to favorites" << endl;
                cout << "6. Delete car from favorites" << endl;
                cout << "Enter your choice: " << endl;
                cin >> choice2;
                switch (choice2) {
                    case 1:
                        show_cars();
                    case 2:
                        show_cars_between_dates();
                    case 3:
                        search_car_by_license_plate();
                    case 4:
                        show_favorites(customerId);
                    case 5:
                        show_add_car_to_favorites(customerId);
                    case 6:
                        show_delete_car_from_favorites(customerId);
                }
            case 3:
                show_change_password(customerId);
            case 4:
                show_change_remarks();

        }
    } while (choice != 0);
}