#include "MaxValueFinder.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int process(const char* filename) {
    FILE *file;
    bool errorflag_syntax = false;
    bool errorflag_empty = false;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        return 1;
    }

    double max_value = MaxValueFinder(file, &errorflag_syntax, &errorflag_empty);
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
}

int main(void) {
#ifdef SELFTEST
    // Запуск автотестов
    printf("Test 1\n");
    if (process("test/global/test1.txt") == 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
        return 1;
    }

    printf("Test 2\n");
    if (process("test/global/test2.txt") == 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
        return 1;
    }

    printf("Test Empty File\n");
    if (process("test/task_empty_file/test_empty.txt") != 0) { 
        printf(" [OK]\n");
    } else { 
        printf(" [FAIL]\n"); 
        return 1; 
    }

    printf("Test Invalid Syntax\n");
    if (process("test/task_invalid_syntax/test_invalid.txt") != 0) { 
        printf(" [OK]\n");
    } else { 
        printf(" [FAIL]\n"); 
        return 1; 
    }

    printf("Test Float Edge Cases\n");
    if (process("test/task_float_edge_cases/test_float_edge_cases.txt") == 1) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
        return 1;
    }

    printf("Test Empty String Case\n");
    if (process("test/task_invalid_cases/test_empty_string.txt") != 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
        return 1;
    }

    printf("Test Multiple Dots Case\n");
    if (process("test/task_invalid_cases/test_multiple_dots.txt") != 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
        return 1;
    }

    printf("Test Invalid Character 'e' Case\n");
    if (process("test/task_invalid_cases/test_invalid_character_e.txt") != 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
        return 1;
    }

    printf("Test Exponent Without Digit Case\n");
    if (process("test/task_invalid_cases/test_exponent_no_digit.txt") != 0) {
        printf(" [OK]\n");
    } else {
        printf(" [FAIL]\n");
        return 1;
    }
#else
    // Ручной запуск с пользовательским вводом
    char filename[256];
    printf("Enter the filename: ");
    if (scanf("%255s", filename) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    return process(filename);
#endif
}
