//
// Created by Cosmin on 5/21/2024.
//

#include "Entity.h"

Entity::Entity(int _id): id(_id){};

int Entity::get_id() const { return id; }
void Entity::set_id(int _id) { id = _id; }

Entity::Entity() {

}
