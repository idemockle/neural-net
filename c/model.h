#ifndef MODEL_H
#define MODEL_H

#include "matrix2d.h"
#include "matrixmath.h"
#include "nnmath.h"

#define NEURAL_NET_NLAYERS 4

extern Matrix2D* INTERCEPTS[NEURAL_NET_NLAYERS - 1];
extern Matrix2D* COEFS[NEURAL_NET_NLAYERS - 1];

void nn_init_param_matrices(void);
Matrix2D* nn_predict(Matrix2D* x);

#endif /* MODEL_H */

