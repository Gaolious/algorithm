#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// to make DESC
// 121132
//    ^ 
// 
// wlneeb
//
int setNext(char str[], int n)
{
    char c;
    int l = n-1;
    int r = n-1;
    // 122341
    //   ^
    while ( l > 0 && str[l-1] >= str[l] ) l--;
    if ( l == 0 )
        return 0;
    
    while ( str[l-1] >= str[r] ) r--;
    
    c=str[r];str[r]=str[l-1];str[l-1]=c;
    
    for ( r = n-1 ; l < r ; l++, r--)
    {
        c = str[r];
        str[r] = str[l];
        str[l] = c;
    }
    return 1;
}
void input(FILE *fp)
{
    char str[1024]= {0,};

    while ( fscanf(fp, "%s ", str) == 1 )
    {
        if (strcmp(str, "#") == 0 )
            break;
        if (setNext(str, strlen(str)))
            printf("%s\n", str);
        else
            printf("No Successor\n");
    }
}
int main()
{
#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input.txt", "rt");
#endif
    input(fp);

#ifdef ONLINE_JUDGE
#else
    if ( fp ) fclose(fp);
#endif

    return 0;
}
