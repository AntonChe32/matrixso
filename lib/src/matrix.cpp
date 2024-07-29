#include <iostream>
#include <cmath>
#include "matrix.h"

using namespace math;

void math::Matrix::getVec(std::vector<real> &mvec) const
{
    // получить вектор элементов
    mvec = this->mvec_;
}

void math::Matrix::setVec(std::vector<real> &vec) {

    // задвть вектор элементов
    this->mvec_ = vec;
}

int math::Matrix::rows() const
{
    return this->rows_;
}

int math::Matrix::cols() const
{
    return this->cols_;
}

real &Matrix::operator()(int row, int col)
{
    if (row >= this->rows_)
    {
        std::cerr << "ERROR: row number out of bounds" << std::endl;
    }
    if (col >= this->cols_)
    {
        std::cerr << "ERROR: col number out of bounds" << std::endl;
    }

    return this->mvec_.at(cols_ * row + col);
}

real Matrix::operator()(int row, int col) const
{
    if (row >= this->rows_)
    {
        std::cerr << "ERROR: row number out of bounds" << std::endl;
        // return 0;
    }
    if (col >= this->cols_)
    {
        std::cerr << "ERROR: col number out of bounds" << std::endl;
        // return 0;
    }

     return this->mvec_.at(cols_ * row + col);
}

Matrix &math::Matrix::operator+=(const Matrix &M)
{
    if( cols_ != M.cols_ || rows_ != M.rows_){
        std::cerr << "ERROR: Matrixs dimensions must equal!";
        return *this;
    }
    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) += M.mvec_.at(i);
    }
    return *this;
}

Matrix &math::Matrix::operator-=(const Matrix &M)
{
    if( cols_ != M.cols_ || rows_ != M.rows_){
        std::cerr << "ERROR: Matrixs dimensions must be equal!" << std::endl;
        return *this;
    }
    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) -= M.mvec_.at(i);
    }
    return *this;
}

Matrix &math::Matrix::operator*=(const real n)
{
    for (size_t i = 0; i < this->mvec_.size(); ++i)
    {
        this->mvec_.at(i) *= n;
    }
    return *this;
}
void math::Matrix::clone(const Matrix &B){
    mvec_ = B.mvec_;
    rows_ = B.rows_;
    cols_ = B.cols_;
}
Matrix& math::Matrix::operator*=(const Matrix &B)
{
    Matrix M = *this * B;
    clone(M);
    return *this;
}

Matrix math::Matrix::transpose(){
    Matrix M(cols_, rows_);
    for(int r = 0; r < rows_; r++){
        for(int c = 0; c < cols_; c++){
            M(c, r) = (*this)(r, c);
        
        }
    }
    return M;
}

namespace math
{
    std::ostream &operator<<(std::ostream &out, const Matrix &matrix)
    {
        for (int i = 0; i < matrix.rows_; ++i)
        {
            for (int j = 0; j < matrix.cols_; ++j)
            {
                out << matrix.mvec_.at(matrix.cols_ * i + j) << " ";
            }
            out << std::endl;
        }

        return out;
    }

    std::istream &operator>>(std::istream &in, Matrix &matrix)
    {
        int n(0);
        int m(0);

        in >> n;
        in >> m;

        matrix = Matrix(n, m);

        return in;
    }

    Matrix operator+(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "ERROR: Matrixs dimensions must be equal!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.cols_, A.rows_);

        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            M.mvec_.at(i) = A.mvec_.at(i) + B.mvec_.at(i);
        }

        return M;
    }

    Matrix operator-(const Matrix &A, const Matrix &B)
    {
        if ((A.cols_ != B.cols_) || (A.rows_ != B.rows_))
        {
            std::cerr << "ERROR: Matrixs dimensions must be equal!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.cols_, A.rows_);

        for (int i = 0; i < M.mvec_.size(); ++i)
        {
            M.mvec_.at(i) = A.mvec_.at(i) - B.mvec_.at(i);
        }

        return M;
    }

    Matrix operator*(const Matrix &A, const Matrix &B)
    {
        if (A.cols_ != B.rows_)
        {
            std::cerr << "ERROR: Matrixs dimensions must be equal!" << std::endl;
            return Matrix(0, 0);
        }

        Matrix M(A.rows_, B.cols_);

        for (int pos = 0; pos < M.mvec_.size(); ++pos)
        {
            int row = (int)std::floor(pos / M.cols_);
            int col = pos - row * M.cols_;

            for (int k = 0; k < A.cols_; ++k)
            {
                M.mvec_.at(pos) += A(row, k) * B(k, col);
            }
        }

        return M;
    }
}