

#ifndef PROIECT_COLECTIV_USERCONTROLLER_H
#define PROIECT_COLECTIV_USERCONTROLLER_H


#include "../../Domain/User_Domain/User.h"
#include "../../Repository/IRepo.h"
template<class T>
class UserController {
protected:
    std::shared_ptr<IRepo<T>> repo;
public:

    void login(const string& email, const string& password){
        vector<T> users = repo->get_all();
        bool found = false;
        for (const auto& user : users) {
            if (user.get_email() == email && user.get_password() == password) {
                found = true;
                // Do something if login is successful
                break;
            }
        }
        if (!found) {
            // Handle unsuccessful login
        }
    }
    bool change_password(const string& new_password){
        // Assuming there's only one user logged in
        vector<T> users = repo->get_all();
        for (auto& user : users) {
            // Implement your authentication logic here, e.g., check session, token, etc.
            user.set_password(new_password);
            repo->update(user.get_id(), user);
            return true;
        }
        return false;
    }
    bool change_remarks(const vector<string>& remarks){
        vector<T> users = repo->get_all();
        for (auto& user : users) {
            // Implement your authentication logic here, e.g., check session, token, etc.
            for (const auto& remark : remarks) {
                user.add_remark(remark);
            }
            repo->update(user.get_id(), user);
            return true;
        }
        return false;
    }
};


#endif //PROIECT_COLECTIV_USERCONTROLLER_H
