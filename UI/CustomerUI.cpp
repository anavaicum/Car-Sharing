#include "CustomerUI.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

CustomerUI::CustomerUI() {
    this->customercontroller=CustomerController();
//    this->carcontroller=Car_Controller();
}

void CustomerUI::show_cars(const vector<Car>& cars) {
    cout << "List of Cars:\n";
    for (const auto& car : cars) {
        cout << "License Plate: " << car.getLicensePlate()
             << ", Model: " << car.getModel()
             << ", Brand: " << car.getBrand()
             << ", Year: " << car.getYearOfFirstReg()
             << ", Mileage: " << car.getMileage()
             << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
    }
}

void CustomerUI::show_cars_between_dates(const vector<Car>& cars, int startYear, int endYear) {
    cout << "Cars between " << startYear << " and " << endYear << ":\n";
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

void CustomerUI::search_car_by_license_plate(const vector<Car>& cars, const string& licensePlate) {
    auto it = find_if(cars.begin(), cars.end(), [&](const Car& car) {
        return car.getLicensePlate() == licensePlate;
    });
    if (it != cars.end()) {
        cout << "Car found with license plate " << licensePlate << ":\n";
        cout << "Model: " << it->getModel()
             << ", Brand: " << it->getBrand()
             << ", Year: " << it->getYearOfFirstReg()
             << ", Mileage: " << it->getMileage()
             << ", Price Per Day: " << fixed << setprecision(2) << it->getPricePerDay() << endl;
    } else {
        cout << "Car with license plate " << licensePlate << " not found.\n";
    }
}

void CustomerUI::show_ordered_cars_sorted(const vector<Car>& cars) {
    vector<Car> sortedCars = cars;
    sort(sortedCars.begin(), sortedCars.end(), [](const Car& car1, const Car& car2) {
        return car1.getPricePerDay() < car2.getPricePerDay();
    });
    cout << "Ordered Cars by Price:\n";
    for (const auto& car : sortedCars) {
        cout << "License Plate: " << car.getLicensePlate()
             << ", Price Per Day: " << fixed << setprecision(2) << car.getPricePerDay() << endl;
    }
}

void CustomerUI::show_delete_reservation() {
    int reservationID;
    cout << "Enter Reservation ID to delete: ";
    cin >> reservationID;

    auto it = find_if(orders.begin(), orders.end(), [&](const Order& order) {
        return order.get_id() == reservationID;
    });

    if (it != orders.end()) {
        orders.erase(it);
        cout << "Reservation with ID " << reservationID << " has been deleted.\n";
    } else {
        cout << "Reservation with ID " << reservationID << " not found.\n";
    }
}

void CustomerUI::show_make_reservation() {
    int customerId, carId, orderId;
    Date orderDate, beginDate, endDate;
    float totalPrice;

    cout << "Enter Customer ID: ";
    cin >> customerId;
    cout << "Enter Car ID: ";
    cin >> carId;
    cout << "Enter Order Date (day month year): ";
    cin >> orderDate;
    cout << "Enter Begin Date (day month year): ";
    cin >> beginDate;
    cout << "Enter End Date (day month year): ";
    cin >> endDate;
    cout << "Enter Total Price: ";
    cin >> totalPrice;

    Customer* customer = nullptr;
    for (auto& cust : customers) {
        if (cust.get_id() == customerId) {
            customer = &cust;
            break;
        }
    }

    if (customer == nullptr) {
        cout << "Customer not found.\n";
        return;
    }

    Car* car = nullptr;
    for (auto& c : car) {
        if (c.get_id() == carId) {
            car = &c;
            break;
        }
    }

    if (car == nullptr) {
        cout << "Car not found.\n";
        return;
    }

    Employee employee;
    Order order(orderId, orderDate, Order::Reserved, beginDate, endDate, totalPrice, {}, true, { *car }, employee, *customer);
    orders.push_back(order);

    cout << "Reservation created successfully.\n";
}

void CustomerUI::show_update_reservation() {
    int reservationID;
    cout << "Enter Reservation ID to update: ";
    cin >> reservationID;

    auto it = find_if(orders.begin(), orders.end(), [&](const Order& order) {
        return order.get_id() == reservationID;
    });

    if (it == orders.end()) {
        cout << "Reservation with ID " << reservationID << " not found.\n";
        return;
    }

    Order& order = *it;
    int choice;
    cout << "What would you like to update?\n"
         << "1. Order Date\n"
         << "2. Begin Date\n"
         << "3. End Date\n"
         << "4. Total Price\n"
         << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            Date newOrderDate;
            cout << "Enter new Order Date (day month year): ";
            cin >> newOrderDate;
            order.setOrderDate(newOrderDate);
            break;
        }
        case 2: {
            Date newBeginDate;
            cout << "Enter new Begin Date (day month year): ";
            cin >> newBeginDate;
            order.setBeginDate(newBeginDate);
            break;
        }
        case 3: {
            Date newEndDate;
            cout << "Enter new End Date (day month year): ";
            cin >> newEndDate;
            order.setEndDate(newEndDate);
            break;
        }
        case 4: {
            float newTotalPrice;
            cout << "Enter new Total Price: ";
            cin >> newTotalPrice;
            order.setTotalPrice(newTotalPrice);
            break;
        }
        default:
            cout << "Invalid choice.\n";
            return;
    }

    cout << "Reservation updated successfully.\n";
}


void CustomerUI::show_all_orders_sorted_by_price() {
    vector<Order> sortedOrders = orders;
    sort(sortedOrders.begin(), sortedOrders.end(), [](const Order& order1, const Order& order2) {
        return order1.getTotalPrice() < order2.getTotalPrice();
    });
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

    auto it = find_if(orders.begin(), orders.end(), [&](const Order& order) {
        return order.get_id() == orderID;
    });

    if (it != orders.end()) {
        cout << "Order found with ID " << orderID << ":\n";
        cout << "Order Date: " << it->getOrderDate().getDay() << "/" << it->getOrderDate().getMonth() << "/" << it->getOrderDate().getYear()
             << ", Status: " << Order::statusToString(it->getStat())
             << ", Begin Date: " << it->getBeginDate().getDay() << "/" << it->getBeginDate().getMonth() << "/" << it->getBeginDate().getYear()
             << ", End Date: " << it->getEndDate().getDay() << "/" << it->getEndDate().getMonth() << "/" << it->getEndDate().getYear()
             << ", Total Price: " << fixed << setprecision(2) << it->getTotalPrice() << endl;
    } else {
        cout << "Order with ID " << orderID << " not found.\n";
    }
}

void CustomerUI::show_change_password(Customer& customer, const std::string& newPassword) {
    customer.set_password(newPassword);
    cout << "Password updated successfully.\n";
}

void CustomerUI::show_change_remarks(Car& car, const std::vector<std::string>& newRemarks) {
    car.setRemarks(newRemarks);
    cout << "Remarks updated successfully.\n";
}

void CustomerUI::show_add_car_to_favorites(Customer& customer, const Car& car) {
    customer.add_favorite(car);
    cout << "Car added to favorites successfully.\n";
}

void CustomerUI::show_delete_car_from_favorites(Customer& customer, const Car& car) {
    auto& favorites = customer.get_favorites();
    auto it = find_if(favorites.begin(), favorites.end(), [&](const Car& favoriteCar) {
        return favoriteCar.get_id() == car.get_id();
    });

    if (it != favorites.end()) {
        favorites.erase(it);
        cout << "Car removed from favorites successfully.\n";
    } else {
        cout << "Car not found in favorites.\n";
    }
}

void CustomerUI::show_favorites(const Customer& customer) {
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
