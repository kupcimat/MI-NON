/*
 * tests.cpp
 *
 *  Created on: Sep 21, 2012
 *      Author: matej
 */

#ifdef TEST

#include <boost/test/minimal.hpp>
#include "simplevector.h"
#include "simplematrix.h"

/**
 * Creates linearly initialized SimpleVector,
 * [0,1,2,..].
 */
SimpleVector createSimpleVector(int size) {
    SimpleVector v(size);

    for (int i = 0; i < size; ++i) {
        v.setElement(i, i);
    }

    return v;
}

/**
 * Creates linearly initialized SimpleMatrix,
 * [0,1,2,..]
 * [0,1,2,..]
 * [..      ].
 */
SimpleMatrix createSimpleMatrix(int rows, int cols) {
    SimpleMatrix m = SimpleMatrix(rows, cols);

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            m.setElement(r, c, c);
        }
    }

    return m;
}

void testSimpleVectorDataAccess() {
    SimpleVector v = createSimpleVector(3);

    BOOST_CHECK( v.getElement(0) == 0 );
    BOOST_CHECK( v.getElement(1) == 1 );
    BOOST_CHECK( v.getElement(2) == 2 );
}

void testSimpleVectorSize() {
    SimpleVector v = createSimpleVector(5);

    BOOST_CHECK( v.size() == 5 );
}

void testSimpleVectorPlus() {
    SimpleVector v1 = createSimpleVector(3);
    SimpleVector v2 = createSimpleVector(3);

    // [0,1,2] + [0,1,2] = [0,2,4]
    v1.plus(v2);
    BOOST_CHECK( v1.getElement(0) == 0 );
    BOOST_CHECK( v1.getElement(1) == 2 );
    BOOST_CHECK( v1.getElement(2) == 4 );
}

void testSimpleVectorMinus() {
    SimpleVector v1 = createSimpleVector(3);
    SimpleVector v2 = createSimpleVector(3);

    // [0,1,2] - [0,1,2] = [0,0,0]
    v1.minus(v2);
    BOOST_CHECK( v1.getElement(0) == 0 );
    BOOST_CHECK( v1.getElement(1) == 0 );
    BOOST_CHECK( v1.getElement(2) == 0 );
}

void testSimpleVectorMultiply() {
    SimpleVector v = createSimpleVector(3);

    // [0,1,2] * 3 = [0,3,6]
    v.multiply(3);
    BOOST_CHECK( v.getElement(0) == 0 );
    BOOST_CHECK( v.getElement(1) == 3 );
    BOOST_CHECK( v.getElement(2) == 6 );
}

void testSimpleVectorScalarProduct() {
    SimpleVector v1 = createSimpleVector(3);
    SimpleVector v2 = createSimpleVector(3);

    // [0,1,2] * [0,1,2] = 5
    BOOST_CHECK( v1.scalarProduct(v2) == 5 );
}

void testSimpleVectorScalarProductInequalSize() {
    SimpleVector v1 = createSimpleVector(2);
    SimpleVector v2 = createSimpleVector(3);

    try {
        v1.scalarProduct(v2);
        BOOST_ERROR( "Exception should have been thrown!" );
    } catch (const char* e) {
    }
}

void testSimpleMatrixDataAccess() {
    SimpleMatrix m = createSimpleMatrix(2, 2);

    BOOST_CHECK( m.getElement(0, 0) == 0 );
    BOOST_CHECK( m.getElement(0, 1) == 1 );
    BOOST_CHECK( m.getElement(1, 0) == 0 );
    BOOST_CHECK( m.getElement(1, 1) == 1 );
}

void testSimpleMatrixSize() {
    SimpleMatrix m = createSimpleMatrix(3, 4);

    BOOST_CHECK( m.rowSize() == 3 );
    BOOST_CHECK( m.columnSize() == 4 );
}

void testSimpleMatrixMultiplyLeft() {
    SimpleVector v = SimpleVector(3);
    SimpleMatrix m = createSimpleMatrix(3, 2);

    v.setElement(0, 3);
    v.setElement(1, 2);
    v.setElement(2, 1);

    // [3,2,1] * [0,1] = [0,6]
    //           [0,1]
    //           [0,1]
    Vector* res = m.multiplyLeft(v);

    BOOST_CHECK( res->size() == 2 );
    BOOST_CHECK( res->getElement(0) == 0 );
    BOOST_CHECK( res->getElement(1) == 6 );

    delete res;
}

void testSimpleMatrixMultiplyRight() {
    SimpleVector v = SimpleVector(3);
    SimpleMatrix m = createSimpleMatrix(2, 3);

    v.setElement(0, 3);
    v.setElement(1, 2);
    v.setElement(2, 1);

    // [0,1,2] * [3] = [4]
    // [0,1,2]   [2]   [4]
    //           [1]
    Vector* res = m.multiplyRight(v);

    BOOST_CHECK( res->size() == 2 );
    BOOST_CHECK( res->getElement(0) == 4 );
    BOOST_CHECK( res->getElement(1) == 4 );

    delete res;
}

void testSimpleMatrixMultiplyInequalSize() {
    SimpleVector v = createSimpleVector(3);
    SimpleMatrix m = createSimpleMatrix(2, 2);

    try {
        m.multiplyLeft(v);
        BOOST_ERROR( "Exception should have been thrown!" );
    } catch (const char* e) {
    }

    try {
        m.multiplyRight(v);
        BOOST_ERROR( "Exception should have been thrown!" );
    } catch (const char* e) {
    }
}

int test_main(int, char *[]) {

    testSimpleVectorDataAccess();
    testSimpleVectorSize();
    testSimpleVectorPlus();
    testSimpleVectorMinus();
    testSimpleVectorMultiply();
    testSimpleVectorScalarProduct();
    testSimpleVectorScalarProductInequalSize();

    testSimpleMatrixDataAccess();
    testSimpleMatrixSize();
    testSimpleMatrixMultiplyLeft();
    testSimpleMatrixMultiplyRight();
    testSimpleMatrixMultiplyInequalSize();

    return 0;
}

#endif /* TEST */
