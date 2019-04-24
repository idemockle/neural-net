#include "matrix2d.h"


Matrix2D* matrix2d_from_static_arr(double* arr, size_t nrow, size_t ncol) {
    Matrix2D* out;

    out = (Matrix2D*) malloc(sizeof(Matrix2D));
    out->i = (double**) malloc(nrow*sizeof(double*));

    for (int idx = 0; idx < nrow; idx++)
        out->i[idx] = &arr[idx*ncol];

    out->shape[0] = nrow;
    out->shape[1] = ncol;
    
    out->is_static = true;
    
    return out;
}

Matrix2D* matrix2d_init(size_t nrow, size_t ncol) {
    Matrix2D* out;
    
    out = (Matrix2D*) malloc(sizeof(Matrix2D));
    out->i = (double**) malloc(nrow*sizeof(double*));
    out->i[0] = (double*) calloc(nrow*ncol, sizeof(double));
    
    for (int idx = 1; idx < nrow; idx++) {
        out->i[idx] = &(out->i[0][idx*ncol]);
    }
    
    out->shape[0] = nrow;
    out->shape[1] = ncol;
    
    out->is_static = false;
    
    return out;
}

void destroy_matrix2d(Matrix2D* mat) {
    if (!mat->is_static) {
        free(mat->i[0]);
    }
    free(mat->i);
    free(mat);
}

void print_matrix2d(Matrix2D* mat) {
    printf("[ ");
    for (int i = 0; i < mat->shape[0]; i++){
        printf("[ ");
        for (int j = 0; j < mat->shape[1]; j++) {
            printf("%f", mat->i[i][j]);
            if (j < mat->shape[1] - 1) {
                printf(", ");
            }
        }
        if (i < mat->shape[0] - 1)
            printf(" ]\n  ");
        else
            printf(" ] ]\n");
    }
}
