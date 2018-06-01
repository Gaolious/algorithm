#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _color
{
    char type ;
} COLOR;
typedef struct _city
{
    // TYPE plastic, glass, aluminium, steel, newspaper;
    COLOR r, o, y, g, b ;
} CITY;

void parse(char str[], CITY *pCity )
{
    char *pStr = (char *)str;

    while ( *pStr && *pStr != '\n' )
    {
        while ( *pStr == ' ' ) pStr ++;
        COLOR *pColor = NULL ;

        switch ( *pStr )
        {
            case 'r' : pColor = &(pCity->r); break;
            case 'o' : pColor = &(pCity->o); break;
            case 'y' : pColor = &(pCity->y); break;
            case 'g' : pColor = &(pCity->g); break;
            case 'b' : pColor = &(pCity->b); break;
        }
        pStr ++;

        if ( !pColor ) continue ;
        while ( *pStr == ' ' || *pStr == '/' ) pStr ++;
        
        pColor->type = *pStr ;
        pStr++;
        while ( *pStr == ' ' || *pStr == ','|| *pStr == '\n' ) pStr ++;
    }
}

void process(FILE *fp)
{
    char str[10000];

    while ( fgets(str, sizeof(str)-1, fp ) && str[0] != '#' )
    {
        CITY city[100 + 1 ]={0,};
        int nCity = 0 ;

        while (str[0] != 'e')
        {
            parse( str, city + nCity );
            nCity++;
            fgets(str, sizeof(str)-1, fp );
        }

        int min_changes = -1 ;
        int min_change_index ;
        int changes;
        int i, j;

        for ( i = 0 ; i < nCity ; i ++)
        {
            changes = 0 ;

            for ( j = 0 ; j < nCity ; j ++)
            if ( i != j )
            {
                changes += city[i].r.type != city[j].r.type ? 1 : 0;
                changes += city[i].o.type != city[j].o.type ? 1 : 0;
                changes += city[i].y.type != city[j].y.type ? 1 : 0;
                changes += city[i].g.type != city[j].g.type ? 1 : 0;
                changes += city[i].b.type != city[j].b.type ? 1 : 0;
            }
            if ( min_changes < 0 || changes < min_changes )
            {
                min_change_index = i ;
                min_changes = changes ;
            }
        }

        printf("%d\n", min_change_index + 1);
    }
}

int main()
{

#ifdef ONLINE_JUDGE
    FILE *fp = stdin;
#else
    FILE *fp = fopen("input/input.txt", "rt");
#endif

process(fp);

#ifdef ONLINE_JUDGE
#else
    if (fp)
        fclose(fp);
#endif

}