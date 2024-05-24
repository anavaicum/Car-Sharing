#ifndef PROIECT_COLECTIV_IREPO_H
#define PROIECT_COLECTIV_IREPO_H

#include <vector>

template <class T>
class IRepo{
public:
    virtual std::vector<T> get_all() = 0;
    virtual void add(T t) = 0;
    virtual void read_from_file() = 0;
    virtual void update() = 0;
    virtual void delete_by_id() = 0;

};


#endif //PROIECT_COLECTIV_IREPO_H
