#include "maze.h"

int **create_int_array (int height, int length) {
    int i;
    int **array = malloc(sizeof(int *) * (height+1));

    for (i = 0; i < height; i++) {
        array[i] = malloc(sizeof(int) * (length+1));
        array[i][length] = -1;
    }
    array[height] = malloc(sizeof(int) * (length+1));
    for (i = 0; i < length+1; i++)
        array[height][i] = -1;
    return array;
}
