/* 
Rubinos, Tyna - BSCS II
Exercise #1 - Day of the Week
User inputs date (YYYY MM DD) and must display the day of the week, and its ordinal date of that year.
*/
#include <stdio.h>
/* Variables */
int month_adjust_common[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int month_adjust_leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
int user_year, user_month, user_day;

/* Functions */
void user_input();
int is_leap_year(int year);
int calc_gauss(int year, int month, int day);
void gauss_convert(int gauss);
int calc_nth_day(int year, int month, int day);
void ordinal_date(int nth);

int main(){
    user_input();
    gauss_convert(calc_gauss(user_year,user_month,user_day));
    int nth_day = calc_nth_day(user_year,user_month,user_day);
    printf("the %d",nth_day);
    ordinal_date(nth_day);
    printf(" day of the year");

    getchar();
    return 0;
}

/* Check for leap year */
int is_leap_year(int year){
    int no_of_days;
    if (((year%4==0)&&(year%100==0)&&(year%400==0)) || ((year%4==0)&&(year%100!=0)))
        no_of_days = 366;
    else
        no_of_days = 365;    
    return (no_of_days);
}

/* Input date */
void user_input(){
    do{
        do{
        printf("Input date (YYYY MM DD): ");
        scanf("%d %d %d", &user_year, &user_month, &user_day);
        getchar();
        if (user_month>12||user_month<1)
            printf("Invalid input. Try again.\n");
        else{
            if (((is_leap_year(user_year)==366)&&(user_day>month_adjust_leap[user_month-1]))||((is_leap_year(user_year)==365)&&(user_day>month_adjust_common[user_month-1])))
                printf("Invalid input. Try again.\n");
            else
                break;                
        }            
         }while(((is_leap_year(user_year)==366)&&(user_day>month_adjust_leap[user_month-1]))||((is_leap_year(user_year)==365)&&(user_day>month_adjust_common[user_month-1])));
    
    }while(user_month>12||user_month<1);    
}
/* Gauss algorithm */
int calc_gauss(int year, int month, int day){
    int gauss_leap[] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int gauss_common[] = {0,3,4,0,2,5,0,3,6,1,4,6};
    int gauss_value;

    if (is_leap_year(year)==366){
        gauss_value = (day+gauss_leap[month-1]+(5*((year-1)%4))+(4*((year-1)%100)+(6*((year-1)%400))))%7;
    }
    else if (is_leap_year(year)==365){    
        gauss_value = (day+gauss_common[month-1]+(5*((year-1)%4))+(4*((year-1)%100)+(6*((year-1)%400))))%7;
    }
    return gauss_value;
}

/* Gauss to day */
void gauss_convert(int gauss){
    switch (gauss)
    {
        case 0:
            printf("Sunday, ");
            break;
        case 1:
            printf("Monday, ");
            break;
        case 2:
            printf("Tuesday, ");
            break;
        case 3:
            printf("Wednesday, ");
            break;
        case 4:
            printf("Thursday, ");
            break;                
        case 5:
            printf("Friday, ");
            break;    
        case 6:        
            printf("Saturday, ");
            break; 
        default:
            break;               
    }
}

/* Calculate for nth day */
int calc_nth_day(int year, int month, int day){
    int nth_day=0;
    if (is_leap_year(year)==366){
        for (int i = 1; i < month; i++)
            nth_day += month_adjust_leap[i-1];
    }
    else if (is_leap_year(year)==365){
        for (int i = 1; i < month; i++)
            nth_day += month_adjust_common[i-1];
    }
    return (nth_day+day);
}

/* Insert ordinal */
void ordinal_date(int nth){
    switch (nth%10)
    {
    case 1:
        switch (nth)
        {
        case 11:
            printf("th");
            break;
        default:
            printf("st");
            break;
        }
        break;
    case 2:
        switch (nth)
        {
        case 12:
            printf("th");
            break;
        default:
            printf("nd");
            break;
        }
        break;
    case 3:
        switch (nth)
        {
        case 13:
            printf("th");
            break;
        default:
            printf("rd");
            break;
        }
        break;        
    default:
        printf("th");
        break;
    }
}