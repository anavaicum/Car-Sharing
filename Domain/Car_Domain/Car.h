#ifndef PROIECT_COLECTIV_CAR_H
#define PROIECT_COLECTIV_CAR_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <unordered_map>
#include <iomanip>
#include "../Entity.h"
using namespace std;

class Car:public Entity {
public:

    enum fuel_type { Gas, Diesel, Electric, Petrol, Unknown };
    enum transmission { Automatic, Manual, UnknownTrans };

private:

    string license_plate;
    string model;
    string brand;
    int year_of_first_reg;
    float mileage;
    float price_per_day;
    fuel_type fuel;
    transmission trans;
    string color;
    vector <string> remarks;

    unordered_map<string, fuel_type> stringToFuelType = {
            {"Gas", Gas},
            {"Diesel", Diesel},
            {"Electric", Electric},
            {"Petrol", Petrol}
    };

    unordered_map<string, transmission> stringToTransmission = {
            {"Automatic", Automatic},
            {"Manual", Manual}
    };

    fuel_type stringToFuelTypeEnum(string fuelStr);

    transmission stringToTransmissionEnum(string transStr);

public:

    Car(int _id, string licensePlate, string model, string brand, int yearOfFirstReg, float mileage,
        float pricePerDay, fuel_type fuel, transmission trans, string color, const vector<string> &remarks);

    Car();

    const string &getLicensePlate() const;

    void setLicensePlate(const string &licensePlate);

    const string &getModel() const;

    void setModel(const string &model);

    const string &getBrand() const;

    void setBrand(const string &brand);

    int getYearOfFirstReg() const;

    void setYearOfFirstReg(int yearOfFirstReg);

    float getMileage() const;

    void setMileage(float mileage);

    float getPricePerDay() const;

    void setPricePerDay(float pricePerDay);

    fuel_type getFuel() const;

    void setFuel(fuel_type fuel);

    transmission getTrans() const;

    void setTrans(transmission trans);

    const string &getColor() const;

    void setColor(const string &color);

    const vector<string> &getRemarks() const;

    void setRemarks(const vector<string> &remarks);

    static string fuelTypeToString(fuel_type f);

    static string transmissionToString(transmission t);

    static string vectorToString(const vector<string>& vec);

    string to_CSV() const;

    Car From_String_To_Object(const string &string_of_obj, char delim = ',');

};


#endif //PROIECT_COLECTIV_CAR_H
