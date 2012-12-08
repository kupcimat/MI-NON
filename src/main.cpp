//============================================================================
// Name        : main.cpp
// Author      : Matej Kupciha
//============================================================================

//#ifndef TEST

#include <iostream>
using namespace std;

#include "simplevector.h"
#include "simplematrix.h"
#include "algorithm.h"
#include "gradientdescent.h"

int main(int argc, char* argv[]) {

    Vector* v = new SimpleVector(2);
    Matrix* m = new SimpleMatrix(2, 2);

    v->setElement(0, 2);
    v->setElement(1, 1);
    v->print(cout);
    cout << endl;

    m->setElement(0, 0, 2);
    m->setElement(0, 1, -1);
    m->setElement(1, 0, -1);
    m->setElement(1, 1, 1);
    m->print(cout);
    cout << endl;

    Algorithm* a = new GradientDescent();
    Vector* res = a->solve(*m, *v, 0.001);
    res->print(cout);
    cout << endl;

    // free memory
    delete v;
    delete m;
    delete a;
    delete res;

    return 0;
}

//#endif /* TEST */
