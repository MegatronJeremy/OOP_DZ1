#include "pilot.h"

string Pilot::strStatus[] = {"L", "N"};

void Pilot::out() const {
    cout << name << "(" << hrs << ")" << "-" << strStatus[stat];
}