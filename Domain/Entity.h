#ifndef PROIECT_COLECTIV_ENTITY_H
#define PROIECT_COLECTIV_ENTITY_H

/**
 * @brief Represents a generic entity with an ID.
 */
class Entity {
private:
    int id;
public:
    Entity(int _id);
    Entity();
    int get_id() const;
    void set_id(int _id);
};


#endif //PROIECT_COLECTIV_ENTITY_H
