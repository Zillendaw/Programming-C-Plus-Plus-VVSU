#include <iostream>
#include <fstream>
#include "templates.h"
#include "BirthDate.h"

using namespace std;

int main()
{
    ifstream file("students.txt");
    if (!file.is_open())
    {
        cout << "Файл не открылся!" << endl;
        return -1;
    }

    char surnames[100][50], names[100][50], patronymics[100][50];
    BirthDate dates[100];
    int heights[100];
    double weights[100];
    int n = 0;

    while (n < 100 && file >> surnames[n] >> names[n] >> patronymics[n] >> dates[n] >> heights[n] >> weights[n])
    {
        n++;
    }
    file.close();

    if (n == 0)
    {
        cout << "Файл пуст или содержит некорректные данные." << endl;
        return 0;
    }

    // Нормативные границы для класса
    BirthDate minDate(1, 6, 2014), maxDate(31, 8, 2014);
    int minHeight = 130, maxHeight = 150;
    double minWeight = 30.0, maxWeight = 45.0;

    // 1. Число людей в файле
    cout << "Число учеников в файле: " << n << endl << endl;

    // 2. Статистика по каждому показателю
    cout << "--- Дата рождения ---" << endl;
    cout << "Минимум: " << minValue(dates, n) << endl;
    cout << "Максимум: " << maxValue(dates, n) << endl;
    cout << "Среднее: " << avgValue(dates, n) << endl;
    cout << "Размах: " << valueRange(dates, n) << endl;
    cout << "В норме (" << minDate << " - " << maxDate << "): "
         << countInRange(dates, n, minDate, maxDate) << " чел." << endl << endl;

    cout << "--- Рост (см) ---" << endl;
    cout << "Минимум: " << minValue(heights, n) << endl;
    cout << "Максимум: " << maxValue(heights, n) << endl;
    cout << "Среднее: " << avgValue(heights, n) << endl;
    cout << "Размах: " << valueRange(heights, n) << endl;
    cout << "В норме (" << minHeight << " - " << maxHeight << "): "
         << countInRange(heights, n, minHeight, maxHeight) << " чел." << endl << endl;

    cout << "--- Масса (кг) ---" << endl;
    cout << "Минимум: " << minValue(weights, n) << endl;
    cout << "Максимум: " << maxValue(weights, n) << endl;
    cout << "Среднее: " << avgValue(weights, n) << endl;
    cout << "Размах: " << valueRange(weights, n) << endl;
    cout << "В норме (" << minWeight << " - " << maxWeight << "): "
         << countInRange(weights, n, minWeight, maxWeight) << " чел." << endl << endl;

    // 3. Список учеников с отклонениями от нормы
    cout << "--- Ученики вне нормативных границ ---" << endl;
    bool allInNorm = true;
    for (int i = 0; i < n; i++)
    {
        bool dateOk = isInRange(dates[i], minDate, maxDate);
        bool heightOk = isInRange(heights[i], minHeight, maxHeight);
        bool weightOk = isInRange(weights[i], minWeight, maxWeight);

        if (!dateOk || !heightOk || !weightOk)
        {
            allInNorm = false;
            cout << surnames[i] << " " << names[i] << " " << patronymics[i] << " (";
            if (!dateOk) cout << "дата: " << dates[i] << "; ";
            if (!heightOk) cout << "рост: " << heights[i] << "; ";
            if (!weightOk) cout << "масса: " << weights[i] << "; ";
            cout << ")" << endl;
        }
    }

    if (allInNorm)
    {
        cout << "Все ученики попадают в норму." << endl;
    }

    return 0;
}
