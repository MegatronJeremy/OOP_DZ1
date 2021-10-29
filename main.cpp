#include "flotaAviona.h"
#include "Arhiva.h"

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

    FlotaAviona f2(f1);

    Let l1("Suscepan", "Kosovo", a3);
    Let l2("Birmingham", "Hell", a2);

    Arhiva arh1;
    arh1.addL(l1);
    arh1.addL(l2);
    Let l3 = l2;

    arh1.out();
    f1.getMaxPl()->out();

    NodeA *r1 = f1.getRange(700, 760);
    NodeL *rl1 = arh1.getDestFl("Hell");
    NodeL *rl2 = arh1.getStartFl("Suscepan");
    NodeL *rl3 = arh1.getStartAndDestFl("Birmingham", "Hell");

    cout << endl << f1.getMaxCap() << " " << f1.getSize() << endl;
    cout << f2.getMaxCap() << " " << f2.getSize() << endl;

    f1.remove("Ed Force One");
    cout << f1.getMaxCap() << " "<<f1.getSize() << endl;
    f1.getMaxPl()->out();

    return 0;
}
