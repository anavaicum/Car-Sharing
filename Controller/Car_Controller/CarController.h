#ifndef PROIECT_COLECTIV_CARCONTROLLER_H
#define PROIECT_COLECTIV_CARCONTROLLER_H


#include "../../Domain/Car_Domain/Car.h"
#include <vector>
#include <map>

using namespace std;

class Car_Controller {
private:
    map<string, Car> cars; // Map to store cars with license plate as key
    string type; // Field to store type of controller

public:
    Car_Controller(const string& type); // Constructor

    // Function to add a car to the controller
    void addCar(const Car& car);

    // Function to search for a car by license plate
    Car search_by_license_plate(const string& license_plate) const;

    // Function to get ordered cars for a specific customer
    vector<Car> get_ordered_cars(const string& customer_id) const;
};



#endif //PROIECT_COLECTIV_CARCONTROLLER_H
