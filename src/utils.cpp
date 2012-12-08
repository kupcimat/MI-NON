/*
 * Utils.cpp
 *
 *  Created on: Dec 8, 2012
 *      Author: matej
 */

#include "utils.h"
#include "simplevector.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Vector* Utils::randomVector(int size) {
    Vector* result = new SimpleVector(size);

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        result->setElement(i, (rand() % 1000) / 1000.0);
    }

    return result;
}

double Utils::vectorSize(const Vector& vector) {
    double sum = 0;
    for (int i = 0; i < vector.size(); ++i) {
        sum += (vector.getElement(i) * vector.getElement(i));
    }

    return sqrt(sum);
}
