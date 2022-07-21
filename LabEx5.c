/* 
Rubinos, Tyna - BSCS II
Exercise #5 - Sorting
User inputs an integer n, and is asked to input n number of integers. 
Output must be the integers sorted in ascending order, using pointer arithmetic.
*/
#include <stdio.h>

/* Function */
void insertion_sort(int *arr, int length);

int main(){
    /* Input number of integers */
    int x;
    do{
    printf("Input number of integers: ");
    scanf("%d", &x);
    getchar();
    
    if(x<1){
        printf("Invalid input. Try again.\n");
    }
    }while(x<1);
    
    /* Initialize array */ 
    int integer_list[x];

    /* Input integers */
    printf("Input integers: ");
    for (int i = 0; i < x; ++i){
        scanf("%d", (integer_list+i));
    }

    /* Using insertion sort */
    insertion_sort(integer_list,x);

    /* Print sorted integers */
    for (int i = 0; i < x; ++i)
    {
        printf("%d ", *(integer_list+i));
    }    

    return 0;
}

void insertion_sort(int *arr, int length){
    for (int i = 1; i < length; ++i){
        int key = *(arr+i);
        int j = i - 1;

        while (j>=0 && *(arr+j)>key){
            *(arr+j+1) = *(arr+j);
            j = j-1;
        }
       *(arr+j+1) = key;
    }
}