#pragma once
#include <vector>
#include <iostream>

namespace math
{
    #ifdef MATH_DOUBLE_PRECISION_DEFINE
        typedef double real;
    #else
        typedef float real;
    #endif
    /**
     * @brief Класс матриц
    */
    class Matrix
    {
    protected:
        /// @brief число столбцов
        int cols_;

        /// @brief число строк
        int rows_;

        /// @brief одномерный вектор элементов матрицы
        std::vector<real> mvec_;
    public:
        /// @brief конструктор по умолчанию
        Matrix(){
            std::cout << "Constructor by default called!!!" << std::endl;
        }
        /// @brief конструктор с параметрами -создает матрицу размерности rows x cols, заполненную
        /// нулевыми значениями
        /// @param rows количество строк в матрице
        /// @param cols количество столбцов в матрице
        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols)) {
            std::cout << "Constructor with parameter called" << std::endl;
        }
        
        /// @brief получить одномерный вектор элементов
        /// @param[out] mvec вектор элементов матрицы
        void getVec(std::vector<real>& mvec) const;
        /// @brief установить одномерный вектор
        /// @param vec вектор элементов матрицы
        void setVec(std::vector<real> &vec);
        /// @brief клонировать матрицу
        /// @param B клонируемая матрица
        void clone(const Matrix &B);
        /// @brief Транспонирование матрицы
        /// @return Новая транвпонированная матрица
        Matrix transpose();
        /// @brief Транспонирование матрицы на новую матрицу
        /// @param B новая матрица
        /// @return Ссылка на новую матрицу
        Matrix& _transpose(Matrix &B);
        /// @brief количество строк в матрице
        /// @return 
        int rows() const;

        /// @brief количество столбцов в матрице
        /// @return 
        int cols() const;

        /// @brief оператор доступа к элементам матрицы
        /// @param row номер строки
        /// @param col номер столбца
        /// @return элемент матрицы
        real& operator()(int row, int col);

        /// @brief константная версия operator()
        /// @param row номер строки
        /// @param col номер столбца
        /// @return элемент матрицы
        real operator()(int row, int col) const;

        /// @brief перегрузка оператора вывода для печати элементов матрицы в консоль
        friend std::ostream& operator<< (std::ostream &out, const Matrix &matrix);
        
        /// @brief перегрузка оператора ввода размерности матрицы
        friend std::istream& operator>> (std::istream &in, Matrix &matrix);

        /// @brief оператор сложения матриц A и B
        /// @param A 
        /// @param B 
        /// @return 
        friend Matrix operator+(const Matrix& A, const Matrix& B);

        /// @brief оператор вычитания матриц A и B
        /// @param A 
        /// @param B 
        /// @return 
        friend Matrix operator-(const Matrix& A, const Matrix& B);

        /// @brief оператор умножения матриц A и B
        /// @param A 
        /// @param B 
        /// @return 
        friend Matrix operator*(const Matrix& B);

		/// @brief оператор сложения матриц с присваимванием
		/// @param M 
		/// @return 
		Matrix& operator+=(const Matrix& M);

		/// @brief оператор вычитания матриц с присваимванием
		/// @param M 
		/// @return 
		Matrix& operator-=(const Matrix& M);

		/// @brief оператор умножения матрицы на число с присваимванием
		/// @param M 
		/// @return 
		Matrix& operator*=(const real n);
		Matrix& operator*=(const Matrix& B);
        friend Matrix operator*(const Matrix &A, const Matrix &B);

    };

} // namespace math
