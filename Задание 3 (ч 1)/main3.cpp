#include <iostream>
#include <stdexcept>
#include "fraction.h"
#include "matrix.h"

using namespace std;

void testConstructors()
{
    cout << "Запуск конструкторов..." << endl;
    Fraction f0;        // по умолчанию
    Fraction f1(1, 2);  // с параметрами
    Fraction f2(5);     // целое число 5 = 5/1
    cout << "f0 = " << f0 << ", f1 = " << f1 << ", f2 = " << f2 << endl;

    cout << "\nПроверка нулевого знаменателя..." << endl;
    try
    {
        Fraction bad(1, 0);
        cout << "Создана дробь " << bad << endl;  // сюда не дойдём
    }
    catch (const invalid_argument& e)
    {
        cout << "Ошибка: " << e.what() << endl;
    }
}

void testToDoubleAndNormalize()
{
    cout << "\Запуск функций: toDouble" << endl;
    Fraction f(3, 4);
    cout << f << " = " << f.toDouble() << endl;

    cout << "\nЗапуск функций: normalize" << endl;
    Fraction g(4, 8);
    cout << g << " -> ";
    g.normalize();
    cout << g << endl;

    Fraction h(6, -9);
    cout << "6/-9 -> ";
    h.normalize();
    cout << h << endl;
}

void testArithmetic()
{
    Fraction a(1, 2), b(2, 3);

    cout << "\nДробь и дробь:" << endl;
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    cout << "\nДробь и целое:" << endl;
    cout << a << " + 2 = " << a + 2 << endl;
    cout << "3 + " << a << " = " << 3 + a << endl;
    cout << a << " - 1 = " << a - 1 << endl;
    cout << "1 - " << a << " = " << 1 - a << endl;
    cout << b << " * 3 = " << b * 3 << endl;
    cout << "2 * " << a << " = " << 2 * a << endl;
    cout << a << " / 2 = " << a / 2 << endl;
    cout << "2 / " << b << " = " << 2 / b << endl;

    cout << "\nДеление на ноль:" << endl;
    try
    {
        cout << a / 0 << endl;
    }
    catch (const domain_error& e)
    {
        cout << "Ошибка: " << e.what() << endl;
    }
}

void testMatrix()
{
    cout << "\nМатрица 2x2:" << endl;
    Matrix2 A = { { { Fraction(1, 2), Fraction(2, 3) },
                    { Fraction(3, 4), Fraction(1, 5) } } };

    cout << "A =\n" << A;

    Matrix2 AA = multiply(A, A);
    cout << "\nA * A =\n" << AA;

    Matrix2 AAt = multiply(A, transpose(A));
    cout << "\nA * A^T =\n" << AAt;

    Fraction detA = determinant(A);
    cout << "\ndet(A) = " << detA << " = " << detA.toDouble() << endl;

    // Проверка: det(A*A) должен быть равен det(A)^2
    cout << "det(A*A) = " << determinant(AA)
         << ", det(A)^2 = " << detA * detA << endl;
}

int main()
{
    testConstructors();
    testToDoubleAndNormalize();
    testArithmetic();
    testMatrix();
    return 0;
}
