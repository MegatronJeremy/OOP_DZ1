#ifndef OOP_DZ1_PILOT_H
#define OOP_DZ1_PILOT_H

#include <string>
#include <iostream>

using namespace std;

class Pilot {
public:
    Pilot(string n, int h, bool s = false) : name(n), hrs(h), stat(s) {};
    Pilot(Pilot &p) = delete;

    string getName() const { return name; }
    int getHrs() const { return hrs; }
    bool getStat() const { return stat; }

    void addHrs(int h) { hrs += h; }
    void chStat(bool s) { stat = s; }

    void out() const;

private:
    string name;
    int hrs;
    bool stat;
};

#endif //OOP_DZ1_PILOT_H
