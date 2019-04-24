#ifndef MATRIX2D_H
#define MATRIX2D_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    double** i;
    size_t shape[2];
    bool is_static;
} Matrix2D;

Matrix2D* matrix2d_from_static_arr(double* arr, size_t nrow, size_t ncol);
Matrix2D* matrix2d_init(size_t nrow, size_t ncol);
void destroy_matrix2d(Matrix2D* mat);
void print_matrix2d(Matrix2D* mat);

#endif