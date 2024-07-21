#include <stdio.h>

int Calculator(int *a, int *b){
    return *a+*b;
}

int main() {
    int a=13;
    int b=20;

    Calculator(&a,&b);

    return 0;
}
