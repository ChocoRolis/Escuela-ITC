#include <stdio.h>
int main(){
    int x, y, *p, *q;
    p = &x;
    *p = 12;
    q = &y;
    *q = 23;
    printf("%d %d\n", *p, *q);
    *p =*q;
    printf("%d %d\n", *p, *q);
    q = NULL;
    printf("%d\n", *p);
    printf("%d %d\n", x, y);
    return 0;
}