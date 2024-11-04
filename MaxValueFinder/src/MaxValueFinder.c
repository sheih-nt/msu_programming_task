#include "MaxValueFinder.h"
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool is_valid_float(const char* str) {
    int len = strlen(str);
    bool has_dot = false;
    bool has_digit = false;
    bool has_exponent = false;
    int i = 0;

    if (len == 0) {
        return false;
    }

    if (str[0] == '-') {
        if (len == 1) {
            return false;
        }
        i = 1;
    }

    for (; i < len; i++) {
        if (str[i] == '.') {
            if (has_dot || has_exponent) {
                return false;
            }
            has_dot = true;
        } else if (str[i] == 'e' || str[i] == 'E') {
            if (has_exponent || !has_digit) {
                return false;
            }
            has_exponent = true;
            has_digit = false;
        } else if (str[i] >= '0' && str[i] <= '9') {
            has_digit = true;
        } else if (str[i] == '-' && (str[i - 1] == 'e' || str[i - 1] == 'E')) {
            if (i + 1 >= len || (str[i + 1] < '0' || str[i + 1] > '9')) {
                return false;
            }
        } else {
            return false;
        }
    }

    return has_digit;
}

double MaxValueFinder(FILE *file, bool *errorflag_syntax, bool *errorflag_empty) {
    char buffer[100];
    double max_value = -__DBL_MAX__;
    *errorflag_empty = true;

    while (fscanf(file, "%99s", buffer) == 1) {
        if (!is_valid_float(buffer)) {
            *errorflag_syntax = true;
            return 0.0;
        }
        *errorflag_empty = false;

        double value = atof(buffer);
        if (value > max_value) {
            max_value = value;
        }
    }

    return max_value;
}
