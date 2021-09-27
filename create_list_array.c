#include "maze.h"

t_linked_list ***create_list_array(int height, int length) {
    int i;
    int j;
    t_linked_list ***list = malloc(sizeof(t_linked_list **) * (height+1));

    for (i = 0; i < height; i++) {
        list[i] = malloc(sizeof(t_linked_list *) * (length+1));
        list[i][length] = (t_linked_list *)0;
    }
    list[height] = malloc(sizeof(t_linked_list *) * (length+1));
    for (i = 0; i < length+1; i++)
        list[height][i] = (t_linked_list *)0;
    for (i = 0; i < height; i++) 
        for (j = 0; j < length; j++)
            list[i][j] = (t_linked_list *)1;
    return list;
}
