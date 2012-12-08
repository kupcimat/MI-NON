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
    Vector* x = Utils::randomVector(b.size());
    Vector* r = A.multiplyRight(*x);

    //while (Utils::vectorSize(*r) > epsilon) {

    //}

    return x;
}
