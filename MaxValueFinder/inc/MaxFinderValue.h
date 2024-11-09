#ifndef MAXFINDERVALUE_H
#define MAXFINDERVALUE_H

#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Finds the maximum floating-point value in a file.
 * 
 * This function reads from a file containing floating-point numbers and determines 
 * the maximum value. It also checks for syntax errors and empty file conditions 
 * by setting the provided flags.
 * 
 * @param file Pointer to an open file stream for reading.
 * @param errorflag_syntax Pointer to a boolean flag. Set to `true` if a syntax error 
 * (non-numeric data) is found in the file.
 * @param errorflag_empty Pointer to a boolean flag. Set to `true` if the file is empty
 * or contains no valid numbers.
 * 
 * @return The maximum floating-point value found in the file. If the file is empty 
 * or contains no valid numbers, returns the lowest possible double value, and 
 * `errorflag_empty` is set to `true`.
 */
double fMax(FILE *file, bool *errorflag_syntax, bool *errorflag_empty);

#endif // MAXFINDERVALUE_H
