/*
 * CompressedMatrix.h
 *
 *  Created on: Dec 10, 2012
 *      Author: matej
 */

#ifndef COMPRESSEDMATRIX_H_
#define COMPRESSEDMATRIX_H_

#include "matrix.h"

class CompressedMatrix: public Matrix {

public:
    CompressedMatrix(std::istream& is);
    virtual ~CompressedMatrix();

    virtual int rowSize() const;
    virtual int columnSize() const;
    virtual double getElement(int row, int col) const;
    virtual void setElement(int row, int col, double value);

    virtual Vector* multiplyLeft(const Vector& vector) const;
    virtual Vector* multiplyRight(const Vector& vector) const;

    virtual void print(std::ostream& os) const;

private:
    int m_rows;
    int m_cols;
    int m_dataSize;
    double* m_data;
    int* m_columnIndex;
    int* m_rowAddress;

    bool indexOutOfBounds(int row, int col) const;
    void checkStreamError(std::istream& is);
};

#endif /* COMPRESSEDMATRIX_H_ */
