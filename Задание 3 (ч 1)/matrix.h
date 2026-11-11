#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "fraction.h"

const int N = 2;

// Матрица 2x2 из дробей, хранится в виде двумерного массива
struct Matrix2
{
    Fraction m[N][N];
};

Matrix2 multiply(const Matrix2& a, const Matrix2& b);  // произведение
Matrix2 transpose(const Matrix2& a);                   // транспонирование
Fraction determinant(const Matrix2& a);                // определитель

std::ostream& operator<<(std::ostream& os, const Matrix2& a);

#endif // MATRIX_H
