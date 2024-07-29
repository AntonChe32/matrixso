#include "api.h"
#include "../matrix.h"

#define V2M(v) ((math::Matrix*)(v)) 
#define M2V(m) ((VMatrix*)(m))

VMatrix* MATRIXLIB_EXPORT math_matrix_create(int col, int row){
    return M2V(new math::Matrix(col, row));
}
void MATRIXLIB_EXPORT math_matrix_delete(VMatrix *m){
    delete V2M(m);
}

int MATRIXLIB_EXPORT math_matrix_get_cols(VMatrix *m){
    return V2M(m)->cols();
}
int MATRIXLIB_EXPORT math_matrix_get_rows(VMatrix *m){
    return V2M(m)->rows();
}

math::real MATRIXLIB_EXPORT math_matrix_get_element(VMatrix *m, int col, int row){
    return V2M(m)->operator()(col, row);
}

void MATRIXLIB_EXPORT math_matrix_set_element(VMatrix *m, int col, int row, math::real toset){
    V2M(m)->operator()(col, row) = toset;
}

VMatrix* MATRIXLIB_EXPORT math_matrix_plus_bind(VMatrix *m, VMatrix *b){
    return M2V(&V2M(m)->operator+=(*V2M(b)));
}

VMatrix* MATRIXLIB_EXPORT math_matrix_minus_bind(VMatrix *m, VMatrix *b){
    return M2V(&V2M(m)->operator-=(*V2M(b)));
}

VMatrix* MATRIXLIB_EXPORT math_matrix_mul_bind(VMatrix *m, math::real r){
    return M2V(&V2M(m)->operator*=(r));
}

VMatrix* MATRIXLIB_EXPORT math_matrix_dot_bind(VMatrix *m, VMatrix *b){
    return M2V(&V2M(m)->operator*=(*V2M(b)));
}

VMatrix* MATRIXLIB_EXPORT math_matrix_transpose(VMatrix *m){
    return M2V(new math::Matrix(V2M(m)->transpose()));
}

void MATRIXLIB_EXPORT math_matrix_print(VMatrix *m){
    std::cout << *V2M(m);
}
void MATRIXLIB_EXPORT math_matrix_input(VMatrix *m){
    std::cin >> *V2M(m);
}

VMatrix* MATRIXLIB_EXPORT math_matrix_add(VMatrix *m, VMatrix *b){
    return M2V(new math::Matrix(*(V2M(m))+*(V2M(b))));
}

VMatrix* MATRIXLIB_EXPORT math_matrix_sub(VMatrix *m, VMatrix *b){
    return M2V(new math::Matrix(*(V2M(m))-*(V2M(b))));
}

VMatrix* MATRIXLIB_EXPORT math_matrix_dot(VMatrix *m, VMatrix *b){
    return M2V(new math::Matrix(*(V2M(m)) * *(V2M(b))));
}
