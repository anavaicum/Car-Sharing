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
    /**
     * Connection to the car Repo
     */
    shared_ptr<IRepo<Car>> car_repo;
    string type; // Field to store type of controller
    /**
     * @return the next available ID
     */
    int find_next_id();

public:
    /**
     * Initialises the Repo with a file path
     */
    Car_Controller();
    /**
     * @param license_plate unique Identifier for the Car class
     * @return Car with specified license plate
     */
    Car search_by_license_plate(const std::string &license_plate) const;

    /**
     * Creates a car object with the following params
     * @param lic_plate
     * @param mod
     * @param br
     * @param f_type
     * @param trans
     * @param col
     * @param year
     * @param mil
     * @param ppd
     * @return true, if object was created, false if error occurred
     */
    bool create_car(string lic_plate, string mod
                    , string br, string f_type, string trans,
                    string col, int year, float mil, float ppd);

    bool update_car(string lic_plate, string mod
            , string br, string f_type, string trans,
                    string col, int year, float mil, float ppd);

    bool delete_car(int id);

    Car get_by_id(int carId);

    /**
     * @return vector of all cars and are ordered by price_per_day
     */
    std::vector<Car> get_ordered_cars() const;

    std::vector<Car> get_cars_between_dates(int startYear, int endYear) const;

    void load_cars();
};

#endif // CAR_CONTROLLER_H

