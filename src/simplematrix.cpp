/*
 * simplematrix.cpp
 *
 *  Created on: Sep 20, 2012
 *      Author: matej
 */

#include "simplematrix.h"
#include "simplevector.h"
using namespace std;

SimpleMatrix::SimpleMatrix(int _rows, int _cols) {
    m_rows = _rows;
    m_cols = _cols;

    m_data = new double*[m_rows];
    for (int row = 0; row < m_rows; ++row) {
        m_data[row] = new double[m_cols];
    }
}

SimpleMatrix::~SimpleMatrix() {
    for (int row = 0; row < m_rows; ++row) {
        delete[] m_data[row];
    }
    delete[] m_data;
}

int SimpleMatrix::rowSize() const {
    return m_rows;
}

int SimpleMatrix::columnSize() const {
    return m_cols;
}

double SimpleMatrix::getElement(int row, int col) const {
    if (indexOutOfBounds(row, col)) {
        throw "Index out of bounds";
    }

    return m_data[row][col];
}

void SimpleMatrix::setElement(int row, int col, double value) {
    if (indexOutOfBounds(row, col)) {
        throw "Index out of bounds";
    }

    m_data[row][col] = value;
}

Vector* SimpleMatrix::multiplyLeft(const Vector& vector) const {
    if (vector.size() != m_rows) {
        throw "Vector size does not match matrix rows";
    }

    Vector* result = new SimpleVector(m_cols);

    for (int col = 0; col < m_cols; ++col) {
        double tmpSum = 0;
        for (int i = 0; i < vector.size(); ++i) {
            tmpSum += vector.getElement(i) * m_data[i][col];
        }
        result->setElement(col, tmpSum);
    }

    return result;
}

Vector* SimpleMatrix::multiplyRight(const Vector& vector) const {
    if (vector.size() != m_cols) {
        throw "Vector size does not match columns";
    }

    Vector* result = new SimpleVector(m_rows);

    for (int row = 0; row < m_rows; ++row) {
        double tmpSum = 0;
        for (int i = 0; i < vector.size(); ++i) {
            tmpSum += m_data[row][i] * vector.getElement(i);
        }
        result->setElement(row, tmpSum);
    }

    return result;
}

void SimpleMatrix::print(ostream& os) const {
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            os << m_data[row][col] << " ";
        }
        os << endl;
    }
}

bool SimpleMatrix::indexOutOfBounds(int row, int col) const {
    return (row < 0 || col < 0 || row >= m_rows || col >= m_cols);
}
