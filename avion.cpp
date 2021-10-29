#include "avion.h"

bool Avion::setCapt(Pilot &capt) {
    if (capt.getHrs() < 100) return false;
    capt.chStat(true);
    captain = &capt;
    return true;
}

void Avion::out() const {
    cout << "AVION:" << name << " - " << cap;

//    cout << " KAPETAN:", captain->out(), cout << " KOPILOT:", copilot->out();
}
