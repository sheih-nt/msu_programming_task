#include "PressureCheck.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Обработка файла для проверки давления.
 *
 * Открывает файл, читает данные и определяет, есть ли критические изменения давления.
 * Обрабатывает ошибки синтаксиса и пустого файла.
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
}

int main(void) {
#ifdef SELFTEST
    // Автоматические тесты
    printf("Running Tests:\n");

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

#else
    char filename[256];
    printf("Enter the filename: ");
    if (scanf("%255s", filename) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    return process(filename);
#endif
}
