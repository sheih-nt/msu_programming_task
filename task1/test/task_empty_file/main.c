#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> // Для использования bool, true, false
#include "../../inc/fMax.h"

/**
 * @brief Основная функция программы.
 *
 * Эта функция инициализирует флаги ошибок, открывает файл с числами
 * и вызывает функцию fMax для нахождения максимального значения.
 * Выводит соответствующие сообщения об ошибках, если это необходимо.
 *
 * @return int Код завершения программы.
 */
int main(void)
{
    // Инициализация флагов
    errorflag_sintax = false;
    errorflag_empty = false;

    FILE *file = fopen("numbers.txt", "r"); // Открытие файла
    if (file == NULL)
    {
        printf("Open error.\n");
        return 1;
    }

    int max_value = fMax(file); // Вызов функции fMax

    if (errorflag_empty)
    {
        printf("File is empty.\n");
        return 1;
    }
    else if (errorflag_sintax)
    {
        printf("Invalid syntax.\n");
        return 1;
    }

    printf("Max value: %d\n", max_value); // Вывод максимального значения
    fclose(file); // Закрытие файла
    return 0;
}
