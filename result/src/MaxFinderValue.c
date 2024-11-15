#include "MaxFinderValue.h"
#include <stdlib.h>
#include <float.h>

double fMax(FILE *file, bool *errorflag_syntax, bool *errorflag_empty) {
    double max_value = -DBL_MAX;
    double current_value;
    char ch;

    *errorflag_syntax = false;
    *errorflag_empty = true;

    while (fscanf(file, "%lf", &current_value) == 1) {
        if (!*errorflag_empty) {
            if (current_value > max_value) {
                max_value = current_value;
            }
        } else {
            max_value = current_value;
            *errorflag_empty = false;
        }
    }

    // Проверка на синтаксические ошибки
    if ((ch = fgetc(file)) != EOF) {
        ungetc(ch, file);
        *errorflag_syntax = true;
    }

    return max_value;
}