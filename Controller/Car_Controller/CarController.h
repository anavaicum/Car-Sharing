#ifndef PROIECT_COLECTIV_CARCONTROLLER_H
#define PROIECT_COLECTIV_CARCONTROLLER_H


#include "../../Domain/Car_Domain/Car.h"
#include "../../Repository/IRepo.h"
#include "../../Repository/Repo.h"
#include <vector>
#include <memory>
#include <map>

using namespace std;

class Car_Controller {
private:
    shared_ptr<IRepo<Car>> car_repo;
    string type; // Field to store type of controller

public:
    Car_Controller(const string& type, shared_ptr<IRepo<Car>> repo); // Constructor

    // Function to add a car to the controller
    void addCar(const Car& car);

    // Function to search for a car by license plate
    Car search_by_license_plate(const string& license_plate) const;

    // Function to get ordered cars for a specific customer
    vector<Car> get_ordered_cars(const string& customer_id) const;
};



#endif //PROIECT_COLECTIV_CARCONTROLLER_H
