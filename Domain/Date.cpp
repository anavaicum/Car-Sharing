//
// Created by Cosmin on 5/16/2024.
//

#include "Date.h"
#include <string>
#include <vector>

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const {
    return this->day;
}

int Date::getMonth() const {
    return this->month;
}

int Date::getYear() const {
    return this->year;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

bool Date::operator<(const Date &rhs) const {
//    if (day < rhs.day)
//        return true;
//    if (rhs.day < day)
//        return false;
//    if (month < rhs.month)
//        return true;
//    if (rhs.month < month)
//        return false;
//    return year < rhs.year;

    if(year < rhs.year) {
        return true;
    }
    if(year == rhs.year && month < rhs.month) {
        return true;
    }
    if(year == rhs.year && month == rhs.month && day < rhs.day) {
        return true;
    }
    return false;

}

bool Date::operator>(const Date &rhs) const {
    return rhs < *this;
}

bool Date::operator<=(const Date &rhs) const {
    return !(rhs < *this);
}

bool Date::operator>=(const Date &rhs) const {
    return !(*this < rhs);
}

Date::Date() {

}

Date::Date(vector <string> birth) {
    day = stoi(birth[0]);
    month = stoi(birth[1]);
    year = stoi(birth[2]);
}

bool Date::operator==(const Date &rhs) const {
    if(day == rhs.day && month == rhs.month && year == rhs.year){
        return true;
    }
    return false;
}
