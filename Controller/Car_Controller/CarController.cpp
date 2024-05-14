// Car_Controller.cpp
#include "CarController.h"

// Constructor
Car_Controller::Car_Controller(const string& type) : type(type) {}

// Function to add a car to the controller
void Car_Controller::addCar(const Car& car) {
    cars.insert({car.getLicensePlate(), car});
}

// Function to search for a car by license plate
Car Car_Controller::search_by_license_plate(const string& license_plate) const {
    auto it = cars.find(license_plate);
    if (it != cars.end()) {
        return it->second;
    } else {
        // Return a default-constructed Car if not found
        return Car("", "", "", 0, 0.0, 0.0, "", {});
    }
}

// Function to get ordered cars for a specific customer
vector<Car> Car_Controller::get_ordered_cars(const string& customer_id) const {
    // Dummy implementation, returning an empty vector
    return vector<Car>();
}

