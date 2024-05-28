//
// Created by Cosmin on 5/14/2024.
//

#include <algorithm>
#include "Customer.h"

Customer::Customer(int id, const string &email, const string &password, const string &firstName, const string &lastName,
                   const string &phone, const string &address, bool gdpRdeleted, const vector<Car>& favorites) : User(id, email, password, firstName,
                                                                                                                      lastName), phone(phone),
                                                                                                                 address(address),
                                                                                                                 GDPRdeleted(gdpRdeleted), favorites(favorites) {}

const string& Customer::get_phone() const { return phone; }
void Customer::set_phone(const string& _phone) { phone = _phone; }

const string& Customer::get_address() const { return address; }
void Customer::set_address(const string& _address) { address = _address; }

bool Customer::is_GDPRdeleted() const { return GDPRdeleted; }
void Customer::set_GDPRdeleted(bool _GDPRdeleted) { GDPRdeleted = _GDPRdeleted; }

const vector<Car>& Customer::get_favorites() const { return favorites; }
void Customer::add_favorite(const Car& favorite) { favorites.push_back(favorite); }

string Customer::to_CSV() const{



//    bool file_exists = filesystem::exists(filename);
//    if(!file_exists) {
//        file << "ID,email,password,first name,last name,phone,address,GDPR deleted,favorites,remarks\n";
//    }
//    "ID,email,password,first name,last name,phone,address,GDPR deleted,favorites\n";

    stringstream ss;

    ss << get_id() << ","
       << get_email() << ","
       << get_password() << ","
       << get_first_name() << ","
       << get_last_name() << ","
       << phone << ","
       << address << ","
       << GDPRdeleted << ","
       << Customer::favoritesToString() << "\n";
    return ss.str();
}

string Customer::favoritesToString() const {
    std::stringstream ss;
    for (size_t i = 0; i < favorites.size(); ++i) {
        //ss << "{";
        ss << favorites[i].getLicensePlate() << "/"
           << favorites[i].getModel() << "/"
           << favorites[i].getBrand() << "/"
           << favorites[i].getYearOfFirstReg() << "/"
           << favorites[i].getMileage() << "/"
           << favorites[i].getPricePerDay() << "/"
           << favorites[i].fuelTypeToString(favorites[i].getFuel()) << "/"
           << favorites[i].transmissionToString(favorites[i].getTrans()) << "/"
           << favorites[i].getColor() << "/"
           << favorites[i].vectorToString(favorites[i].getRemarks());
        //ss << "}";
        if (i != favorites.size() - 1) {
            ss << " | "; // Use vertical bar as separator for readability
        }
    }
    return ss.str();
}

Customer Customer::From_String_To_Object(const string &string_of_obj, char delim) {


    stringstream ss(string_of_obj);
    string id_string, mail, pass, f_name, l_name, phone_num, addr, gdpr, vec_faves;
    int id_num;
    bool gdpr_bool;
    vector<Car> faves;

    Car c(1,"SB12OGV", "Sandero", "Dacia", 2017, 100000.5, 12,
          Car::Gas, Car::Manual, "Red", vector<string>());


    getline(ss, id_string,delim);
    getline(ss, mail,delim);
    getline(ss, pass,delim);
    getline(ss, f_name,delim);
    getline(ss, l_name,delim);
    getline(ss, phone_num,delim);
    getline(ss, addr,delim);
    getline(ss, gdpr,delim);
    getline(ss, vec_faves,delim);

    id_num = stoi(id_string);
    gdpr_bool = (gdpr == "1");

    stringstream CarStream(vec_faves);
    string line;
    while(getline(CarStream, line, '|')){
        if(line == "\n"){
            break;
        }
        c = c.From_String_To_Object(line, '/');
        faves.push_back(c);
    }
    Customer cus(id_num, mail, pass, f_name, l_name, phone_num,
                 addr, gdpr_bool, faves);
    return cus;
}

Customer::Customer() {

}

string Customer::Customer_To_String() const {
    stringstream ss;
    ss << get_id() << "!"
       << get_email() << "!"
       << get_password() << "!"
       << get_first_name() << "!"
       << get_last_name() << "!"
       << phone << "!"
       << address << "!"
       << GDPRdeleted << "!"
       << Customer::favoritesToString();
    return ss.str();
}

void Customer::remove_favorite(int id) {
    auto new_end = std::remove_if(favorites.begin(), favorites.end(), [&id](Car car){
        return car.get_id()==id;
    });
    favorites.erase(new_end, favorites.end());
}
