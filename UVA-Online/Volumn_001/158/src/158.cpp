#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <queue>

typedef struct _data_
{
    int day, month, dday ;
    int t_days ;
    char name[256];
} DATA;
std::vector<DATA> data ;
int total_days_today = 0 ;

void trim(char name[])
{
    int len = strlen(name);
    while ( len > 0 && ( name[len-1] == '\n' ) )
        name[--len] = 0x00;
}
int is_leap(int y)
{
    return y % 4 == 0 ;
}
int total_days(int year, int month, int day)
{
    const int months[] = {
        0, 
        31, 59, 90, 120, 151, 
        181, 212, 243, 273, 304, 
        334, 365        
    };
    const int leap_months[] = {
        0, 
        31, 60, 91, 121, 152, 
        182, 213, 244, 274, 305, 
        335, 366
    };

    int days = 0;
    int yester_year = year - 1;

    days = ( yester_year ) * 365;
    days += is_leap(year) ? leap_months[ month - 1 ] : months[ month - 1 ] ;
    days += day;
    days += yester_year / 4 ;
    return days;
}

int comp(const void *a, const void *b)
{
    int n1, n2 ;
    int i = *(int *)a;
    int j = *(int *)b;
    
    if ( data[i].month < data[j].month ) return -1;
    else if ( data[i].month > data[j].month ) return 1;

    if ( data[i].day < data[j].day ) return -1;
    else if ( data[i].day > data[j].day ) return 1;
    
    if ( data[ j ].t_days - total_days_today == 0 &&
    data[ j ].t_days - total_days_today == 0)
        return 0;

    n1 = data[ i ].dday - (data[ i ].t_days - total_days_today);
    n2 = data[ j ].dday - (data[ j ].t_days - total_days_today);

    if ( n1 < n2 ) return 1;
    else if ( n1 > n2 ) return -1;
    else return 0;
}

void print_element(DATA *pData, int month, int day)
{
    int i;
    int star;

    printf("%3d%3d ", pData->day, pData->month);

    star = pData->dday - ( pData->t_days - total_days_today );

    if ( pData->month == month && pData->day == day )
        printf("*TODAY*");
    else
    {
        for ( i = 0 ; i <= star ; i ++ ) printf("*");
        for ( i = 1 ; i < 7 - star ; i ++) printf(" ");
    }
    printf(" %s", pData->name);

    // printf("\tTotal:%6d, today:%6d, diff(%6d)", 
    //     pData->t_days, total_days_today, pData->t_days - total_days_today

    // );

    printf("\n");
}

void print(int year, int month, int day)
{
    total_days_today = total_days(year, month, day);

    printf("Today is:%3d%3d\n", day, month);

    int len_idx = 0 ;
    int i, j;
    int star ;

    std::list<int> today_index ;
    std::list<int> star_index[8] ;

    for ( i = 0 ; i < data.size(); i ++ )
    if ( data[i].t_days - total_days_today <= data[i].dday &&  data[i].t_days >= total_days_today)
    {
        if ( data[i].t_days == total_days_today ) 
            today_index.push_back(i);
        else
            {
                star = data[ i ].dday - (data[ i ].t_days - total_days_today);
                star_index[ star ].push_back(i);
            }
    }

    for ( std::list<int>::iterator a = today_index.begin() ; a != today_index.end() ; a ++ )
    {
        i = *a ;
        print_element( &(data[i]), month, day );
    }

    for ( j = 7 ; j >=0 ; j -- )
    for ( std::list<int>::iterator a = star_index[j].begin() ; a != star_index[j].end() ; a ++ )
    {
        i = *a ;
        print_element( &(data[i]), month, day );
    }
}

void process(FILE *fp)
{
    int year ;
    char cmd ;
    int f =0 ;

    fscanf(fp, "%d ", &year);

    while ( fscanf(fp, "%c ", &cmd) == 1 && cmd != '#' )
    {
        if ( cmd == 'A' )
        {
            DATA d ;

            fscanf(fp, "%d %d %d ", &d.day, &d.month, &d.dday );
            fgets(d.name, sizeof(d.name)-1, fp);
            trim(d.name);
            d.t_days = total_days(year, d.month, d.day);
            data.push_back(d);

            d.t_days = total_days(year+1, d.month, d.day);            
            data.push_back(d);
        }
        else if ( cmd == 'D' )
        {
            int day, month ;

            fscanf(fp, "%d %d ", &day, &month );
            if ( f != 0 ) printf("\n");
            else f=1;
            print(year, month, day);
        }
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