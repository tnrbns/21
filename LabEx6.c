/* 
Rubinos, Tyna - BSCS II
Exercise #6 - Snakes and Ladders
Create a 10x10 snakes and ladders game using pointer arithmetic
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Initialize array */
char a_moves[100], b_moves[100], c_moves[100], d_moves[100], ladders[100], snakes[100];
int s1_head, s2_head, s3_head, s1_tail, s2_tail, s3_tail, 
l1_top, l2_top, l3_top, l1_bottom, l2_bottom, l3_bottom, 
roll, a_pos = 0, b_pos = 0, c_pos = 0, d_pos = 0;

/* Functions */
int die();
void print_board();
void whitespace();
void randomize_snl();
void play_game();
void a_plays();
void b_plays();
void c_plays();
void d_plays();

int main(){
    srand(time(NULL));

    /* Add whitespace to boards */
    whitespace();

    /* Placing snakes and ladders in the board */
    randomize_snl();

    /* Print board and play game */
    printf("********* Snakes and Ladders ng Kahirapan *********\n");

    print_board();
    play_game();
    getchar();
    return 0;
}

int die(){
    return (1 + (rand() % 6));
}

/* Randomizing snake position
    Check if:
    (1) Snake heads (S) are in same positions 
    (2) Snake tails (s) are in same positions
    (3) Ladder bottoms (L) are in same position
    (4) Ladder tops (l) are in same position
    (5) Snakes and ladders are in same position
    (6) Snake tails (s) are placed higher than OR equal to snake heads (S)
    (7) Ladder tops (l) are placed lower than OR equal to ladder bottom (L)
*/
void randomize_snl(){
    s1_head = 2 + (rand() % 97);
    s2_head = 2 + (rand() % 97);
    s3_head = 2 + (rand() % 97);
    s1_tail = 2 + (rand() % 97);
    s2_tail = 2 + (rand() % 97);
    s3_tail = 2 + (rand() % 97);

    l1_bottom = 2 + (rand() % 97);
    l2_bottom = 2 + (rand() % 97);
    l3_bottom = 2 + (rand() % 97);
    l1_top = 2 + (rand() % 97);
    l2_top = 2 + (rand() % 97);
    l3_top = 2 + (rand() % 97);
    
    if (s1_head==s2_head || s1_head==s3_head || s2_head==s3_head)
        randomize_snl();
    else if (s1_tail==s2_tail || s1_tail==s3_tail || s2_head==s3_tail)       
        randomize_snl();
    else if (l1_bottom==l2_bottom || l1_bottom==l3_bottom || l2_bottom==l3_bottom)
        randomize_snl();
    else if (l1_top==l2_top || l1_top==l3_top || l2_bottom==l3_top)
        randomize_snl();
    else if (s1_head==l1_bottom || s1_head==l2_bottom || s1_head==l3_bottom || s1_head==l1_top || s1_head==l2_top || s1_head==l3_top)
        randomize_snl();
    else if (s2_head==l1_bottom || s2_head==l2_bottom || s2_head==l3_bottom || s2_head==l1_top || s2_head==l2_top || s2_head==l3_top)
        randomize_snl();
    else if (s3_head==l1_bottom || s3_head==l2_bottom || s3_head==l3_bottom || s3_head==l1_top || s3_head==l2_top || s3_head==l3_top)
        randomize_snl();     
    else if (s1_tail==l1_bottom || s1_tail==l2_bottom || s1_tail==l3_bottom || s1_tail==l1_top || s1_tail==l2_top || s1_tail==l3_top)
        randomize_snl();
    else if (s2_tail==l1_bottom || s2_tail==l2_bottom || s2_tail==l3_bottom || s2_tail==l1_top || s2_tail==l2_top || s2_tail==l3_top)
        randomize_snl();
    else if (s3_tail==l1_bottom || s3_tail==l2_bottom || s3_tail==l3_bottom || s3_tail==l1_top || s3_tail==l2_top || s3_tail==l3_top)
        randomize_snl();     
    else if (s1_tail >= s1_head || s2_tail >= s2_head || s3_tail >= s3_head )
        randomize_snl();
    else if (l1_bottom >= l1_top || l2_bottom >= l2_top || l3_bottom >= l3_top )
        randomize_snl();
    else{
        *(snakes+s1_head)='S';
        *(snakes+s2_head)='S';
        *(snakes+s3_head)='S';
        *(snakes+s1_tail)='s';
        *(snakes+s2_tail)='s';
        *(snakes+s3_tail)='s';
        *(ladders+l1_bottom)='L';
        *(ladders+l2_bottom)='L';
        *(ladders+l3_bottom)='L';
        *(ladders+l1_top)='l';
        *(ladders+l2_top)='l';
        *(ladders+l3_top)='l';
    }
}

