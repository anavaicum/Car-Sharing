#ifndef PROIECT_COLECTIV_IREPO_H
#define PROIECT_COLECTIV_IREPO_H

#include <vector>

/**
 * @brief Interface for a generic repository.
 * @tparam T The type of entities being managed.
 */
template <class T>
class IRepo{
public:
    virtual std::vector<T> get_all() = 0;
    virtual bool add(T t) = 0;
    virtual bool update(int id, const T& new_entity) = 0;
    virtual bool delete_by_id(int id) = 0;
    virtual T get_by_Id(int id) = 0;
};


#endif //PROIECT_COLECTIV_IREPO_H
