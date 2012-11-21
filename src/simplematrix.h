/*
 * simplematrix.h
 *
 *  Created on: Sep 20, 2012
 *      Author: matej
 */

#ifndef SIMPLE_MATRIX_H_
#define SIMPLE_MATRIX_H_

#include <iostream>
#include "matrix.h"

class SimpleMatrix: public Matrix {

public:
    SimpleMatrix(int _rows, int _cols);
    virtual ~SimpleMatrix();

    virtual int rowSize() const;
    virtual int columnSize() const;
    virtual double getElement(int row, int col) const;
    virtual void setElement(int row, int col, double value);

    virtual Vector* multiplyLeft(const Vector& vector);
    virtual Vector* multiplyRight(const Vector& vector);

    virtual void print(std::ostream& os) const;

private:
    int m_rows;
    int m_cols;
    double** m_data;

    bool indexOutOfBounds(int row, int col) const;
};

#endif /* SIMPLE_MATRIX_H_ */
