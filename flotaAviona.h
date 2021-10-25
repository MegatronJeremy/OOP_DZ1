#ifndef OOP_DZ1_FLOTAAVIONA_H
#define OOP_DZ1_FLOTAAVIONA_H

#include "avion.h"

class FlotaAviona {
public:
    FlotaAviona(string n) : name(n) {};
    FlotaAviona(FlotaAviona &f);
    FlotaAviona(FlotaAviona &&f);
    ~FlotaAviona();

    void addPlane(Avion &a);

    int getNOP() const { return fleetSize; }
    int getMaxPas() const { return maxPas; }
    Avion *getMaxPl() const { return maxPl; }

    void out() const;

private:
    struct Node {
        Avion *avion;
        Node *next;

        Node(Avion &a, Node *p = nullptr) { avion = &a, next = p; }
    };

    string name;
    int fleetSize = 0;
    int maxPas = 0;
    Avion *maxPl = nullptr;
    Node *fleet = nullptr;
};


#endif //OOP_DZ1_FLOTAAVIONA_H
