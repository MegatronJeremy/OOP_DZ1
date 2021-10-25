#ifndef OOP_DZ1_PILOT_H
#define OOP_DZ1_PILOT_H

#include <string>
#include <iostream>

using namespace std;

enum Status {L, N};

class Pilot {
public:
    Pilot(string n, int h, Status s = N) : name(n), hrs(h), stat(s) {};
    Pilot(Pilot &p) = delete;

    string getName() const { return name; }
    int getHrs() const { return hrs; }
    Status getStat() const { return stat; }

    void addHrs(int h) { hrs += h; }
    void chStat(Status s) { stat = s; }

    void out() const;

private:
    string name;
    int hrs;
    Status stat;

    static string strStatus[];
};

#endif //OOP_DZ1_PILOT_H
