#include "PressureCheck.h"
#include <stdlib.h>

#define NORMAL_PRESSURE 760.0
#define LOWER_LIMIT 637.55
#define UPPER_LIMIT 814.27
#define CRITICAL_CHANGE 10.0

bool check_pressure(FILE *file, bool *syntax_error, bool *empty_file) {
    double pressure = NORMAL_PRESSURE;
    double change;
    int consecutive_large_changes = 0;
    bool has_data = false;

    while (true) {
        int result = fscanf(file, "%lf", &change);

        if (result == 1) {  
            has_data = true;
            double new_pressure = pressure + change;

            if (new_pressure < LOWER_LIMIT || new_pressure > UPPER_LIMIT) {
                return true;
            }

            if (abs(change) > CRITICAL_CHANGE) {
                consecutive_large_changes++;
                if (consecutive_large_changes >= 2) {
                    return true;
                }
            } else {
                consecutive_large_changes = 0;
            }

            pressure = new_pressure;
        } else if (result == EOF) {  
            break;
        } else {  
            *syntax_error = true;
            return false;
        }
    }

    if (!has_data) {
        *empty_file = true;
        return false;
    }

    if (ferror(file)) {  
        *syntax_error = true;
    }

    return false;
}
