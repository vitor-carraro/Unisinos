#include <stdio.h>

int main(){

    int x = 2, *p;

    p = &x;
    *p = 6;

    printf("%d", x);
}