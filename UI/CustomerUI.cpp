#include "CustomerUI.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

CustomerUI::CustomerUI() {}

void CustomerUI::show_cars(const vector<Car> &cars) {
    cout << "List of Cars:\n";
    for (const auto &car : cars) {
        cout << "License Plate: " << car.getLicensePlate() << ", Model: " << car.getModel() << ", Brand: " << car.getBrand() << endl;
    }
}

void CustomerUI::show_cars_between_dates(const vector<Car> &cars, int startYear, int endYear) {
    cout << "Cars between " << startYear << " and " << endYear << ":\n";
    for (const auto &car : cars) {
        if (car.getYearOfFirstReg() >= startYear && car.getYearOfFirstReg() <= endYear) {
            cout << "License Plate: " << car.getLicensePlate() << ", Model: " << car.getModel() << ", Brand: " << car.getBrand() << endl;
        }
    }
}

void CustomerUI::search_car_by_license_plate(const vector<Car> &cars, const string &licensePlate) {
    auto it = find_if(cars.begin(), cars.end(), [&](const Car &car) {
        return car.getLicensePlate() == licensePlate;
    });
    if (it != cars.end()) {
        cout << "Car found with license plate " << licensePlate << ":\n";
        cout << "Model: " << it->getModel() << ", Brand: " << it->getBrand() << endl;
    } else {
        cout << "Car with license plate " << licensePlate << " not found.\n";
    }
}

void CustomerUI::show_ordered_cars_sorted(const vector<Car> &cars) {
    vector<Car> sortedCars = cars;
    sort(sortedCars.begin(), sortedCars.end(), [](const Car &car1, const Car &car2) {
        return car1.getPricePerDay() < car2.getPricePerDay();
    });
    cout << "Ordered Cars by Price:\n";
    for (const auto &car : sortedCars) {
        cout << "License Plate: " << car.getLicensePlate() << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
    }
}

void CustomerUI::show_delete_reservation() {
}

void CustomerUI::show_make_reservation() {
}

void CustomerUI::show_update_reservation() {
}

void CustomerUI::show_all_orders_sorted_by_price(const vector<Car> &cars) {
    vector<Car> sortedCars = cars;
    sort(sortedCars.begin(), sortedCars.end(), [](const Car &car1, const Car &car2) {
        return car1.getPricePerDay() < car2.getPricePerDay();
    });
    cout << "All Orders Sorted by Price:\n";
    for (const auto &car : sortedCars) {
        cout << "License Plate: " << car.getLicensePlate() << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
    }
}

void CustomerUI::show_search_by_order_id() {
}

void CustomerUI::show_change_password() {
}

void CustomerUI::show_change_remarks() {
}

void CustomerUI::show_add_car_to_favorites() {
}

void CustomerUI::show_delete_car_from_favorites() {
}

void CustomerUI::show_favorites() {
}


void CustomerUI::show_customer_menu() {
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
                        show_favorites();
                    case 5:
                        show_add_car_to_favorites();
                    case 6:
                        show_delete_car_from_favorites();
                }
            case 3:
                show_change_password();
            case 4:
                show_change_remarks();

        }
    } while (choice != 0);
}
