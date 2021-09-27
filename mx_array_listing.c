#include "maze.h"

int mx_array_listing (int **array, t_pos source, t_pos dest) {
    int i[8];
    t_linked_list ***list_array;
    t_pos cur;
    bool flag;

    for (i[0] = 0; array[i[0]][0] != -1; i[0]++) {}
    for (i[1] = 0; array[0][i[1]] != -1; i[1]++) {}
    list_array = create_list_array(i[0], i[1]);
    list_array[source.x][source.y] = mx_create_node(source, 0);
    i[4] = 0;
    while (true) {
        flag = false;
        for (i[2] = 0; i[2] < i[0]; i[2]++) { //all cols
            for (i[3] = 0; i[3] < i[1]; i[3]++) { //all rows
                if (list_array[i[2]][i[3]] && //if not null
                    list_array[i[2]][i[3]] != (t_linked_list *)1 && //if exists
                    *list_array[i[2]][i[3]]->distance == i[4]) { //if correct iteration
                    if (--i[2] > -1 &&
                        array[i[2]][i[3]] == 1 &&
                        list_array[i[2]][i[3]] == (t_linked_list *)1) {
                        flag = true;
                        cur.x = i[2];
                        cur.y = i[3];
                        list_array[i[2]][i[3]] = mx_create_node(cur, i[4]+1);
                        list_array[i[2]][i[3]]->prev = list_array[i[2]+1][i[3]];
                    }
                    i[2]++;
                    if (++i[3] < i[1] &&
                        array[i[2]][i[3]] == 1 &&
                        list_array[i[2]][i[3]] == (t_linked_list *)1) {
                        flag = true;
                        cur.x = i[2];
                        cur.y = i[3];
                        list_array[i[2]][i[3]] = mx_create_node(cur, i[4]+1);
                        list_array[i[2]][i[3]]->prev = list_array[i[2]][i[3]-1];
                    }
                    i[3]--;
                    if (--i[3] > -1 &&
                        array[i[2]][i[3]] == 1 &&
                        list_array[i[2]][i[3]] == (t_linked_list *)1) {
                        flag = true;
                        cur.x = i[2];
                        cur.y = i[3];
                        list_array[i[2]][i[3]] = mx_create_node(cur, i[4]+1);
                        list_array[i[2]][i[3]]->prev = list_array[i[2]][i[3]+1];
                    }
                    i[3]++;
                    if (++i[2] < i[0] && //if not out of range
                        array[i[2]][i[3]] == 1 && //if free space
                        list_array[i[2]][i[3]] == (t_linked_list *)1) {
                        flag = true;
                        cur.x = i[2];
                        cur.y = i[3];
                        list_array[i[2]][i[3]] = mx_create_node(cur, i[4]+1);
                        list_array[i[2]][i[3]]->prev = list_array[i[2]-1][i[3]];
                    }
                    i[2]--;
                }
            }
        }
        if (flag == false)
            break;
        i[4]++;
    }
    i[4]--;
    for (i[2] = 0; i[2] < i[0]; i[2]++) { //all cols
        for (i[3] = 0; i[3] < i[1]; i[3]++) { //all rows
            if (list_array[i[2]][i[3]] && //if not null
                list_array[i[2]][i[3]] != (t_linked_list *)1 && //if exists
                *list_array[i[2]][i[3]]->distance == i[4]) { //if correct iteration
                if (--i[2] > -1 &&
                    array[i[2]][i[3]] == 1 &&
                    *list_array[i[2]][i[3]]->distance != i[4]-1) {
                    i[7]=*list_array[i[2]][i[3]]->distance;
                    if (array[i[2]][i[3]] == 3)
                        array[i[2]][i[3]] = 4;
                    else
                        array[i[2]][i[3]] = 2;
                }
                i[2]++;
                if (++i[2] < i[0] &&
                    array[i[2]][i[3]] == 1 &&
                    *list_array[i[2]][i[3]]->distance != i[4]-1) {
                    i[7]=*list_array[i[2]][i[3]]->distance;
                    if (array[i[2]][i[3]] == 3)
                        array[i[2]][i[3]] = 4;
                    else
                        array[i[2]][i[3]] = 2;
                }
                i[2]--;
                if (--i[3] > -1 &&
                    array[i[2]][i[3]] == 1 &&
                    *list_array[i[2]][i[3]]->distance != i[4]-1) {
                    i[7]=*list_array[i[2]][i[3]]->distance;
                    if (array[i[2]][i[3]] == 3)
                        array[i[2]][i[3]] = 4;
                    else
                        array[i[2]][i[3]] = 2;
                }
                i[3]++;
                if (++i[3] < i[1] &&
                    array[i[2]][i[3]] == 1 &&
                    *list_array[i[2]][i[3]]->distance != i[4]-1) {
                    i[7]=*list_array[i[2]][i[3]]->distance;
                    if (array[i[2]][i[3]] == 3)
                        array[i[2]][i[3]] = 4;
                    else
                        array[i[2]][i[3]] = 2;
                }
                i[3]--;
            }
        }
    }
    i[4] = -1;
    flag = false;
    for (i[2] = 0; i[2] < i[0]; i[2]++) { //all cols
        for (i[3] = 0; i[3] < i[1]; i[3]++) { //all rows
            if (list_array[i[2]][i[3]] &&
                list_array[i[2]][i[3]] != (t_linked_list *)1 &&
                list_array[i[2]][i[3]]->pos->y == dest.y &&
                list_array[i[2]][i[3]]->pos->x == dest.x) {
                if (!list_array[i[2]][i[3]]->prev) {
                    flag = true;
                    i[4] = 0;
                    break;
                }
                if (array[list_array[i[2]][i[3]]->prev->pos->x][list_array[i[2]][i[3]]->prev->pos->y] == 2) {
                    i[7]=*list_array[i[2]][i[3]]->distance;
                    array[list_array[i[2]][i[3]]->prev->pos->x][list_array[i[2]][i[3]]->prev->pos->y] = 4; //path pos
                }
                else {
                    array[list_array[i[2]][i[3]]->prev->pos->x][list_array[i[2]][i[3]]->prev->pos->y] = 3; //path pos
                    if (i[4] == -1)
                        i[4]=*list_array[i[2]][i[3]]->distance;
                }
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }
    if (!flag)
        return 0;
    if (array[dest.x][dest.y] == 2)
        array[dest.x][dest.y] = 4;
    else array[dest.x][dest.y] = 3;
    i[5] = i[0];
    i[6] = i[1];
    i[0] = list_array[i[2]][i[3]]->pos->x;
    i[1] = list_array[i[2]][i[3]]->pos->y;
    while (list_array[i[0]][i[1]]->prev) {
        i[0] = list_array[i[2]][i[3]]->prev->pos->x;
        i[1] = list_array[i[2]][i[3]]->prev->pos->y;
        if (array[list_array[i[2]][i[3]]->prev->pos->x][list_array[i[2]][i[3]]->prev->pos->y] == 2)
            array[list_array[i[2]][i[3]]->prev->pos->x][list_array[i[2]][i[3]]->prev->pos->y] = 4; //path pos
        else
            array[list_array[i[2]][i[3]]->prev->pos->x][list_array[i[2]][i[3]]->prev->pos->y] = 3; //path pos
        i[2] = i[0];
        i[3] = i[1];
    }
    mx_printstr("dist=");
    mx_printint(i[7]);
    mx_printchar('\n');
    mx_printstr("exit=");
    mx_printint(i[4]);
    mx_printchar('\n');
    array[i[2]][i[3]] = 3; //path pos
    /*
     * 0 is not free #
     * 1 is free .
     * 2 is dest D
     * 3 is path *
     * 4 is X
    */
    /*for (i[0] = 0; i[0] < i[5]; i[0]++) {
     *  for (i[1] = 0; i[1] < i[6]; i[1]++) {
     *      switch (array[i[0]][i[1]]) {
     *          case 0:
     *              mx_printchar('#');
     *              break;
     *          case 4:
     *              mx_printchar('X');
     *              break;
     *          case 3:
     *              mx_printchar('*');
     *              break;
     *          case 2:
     *              mx_printchar('D');
     *              break;
     *          case 1:
     *              mx_printchar('.');
     *              break;
     *          default:
     *              mx_printchar(' ');
     *              break;
     *      }
     *  }
     *  mx_printchar('\n');
    }*/
    for (i[0] = 0; i[0] < i[5]+1; i[0]++) {
        for (i[1] = 0; i[1] < i[6]+1; i[1]++) {
            if (list_array[i[0]][i[1]] && 
                list_array[i[0]][i[1]] != (t_linked_list *)1) {
                free(list_array[i[0]][i[1]]->pos);
                free(list_array[i[0]][i[1]]->distance);
                free(list_array[i[0]][i[1]]);
            }
        }
        free(list_array[i[0]]);
    }
    free(list_array);
    i[4] = open("path.txt", O_WRONLY | O_CREAT, 0770);
    for (i[0] = 0; i[0] < i[5]; i[0]++) {
        for (i[1] = 0; i[1] < i[6]; i[1]++) {
            switch (array[i[0]][i[1]]) {
                case 0:
                    mx_printfile(i[4], '#');
                    break;
                case 4:
                    mx_printfile(i[4], 'X');
                    break;
                case 3:
                    mx_printfile(i[4], '*');
                    break;
                case 2:
                    mx_printfile(i[4], 'D');
                    break;
                case 1:
                    mx_printfile(i[4], '.');
                    break;
                default:
                    mx_printfile(i[4], ' ');
                    break;
            }
        }
        mx_printfile(i[4], '\n');
    }
    close(i[4]);
    return 1;
}
