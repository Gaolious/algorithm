#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

const char *monthNameList[] = {
    "",
    "January", "February", "March",
    "April", "May", "June", 
    "July", "August", "September",
    "October", "November", "December"
};

const char *weekNameList[] = {
    "Sunday", 
    "Monday", 
    "Tuesday", 
    "Wednesday", 
    "Thursday", 
    "Friday", 
    "Saturday"
};
int getWeekNo(char weekname[])
{
    int i;

    for ( i = 0 ; i < 7 ; i ++ )
        if ( strncmp( weekname, weekNameList[i] , 2) == 0 )
            return i;
    return -1;
}

int getmonth(char monthname[])
{
    int i;

    for ( i = 1 ; i <= 12 ; i ++ )
        if ( strncmp( monthname, monthNameList[i] , 3) == 0 )
            return i;
    return 0;
}
int is_leap(int year, int is_old)
{

    if ( year % 4 != 0 ) return 0;
    if ( !is_old )
    {
        if ( year % 100 == 0 )
        {
            if ( year % 400 == 0 ) return 1;
            else return 0;
        }
    }
    return 1;
}
int total_days(int year, int month, int day, int is_old)
{
    int days = 0;
    int yester_year = year - 1;

    days = ( yester_year ) * 365;
    days += is_leap(year, is_old) ? leap_months[ month - 1 ] : months[ month - 1 ] ;
    days += day;
    days += yester_year / 4 ;

    if ( !is_old )
    {
        days -= yester_year / 100 ;
        days += yester_year / 400 ;
    }

    return days;
}

void getYMD(int total_days, int &year, int &month, int &day, int is_old)
{
    int is_correct = 0;
    int yester_year = (int)( total_days / 365 ) - 1 ;
    int days ;
    int i;

    while ( is_correct == 0 )
    {
        days = total_days;
        days -= yester_year * 365  + yester_year / 4;
        if ( !is_old )
        {
            days += yester_year / 100;
            days -= yester_year / 400;
        }

        if ( days <= 0 ) 
        {
            yester_year --;
            continue;
        }

        int *pMonth = is_leap(yester_year + 1, is_old ) ? (int *)leap_months : (int *)months ;

        for ( i = 1 ; i <= 12 ; i ++ )
        {
            if ( pMonth[i] >= days )
            {
                year = yester_year + 1 ;
                month = i;
                day = days - pMonth[i-1] ;
                return;
            }
        }

        yester_year ++;
        continue;
    }
}

void process(FILE *fp)
{
    char weekname[100], monthname[100];
    int year, month, day, weekno;
    int days ;

    int y1, m1, d1, t;

    // // old
    // year = 1582, month = 10, day = 5;
    // days = total_days( year, month, day, 1);
    // printf("Input : %d %d %d (%d : %d)\n", year, month, day, days, days % 7);
    // // new 
    // year = 1582, month = 10, day = 15;
    // days = total_days( year, month, day, 0);
    // printf("Input : %d %d %d (%d : %d)\n", year, month, day, days, days % 7);
    // return;
    // 2 days .

    while ( fscanf(fp, "%s ", weekname) == 1 && weekname[0] != '#' &&
        fscanf(fp, "%d %s %d ", &day, monthname, &year ) == 3 )
    {
        
        weekno = getWeekNo(weekname);
        month = getmonth(monthname);
        
        days = total_days( year, month, day, 1) - 2 ;
        // printf("Input : %d %d %d (%d : %d)\n", year, month, day, days, days % 7);
        if ( weekno == days % 7 )
        {
            getYMD(days, y1, m1, d1, 0);
            t = total_days(y1, m1, d1, 0) ;
            // old style -> new style
            printf("%s %d %s %d\n", weekNameList[ t % 7 ], d1, monthNameList[ m1 ], y1 );
        }
        else
        {
            // new style -> old style
            days = total_days( year, month, day, 0) + 2;
            getYMD(days, y1, m1, d1, 1);
            t = total_days(y1, m1, d1, 1) - 2;
            printf("%s %d* %s %d\n", weekNameList[ t % 7 ], d1, monthNameList[ m1 ], y1);
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