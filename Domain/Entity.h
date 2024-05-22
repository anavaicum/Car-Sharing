//
// Created by Cosmin on 5/21/2024.
//

#ifndef PROIECT_COLECTIV_ENTITY_H
#define PROIECT_COLECTIV_ENTITY_H


class Entity {
private:
    Entity(int _id);

    int id;
public:
    const int get_id() const;
    void set_id(int _id);
};


#endif //PROIECT_COLECTIV_ENTITY_H
