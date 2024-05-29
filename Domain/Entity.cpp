//
// Created by Cosmin on 5/21/2024.
//

#include "Entity.h"

Entity::Entity(int _id): id(_id){};

int Entity::get_id() const { return id; }
void Entity::set_id(int _id) { id = _id; }

Entity::Entity() {

}
void set_password(const string& new_password) {
    this->password = new_password;
}

const string& get_first_name() const {
    return first_name;
}

const string& get_last_name() const {
    return last_name;
}