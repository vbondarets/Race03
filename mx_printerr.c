#include "maze.h"

void mx_printerr(const char *s) {
    write(STDOUT_FILENO, s, mx_strlen(s));
}
