#include "avion.h"

bool Avion::setCapt(Pilot &capt) {
    if (capt.getHrs() < 100) return false;
    captain = &capt;
    capt.chStat(Status::L);
    return true;
}

void Avion::out() const {
    cout << "AVION:" << name << " - " << max;

//    cout << " KAPETAN:", captain->out(), cout << " KOPILOT:", copilot->out();
}