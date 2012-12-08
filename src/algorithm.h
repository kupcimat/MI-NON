/*
 * Algorithm.h
 *
 *  Created on: Dec 8, 2012
 *      Author: matej
 */

#ifndef ALGORITHM_H_
#define ALGORITHM_H_

#include "matrix.h"
#include "vector.h"

class Algorithm {

public:
    virtual ~Algorithm() {
    }

    virtual Vector* solve(const Matrix& matrix, const Vector& vector, double epsilon) = 0;
};

#endif /* ALGORITHM_H_ */
