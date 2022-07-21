/* 
Rubinos, Tyna - BSCS II
Exercise #7 - Fractions
Given fractions A and B (except input 5), user can choose the following:
1. Add fractions A and B
2. Subtract fractions A and B
3. Multiply fractions A and B
4. Divide fractions A and B
5. Simply fraction A
*/
#include <stdio.h>
/* Fraction structure */
typedef struct{
    int num;
    int denom;
}fraction;

fraction frac_a, frac_b;

/* Functions */
void user_choose();
void frac_input_one();
void frac_input_two();
void add_fracs(fraction f1, fraction f2);
void sub_fracs(fraction f1, fraction f2);
void mult_fracs(fraction f1, fraction f2);
void div_fracs(fraction f1, fraction f2);
void simp_frac(fraction f1);
int gcd(int n1, int n2);

int main(){
    printf("Options: \n");
    printf("1. Add two fractions \n");
    printf("2. Subtract two fractions \n");
    printf("3. Multiply two fractions \n");
    printf("4. Divide two fractions \n");
    printf("5. Simplify a fraction \n\n");
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
            frac_input_two();
            add_fracs(frac_a,frac_b);
            break;
        case 2:
            frac_input_two();
            sub_fracs(frac_a,frac_b);
            break;
        case 3:
            frac_input_two();
            mult_fracs(frac_a,frac_b);
            break;
        case 4:
            frac_input_two();
            div_fracs(frac_a,frac_b);
            break;
        case 5:
            frac_input_one();
            simp_frac(frac_a);
            break;
        default:
            printf("Invalid input. Try again.\n");
            user_choose();
            break;
    }    
}
void frac_input_one(){
    frac_a.denom = 1;
    do{
    printf("Input one fraction: "); 
    scanf("%d/%d", &frac_a.num, &frac_a.denom);
    getchar();

    if (frac_a.denom == 0)
        printf("0 as a denominator will result to undefined behavior. Try again.\n");       
    }while(frac_a.denom == 0);
}

void frac_input_two(){
    frac_b.denom = 1, frac_a.denom = 1;
    do{
    printf("Input two fractions: "); 
    scanf("%d/%d %d/%d", &frac_a.num, &frac_a.denom, &frac_b.num, &frac_b.denom);
    getchar();

    if (frac_a.denom == 0 || frac_b.denom == 0)
        printf("0 as a denominator will result to undefined behavior. Try again.\n");   
    }while(frac_a.denom == 0 || frac_b.denom == 0);
}

void add_fracs(fraction f1, fraction f2){
    fraction summed_frac;
    if(f1.denom==f2.denom){
        summed_frac.num = f1.num+f2.num;
        summed_frac.denom = f1.denom;
    }
    else{
        summed_frac.denom = f1.denom*f2.denom;
        summed_frac.num = ((summed_frac.denom/f1.denom)*f1.num)+((summed_frac.denom/f2.denom)*f2.num);
    }

    simp_frac(summed_frac);
}

void sub_fracs(fraction f1, fraction f2){
    fraction diff_frac;
    if(f1.denom==f2.denom){
        diff_frac.num = f1.num-f2.num;
        diff_frac.denom = f1.denom;
    }
    else{
        diff_frac.num = ((diff_frac.denom/f1.denom)*f1.num)-((diff_frac.denom/f2.denom)*f2.num);
        diff_frac.denom = f1.denom*f2.denom;
    }

    simp_frac(diff_frac);
}

void mult_fracs(fraction f1, fraction f2){
    fraction prod_frac;
    prod_frac.num = (f1.num)*(f2.num);
    prod_frac.denom = (f1.denom)*(f2.denom);

    simp_frac(prod_frac);
}

void div_fracs(fraction f1, fraction f2){
    fraction quo_frac;
    quo_frac.num = (f1.num)*(f2.denom);
    quo_frac.denom = (f1.denom)*(f2.num);

    simp_frac(quo_frac);
}

int gcd(int n1, int n2){
   int r = n1%n2;
    if(r==0){
        return n2;
    }
   return gcd(n2, r);
}

void simp_frac(fraction f1){
    int to_div;
    fraction final_frac;
    if (f1.num>f1.denom)
        to_div = gcd(f1.num, f1.denom);
    else   
        to_div = gcd(f1.denom,f1.num);

    final_frac.num = f1.num/to_div;
    final_frac.denom = f1.denom/to_div;

    if(final_frac.denom==1)
        printf("%d", final_frac.num);
    else
        printf("%d/%d", final_frac.num, final_frac.denom);
}