// Car_Controller.cpp
#include "CarController.h"

// Constructor
Car_Controller::Car_Controller(const string& type, shared_ptr<IRepo<Car>> repo) : type(type), car_repo(repo) {
    this->car_repo = make_shared<Repo<Car>>("../../Repository/CarRepo.txt");
}

// Function to add a car to the controller
void Car_Controller::addCar(const Car& car) {
    this->car_repo->add(car);
}

// Function to search for a car by license plate
Car Car_Controller::search_by_license_plate(const string& license_plate) const {
    for (const auto& car : car_repo->get_all()) { //
        if (car.getLicensePlate() == license_plate) {
            return car;
        }
    }

    throw exception(); // if object not found
}

// Function to get ordered cars for a specific customer
vector<Car> Car_Controller::get_ordered_cars(const string& customer_id) const {
    // Dummy implementation, returning an empty vector
    return vector<Car>();
}

