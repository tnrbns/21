/* 
Rubinos, Tyna - BSCS II
Exercise #4 - Object counting
Given an N x M grid, program must count the number of objects found in that grid
*/
#include <stdio.h>
#define MAX_SIZE 500

/* Functions */
void user_input();
void count_grid(int x,int y,int c);

int x_direct[8] = {-1,0,1,1,1,0,-1,-1};
int y_direct[8] = {1,1,1,0,-1,-1,-1,0};
int to_label[MAX_SIZE][MAX_SIZE] = {0};
int create_grid[MAX_SIZE][MAX_SIZE] = {0};
int row, column, count = 1;

int main(){
    user_input();
    printf("Number of Objects: %d", count-1);
    getchar();
    return 0;
}

/* User inputs the grid */
void user_input(){
    do{
    printf("Input rows and columns: ");
    scanf("%d %d", &row, &column);    
    if(row<1||column<1)
        printf("Invalid input. Try again.\n");
    }while(row<1||column<1);
    
    create_grid[row][column];
    printf("Print grid: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &create_grid[i][j]);
        }
    }

     for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= column; j++)
        {
             if(create_grid[i][j] && !to_label[i][j]) 
                count_grid(i,j,count++);
        }
    }
}

/* Check for 8-pixel connectivity */
void count_grid(int x,int y,int c){
    to_label[x][y] = c;
    for (int i = 0; i < 8;i++)
    {
        int convert_x = x+x_direct[i], convert_y = y+y_direct[i];

        if(create_grid[convert_x][convert_y] && !to_label[convert_x][convert_y]) 
            count_grid(convert_x,convert_y,c);
    }
}