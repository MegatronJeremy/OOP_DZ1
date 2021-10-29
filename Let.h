//
// Created by xparh on 10/29/2021.
//

#ifndef OOP_DZ1_LET_H
#define OOP_DZ1_LET_H

#include "avion.h"

class Let {
public:
    Let(string s, string d, Avion &p) : start(s), dest(d), plane(&p) {
        cnt++;
    };
    Let(Let &l);

    const string &getStart() const {
        return start;
    }

    const string &getDest() const {
        return dest;
    }

    int getId() const {
        return id;
    }

    Avion *getPlane() const {
        return plane;
    }

    void out() const;

private:
    static int cnt;

    int id = cnt;
    string start, dest;
    Avion *plane;
};


#endif //OOP_DZ1_LET_H
