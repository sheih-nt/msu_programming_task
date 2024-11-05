#include "MaxValueFinder.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @brief Processes the specified file to find the maximum floating-point value.
 * 
 * This function opens a file, reads floating-point numbers, and finds the maximum value.
 * It also handles error checking for syntax issues and empty files.
 * 
 * @param filename Name of the file to be processed.
 * @return int 0 if successful, 1 if an error occurred.
 */
int process(const char* filename) {
    FILE *file;
    bool errorflag_syntax = false;
    bool errorflag_empty = false;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s.\n", filename);
        return 1;
    }

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
}

/**
 * @brief Main function for running tests or manual file input.
 * 
 * If the `SELFTEST` flag is defined, runs a series of automated tests on specific files.
 * Otherwise, prompts the user for a filename to process manually.
 * 
 * @return int 0 if successful, 1 if an error occurred in any test.
 */
int main(void) {
#ifdef SELFTEST
    printf("Running Tests:\n");

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

#else
    // Manual input mode
    char filename[256];
    printf("Enter the filename: ");
    if (scanf("%255s", filename) != 1) {
        printf("Error: Invalid input.\n");
        return 1;
    }
    return process(filename);
#endif
}
