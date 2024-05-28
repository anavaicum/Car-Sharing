#include "../../Controller/Car_Controller/CarController.h"
#include <algorithm> // Include this header for std::sort

// Constructor
Car_Controller::Car_Controller(const shared_ptr<IRepo<Car>> &repo) {
    this->car_repo = make_shared<Repo<Car>>("../../Repository/CarRepo.txt");
}

Car Car_Controller::search_by_license_plate(const std::string &license_plate) const {
    std::vector<Car> cars = car_repo->get_all();
    for (const auto &car : cars) {
        if (car.getLicensePlate() == license_plate) {
            return car;
        }
    }
    throw std::runtime_error("Car not found");
}

std::vector<Car> Car_Controller::get_ordered_cars(int customer_id) const {
    std::vector<Car> cars = car_repo->get_all();
    std::sort(cars.begin(), cars.end(), [](const Car &a, const Car &b) {
        return a.getPricePerDay() < b.getPricePerDay();
    });
    return cars;
}


void Car_Controller::load_cars() {
    car_repo->get_all();
}



