#ifndef OOP_DZ1_FLOTAAVIONA_H
#define OOP_DZ1_FLOTAAVIONA_H

#include "avion.h"

struct NodeA {
    Avion *avion;
    NodeA *next;

    NodeA(Avion &a, NodeA *p = nullptr) : avion(&a), next(p) {}
};

class FlotaAviona {
public:
    FlotaAviona(string n) : name(n) {};
    FlotaAviona(FlotaAviona &f);
    FlotaAviona(FlotaAviona &&f);
    ~FlotaAviona();

    void addPlane(Avion &a);

    int getSize() const;
    int getMaxCap() const;
    Avion *getMaxPl() const;
    void remove(string n);
    NodeA *getRange(int minC, int maxC) const;

    void out() const;

private:
    string name;
    NodeA *fleet = nullptr;
};


#endif //OOP_DZ1_FLOTAAVIONA_H
