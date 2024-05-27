

#include "../../Controller/User_Controller/UserController.h"
void UserController::login(const string& email, const string& password) {
    vector<User> users = repo.get_all();
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

bool UserController::change_password(const string& new_password) {
    // Assuming there's only one user logged in
    vector<User> users = repo.get_all();
    for (auto& user : users) {
        // Implement your authentication logic here, e.g., check session, token, etc.
        user.set_password(new_password);
        repo.update(user.get_id(), user);
        return true;
    }
    return false;
}

bool UserController::change_remarks(const vector<string>& remarks) {
    // Assuming there's only one user logged in
    vector<User> users = repo.get_all();
    for (auto& user : users) {
        // Implement your authentication logic here, e.g., check session, token, etc.
        for (const auto& remark : remarks) {
            user.add_remark(remark);
        }
        repo.update(user.get_id(), user);
        return true;
    }
    return false;
}