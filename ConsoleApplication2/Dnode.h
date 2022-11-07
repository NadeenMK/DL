#include"studant.h"
template<typename any>
class Dnode {
private:
    any data;
    Dnode<any>* next;
    Dnode<any>* prev;
    template<typename any> friend class doublyList;
};
