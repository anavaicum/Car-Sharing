#ifndef PROIECT_COLECTIV_CAR_H
#define PROIECT_COLECTIV_CAR_H
#include <string>
#include <vector>
using namespace std;

class Car {
private:

    string license_plate;
    string model;
    string brand;
    int year_of_first_reg;
    float mileage;
    float price_per_day;
    enum fuel_type { Gas, Diesel, Electric, Petrol };
    enum transmission { Automatic, Manual };
    string color;
    vector <string> remarks;

public:

    Car(const string &licensePlate, const string &model, const string &brand, int yearOfFirstReg, float mileage,
        float pricePerDay, const string &color, const vector<string> &remarks);

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

    const string &getColor() const;

    void setColor(const string &color);

    const vector<string> &getRemarks() const;

    void setRemarks(const vector<string> &remarks);

};


#endif //PROIECT_COLECTIV_CAR_H