/* Add whitespace to board */
void whitespace(){
    for (int i = 0; i < 100; i++)
    {
        *(ladders+i)= ' ';
        *(snakes+i)= ' ';        
    };
     
    for (int i = 1; i < 100; i++)
    {
        *(a_moves+i)=' ';
        *(b_moves+i)=' ';
        *(c_moves+i)=' ';
        *(d_moves+i)=' ';
    };

    *a_moves = 'a';
    *b_moves = 'b';
    *c_moves = 'c';
    *d_moves = 'd';
}

void play_game(){
    while (1){
        a_plays();
            if (a_pos==99)
                break;
        b_plays();
            if (b_pos==99)
                break;
        c_plays();
            if (c_pos==99)
                break;
        d_plays();
            if (d_pos==99)
                break;
    }
    if (a_pos==99)
        printf("\na wins!\n");
    else if (b_pos==99)
        printf("\nb wins!\n");
    else if (c_pos==99)
        printf("\nc wins!\n");
    else if (d_pos==99)
        printf("\nd wins!\n");    
}

/* Player move set for a, b, c, d
Do the following:
1. Roll the die.
2. Original position must be set to ' ' (empty). 
3. Original position + roll be set to 'a' to indicate movement).
4. Print roll.
    4a. If move == snake, go down and print dialog
    4b. If move == ladder, go up and print dialog
*/
void a_plays(){
    printf("\na's turn.\na, press <Enter> to roll.");
    getchar();
    roll = die();

    *(a_moves+a_pos) = ' ';
    a_pos += roll;
    *(a_moves+a_pos) = 'a';
    
    printf("\na rolls a %d!\n", roll);
    
    if (a_pos==s1_head||a_pos==s2_head||a_pos==s3_head){
        printf("a lands on a snake and goes down!\n");
        *(a_moves+a_pos) = ' ';

            if (a_pos==s1_head){
                *(a_moves+s1_tail) = 'a';
                a_pos = s1_tail;
            }
            else if (a_pos==s2_head){
                *(a_moves+s2_tail) = 'a';
                a_pos = s2_tail;
            }         
            else if (a_pos==s3_head){
                *(a_moves+s3_tail) = 'a';
                a_pos = s3_tail;
            }
    }
    else if (a_pos==l1_bottom||a_pos==l2_bottom||a_pos==l3_bottom){
        printf("a lands on a ladder and goes up!\n");
        *(a_moves+a_pos) = ' ';

            if(a_pos==l1_bottom){
                *(a_moves+l1_top) = 'a';
                a_pos = l1_top;
            }
             else if (a_pos==l2_bottom){
                *(a_moves+l2_top) = 'a';
                a_pos = l2_top;
            } 
            else if (a_pos==l3_bottom){
                *(a_moves+l3_top) = 'a';
                a_pos = l3_top;
            }
    }  
    else if (a_pos>99){
        printf("a's roll amounts to more than 100, so a must stay in place!\n");
        *(a_moves+a_pos) = ' ';
        *(a_moves+(a_pos-roll)) = 'a';

        a_pos -= roll;
    }
    getchar();
    printf("\n");
    print_board();  
}

