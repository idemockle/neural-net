#include <math.h>

#include "nnmath.h"


double relu(double x) {
    return (x < 0 ? 0 : x);
}

void softmax(Matrix2D* mat) {
    double exp_arr_sum;
    size_t i;
    size_t length = mat->shape[0] * mat->shape[1];
    double dest_arr[length];
    
    exp_arr_sum = 0;
    for (i = 0; i < length; i++) {
        dest_arr[i] = exp(mat->i[0][i]);
        exp_arr_sum += dest_arr[i];
    }
    
    for (i = 0; i < length; i++) {
        dest_arr[i] /= exp_arr_sum;
        mat->i[0][i] = dest_arr[i];
    }
}

double logistic(double x) {
    return 1. / (exp(x*-1.) + 1.);
}
