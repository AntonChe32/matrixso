#pragma once 

#include "../matrix.h"
#include "../export.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void VMatrix;

VMatrix* MATRIXLIB_EXPORT math_matrix_create(int col, int row);
void MATRIXLIB_EXPORT math_matrix_delete(VMatrix *m);
int MATRIXLIB_EXPORT math_matrix_get_cols(VMatrix *m);
int MATRIXLIB_EXPORT math_matrix_get_rows(VMatrix *m);
math::real MATRIXLIB_EXPORT math_matrix_get_element(VMatrix *m, int col, int row);
void MATRIXLIB_EXPORT math_matrix_set_element(VMatrix *m, int col, int row, math::real toset);
VMatrix* MATRIXLIB_EXPORT math_matrix_plus_bind(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_minus_bind(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_mul_bind(VMatrix *m, math::real r);
VMatrix* MATRIXLIB_EXPORT math_matrix_dot_bind(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_transpose(VMatrix *m);
void MATRIXLIB_EXPORT math_matrix_print(VMatrix *m);
void MATRIXLIB_EXPORT math_matrix_input(VMatrix *m);
VMatrix* MATRIXLIB_EXPORT math_matrix_add(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_sub(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_dot(VMatrix *m, VMatrix *b);

#ifdef __cplusplus
}
#endif
