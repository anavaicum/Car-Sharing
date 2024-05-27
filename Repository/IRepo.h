#ifndef PROIECT_COLECTIV_IREPO_H
#define PROIECT_COLECTIV_IREPO_H

#include <vector>

template <class T>
class IRepo{
public:
    virtual std::vector<T> get_all() = 0;
    virtual void add(T t) = 0;
    virtual void update(int id, const T& new_entity) = 0;
    virtual void delete_by_id(int id) = 0;
    virtual T get_by_Id(int id) = 0;
};


#endif //PROIECT_COLECTIV_IREPO_H
