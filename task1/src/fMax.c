#include "../inc/fMax.h"
#include <stdlib.h>
#include <limits.h>
#include <ctype.h> // Для функции isdigit
#include <stdbool.h> // Для использования bool, true, false

bool errorflag_sintax = false; // Инициализация флагов
bool errorflag_empty = false;   // Инициализация флагов

/**
 * @brief Реализует функцию fMax.
 *
 * Эта функция читает строки из файла и пытается преобразовать
 * их в целые числа, чтобы найти максимальное значение. Если
 * встречается некорректный синтаксис, устанавливается флаг
 * errorflag_sintax. Если файл пустой, устанавливается
 * errorflag_empty.
 *
 * @param file Указатель на файл, из которого читаются числа.
 * @return int Максимальное значение из файла.
 */
int fMax(FILE *file)
{
    int max_value = INT_MIN;    // Инициализация максимального значения
    int current_value;           // Текущее значение
    int has_numbers = 0;         // Флаг наличия чисел
    char current_str[20];        // Строка для хранения текущего значения

    while (fscanf(file, "%s", current_str) == 1)
    {
        int is_number = 1; // Предполагаем, что в current_str число
        for (int i = 0; current_str[i] != '\0'; i++)
        {
            if (!isdigit(current_str[i]) && !(i == 0 && current_str[i] == '-')) // Проверка на отрицательное число
            {
                is_number = 0;
                break;
            }
        }

        if (!is_number)
        {
            errorflag_sintax = true;
            return 0;
        }

        current_value = atoi(current_str); // Преобразование строки в число

        if (current_value > max_value)
        {
            max_value = current_value; // Обновление максимального значения
        }
        has_numbers = 1;
    }

    if (has_numbers)
    {
        return max_value; // Возвращаем максимальное значение
    }
    else
    {
        errorflag_empty = true; // Установка флага пустого файла
    }
    return 0; // Возвращаем 0, если файла нет
}
