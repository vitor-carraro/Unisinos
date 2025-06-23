#include <stdio.h>

void main() {

    int a = 3, b = 2, *p = NULL, *q = NULL;

    p = &a;
    q = p;
    *q = *q + 1;
    q = &b;
    b = b + 1;
    
    printf("%d\n", *q);
    printf("%d\n", *p);
}