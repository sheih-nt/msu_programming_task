#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef TASK1
#include "MaxFinderValue.h"
#endif

#ifdef TASK2
#include "PressureCheck.h"
#endif

/**
 * @brief Обработка файла. Определяет, какую задачу выполнять.
 *
 * @param filename Имя файла для обработки.
 * @return int 0 если успешно, 1 при ошибке.
 */
int process(const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        return 1;
    }

#ifdef TASK1
    bool errorflag_syntax = false;
    bool errorflag_empty = false;
    double max_value = fMax(file, &errorflag_syntax, &errorflag_empty);
    fclose(file);

    if (errorflag_empty) {
        printf("Error: File is empty.\n");
        return 1;
    } else if (errorflag_syntax) {
        printf("Error: Invalid syntax.\n");
        return 1;
    }

    printf("Max value: %.2f\n", max_value);
    return 0;
#endif

#ifdef TASK2
    bool syntax_error = false;
    bool empty_file = false;
    bool is_critical = check_pressure(file, &syntax_error, &empty_file);
    fclose(file);

    if (empty_file) {
        printf("Error: File is empty.\n");
        return 1;
    }
    if (syntax_error) {
        printf("Error: Invalid syntax.\n");
        return 1;
    }

    if (is_critical) {
        printf("Critical pressure change detected.\n");
    } else {
        printf("Pressure remains normal.\n");
    }

    return 0;
#endif
}

/**
 * @brief Основная функция программы.
 *
 * В режиме `SELFTEST` запускает тесты, в противном случае работает в ручном режиме.
 *
 * @return int 0 если успешно, 1 при ошибке.
 */
int main(void) {
#ifdef TASK1
#ifdef SELFTEST
    printf("Running Tests for TASK1:\n");

    printf("Test 1\n");
    if (process("test/global/test1.txt") == 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
    }

    printf("Test Error Open Test2\n");
    if (process("test/global/test2.txt") != 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
    }

    printf("Test Empty File\n");
    if (process("test/global/test_empty.txt") != 0) { 
        printf(" [OK]\n");
    } else { 
        printf(" [FAIL]\n"); 
    }

    printf("Test Invalid Syntax\n");
    if (process("test/global/test_invalid.txt") != 0) { 
        printf(" [OK]\n");
    } else { 
        printf(" [FAIL]\n"); 
    }

    printf("Test Float Edge Cases\n");
    if (process("test/test_float_edge_cases.txt") == 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
    }
    return 0;
#endif
#endif

#ifdef TASK2
#ifdef SELFTEST
    printf("Running Tests for TASK2:\n");

    printf("Test Normal Pressure\n");
    if (process("test/global/test_normal.txt") == 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
    }

    printf("Test Error Open\n");
    if (process("test/global/test_nonexistent.txt") != 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
    }

    printf("Test Empty File\n");
    if (process("test/global/test_empty.txt") != 0) { 
        printf(" [OK]\n");
    } else { 
        printf(" [FAIL]\n"); 
    }

    printf("Test Invalid Syntax\n");
    if (process("test/global/test_invalid.txt") != 0) { 
        printf(" [OK]\n");
    } else { 
        printf(" [FAIL]\n"); 
    }

    printf("Test Critical Pressure\n");
    if (process("test/global/test_critical.txt") == 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
    }
    return 0;
#endif
#endif

    // Manual input mode
    char filename[256];
    printf("Enter the filename: ");
    if (scanf("%255s", filename) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    return process(filename);
}
