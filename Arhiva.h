//
// Created by xparh on 10/29/2021.
//

#ifndef OOP_DZ1_ARHIVA_H
#define OOP_DZ1_ARHIVA_H

#include "Let.h"

struct NodeL {
    Let *let;
    NodeL *next;

    NodeL(Let &l, NodeL *p = nullptr) : let(&l), next(p) {}
};

class Arhiva {
public:
    Arhiva() = default;
    Arhiva(Arhiva &a);
    Arhiva(Arhiva &&a);
    ~Arhiva();

    void addL(Let &l);

    NodeL *getStartFl(string s);
    NodeL *getDestFl(string d);
    NodeL *getStartAndDestFl(string s, string d);

    void out() const;

private:
    NodeL *flights = nullptr;
};


#endif //OOP_DZ1_ARHIVA_H
