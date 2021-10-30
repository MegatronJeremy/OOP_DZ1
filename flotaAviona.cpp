#include "flotaAviona.h"

FlotaAviona::FlotaAviona(FlotaAviona &f) {
    name = f.name;

    for (NodeA *curr = f.fleet; curr; curr = curr->next) {
        fleet = new NodeA(*curr->avion, fleet);
    }
}

FlotaAviona::FlotaAviona(FlotaAviona &&f) {
    name = f.name;
    fleet = f.fleet;
    f.fleet = nullptr;
}

FlotaAviona::~FlotaAviona() {
    while (fleet) {
        NodeA *old = fleet;
        fleet = fleet->next;
        free(old);
    }
}

void FlotaAviona::addPlane(Avion &a) {
    fleet = new NodeA(a, fleet);
}

void FlotaAviona::out() const {
    cout << name << endl;
    for (NodeA *curr = fleet; curr; curr = curr->next) {
        curr->avion->out();
        cout << endl;
    }
}

void FlotaAviona::remove(string n) {
    NodeA *prev = nullptr;
    for (NodeA *curr = fleet; curr; curr = curr->next) {
        if (curr->avion->getName() == n) {
            if (!prev) fleet = curr->next;
            else prev->next = curr->next;
            delete curr;
            break;
        }
        prev = curr;
    }
}

NodeA *FlotaAviona::getRange(int minC, int maxC) const {
    NodeA *head = nullptr;
    for (NodeA *curr = fleet; curr; curr=curr->next) {
        int x = curr->avion->getCap();
        if (x <= maxC && x >= minC) {
            head = new NodeA(*curr->avion, head);
        }
    }
    return head;
}

Avion *FlotaAviona::getMaxPl() const {
    Avion *max = nullptr;
    for (NodeA *curr = fleet; curr; curr = curr->next) {
        if(!max) max = curr->avion;
        else max = curr->avion->getCap() > max->getCap() ? curr->avion : max;
    }
    return max;
}

int FlotaAviona::getSize() const {
    int size = 0;
    for (NodeA *curr = fleet; curr; curr = curr->next, size++);
    return size;
}

int FlotaAviona::getMaxCap() const {
    int cap = 0;
    for (NodeA *curr = fleet; curr; curr = curr->next) cap+=curr->avion->getCap();
    return cap;
}
