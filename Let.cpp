//
// Created by xparh on 10/29/2021.
//

#include "Let.h"

int Let::cnt = 0;

void Let::out() const {
    cout << "LET-" << start << ":" << dest << " - "<< plane->getName();
}

Let::Let(Let &l) {
    start = l.start;
    dest = l.dest;
    plane = l.plane;
    id = cnt++;
}
