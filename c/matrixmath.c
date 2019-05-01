#include "matrixmath.h"


Matrix2D* matmul(Matrix2D* mat1, Matrix2D* mat2) {
    if (mat1->shape[1] != mat2->shape[0]) {
        printf("ALERT! INVALID DIMENSIONS FOR MATRIX MULTIPLICATION!\n");
        return NULL;
    }
    
    Matrix2D* out = matrix2d_init(mat1->shape[0], mat2->shape[1]);
    
    for (size_t i = 0; i < mat1->shape[0]; i++) {
        for (size_t k = 0; k < mat1->shape[1]; k++) {
            for (size_t j = 0; j < mat2->shape[1]; j++) {
                out->i[i][j] += mat1->i[i][k] * mat2->i[k][j];
    }}}

    return out;
}
