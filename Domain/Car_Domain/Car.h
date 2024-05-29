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

/**
 * @brief Represents a Car entity.
 */
class Car:public Entity {
public:

    /**
     * @brief Enum representing the types of fuel a car can use.
     */
    enum fuel_type { Gas, Diesel, Electric, Petrol, Unknown };

    /**
     * @brief Enum representing the types of transmission a car can have.
     */
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

    /**
     * @brief Converts a string to a fuel_type enum.
     * @param fuelStr The string representing the fuel type.
     * @return The corresponding fuel_type enum.
     */
    fuel_type stringToFuelTypeEnum(string fuelStr);


    /**
     * @brief Converts a string to a transmission enum.
     * @param transStr The string representing the transmission type.
     * @return The corresponding transmission enum.
     */
    transmission stringToTransmissionEnum(string transStr);

public:

    /**
      * @brief Car constructor.
      */
    Car(int _id, string licensePlate, string model, string brand, int yearOfFirstReg, float mileage,
        float pricePerDay, fuel_type fuel, transmission trans, string color, const vector<string> &remarks);

    /**
      * @brief Car constructor.
      */
    Car(int _id, string licensePlate, string model, string brand, int yearOfFirstReg, float mileage,
        float pricePerDay, string fuel, string trans, string color, const vector<string> &remarks);

    /**
      * @brief Car constructor.
      */
    Car(int id, string lic_plate, string mod, string br, int year, float mil, float ppd, string f_type, string tr, string col);

    /**
      * @brief Default constructor.
      */
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

    void setRemarks(const string remark);

    /**
     * @brief Converts fuel type to string.
     *
     * @param f Fuel type.
     * @return Fuel type string.
     */
    static string fuelTypeToString(fuel_type f);

    /**
     * @brief Converts transmission type to string.
     *
     * @param t Transmission type.
     * @return Transmission type string.
     */
    static string transmissionToString(transmission t);

    /**
     * @brief Converts the Car object to a CSV string.
     *
     * @return CSV representation of the car.
     */
    static string vectorToString(const vector<string>& vec);

    /**
     * @brief Converts the Car object to a CSV string.
     *
     * @return CSV representation of the car.
     */
    string to_CSV() const;

    /**
     * @brief Creates a Car object from a string.
     *
     * @param string_of_obj String representation of the car.
     * @param delim Delimiter used in the string.
     * @return Car object.
     */
    Car From_String_To_Object(const string &string_of_obj, char delim = ',');

};


#endif //PROIECT_COLECTIV_CAR_H
