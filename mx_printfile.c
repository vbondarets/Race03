#include "maze.h"

void mx_printfile(int descriptor, char c) {
    write(descriptor, &c, 1);
}
