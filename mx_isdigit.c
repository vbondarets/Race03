#include <stdbool.h>

bool mx_isdigit(char c) {
    if (c > 47 && c < 58)
        return true;
    else
        return false;
}
