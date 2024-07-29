#include <iostream>
typedef void VMatrix;

#define MATRIXLIB_EXPORT

typedef float real;

extern "C" {

VMatrix* MATRIXLIB_EXPORT math_matrix_create(int col, int row);
void MATRIXLIB_EXPORT math_matrix_delete(VMatrix *m);
int MATRIXLIB_EXPORT math_matrix_get_cols(VMatrix *m);
int MATRIXLIB_EXPORT math_matrix_get_rows(VMatrix *m);
real MATRIXLIB_EXPORT math_matrix_get_element(VMatrix *m, int col, int row);
void MATRIXLIB_EXPORT math_matrix_set_element(VMatrix *m, int col, int row, real toset);
VMatrix* MATRIXLIB_EXPORT math_matrix_plus_bind(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_minus_bind(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_mul_bind(VMatrix *m, real r);
VMatrix* MATRIXLIB_EXPORT math_matrix_dot_bind(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_transpose(VMatrix *m);
void MATRIXLIB_EXPORT math_matrix_print(VMatrix *m);
void MATRIXLIB_EXPORT math_matrix_input(VMatrix *m);
VMatrix* MATRIXLIB_EXPORT math_matrix_add(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_sub(VMatrix *m, VMatrix *b);
VMatrix* MATRIXLIB_EXPORT math_matrix_dot(VMatrix *m, VMatrix *b);

}
int main()
{
    VMatrix *m = math_matrix_create(4, 5);
    std::cout << "Enter dimensions of the matrix 0" << std::endl;
    math_matrix_input(m);

    for (int i = 0; i < math_matrix_get_rows(m); ++i)
        for (int j = 0; j < math_matrix_get_cols(m); ++j)
            math_matrix_set_element(m, i, j, i*math_matrix_get_cols(m)+j);

    std::cout << "M0" << std::endl;
    math_matrix_print(m);
    
    VMatrix *m1 = math_matrix_create(0,0);
    std::cout << "Enter dimensions of the matrix 1" << std::endl;
    math_matrix_input(m1);

    for (int i = 0; i < math_matrix_get_rows(m1); ++i)
        for (int j = 0; j < math_matrix_get_cols(m1); ++j)
            math_matrix_set_element(m1, math_matrix_get_rows(m1)-i-1, math_matrix_get_cols(m1)-j-1, i*math_matrix_get_cols(m1)+j);
    std::cout << "M1" << std::endl;
    math_matrix_print(m1);


    VMatrix *m2 = math_matrix_add(m, m1);
    std::cout << "M2 = M0+M1" << std::endl;
    math_matrix_print(m2);        
    VMatrix *m3 = math_matrix_transpose(m1);
    std::cout << "M3 = T(M1)" << std::endl;
    math_matrix_print(m3);
    VMatrix *m4 = math_matrix_dot(m1, m3);
    std::cout << "M4 = DOT(M1,M3)" << std::endl;
    math_matrix_print(m4);
 
    // M1 += M2;
    // std::cout << "Add M2 to M1: \n"
    //           << M1 << std::endl;
    // std::cout << "pretranspose" << std::endl;
    // math::Matrix M3 = M1.transpose();
    // std::cout << "Transpose M1 to M3" << std::endl << M3 << std::endl;

    // M1 *= 2.;
    // std::cout << "Multiply M1 on 2: \n"
    //           << M1 << std::endl;

    // M1 *= M3;


    // std::cout << "M1 *= M3; M1 is" << std::endl << M1 <<std::endl;
    math_matrix_delete(m);
    math_matrix_delete(m1);
    math_matrix_delete(m2);
    math_matrix_delete(m3);
    math_matrix_delete(m4);
    
    return 0;
}