#include "flotaAviona.h"

FlotaAviona::FlotaAviona(FlotaAviona &f) {
    name = f.name;
    maxPl = f.maxPl;
    maxPas = f.maxPas;
    fleetSize = f.fleetSize;

    Node *tail, *elem;
    for (Node *curr = f.fleet; curr; curr = curr->next) {
        elem = new Node(*curr->avion);
        if (!fleet) fleet = elem;
        else tail->next = elem;
        tail = elem;
    }
}

FlotaAviona::FlotaAviona(FlotaAviona &&f) {
    name = f.name;
    maxPl = f.maxPl;
    maxPas = f.maxPas;
    fleetSize = f.fleetSize;

    f.maxPl = nullptr;
    f.fleet = nullptr;
}

FlotaAviona::~FlotaAviona() {
    while (fleet) {
        Node *old = fleet;
        fleet = fleet->next;
        free(old);
    }
}

void FlotaAviona::addPlane(Avion &a) {
    fleetSize++;
    maxPas += a.getMax();

    fleet = new Node(a, fleet);
    if (!maxPl) maxPl = &a;
    else maxPl = maxPl->getMax() > a.getMax() ? maxPl : &a;
}

void FlotaAviona::out() const {
    cout << name << endl;
    for (Node *curr = fleet; curr; curr = curr->next) {
        curr->avion->out();
        cout << endl;
    }
}

