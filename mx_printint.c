#include "maze.h"

void mx_printint(int n) {
    int i=1;
    char c;

    if (n < 0) {
        n = -n;
        mx_printchar('-');
    }
    while (i*10<=n && i<1000000000) {
        i*=10;
    }
    while (i >= 1) {
        c=0;

        while (i <= n) {
            n-=i;
            c++;
        }
        mx_printchar(c+48);
        i/=10;
    }
}
