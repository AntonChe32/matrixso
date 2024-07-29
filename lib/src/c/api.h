#pragma once 

#include "../matrix.h"
#include "../export.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void VMatrix;

MATRIXLIB_EXPORT VMatrix* math_matrix_create(int col, int row);
MATRIXLIB_EXPORT void math_matrix_delete(VMatrix *m);
MATRIXLIB_EXPORT int math_matrix_get_cols(VMatrix *m);
MATRIXLIB_EXPORT int math_matrix_get_rows(VMatrix *m);
MATRIXLIB_EXPORT math::real math_matrix_get_element(VMatrix *m, int col, int row);
MATRIXLIB_EXPORT void math_matrix_set_element(VMatrix *m, int col, int row, math::real toset);
MATRIXLIB_EXPORT VMatrix* math_matrix_plus_bind(VMatrix *m, VMatrix *b);
MATRIXLIB_EXPORT VMatrix* math_matrix_minus_bind(VMatrix *m, VMatrix *b);
MATRIXLIB_EXPORT VMatrix* math_matrix_mul_bind(VMatrix *m, math::real r);
MATRIXLIB_EXPORT VMatrix* math_matrix_dot_bind(VMatrix *m, VMatrix *b);
MATRIXLIB_EXPORT VMatrix* math_matrix_transpose(VMatrix *m);
MATRIXLIB_EXPORT void math_matrix_print(VMatrix *m);
MATRIXLIB_EXPORT void math_matrix_input(VMatrix *m);
MATRIXLIB_EXPORT VMatrix* math_matrix_add(VMatrix *m, VMatrix *b);
MATRIXLIB_EXPORT VMatrix* math_matrix_sub(VMatrix *m, VMatrix *b);
MATRIXLIB_EXPORT VMatrix* math_matrix_dot(VMatrix *m, VMatrix *b);

#ifdef __cplusplus
}
#endif
