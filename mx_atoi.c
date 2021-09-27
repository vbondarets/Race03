#include "maze.h"

int mx_atoi (const char *str) {
    int i;
    int start = -1, end = -1;
    long int returned = 0, retun;
    bool minus = false;

    for (i = 0; str[i]; i++) {
        if (mx_isspace(str[i]))
            continue;
        if (mx_isdigit(str[i])) {
            start = i;
            break;
        } else {
            if (str[i] == '-') {
            minus = true;
            } else {
                return 0;
            }
        }
    }

    for (i = start; str[i]; i++) {
        if (mx_isdigit(str[i]))
            end = i;
        else 
            break;
    }

    for (i = end; i >= start; i--) {
            retun = 1;
        for (int j = 0; j < end - i ; j++)
            retun*=10; 
        returned += (str[i]-48)*retun;
    }
    if (minus) 
        returned = -returned;
    return (int)returned;
}
