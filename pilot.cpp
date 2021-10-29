#include "pilot.h"

void Pilot::out() const {
    cout << name << "(" << hrs << ")" << "-" << (stat ? 'L' : 'N');
}