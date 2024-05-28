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

}
