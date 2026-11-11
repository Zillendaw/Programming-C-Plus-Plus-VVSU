#include "matrix.h"

Matrix2 multiply(const Matrix2& a, const Matrix2& b)
{
    Matrix2 result;  // все элементы по умолчанию 0/1
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                result.m[i][j] = result.m[i][j] + a.m[i][k] * b.m[k][j];
    return result;
}

Matrix2 transpose(const Matrix2& a)
{
    Matrix2 result;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            result.m[i][j] = a.m[j][i];
    return result;
}

Fraction determinant(const Matrix2& a)
{
    // |a b|
    // |c d|  = a*d - b*c
    return a.m[0][0] * a.m[1][1] - a.m[0][1] * a.m[1][0];
}

std::ostream& operator<<(std::ostream& os, const Matrix2& a)
{
    for (int i = 0; i < N; ++i)
    {
        os << "[ ";
        for (int j = 0; j < N; ++j)
            os << a.m[i][j] << "\t";
        os << "]\n";
    }
    return os;
}
