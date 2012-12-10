/*
 * conjugategradients.h
 *
 *  Created on: Dec 10, 2012
 *      Author: matej
 */

#ifndef CONJUGATEGRADIENTS_H_
#define CONJUGATEGRADIENTS_H_

#include "algorithm.h"

class ConjugateGradients: public Algorithm {

public:
    virtual ~ConjugateGradients();

    virtual Vector* solve(const Matrix& matrix, const Vector& vector, double epsilon);
};

#endif /* CONJUGATEGRADIENTS_H_ */
