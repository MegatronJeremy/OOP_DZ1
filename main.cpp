#include <iostream>

#include "flotaAviona.h"

int main() {
    FlotaAviona f1("Britanska armada");
    Pilot p1("Dzon Bosnic", 69);
    Pilot p2("Ron Dzeremi", 42069);
    Pilot p3("Mare Vujnovic", 444);
    Pilot p4("Vuk Draskovic", 0);
    Pilot p5("Ozzy Osbourne", 2);
    Pilot p6("Bruce Dickinson", 666);
    Avion a1("Boeing", 747);
    Avion a2("Ed Force One", 757);
    Avion a3("G-4 Super Galeb", 2);

    a1.setCapt(p2);
    a1.setCop(p1);
    a2.setCapt(p6);
    a2.setCop(p5);
    a3.setCapt(p3);
    a3.setCop(p4);

    f1.addPlane(a1);
    f1.addPlane(a2);
    f1.addPlane(a3);

    f1.out();
    f1.getMaxPl()->out();

    return 0;
}
