#ifndef PRESSURE_CHECK_H
#define PRESSURE_CHECK_H

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Проверяет критические изменения атмосферного давления.
 *
 * Читает из файла значения изменений давления и определяет, присутствует ли критическое падение или превышение.
 * Критическим считается падение ниже 637.55 мм рт. ст., превышение выше 814.27 мм рт. ст.,
 * или два последовательных изменения более 10 мм рт. ст.
 *
 * @param file Указатель на файл с данными.
 * @param syntax_error Флаг синтаксической ошибки.
 * @param empty_file Флаг пустого файла.
 * @return true если обнаружено критическое изменение давления, иначе false.
 */
bool check_pressure(FILE *file, bool *syntax_error, bool *empty_file);

#endif // PRESSURE_CHECK_H
