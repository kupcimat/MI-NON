/*
 * GradientDescent.cpp
 *
 *  Created on: Dec 8, 2012
 *      Author: matej
 */

#include "gradientdescent.h"
#include "utils.h"

GradientDescent::~GradientDescent() {
}

Vector* GradientDescent::solve(const Matrix& A, const Vector& b, double epsilon) {
    Vector* x = Utils::zeroVector(b.size());
    // r = b - A * x
    Vector* r = A.multiplyRight(*x);
    r->multiply(-1);
    r->plus(b);

    int counter = 0;
    double alfa;
    double bSize = Utils::vectorSize(b);
    while ((Utils::vectorSize(*r) / bSize) > epsilon) {
        // Ar = A * r
        Vector* Ar = A.multiplyRight(*r);
        Vector* rOld = r->clone();

        // alfa = (r * r) / (r * A * r)
        alfa = r->scalarProduct(*r) / r->scalarProduct(*Ar);
        // x = x + alfa * r
        rOld->multiply(alfa);
        x->plus(*rOld);
        // r = r - alfa * A * r
        Ar->multiply(alfa);
        r->minus(*Ar);

        delete Ar;
        delete rOld;
        counter++;
    }
    delete r;
    std::cout << "Gradient descent iterations: " << counter << std::endl;

    return x;
}
