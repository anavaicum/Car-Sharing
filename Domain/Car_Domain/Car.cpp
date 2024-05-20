#include "Car.h"

#include <utility>

Car::Car(string licensePlate, string model, string brand, int yearOfFirstReg, float mileage,
         float pricePerDay, fuel_type fuel, transmission trans, string color, const vector<string> &remarks) : license_plate(std::move(licensePlate)),
                                                                                                               model(std::move(model)), brand(std::move(brand)),
                                                                                                               year_of_first_reg(yearOfFirstReg),
                                                                                                               mileage(mileage),
                                                                                                               price_per_day(pricePerDay), fuel(fuel), trans(trans),
                                                                                                               color(std::move(color)), remarks(remarks) {}

const string &Car::getLicensePlate() const {
    return license_plate;
}

void Car::setLicensePlate(const string &licensePlate) {
    license_plate = licensePlate;
}

const string &Car::getModel() const {
    return model;
}

void Car::setModel(const string &Model) {
    Car::model = Model;
}

const string &Car::getBrand() const {
    return brand;
}

void Car::setBrand(const string &Brand) {
    Car::brand = Brand;
}

int Car::getYearOfFirstReg() const {
    return year_of_first_reg;
}

void Car::setYearOfFirstReg(int yearOfFirstReg) {
    year_of_first_reg = yearOfFirstReg;
}

float Car::getMileage() const {
    return mileage;
}

void Car::setMileage(float Mileage) {
    Car::mileage = Mileage;
}

float Car::getPricePerDay() const {
    return price_per_day;
}

void Car::setPricePerDay(float pricePerDay) {
    price_per_day = pricePerDay;
}

const string &Car::getColor() const {
    return color;
}

void Car::setColor(const string &Color) {
    Car::color = Color;
}

const vector<string> &Car::getRemarks() const {
    return remarks;
}

void Car::setRemarks(const vector<string> &Remarks) {
    Car::remarks = Remarks;
}

Car::fuel_type Car::getFuel() const {
    return fuel;
}

void Car::setFuel(Car::fuel_type Fuel) {
    Car::fuel = Fuel;
}

Car::transmission Car::getTrans() const {
    return trans;
}

void Car::setTrans(Car::transmission Trans) {
    Car::trans = Trans;
}

void Car::save_to_CSV(const vector<Car>& data, const string& filename) {
    ofstream file(filename);
    //file.open(filename, ios::app);

    if(!file.is_open()) {
        return;
    }

//    bool file_exists = filesystem::exists(filename);
//    if(!file_exists) {
//        file << "License plate,model,brand,year of first registration,mileage,price per day,fuel type,transmission,color,remarks\n";
//    }

    file << "License plate,model,brand,year of first registration,mileage,price per day,fuel type,transmission,color,remarks\n";

    for(const auto& obj : data) {
        file << obj.license_plate << ","
             << obj.model << ","
             << obj.brand << ","
             << obj.year_of_first_reg << ","
             << obj.mileage << ","
             << obj.price_per_day << ","
             << fuelTypeToString(obj.fuel) << ","
             << transmissionToString(obj.trans) << ","
             << obj.color << ","
             << vectorToString(obj.remarks) << "\n";
    }
    file.close();
}

string Car::fuelTypeToString(Car::fuel_type f) {
    switch (f) {
        case Gas: return "Gas";
        case Diesel: return "Diesel";
        case Electric: return "Electric";
        case Petrol: return "Petrol";
        default: return "Unknown";
    }
}

string Car::transmissionToString(Car::transmission t) {
    switch (t) {
        case Automatic: return "Automatic";
        case Manual: return "Manual";
        default: return "Unknown";
    }
}

string Car::vectorToString(const vector<string> &vec) {
    stringstream ss;
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i != vec.size() - 1) {
            ss << "; "; // Use semicolon and space as separator for readability for vector
        }
    }
    return ss.str();
}
