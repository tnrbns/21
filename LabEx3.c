/* 
Rubinos, Tyna - BSCS II
Exercise #3 - Tic-Tac-Toe
Implementation of a tic-tac-toe game
*/
#include <stdio.h>
/* Array to store X's and O's */
char tictactoe[][3]={
                         {' ',' ',' '},
                         {' ',' ',' '},
                         {' ',' ',' '}
                        };

/* Count to check number of turns; user inputs for column and row */                        
int count = 1, row_input, column_input;

/* Functions */
void print_tictactoe_board();
void play_tictactoe();
void input_x();
void input_o();
void win_condition();

int main(){
    play_tictactoe();
    getchar();
    return 0;
}

void print_tictactoe_board(){
    printf("\n");
    printf(" %c | %c | %c \n", tictactoe[0][0], tictactoe[0][1], tictactoe[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tictactoe[1][0], tictactoe[1][1], tictactoe[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", tictactoe[2][0], tictactoe[2][1], tictactoe[2][2]);
    printf("\n");
};

/* User input. Odd turns mean X, even turns mean O */
void play_tictactoe(){
    if(count%2 != 0){
        print_tictactoe_board();
        printf("X's turn \n\n");
        input_x();
        win_condition();
    }
    else if(count%2 == 0){
        print_tictactoe_board();
        printf("O's turn \n\n");
        input_o();
        win_condition();
    }
}

/* Puts X in the board */
void input_x(){
    do{
    printf("Row: ");
    scanf("%d", &row_input);
    getchar();
        if(row_input<1||row_input>3){
            printf("Invalid input. Try again.\n");
        }
    }while(row_input<1||row_input>3);

    do{
    printf("Column: ");
    scanf("%d", &column_input);
    getchar();
        if(column_input<1||column_input>3){
            printf("Invalid input. Try again.\n");
        }
    }while(column_input<1||column_input>3);

    if(tictactoe[row_input-1][column_input-1] != ' '){
        printf("(%d, %d) Occupied!\n\n", row_input, column_input);
        input_x();
    }
    else
        tictactoe[row_input-1][column_input-1] = 'X';
}

/* Puts O in the board */
void input_o(){
    do{
    printf("Row: ");
    scanf("%d", &row_input);
    getchar();
        if(row_input<1||row_input>3){
            printf("Invalid input. Try again.\n");
        }
    }while(row_input<1||row_input>3);

    do{
    printf("Column: ");
    scanf("%d", &column_input);
    getchar();
        if(column_input<1||column_input>3){
            printf("Invalid input. Try again.\n");
        }
    }while(column_input<1||column_input>3);

    if(tictactoe[row_input-1][column_input-1] != ' '){
        printf("(%d, %d) Occupied!\n\n", row_input, column_input);
        input_o();
    }
    else
        tictactoe[row_input-1][column_input-1] = 'O';
}

void win_condition(){
    /* Vertical win for X */
    if((tictactoe[0][0] == 'X' && tictactoe[1][0] == 'X' && tictactoe[2][0] == 'X')||(tictactoe[0][1] == 'X' && tictactoe[1][1] == 'X' && tictactoe[2][1] == 'X')||(tictactoe[0][2] == 'X' && tictactoe[1][2] == 'X' && tictactoe[2][2] == 'X'))
        printf("\nX wins!");
    /* Horizontal win for X */        
    else if((tictactoe[0][0] == 'X' && tictactoe[0][1] == 'X' && tictactoe[0][2] == 'X')||(tictactoe[1][0] == 'X' && tictactoe[1][1] == 'X' && tictactoe[1][2] == 'X')||(tictactoe[2][0] == 'X' && tictactoe[2][1] == 'X' && tictactoe[2][2] == 'X'))
        printf("\nX wins!");   
    /* Diagonal win for X */
    else if((tictactoe[0][0] == 'X' && tictactoe[1][1] == 'X' && tictactoe[2][2] == 'X')||(tictactoe[0][2] == 'X' && tictactoe[1][1] == 'X' && tictactoe[2][0] == 'X'))
        printf("\nX wins!"); 
    /* Vertical win for O */
    else if((tictactoe[0][0] == 'O' && tictactoe[1][0] == 'O' && tictactoe[2][0] == 'O')||(tictactoe[0][1] == 'O' && tictactoe[1][1] == 'O' && tictactoe[2][1] == 'O')||(tictactoe[0][2] == 'O' && tictactoe[1][2] == 'O' && tictactoe[2][2] == 'O'))
        printf("\nO wins!");
    /* Horizontal win for O */        
    else if((tictactoe[0][0] == 'O' && tictactoe[0][1] == 'O' && tictactoe[0][2] == 'O')||(tictactoe[1][0] == 'O' && tictactoe[1][1] == 'O' && tictactoe[1][2] == 'O')||(tictactoe[2][0] == 'O' && tictactoe[2][1] == 'O' && tictactoe[2][2] == 'O'))
        printf("\nO wins!");   
    /* Diagonal win for O */
    else if((tictactoe[0][0] == 'O' && tictactoe[1][1] == 'O' && tictactoe[2][2] == 'O')||(tictactoe[0][2] == 'O' && tictactoe[1][1] == 'O' && tictactoe[2][0] == 'O'))
        printf("\nO wins!"); 
    /* Draw */
    else if(count==9)
        printf("\nIt's a draw!");
    /* Number of turns is less than 9, continues the game */        
    else {
        count++;
        play_tictactoe();
    }
}