/*
 * matrix.h
 *
 *  Created on: Sep 18, 2012
 *      Author: matej
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include "vector.h"

class Matrix {

public:
    virtual ~Matrix() {
    }

    virtual int rowSize() const = 0;
    virtual int columnSize() const = 0;
    virtual double getElement(int row, int col) const = 0;
    virtual void setElement(int row, int col, double value) = 0;

    virtual Vector* multiplyLeft(const Vector& vector) = 0;
    virtual Vector* multiplyRight(const Vector& vector) = 0;

    virtual void print(std::ostream& os) const = 0;
};

#endif /* MATRIX_H_ */
