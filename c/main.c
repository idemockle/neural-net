#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix2d.h"
#include "model.h"

int main(int argc, char** argv) {
    Matrix2D* mat;
    Matrix2D* res;
    
//    init_param_matrices();
//    
//    for (int i = 0; i < NEURAL_NET_NLAYERS-1; i++) {
//        printf("LAYER %d INTERCEPTS:\n", i+1);
//        print_matrix2d(INTERCEPTS[i]);
//        
//        printf("LAYER %d COEFS:\n", i+1);
//        print_matrix2d(COEFS[i]);
//    }
    
    mat = matrix2d_init(1, 4);
    
    res = nn_predict(mat);
    
    print_matrix2d(res);
    
    destroy_matrix2d(mat);
    destroy_matrix2d(res);
    
    return (EXIT_SUCCESS);
}
