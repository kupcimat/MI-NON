/*
 * Utils.h
 *
 *  Created on: Dec 8, 2012
 *      Author: matej
 */

#ifndef UTILS_H_
#define UTILS_H_

#include "vector.h"

class Utils {

public:
    static Vector* randomVector(int size);
    static double vectorSize(const Vector& vector);
};

#endif /* UTILS_H_ */
