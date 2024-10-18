#include "fMax.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>  // Для isdigit
#include <stdbool.h>  // Для bool, true, false

bool errorflag_syntax = false;  // Флаг синтаксической ошибки
bool errorflag_empty = false;   // Флаг пустого файла

/**
 * @brief Функция для нахождения максимального значения.
 *
 * @param file Указатель на файл
 * @return double Максимальное значение
 */
double fMax(FILE* file)
{
    double max_value = -__DBL_MAX__;  // Минимальное значение для double
    double current_value;
    int has_numbers = 0;  // Флаг наличия чисел
    char current_str[20];

    // Чтение строки из файла
    while (fscanf(file, "%s", current_str) == 1)
    {
        int is_number = 1;
        for (int i = 0; current_str[i] != '\0'; i++)
        {
            if (!isdigit(current_str[i]) && !(i == 0 && current_str[i] == '-')) // Проверка отрицательных чисел
            {
                is_number = 0;
                break;
            }
        }

        if (!is_number)
        {
            errorflag_syntax = true;
            return 0;
        }

        current_value = atof(current_str);  // Преобразование строки в double

        if (current_value > max_value)
        {
            max_value = current_value;
        }
        has_numbers = 1;
    }

    if (!has_numbers)
    {
        errorflag_empty = true;
        return 0;
    }

    return max_value;
}