void b_plays(){
    printf("\nb's turn.\nb, press <Enter> to roll.");
    getchar();
    roll = die();

    *(b_moves+b_pos) = ' ';
    b_pos += roll;
    *(b_moves+b_pos) = 'b';
    
    printf("\nb rolls a %d!\n", roll);
    
    if (b_pos==s1_head||b_pos==s2_head||b_pos==s3_head){
        printf("b lands on a snake and goes down!\n");
        *(b_moves+b_pos) = ' ';

            if (b_pos==s1_head){
                *(b_moves+s1_tail) = 'b';
                b_pos = s1_tail;
            }
            else if (b_pos==s2_head){
                *(b_moves+s2_tail) = 'b';
                b_pos = s2_tail;
            }         
            else if (b_pos==s3_head){
                *(b_moves+s3_tail) = 'b';
                b_pos = s3_tail;
            }
    }
    else if (b_pos==l1_bottom||b_pos==l2_bottom||b_pos==l3_bottom){
        printf("b lands on a ladder and goes up!\n");
        *(b_moves+b_pos) = ' ';

            if(b_pos==l1_bottom){
                *(b_moves+l1_top) = 'b';
                b_pos = l1_top;
            }
             else if (b_pos==l2_bottom){
                *(b_moves+l2_top) = 'b';
                b_pos = l2_top;
            } 
            else if (b_pos==l3_bottom){
                *(b_moves+l3_top) = 'b';
                b_pos = l3_top;
            }
    }  
    else if (b_pos>99){
        printf("b's roll amounts to more than 100, so b must stay in place!\n");
        *(b_moves+b_pos) = ' ';
        *(b_moves+(b_pos-roll)) = 'b';

        b_pos -= roll;
    }
    getchar();
    printf("\n");
    print_board();  
}

void c_plays(){
    printf("\nc's turn.\nc, press <Enter> to roll.");
    getchar();
    roll = die();

    *(c_moves+c_pos) = ' ';
    c_pos += roll;
    *(c_moves+c_pos) = 'c';
    
    printf("\nc rolls a %d!\n", roll);
    
    if (c_pos==s1_head||c_pos==s2_head||c_pos==s3_head){
        printf("c lands on a snake and goes down!\n");
        *(c_moves+c_pos) = ' ';

            if (c_pos==s1_head){
                *(c_moves+s1_tail) = 'c';
                c_pos = s1_tail;
            }
            else if (c_pos==s2_head){
                *(c_moves+s2_tail) = 'c';
                c_pos = s2_tail;
            }         
            else if (c_pos==s3_head){
                *(c_moves+s3_tail) = 'c';
                c_pos = s3_tail;
            }
    }
    else if (c_pos==l1_bottom||c_pos==l2_bottom||c_pos==l3_bottom){
        printf("c lands on a ladder and goes up!\n");
        *(c_moves+c_pos) = ' ';

            if(c_pos==l1_bottom){
                *(c_moves+l1_top) = 'c';
                c_pos = l1_top;
            }
             else if (c_pos==l2_bottom){
                *(c_moves+l2_top) = 'c';
                c_pos = l2_top;
            } 
            else if (c_pos==l3_bottom){
                *(c_moves+l3_top) = 'c';
                c_pos = l3_top;
            }
    }  
    else if (c_pos>99){
        printf("c's roll amounts to more than 100, so c must stay in place!\n");
        *(c_moves+c_pos) = ' ';
        *(c_moves+(c_pos-roll)) = 'c';

        c_pos -= roll;
    }
    getchar();
    printf("\n");
    print_board();  
}

