#ifndef OOP_DZ1_AVION_H
#define OOP_DZ1_AVION_H

#include "pilot.h"

class Avion {
public:
    Avion(string n, int m) : name(n), max(m) {};
    Avion(Avion &a) = delete;

    string getName() const { return name; }
    Pilot &getCapt() const { return *captain; }
    Pilot &getCop() const { return *copilot; }
    int getMax() const { return max;}

    bool setCapt(Pilot &capt);
    void setCop(Pilot &cop) { copilot = &cop, cop.chStat(Status::L); };

    void out() const;

private:
    string name;
    Pilot *captain = nullptr, *copilot = nullptr;
    int max;
};


#endif //OOP_DZ1_AVION_H
