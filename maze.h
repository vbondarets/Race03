#ifndef MAZE_H
#define MAZE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <limits.h>
#include <stdbool.h>

typedef struct s_pos {
    int x;
    int y;
}              t_pos;

typedef struct s_linked_list {
    int *distance;
    t_pos *pos;
    struct s_linked_list *prev;
}              t_linked_list;

int distance (int **array);
int **create_int_array (int height, int length);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printchar(char c);
t_linked_list ***create_list_array(int height, int length);
int mx_array_listing (int **array, t_pos source, t_pos dest);
t_linked_list *mx_create_node(t_pos pos, int distance);
bool mx_isdigit (char c);
bool mx_isspace (char c);
int mx_atoi(const char *str);
void mx_printfile(int descriptor, char c);

#endif //MAZE_H