void d_plays(){
    printf("\nd's turn.\nd, press <Enter> to roll.");
    getchar();
    roll = die();

    *(d_moves+d_pos) = ' ';
    d_pos += roll;
    *(d_moves+d_pos) = 'd';
    
    printf("\nd rolls a %d!\n", roll);
    
    if (d_pos==s1_head||d_pos==s2_head||d_pos==s3_head){
        printf("d lands on a snake and goes down!\n");
        *(d_moves+d_pos) = ' ';

            if (d_pos==s1_head){
                *(d_moves+s1_tail) = 'd';
                d_pos = s1_tail;
            }
            else if (d_pos==s2_head){
                *(d_moves+s2_tail) = 'd';
                d_pos = s2_tail;
            }         
            else if (d_pos==s3_head){
                *(d_moves+s3_tail) = 'd';
                d_pos = s3_tail;
            }
    }
    else if (d_pos==l1_bottom||d_pos==l2_bottom||d_pos==l3_bottom){
        printf("d lands on a ladder and goes up!\n");
        *(d_moves+d_pos) = ' ';

            if(d_pos==l1_bottom){
                *(d_moves+l1_top) = 'd';
                d_pos = l1_top;
            }
             else if (d_pos==l2_bottom){
                *(d_moves+l2_top) = 'd';
                d_pos = l2_top;
            } 
            else if (d_pos==l3_bottom){
                *(d_moves+l3_top) = 'd';
                d_pos = l3_top;
            }
    }  
    else if (d_pos>99){
        printf("d's roll amounts to more than 100, so d must stay in place!\n");
        *(d_moves+d_pos) = ' ';
        *(d_moves+(d_pos-roll)) = 'd';

        d_pos -= roll;
    }
    getchar();
    printf("\n");
    print_board();  
}

