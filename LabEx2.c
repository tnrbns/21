/* 
Rubinos, Tyna - BSCS II
Exercise #2 - Recursion
User is given three options:
1. Division - divides two positive integers from user
2. Relatively prime - checks if two integers are relatively prime
3. Integer check - user inputs A amount of integers (in ascending order) and checks if integer N is one of them
All solutions will be implemented using recursion.
*/

#include <stdio.h>
#define MAX_SIZE 20
int int_array[MAX_SIZE];                                        

/* User options */
void user_choose();
/* Division functions */                                     
void divide_input();
int divide(int dividend, int divisor);
/* Relative primality functions */
void gcd_input();
int gcd(int n1, int n2);
/* Integer check functions */
void integer_check_input();
void integer_check_add_elements(int size, int i);
int integer_check(int size, int n, int i);

int main(){
    printf("Options: \n");
    printf("1. Division \n");
    printf("2. Relative primality \n");
    printf("3. Check an integer from a list \n");
    user_choose();
    getchar();
    return 0;
}

void user_choose(){
    int user_input;
    printf("Choose input: ");
    scanf("%d", &user_input);
    getchar();

    switch(user_input){
        case 1:
            divide_input();
            break;
        case 2:
            gcd_input();
            break;
        case 3:
            integer_check_input();
            break;
        default:
            printf("Invalid input. Try again.\n");
            user_choose();
            break;
    }    
}

void divide_input(){
    int x,y;
    printf("Input two positive integers: ");
    scanf("%d %d", &x, &y);
    getchar();
    
    if(x<0 || y<0){
        printf("Integers must be positive. Try again. \n");
        divide_input();
    }
    else if (y==0){
        printf("Dividing by zero is undefined. Try again. \n");
        divide_input();
    }
    else{
        printf("%d",divide(x,y));
    }
}

int divide(int dividend, int divisor){
    if(dividend<divisor)
        return 0;
    else
        return 1 + divide(dividend-divisor, divisor);    
}

void gcd_input(){
    int x,y;
    printf("Input two integers: ");
    scanf("%d %d", &x, &y);
    getchar();

    abs(x), abs(y);
    if(x>y){
        printf("%d",gcd(x,y));
    }
    else{
        printf("%d",gcd(y,x));
    }
}

int gcd(int n1, int n2){
   int r = n1%n2;
    if(n2==1 && r==0){
        return 1;
    }
    else if(n2!=1 && r==0){
        return 0;
    }
   return gcd(n2, r);
}

void integer_check_input(){
    int x;
    printf("Input number of integers (2-20): ");
    scanf("%d", &x);
    getchar();
    
    if(x<2 || x>20){
        printf("Minimum of 2 and maximum of 20 integers only. Try again. \n");
        integer_check_input();
    }
    
    integer_check_add_elements(x,0);
}

void integer_check_add_elements(int size, int i){
    if (i<size){
        printf("Input integer no. %d (in ascending order): ",i+1);
        scanf("%d", &int_array[i]);
            if (int_array[i]<int_array[i-1]){
                printf("Invalid input. Please input integers in ascending order.\n");
                integer_check_add_elements(size,i);
            }
            else
                integer_check_add_elements(size,i+1);    
    }
    else{
        int n;
        printf("Input integer to find: ");
        scanf("%d", &n);
        getchar();

        int to_check = integer_check(size, n, 0);
        printf("%d", to_check);
    }        
}

int integer_check(int size, int n, int i){
    if ((int_array[i]!=n && i < size))
        return integer_check(size, n, i+1);
    else if ((int_array[i]!=n && i == size))
        return 0;
    else
        return 1;        
} 