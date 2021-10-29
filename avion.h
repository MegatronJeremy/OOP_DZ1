#ifndef OOP_DZ1_AVION_H
#define OOP_DZ1_AVION_H

#include "pilot.h"

class Avion {
public:
    Avion(string n, int c) : name(n), cap(c) {}
    Avion(Avion &a) = delete;

    string getName() const { return name; }
    Pilot *getCapt() const { return captain; }
    Pilot *getCop() const { return copilot; }

    int getCap() const { return cap; }

    bool setCapt(Pilot &capt);
    void setCop(Pilot &cop) { copilot = &cop, cop.chStat(true); }

    void out() const;

private:
    string name;
    Pilot *captain = nullptr, *copilot = nullptr;
    int cap;
};


#endif //OOP_DZ1_AVION_H