/* I am so sorry */
void print_board(){
    /* 99 - 90 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|#   |%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+98),*(snakes+98),
    *(ladders+97),*(snakes+97),
    *(ladders+96),*(snakes+96),
    *(ladders+95),*(snakes+95),
    *(ladders+94),*(snakes+94),
    *(ladders+93),*(snakes+93),
    *(ladders+92),*(snakes+92),
    *(ladders+91),*(snakes+91),
    *(ladders+90),*(snakes+90));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+99),*(b_moves+99),*(c_moves+99),*(d_moves+99),
    *(a_moves+98),*(b_moves+98),*(c_moves+98),*(d_moves+98),
    *(a_moves+97),*(b_moves+97),*(c_moves+97),*(d_moves+97),
    *(a_moves+96),*(b_moves+96),*(c_moves+96),*(d_moves+96),
    *(a_moves+95),*(b_moves+95),*(c_moves+95),*(d_moves+95),
    *(a_moves+94),*(b_moves+94),*(c_moves+94),*(d_moves+94),
    *(a_moves+93),*(b_moves+93),*(c_moves+93),*(d_moves+93),
    *(a_moves+92),*(b_moves+92),*(c_moves+92),*(d_moves+92),
    *(a_moves+91),*(b_moves+91),*(c_moves+91),*(d_moves+91),
    *(a_moves+90),*(b_moves+90),*(c_moves+90),*(d_moves+90));
    
    /* 80 - 89 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+80),*(snakes+80),
    *(ladders+81),*(snakes+81),
    *(ladders+82),*(snakes+82),
    *(ladders+83),*(snakes+83),
    *(ladders+84),*(snakes+84),
    *(ladders+85),*(snakes+85),
    *(ladders+86),*(snakes+86),
    *(ladders+87),*(snakes+87),
    *(ladders+88),*(snakes+88),
    *(ladders+89),*(snakes+89));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+80),*(b_moves+80),*(c_moves+80),*(d_moves+80),
    *(a_moves+81),*(b_moves+81),*(c_moves+81),*(d_moves+81),
    *(a_moves+82),*(b_moves+82),*(c_moves+82),*(d_moves+82),
    *(a_moves+83),*(b_moves+83),*(c_moves+83),*(d_moves+83),
    *(a_moves+84),*(b_moves+84),*(c_moves+84),*(d_moves+84),
    *(a_moves+85),*(b_moves+85),*(c_moves+85),*(d_moves+85),
    *(a_moves+86),*(b_moves+86),*(c_moves+86),*(d_moves+86),
    *(a_moves+87),*(b_moves+87),*(c_moves+87),*(d_moves+87),
    *(a_moves+88),*(b_moves+88),*(c_moves+88),*(d_moves+88),
    *(a_moves+89),*(b_moves+89),*(c_moves+89),*(d_moves+89));
    
    /* 79 - 70 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+79),*(snakes+79),
    *(ladders+78),*(snakes+78),
    *(ladders+77),*(snakes+77),
    *(ladders+76),*(snakes+76),
    *(ladders+75),*(snakes+75),
    *(ladders+74),*(snakes+74),
    *(ladders+73),*(snakes+73),
    *(ladders+72),*(snakes+72),
    *(ladders+71),*(snakes+71),
    *(ladders+70),*(snakes+70));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+79),*(b_moves+79),*(c_moves+79),*(d_moves+79),
    *(a_moves+78),*(b_moves+78),*(c_moves+78),*(d_moves+78),
    *(a_moves+77),*(b_moves+77),*(c_moves+77),*(d_moves+77),
    *(a_moves+76),*(b_moves+76),*(c_moves+76),*(d_moves+76),
    *(a_moves+75),*(b_moves+75),*(c_moves+75),*(d_moves+75),
    *(a_moves+74),*(b_moves+74),*(c_moves+74),*(d_moves+74),
    *(a_moves+73),*(b_moves+73),*(c_moves+73),*(d_moves+73),
    *(a_moves+72),*(b_moves+72),*(c_moves+72),*(d_moves+72),
    *(a_moves+71),*(b_moves+71),*(c_moves+71),*(d_moves+71),
    *(a_moves+70),*(b_moves+70),*(c_moves+70),*(d_moves+70));

    /* 60 - 69 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+60),*(snakes+60),
    *(ladders+61),*(snakes+61),
    *(ladders+62),*(snakes+62),
    *(ladders+63),*(snakes+63),
    *(ladders+64),*(snakes+64),
    *(ladders+65),*(snakes+65),
    *(ladders+66),*(snakes+66),
    *(ladders+67),*(snakes+67),
    *(ladders+68),*(snakes+68),
    *(ladders+69),*(snakes+69));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+60),*(b_moves+60),*(c_moves+60),*(d_moves+60),
    *(a_moves+61),*(b_moves+61),*(c_moves+61),*(d_moves+61),
    *(a_moves+62),*(b_moves+62),*(c_moves+62),*(d_moves+62),
    *(a_moves+63),*(b_moves+63),*(c_moves+63),*(d_moves+63),
    *(a_moves+64),*(b_moves+64),*(c_moves+64),*(d_moves+64),
    *(a_moves+65),*(b_moves+65),*(c_moves+65),*(d_moves+65),
    *(a_moves+66),*(b_moves+66),*(c_moves+66),*(d_moves+66),
    *(a_moves+67),*(b_moves+67),*(c_moves+67),*(d_moves+67),
    *(a_moves+68),*(b_moves+68),*(c_moves+68),*(d_moves+68),
    *(a_moves+69),*(b_moves+69),*(c_moves+69),*(d_moves+69));
   
    /* 59 - 50 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+59),*(snakes+59),
    *(ladders+58),*(snakes+58),
    *(ladders+57),*(snakes+57),
    *(ladders+56),*(snakes+56),
    *(ladders+55),*(snakes+55),
    *(ladders+54),*(snakes+54),
    *(ladders+53),*(snakes+53),
    *(ladders+52),*(snakes+52),
    *(ladders+51),*(snakes+51),
    *(ladders+50),*(snakes+50));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+59),*(b_moves+59),*(c_moves+59),*(d_moves+59),
    *(a_moves+58),*(b_moves+58),*(c_moves+58),*(d_moves+58),
    *(a_moves+57),*(b_moves+57),*(c_moves+57),*(d_moves+57),
    *(a_moves+56),*(b_moves+56),*(c_moves+56),*(d_moves+56),
    *(a_moves+55),*(b_moves+55),*(c_moves+55),*(d_moves+55),
    *(a_moves+54),*(b_moves+54),*(c_moves+54),*(d_moves+54),
    *(a_moves+53),*(b_moves+53),*(c_moves+53),*(d_moves+53),
    *(a_moves+52),*(b_moves+52),*(c_moves+52),*(d_moves+52),
    *(a_moves+51),*(b_moves+51),*(c_moves+51),*(d_moves+51),
    *(a_moves+50),*(b_moves+50),*(c_moves+50),*(d_moves+50));
    
    /* 40 - 49 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+40),*(snakes+40),
    *(ladders+41),*(snakes+41),
    *(ladders+42),*(snakes+42),
    *(ladders+43),*(snakes+43),
    *(ladders+44),*(snakes+44),
    *(ladders+45),*(snakes+45),
    *(ladders+46),*(snakes+46),
    *(ladders+47),*(snakes+47),
    *(ladders+48),*(snakes+48),
    *(ladders+49),*(snakes+49));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+40),*(b_moves+40),*(c_moves+40),*(d_moves+40),
    *(a_moves+41),*(b_moves+41),*(c_moves+41),*(d_moves+41),
    *(a_moves+42),*(b_moves+42),*(c_moves+42),*(d_moves+42),
    *(a_moves+43),*(b_moves+43),*(c_moves+43),*(d_moves+43),
    *(a_moves+44),*(b_moves+44),*(c_moves+44),*(d_moves+44),
    *(a_moves+45),*(b_moves+45),*(c_moves+45),*(d_moves+45),
    *(a_moves+46),*(b_moves+46),*(c_moves+46),*(d_moves+46),
    *(a_moves+47),*(b_moves+47),*(c_moves+47),*(d_moves+47),
    *(a_moves+48),*(b_moves+48),*(c_moves+48),*(d_moves+48),
    *(a_moves+49),*(b_moves+49),*(c_moves+49),*(d_moves+49));

    /* 39 - 30 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+39),*(snakes+39),
    *(ladders+38),*(snakes+38),
    *(ladders+37),*(snakes+37),
    *(ladders+36),*(snakes+36),
    *(ladders+35),*(snakes+35),
    *(ladders+34),*(snakes+34),
    *(ladders+33),*(snakes+33),
    *(ladders+32),*(snakes+32),
    *(ladders+31),*(snakes+31),
    *(ladders+30),*(snakes+30));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+39),*(b_moves+39),*(c_moves+39),*(d_moves+39),
    *(a_moves+38),*(b_moves+38),*(c_moves+38),*(d_moves+38),
    *(a_moves+37),*(b_moves+37),*(c_moves+37),*(d_moves+37),
    *(a_moves+36),*(b_moves+36),*(c_moves+36),*(d_moves+36),
    *(a_moves+35),*(b_moves+35),*(c_moves+35),*(d_moves+35),
    *(a_moves+34),*(b_moves+34),*(c_moves+34),*(d_moves+34),
    *(a_moves+33),*(b_moves+33),*(c_moves+33),*(d_moves+33),
    *(a_moves+32),*(b_moves+32),*(c_moves+32),*(d_moves+32),
    *(a_moves+31),*(b_moves+31),*(c_moves+31),*(d_moves+31),
    *(a_moves+30),*(b_moves+30),*(c_moves+30),*(d_moves+30));

    /* 20 - 29 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+20),*(snakes+20),
    *(ladders+21),*(snakes+21),
    *(ladders+22),*(snakes+22),
    *(ladders+23),*(snakes+23),
    *(ladders+24),*(snakes+24),
    *(ladders+25),*(snakes+25),
    *(ladders+26),*(snakes+26),
    *(ladders+27),*(snakes+27),
    *(ladders+28),*(snakes+28),
    *(ladders+29),*(snakes+29));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+20),*(b_moves+20),*(c_moves+20),*(d_moves+20),
    *(a_moves+21),*(b_moves+21),*(c_moves+21),*(d_moves+21),
    *(a_moves+22),*(b_moves+22),*(c_moves+22),*(d_moves+22),
    *(a_moves+23),*(b_moves+23),*(c_moves+23),*(d_moves+23),
    *(a_moves+24),*(b_moves+24),*(c_moves+24),*(d_moves+24),
    *(a_moves+25),*(b_moves+25),*(c_moves+25),*(d_moves+25),
    *(a_moves+26),*(b_moves+26),*(c_moves+26),*(d_moves+26),
    *(a_moves+27),*(b_moves+27),*(c_moves+27),*(d_moves+27),
    *(a_moves+28),*(b_moves+28),*(c_moves+28),*(d_moves+28),
    *(a_moves+29),*(b_moves+29),*(c_moves+29),*(d_moves+29));

    /* 19 - 10 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders+19),*(snakes+19),
    *(ladders+18),*(snakes+18),
    *(ladders+17),*(snakes+17),
    *(ladders+16),*(snakes+16),
    *(ladders+15),*(snakes+15),
    *(ladders+14),*(snakes+14),
    *(ladders+13),*(snakes+13),
    *(ladders+12),*(snakes+12),
    *(ladders+11),*(snakes+11),
    *(ladders+10),*(snakes+10));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves+19),*(b_moves+19),*(c_moves+19),*(d_moves+19),
    *(a_moves+18),*(b_moves+18),*(c_moves+18),*(d_moves+18),
    *(a_moves+17),*(b_moves+17),*(c_moves+17),*(d_moves+17),
    *(a_moves+16),*(b_moves+16),*(c_moves+16),*(d_moves+16),
    *(a_moves+15),*(b_moves+15),*(c_moves+15),*(d_moves+15),
    *(a_moves+14),*(b_moves+14),*(c_moves+14),*(d_moves+14),
    *(a_moves+13),*(b_moves+13),*(c_moves+13),*(d_moves+13),
    *(a_moves+12),*(b_moves+12),*(c_moves+12),*(d_moves+12),
    *(a_moves+11),*(b_moves+11),*(c_moves+11),*(d_moves+11),
    *(a_moves+10),*(b_moves+10),*(c_moves+10),*(d_moves+10));

    /* 0 - 9 */
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    printf("|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|%c  %c|\n", 
    *(ladders),*(snakes),
    *(ladders+1),*(snakes+1),
    *(ladders+2),*(snakes+2),
    *(ladders+3),*(snakes+3),
    *(ladders+4),*(snakes+4),
    *(ladders+5),*(snakes+5),
    *(ladders+6),*(snakes+6),
    *(ladders+7),*(snakes+7),
    *(ladders+8),*(snakes+8),
    *(ladders+9),*(snakes+9));
    printf("|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|%c%c%c%c|\n",
    *(a_moves),*(b_moves),*(c_moves),*(d_moves),
    *(a_moves+1),*(b_moves+1),*(c_moves+1),*(d_moves+1),
    *(a_moves+2),*(b_moves+2),*(c_moves+2),*(d_moves+2),
    *(a_moves+3),*(b_moves+3),*(c_moves+3),*(d_moves+3),
    *(a_moves+4),*(b_moves+4),*(c_moves+4),*(d_moves+4),
    *(a_moves+5),*(b_moves+5),*(c_moves+5),*(d_moves+5),
    *(a_moves+6),*(b_moves+6),*(c_moves+6),*(d_moves+6),
    *(a_moves+7),*(b_moves+7),*(c_moves+7),*(d_moves+7),
    *(a_moves+8),*(b_moves+8),*(c_moves+8),*(d_moves+8),
    *(a_moves+9),*(b_moves+9),*(c_moves+9),*(d_moves+9));
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
}; 