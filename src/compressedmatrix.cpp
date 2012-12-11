/*
 * compressedmatrix.cpp
 *
 *  Created on: Dec 10, 2012
 *      Author: matej
 */

#include "compressedmatrix.h"
#include "simplevector.h"
using namespace std;

CompressedMatrix::CompressedMatrix(istream& is) {
    is >> m_rows >> m_dataSize;
    m_cols = m_rows;
    checkStreamError(is);

    m_data = new double[m_dataSize];
    m_columnIndex = new int[m_dataSize];
    m_rowAddress = new int[m_rows + 1];
    m_rowAddress[0] = 0;

    int row, col, prevRow = 0, colCount = 0;
    double value;
    for (int i = 0; i < m_dataSize; ++i) {
        is >> row >> col >> value;
        checkStreamError(is);
        // transform coordinates
        row -= 1;
        col -= 1;

        colCount++;
        m_data[i] = value;
        m_columnIndex[i] = col;
        if (row > prevRow) {
            m_rowAddress[row] = colCount - 1;
            prevRow = row;
        }
    }
    m_rowAddress[m_rows] = colCount;
}

CompressedMatrix::~CompressedMatrix() {
    delete[] m_data;
    delete[] m_columnIndex;
    delete[] m_rowAddress;
}

int CompressedMatrix::rowSize() const {
    return m_rows;
}

int CompressedMatrix::columnSize() const {
    return m_cols;
}

double CompressedMatrix::getElement(int row, int col) const {
    throw "Not implemented";
}

void CompressedMatrix::setElement(int row, int col, double value) {
    throw "Not implemented";
}

Vector* CompressedMatrix::multiplyLeft(const Vector& vector) const {
    throw "Not implemented";
}

Vector* CompressedMatrix::multiplyRight(const Vector& vector) const {
    if (vector.size() != m_cols) {
        throw "Vector size does not match columns";
    }
    Vector* result = new SimpleVector(m_rows);

    for (int row = 0; row < m_rows; ++row) {
        double tmpSum = 0;
        for (int i = m_rowAddress[row]; i < m_rowAddress[row + 1]; ++i) {
            tmpSum += m_data[i] * vector.getElement(m_columnIndex[i]);
        }
        result->setElement(row, tmpSum);
    }

    return result;
}

void CompressedMatrix::print(ostream& os) const {
    os << "Data: ";
    for (int i = 0; i < m_dataSize; ++i) {
        os << m_data[i] << " ";
    }
    os << endl << "Column indexes: ";
    for (int i = 0; i < m_dataSize; ++i) {
        os << m_columnIndex[i] << " ";
    }
    os << endl << "Row addresses:  ";
    for (int i = 0; i < (m_rows + 1); ++i) {
        os << m_rowAddress[i] << " ";
    }
    os << endl;
}

bool CompressedMatrix::indexOutOfBounds(int row, int col) const {
    return (row < 0 || col < 0 || row >= m_rows || col >= m_cols);
}

void CompressedMatrix::checkStreamError(istream& is) {
    if (is.fail()) {
        throw "Wrong input data format";
    }
}
