//============================================================================
// Name        : main.cpp
// Author      : Matej Kupciha
//============================================================================

#ifndef TEST

#include <iostream>
using namespace std;

#include "simplevector.h"
#include "simplematrix.h"
#include "algorithm.h"
#include "gradientdescent.h"
#include "conjugategradients.h"

int main(int argc, char* argv[]) {

    Vector* v = new SimpleVector(2);
    Matrix* m = new SimpleMatrix(2, 2);

    v->setElement(0, 2);
    v->setElement(1, 1);

    m->setElement(0, 0, 2);
    m->setElement(0, 1, -1);
    m->setElement(1, 0, -1);
    m->setElement(1, 1, 1);

    Algorithm* descent = new GradientDescent();
    Algorithm* gradients = new ConjugateGradients();
    Vector* res = descent->solve(*m, *v, 0.000001);
    Vector* res2 = gradients->solve(*m, *v, 0.000001);

    v->print(cout);
    cout << endl;
    m->print(cout);
    cout << endl << "Gradient descent: ";
    res->print(cout);
    cout << endl << "Conjugate gradients: ";
    res2->print(cout);
    cout << endl;

    // free memory
    delete v;
    delete m;
    delete descent;
    delete gradients;
    delete res;
    delete res2;

    return 0;
}

#endif /* TEST */
