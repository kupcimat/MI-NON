/*
 * simplevector.h
 *
 *  Created on: Sep 19, 2012
 *      Author: matej
 */

#ifndef SIMPLE_VECTOR_H_
#define SIMPLE_VECTOR_H_

#include <iostream>
#include "vector.h"

class SimpleVector: public Vector {

public:
    SimpleVector(int _size);
    virtual ~SimpleVector();

    virtual int size() const;
    virtual double getElement(int index) const;
    virtual void setElement(int index, double value);

    virtual void plus(const Vector& other);
    virtual void minus(const Vector& other);
    virtual void multiply(double value);
    virtual double scalarProduct(const Vector& other) const;

    virtual void print(std::ostream& os) const;

private:
    int m_size;
    double* m_data;

    bool indexOutOfBounds(int index) const;
};

#endif /* SIMPLE_VECTOR_H_ */
