#include "maze.h"

t_linked_list *mx_create_node(t_pos pos, int distance) {
    t_linked_list *dee = malloc(sizeof(t_linked_list));
    dee->pos = malloc(sizeof(t_pos));
    dee->pos->x = pos.x;
    dee->pos->y = pos.y;
    dee->distance = malloc(sizeof(distance));
    *(dee->distance) = distance;
    dee->prev = (t_linked_list *)0;
    return dee;
}
