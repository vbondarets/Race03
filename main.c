#include "maze.h"
//#include "../inc/list.h"

int main (int argc, char *argv[]) {
    int i[3];
    int descriptor;
    int **array;
    char buf;
    //bool pass = false;
    t_pos pos[2];

    if(argc != 6) {
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        exit(0);
    }

    if(mx_atoi(argv[2]) < 0 || mx_atoi(argv[3]) < 0 || mx_atoi(argv[4]) < 0 || mx_atoi(argv[5]) < 0) {
        mx_printerr("points are out of map range\n");
        exit(0);
    }
    

    
    descriptor = open(argv[1], O_RDONLY);
    if (descriptor < 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    argc = 0; /* height */
    i[1] = 0; /* length of current line */
    i[0] = -1; /* length of previous line */
    while ((i[2] = read(descriptor, &buf, 1))) {
        switch (buf) {
            case '#':
            case '.':
                i[1]++;
                break;
            case ',':
                break;
            case '\n':
                if (i[0] != -1 && i[0] != i[1]) {
                    mx_printerr("map error\n");
                    exit (0);
                }
                i[0] = i[1];
                i[1] = 0;
                argc++;
                break;
            default:
                mx_printerr("map error\n");
                exit(0);
                break;
        }
    }
    if (i[0] == 0) { 
        mx_printerr("map does not exist\n");
        exit(0);
    }
    if (close(descriptor) == -1) {
        mx_printerr("error\n");
        exit(0);
    } 
    array = create_int_array(argc, i[0]); /* created the array of the required size */
    descriptor = open(argv[1], O_RDONLY);
    if (descriptor < 0) {
        mx_printerr("map does not exist\n");
        exit(0);
    }
    argc = 0;
    i[1] = 0; /* length of current line */
    i[0] = -1; /* length of previous line */
    while ((i[2] = read(descriptor, &buf, 1))) {
        if (i[2] == -1) {
            mx_printerr("error\n");
            exit(0);
        }
        switch (buf) {
            case '#':
                array[argc][i[1]] = 0;
                i[1]++;
                break;
            case '.':
                array[argc][i[1]] = 1;
                i[1]++;
                break;
            case ',':
                break;
            case '\n':
                i[0] = i[1];
                i[1] = 0;
                argc++;
                break;
            default:
                break;
        }
    }
    if (close(descriptor) == -1) {
        mx_printerr("error\n");
        exit(0);
    } 
    descriptor = i[0];
    if (!array[mx_atoi(argv[5])][mx_atoi(argv[4])]) {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(0);
    }
    if (!array[mx_atoi(argv[3])][mx_atoi(argv[2])]) {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(0);
    }
    /*for (i[0] = 0; i[0] < argc+1; i[0]++) {
        for (i[1] = 0; i[1] < descriptor+1; i[1]++) {
            printf("%d", array[i[0]][i[1]]);
            fflush (stdin);
        }
        putchar('\n');
    }*/
    if (mx_atoi(argv[3]) >= argc ||
        mx_atoi(argv[5]) >= argc ||
        mx_atoi(argv[2]) >= descriptor ||
        mx_atoi(argv[4]) >= descriptor) {
        mx_printerr("points are out of map range\n");
        exit(0);
    }
    pos[0].x = mx_atoi(argv[3]);
    pos[0].y = mx_atoi(argv[2]);
    pos[1].x = mx_atoi(argv[5]);
    pos[1].y = mx_atoi(argv[4]);
    if(!mx_array_listing(array, pos[0], pos[1])) {
        mx_printerr("route not found\n");
        exit(0);
    }
    for (i[0] = 0; i[0] < argc+1; i[0]++) {
        free(array[i[0]]);
    }
    free(array);

    /*if(mx_array_listing(array, pos[0], pos[1]) == false) {
        mx_printerr("route not found");
        exit(0);
    }*/

    
}
