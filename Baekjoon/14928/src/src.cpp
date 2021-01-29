#include <stdio.h>

int main() 
{ 
    char buf[1000000+2];
    int a = 0, N = 20000303;
    fread(buf, 1, sizeof(buf)-1, stdin);
    for ( int i = 0 ; buf[i] >= '0' ; i ++ )
        a = (a * 10 + ( buf[i] - '0')) % N ;

    printf("%d\n", a);
    return 0; 
} 