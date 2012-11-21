/*
 * vector.h
 *
 *  Created on: Sep 18, 2012
 *      Author: matej
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

class Vector {

public:
    virtual ~Vector() {
    }

    virtual int size() const = 0;
    virtual double getElement(int index) const = 0;
    virtual void setElement(int index, double value) = 0;

    virtual double scalarProduct(const Vector& other) const = 0;

    virtual void print(std::ostream& os) const = 0;
};

#endif /* VECTOR_H_ */
