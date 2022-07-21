/* 
Rubinos, Tyna - BSCS II
Exercise #10 - Zodiac signs
Given a birth year, month and day, display the zodiac sign and print out a fortune. 
Fortunes are read from the data.for file, and must not be repeated. Horoscope tips courtesy of Vogue's website.
Dates will be added in data.in. 
*/
#include <stdio.h>
#include <string.h>
int month_adjust_common[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int month_adjust_leap[] = {31,29,31,30,31,30,31,31,30,31,30,31};
int zodiac_lines[][5]={
                      {1,13,25,37,49},  // Capricorn
                      {2,14,26,38,50},  // Aquarius
                      {3,15,27,39,51},  // Pisces
                      {4,16,28,40,52},  // Aries
                      {5,17,29,41,53},  // Taurus
                      {6,18,30,42,54},  // Gemini
                      {7,19,31,43,55},  // Cancer
                      {8,20,32,44,56},  // Leo
                      {9,21,33,45,57},  // Virgo
                      {10,22,34,46,58}, // Libra
                      {11,23,35,47,59}, // Scorpio
                      {12,24,36,48,60}, // Sagittarius
                      };
int user_year, user_month, user_day, z_row, z_column, file_month, file_day, file_count = 1;
char line[100], c[10]; 
FILE *fp1, *fp2;

/* Functions */
int is_leap_year(int year);
void user_input();
void zodiac_sign(int m, int d);
void open_file();
void get_horoscope(FILE *fptr);
void tick_off_dates();
void zodiac_check_file(int m, int d);

int main(){
    open_file();    
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

void open_file(){
    fp1 = fopen("data.in", "r");

    if (fgetc(fp1)==EOF) {
        fclose(fp1);
        user_input();
        fp2 = fopen("data.for", "r");
        get_horoscope(fp2);   
        fp1 = fopen("data.in","a");
        fprintf(fp1, "%d-%02d-%02d \n", user_year, user_month, user_day);
        fclose(fp1);
    }
    else {
        tick_off_dates();
        user_input();
        z_column=0;
        fp2 = fopen("data.for", "r");
        get_horoscope(fp2); 
        fp1 = fopen("data.in","a");
        fprintf(fp1, "%d-%02d-%02d \n", user_year, user_month, user_day);
        fclose(fp1);
    }
}

/* Input date or year */
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
    zodiac_sign(user_month,user_day);
    
}

/* Prints zodiac signs */
void zodiac_sign(int m, int d){
    if ((m==12&&d>=22)||(m==1&&d<=19)){
        z_row = 0;
        printf("Capricorn: ");
    }    
    else if ((m==1&&d>=20)||(m==2&&d<=17)){
        z_row = 1;
        printf("Aquarius: ");
    }        
    else if ((m==2&&d>=18)||(m==3&&d<=19)){
        z_row = 2;
        printf("Pisces: ");
    }        
    else if ((m==3&&d>=20)||(m==4&&d<=19)){
        z_row = 3;
        printf("Aries: ");
    }        
    else if ((m==4&&d>=20)||(m==5&&d<=20)){
        z_row = 4;
        printf("Taurus: ");
    }        
    else if ((m==5&&d>=21)||(m==6&&d<=20)){
        z_row = 5;
        printf("Gemini: ");
    }                            
    else if ((m==6&&d>=21)||(m==7&&d<=22)){
        z_row = 6;
        printf("Cancer: ");
    }        
    else if ((m==7&&d>=23)||(m==8&&d<=22)){
        z_row = 7;
        printf("Leo: ");
    }        
    else if ((m==8&&d>=23)||(m==9&&d<=22)){
        z_row = 8;
        printf("Virgo: ");
    }        
    else if ((m==9&&d>=23)||(m==10&&d<=22)){
        z_row = 9;
        printf("Libra: ");  
    }        
    else if ((m==10&&d>=23)||(m==11&&d<=21)){
        z_row = 10;
        printf("Scorpio: ");
    }       
    else if ((m==11&&d>=22)||(m==12&&d<=21)){
        z_row = 11;
        printf("Sagittarius: ");
    }                   
}

/* Prints horoscope* */
void get_horoscope(FILE *fptr){
    while (fgets(line, sizeof line, fp2) != NULL){
        if ((file_count == zodiac_lines[z_row][z_column])&&(zodiac_lines[z_row][z_column]!=0)){
            printf("%s", line);
            fclose(fp2);
        }     
        else if ((file_count<zodiac_lines[z_row][z_column])){
            file_count++;
            get_horoscope(fp2);
        }       
        else if ((zodiac_lines[z_row][z_column] == 0)){
            z_column++;
            get_horoscope(fp2);
        }            
    }  
}

/* Check dates with same zodiac sign */
void tick_off_dates(){
    fscanf(fp1, "%*d-%d-%d", &file_month, &file_day);
    zodiac_check_file(file_month,file_day);
    while(fgets(c, sizeof(c), fp1)!=NULL){
        fscanf(fp1, "%*d-%d-%d", &file_month, &file_day);
        zodiac_check_file(file_month,file_day);
    }
}

/* Check zodiac sign for file */
void zodiac_check_file(int m, int d){
    if ((m==12&&d>=22)||(m==1&&d<=19)){
        z_row = 0;
    }    
    else if ((m==1&&d>=20)||(m==2&&d<=17)){
        z_row = 1;
    }        
    else if ((m==2&&d>=18)||(m==3&&d<=19)){
        z_row = 2;
    }        
    else if ((m==3&&d>=20)||(m==4&&d<=19)){
        z_row = 3;
    }        
    else if ((m==4&&d>=20)||(m==5&&d<=20)){
        z_row = 4;
    }        
    else if ((m==5&&d>=21)||(m==6&&d<=20)){
        z_row = 5;
    }                            
    else if ((m==6&&d>=21)||(m==7&&d<=22)){
        z_row = 6;
    }        
    else if ((m==7&&d>=23)||(m==8&&d<=22)){
        z_row = 7;
    }        
    else if ((m==8&&d>=23)||(m==9&&d<=22)){
        z_row = 8;
    }        
    else if ((m==9&&d>=23)||(m==10&&d<=22)){
        z_row = 9;
    }        
    else if ((m==10&&d>=23)||(m==11&&d<=21)){
        z_row = 10;
    }       
    else if ((m==11&&d>=22)||(m==12&&d<=21)){
        z_row = 11;
    }
    if (zodiac_lines[z_row][z_column]==0){
        z_column++;
        zodiac_check_file(file_month,file_day);
    }
    else{
        zodiac_lines[z_row][z_column] = 0;
    }                  
}