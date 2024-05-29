#ifndef CAR_CONTROLLER_H
#define CAR_CONTROLLER_H

#include "../../Repository/IRepo.h"
#include "../../Domain/Car_Domain/Car.h"
#include "../../Repository/Repo.h"
#include <vector>
#include <string>
#include <memory>

class Car_Controller {
private:
    //std::shared_ptr<IRepo<Car>> carRepo;
    shared_ptr<IRepo<Car>> car_repo;
    string type; // Field to store type of controller

public:
    Car_Controller();

    Car search_by_license_plate(const std::string &license_plate) const;

    Car get_by_id(int carId);

    std::vector<Car> get_ordered_cars() const;

    std::vector<Car> get_cars_between_dates(int startYear, int endYear) const;

    void load_cars();
};

#endif // CAR_CONTROLLER_H

