//
// Created by Cosmin on 5/16/2024.
//

#ifndef PROIECT_COLECTIV_DATA_H
#define PROIECT_COLECTIV_DATA_H
#include <string>
#include <vector>

using namespace std;

class Date {
private:

    int day;
    int month;
    int year;

public:

    Date(int day, int month, int year);

    Date();

    Date(vector<string> birth);

    int getDay() const;

    int getMonth() const;

    int getYear() const;

    void setDay(int day);

    void setMonth(int month);

    void setYear(int year);

    bool operator<(const Date &rhs) const;

    bool operator>(const Date &rhs) const;

    bool operator<=(const Date &rhs) const;

    bool operator>=(const Date &rhs) const;


};


#endif //PROIECT_COLECTIV_DATA_H
