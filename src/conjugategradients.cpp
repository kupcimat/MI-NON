/*
 * conjugategradients.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: matej
 */

#include "conjugategradients.h"
#include "utils.h"

ConjugateGradients::~ConjugateGradients() {
}

Vector* ConjugateGradients::solve(const Matrix& A, const Vector& b, double epsilon) {
    Vector* x = Utils::zeroVector(b.size());
    // r = b - A * x
    Vector* r = A.multiplyRight(*x);
    r->multiply(-1);
    r->plus(b);
    // s = r
    Vector* s = r->clone();

    int counter = 0;
    double alfa, beta;
    double bSize = Utils::vectorSize(b);
    while ((Utils::vectorSize(*r) / bSize) > epsilon) {
        // As = A * s
        Vector* As = A.multiplyRight(*s);
        Vector* sOld = s->clone();
        double rr = r->scalarProduct(*r);

        // alfa = (r * r) / (s * A * s)
        alfa = rr / s->scalarProduct(*As);
        // x = x + alfa * s
        sOld->multiply(alfa);
        x->plus(*sOld);
        // r = r - alfa * A * s
        As->multiply(alfa);
        r->minus(*As);

        // beta = (r * r) / (rOld * rOld)
        beta = r->scalarProduct(*r) / rr;
        // s = r + beta * s
        s->multiply(beta);
        s->plus(*r);

        delete As;
        delete sOld;
        counter++;
    }
    delete r;
    delete s;
    std::cout << "Conjugate gradients iterations: " << counter << std::endl;

    return x;
}
