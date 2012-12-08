/*
 * GradientDescent.h
 *
 *  Created on: Dec 8, 2012
 *      Author: matej
 */

#ifndef GRADIENTDESCENT_H_
#define GRADIENTDESCENT_H_

#include "algorithm.h"

class GradientDescent: public Algorithm {

public:
    virtual ~GradientDescent();

    virtual Vector* solve(const Matrix& matrix, const Vector& vector, double epsilon);
};

#endif /* GRADIENTDESCENT_H_ */
