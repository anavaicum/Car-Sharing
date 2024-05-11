#include "Car.h"

Car::Car(const string &licensePlate, const string &model, const string &brand, int yearOfFirstReg, float mileage,
         float pricePerDay, const string &color, const vector<string> &remarks) : license_plate(licensePlate),
                                                                                  model(model), brand(brand),
                                                                                  year_of_first_reg(yearOfFirstReg),
                                                                                  mileage(mileage),
                                                                                  price_per_day(pricePerDay),
                                                                                  color(color), remarks(remarks) {}

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