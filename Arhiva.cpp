//
// Created by xparh on 10/29/2021.
//

#include "Arhiva.h"

Arhiva::Arhiva(Arhiva &a) {
    NodeL *tail;
    for (NodeL *curr = a.flights; curr; curr = curr->next) {
        if (!flights) flights = curr;
        else tail->next = curr;
        tail = curr;
    }
}

Arhiva::Arhiva(Arhiva &&a) {
    flights = a.flights;
    a.flights = nullptr;
}

Arhiva::~Arhiva() {
    while (flights) {
        NodeL *old = flights;
        flights = flights->next;
        delete old;
    }
}

NodeL *Arhiva::getStartFl(string s) {
    NodeL *stRange = nullptr;
    for (NodeL *curr = flights; curr; curr = curr->next) {
        if (curr->let->getStart() == s)
            stRange = new NodeL(*curr->let, stRange);
    }
    return stRange;
}

NodeL *Arhiva::getDestFl(string d) {
    NodeL *dstRange = nullptr;
    for (NodeL *curr = flights; curr; curr = curr->next) {
        if (curr->let->getDest() == d)
            dstRange = new NodeL(*curr->let, dstRange);
    }
    return dstRange;
}

NodeL *Arhiva::getStartAndDestFl(string s, string d) {
    NodeL *fRange = nullptr;
    for (NodeL *curr = flights; curr; curr = curr->next) {
        if (curr->let->getStart() == s && curr->let->getDest() == d)
            fRange = new NodeL(*curr->let, fRange);
    }
    return fRange;
}

void Arhiva::out() const {
    cout << "ARHIVA" << endl;
    for (NodeL *curr = flights; curr; curr=curr->next) {
        curr->let->out();
        cout << endl;
    }
}

void Arhiva::addL(Let &l) {
    flights = new NodeL(l, flights);
}

