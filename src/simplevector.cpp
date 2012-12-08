/*
 * simplevector.cpp
 *
 *  Created on: Sep 18, 2012
 *      Author: matej
 */

#include "simplevector.h"
using namespace std;

SimpleVector::SimpleVector(int _size) {
    m_size = _size;
    m_data = new double[m_size];
}

SimpleVector::~SimpleVector() {
    delete[] m_data;
}

int SimpleVector::size() const {
    return m_size;
}

double SimpleVector::getElement(int index) const {
    if (indexOutOfBounds(index)) {
        throw "Index out of bounds";
    }

    return m_data[index];
}

void SimpleVector::setElement(int index, double value) {
    if (indexOutOfBounds(index)) {
        throw "Index out of bounds";
    }

    m_data[index] = value;
}

void SimpleVector::plus(const Vector& other) {
    if (other.size() != m_size) {
        throw "Vectors must have the same size";
    }

    for (int i = 0; i < m_size; ++i) {
        m_data[i] += other.getElement(i);
    }
}

void SimpleVector::minus(const Vector& other) {
    if (other.size() != m_size) {
        throw "Vectors must have the same size";
    }

    for (int i = 0; i < m_size; ++i) {
        m_data[i] -= other.getElement(i);
    }
}

void SimpleVector::multiply(double value) {
    for (int i = 0; i < m_size; ++i) {
        m_data[i] *= value;
    }
}

double SimpleVector::scalarProduct(const Vector& other) const {
    if (other.size() != m_size) {
        throw "Vectors must have the same size";
    }

    double result = 0;
    for (int i = 0; i < m_size; ++i) {
        result += other.getElement(i) * m_data[i];
    }

    return result;
}

void SimpleVector::print(ostream& os) const {
    for (int i = 0; i < m_size; i++) {
        os << getElement(i) << " ";
    }
}

bool SimpleVector::indexOutOfBounds(int index) const {
    return (index < 0 || index >= m_size);
}
