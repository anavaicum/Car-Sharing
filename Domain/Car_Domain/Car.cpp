#include "Car.h"

#include <utility>
#include <unordered_map>
#include <string.h>

Car::Car(int _id,string licensePlate, string model, string brand, int yearOfFirstReg, float mileage,
         float pricePerDay, fuel_type fuel, transmission trans, string color, const vector<string> &remarks) : Entity(_id),
                                                                                                               license_plate(std::move(licensePlate)),
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

string Car::to_CSV() {
    //"ID, license plate,model,brand,year of first registration,mileage,price per day,fuel type,transmission,color,remarks\n";
    stringstream ss;
    ss << get_id() << ","
       << license_plate << ","
       << model << ","
       << brand << ","
       << year_of_first_reg << ","
       << fixed << setprecision(2) << mileage << ","
       << fixed << setprecision(2) << price_per_day << ","
       << fuelTypeToString(fuel) << ","
       << transmissionToString(trans) << ","
       << color << ","
       << vectorToString(remarks) << "\n";
    return ss.str();
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
        default: return "UnknownTrans";
    }
}

string Car::vectorToString(const vector<string> &vec) {
    stringstream ss;
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i != vec.size() - 1) {
            ss << ";"; // Use semicolon and space as separator for readability for vector
        }
    }
    return ss.str();
}

Car Car::From_String_To_Object(const string &string_of_obj, char delim) {
    stringstream ss(string_of_obj);
    string idstring, license, mod, br, year_of_rg, ml, ppd, fu, tra, col, rm;
    vector<string> rm_vec;
    int id;
    int year;
    float mil, price;
    getline(ss,idstring,delim);
    getline(ss, license, delim);
    getline(ss, mod, delim);
    getline(ss, br, delim);
    getline(ss, year_of_rg, delim);
    getline(ss, ml, delim);
    getline(ss, ppd, delim);
    getline(ss, fu, delim);
    getline(ss, tra, delim);
    getline(ss, col, delim);
    getline(ss, rm, delim);

    id=stoi(idstring);
    year = stoi(year_of_rg);
    mil = stof(ml);
    price = stof(ppd);


    stringstream remarksStream(rm);
    string remark;
    while(getline(remarksStream, remark, ';'))
    {
        rm_vec.push_back(remark);
    }
    fuel_type ft = stringToFuelTypeEnum(fu);
    transmission tr = stringToTransmissionEnum(tra);
    if(rm_vec.size() == 1 && rm_vec[0] == "\n"){
        rm_vec.pop_back();
    }
    Car obj(id,license, mod, br, year, mil, price,
            ft, tr, col, rm_vec);
    return obj;
}



Car::fuel_type Car::stringToFuelTypeEnum(string fuelStr) {
    auto it = stringToFuelType.find(fuelStr);
    if (it != stringToFuelType.end()) {
        return it->second;
    }
    return Unknown;
}

Car::transmission Car::stringToTransmissionEnum(string transStr) {
    auto it = stringToTransmission.find(transStr);
    if (it != stringToTransmission.end()) {
        return it->second;
    }
    return UnknownTrans;
}

Car::Car() {

}
