#ifndef NNMATH_H
#define NNMATH_H

#include <stdio.h>
#include <stdlib.h>

#include "matrix2d.h"

double relu(double x);
void softmax(Matrix2D* mat);
double logistic(double x);

#endif /* NNMATH_H */

