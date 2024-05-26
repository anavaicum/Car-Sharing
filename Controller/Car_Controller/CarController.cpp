#include "../../Controller/Car_Controller/CarController.h"
#include <algorithm> // Include this header for std::sort

Car_Controller::Car_Controller(const std::shared_ptr<IRepo<Car>> &repo) : carRepo(repo) {
    load_cars();
}

Car Car_Controller::search_by_license_plate(const std::string &license_plate) const {
    std::vector<Car> cars = carRepo->get_all();
    for (const auto &car : cars) {
        if (car.getLicensePlate() == license_plate) {
            return car;
        }
    }
    throw std::runtime_error("Car not found");
}

std::vector<Car> Car_Controller::get_ordered_cars(int customer_id) const {
    std::vector<Car> cars = carRepo->get_all();
    std::sort(cars.begin(), cars.end(), [](const Car &a, const Car &b) {
        return a.getPricePerDay() < b.getPricePerDay();
    });
    return cars;
}


void Car_Controller::load_cars() {
    carRepo->read_from_file();
}

