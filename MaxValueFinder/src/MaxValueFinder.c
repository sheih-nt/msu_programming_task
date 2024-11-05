#include "MaxValueFinder.h"
#include <stdlib.h>
#include <float.h>

/**
 * @brief Finds the maximum floating-point number in a file.
 * 
 * This function reads a file containing floating-point numbers, identifying
 * the maximum value in the file. It also sets error flags to indicate if the 
 * file is empty or contains invalid syntax (non-numeric characters after the 
 * initial sequence of numbers).
 * 
 * @param file Pointer to an open file stream for reading.
 * @param errorflag_syntax Pointer to a boolean flag that is set to `true` if 
 * non-numeric characters are encountered after the initial numeric sequence, 
 * indicating a syntax error.
 * @param errorflag_empty Pointer to a boolean flag that is set to `true` if 
 * the file is empty or contains no valid numbers.
 * 
 * @return The maximum floating-point value found in the file. If the file is empty
 * or contains no valid numbers, returns a minimum floating-point value, and 
 * `errorflag_empty` is set to `true`.
 */
double fMax(FILE *file, bool *errorflag_syntax, bool *errorflag_empty) {
    double max_value = -DBL_MAX; ///< Initialize max_value to the lowest possible double value.
    double current_value;
    *errorflag_syntax = false; ///< Initialize syntax error flag to false.
    *errorflag_empty = true; ///< Initialize empty file flag to true.

    // Read numbers from the file
    while (fscanf(file, "%lf", &current_value) == 1) { 
        if (!*errorflag_empty) { ///< If the file has valid numbers.
            if (current_value > max_value) { 
                max_value = current_value; ///< Update max_value if current_value is greater.
            }
        } else {
            max_value = current_value; ///< Set max_value to the first valid number.
            *errorflag_empty = false; ///< File is not empty as a valid number was found.
        }
    }

    // Check for syntax errors (non-numeric characters left in the file)
    char ch;
    if ((ch = fgetc(file)) != EOF) { 
        ungetc(ch, file); ///< Push back character if a non-numeric is found.
        *errorflag_syntax = true; ///< Set syntax error flag to true.
    }

    return max_value; ///< Return the maximum value found.
}
