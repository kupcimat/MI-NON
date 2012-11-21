//============================================================================
// Name        : main.cpp
// Author      : Matej Kupciha
//============================================================================

#ifndef TEST

#include <iostream>
using namespace std;

#include "simplevector.h"
#include "simplematrix.h"

int main(int argc, char* argv[]) {

    int size = 5;
    Vector* v = new SimpleVector(size);
    Vector* v2 = new SimpleVector(size);

    for (int i = 0; i < size; i++) {
        v->setElement(i, i);
        v2->setElement(i, 2 * i);
    }

    v->print(cout);
    cout << endl;
    v2->print(cout);
    cout << endl;

    cout << "v * v2 = " << v->scalarProduct(*v2) << endl;

    Matrix* m = new SimpleMatrix(5, 5);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            m->setElement(i, j, j);
        }
    }

    m->print(cout);
    cout << endl;

    Vector* res = m->multiplyRight(*v);
    res->print(cout);

    delete v;
    delete v2;
    delete m;
    delete res;

    return 0;
}

#endif /* TEST */
