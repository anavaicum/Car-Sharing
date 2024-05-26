#ifndef CAR_CONTROLLER_H
#define CAR_CONTROLLER_H

#include "../../Repository/IRepo.h"
#include "../../Domain/Car_Domain/Car.h"
#include <vector>
#include <string>
#include <memory>

class Car_Controller {
private:
    std::shared_ptr<IRepo<Car>> carRepo;

public:
    Car_Controller(const std::shared_ptr<IRepo<Car>> &repo);

    Car search_by_license_plate(const std::string &license_plate) const;

    std::vector<Car> get_ordered_cars(int customer_id) const;

    void load_cars();
};

#endif // CAR_CONTROLLER_H

