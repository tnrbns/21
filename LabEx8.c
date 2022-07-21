/* 
Rubinos, Tyna - BSCS II
Exercise #9 - Strings
User is given two options:
1. Concatenate two strings A and B
2. Slice string A from integer B to C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int size;
    int capacity;
    char *arr;
} vector;

/* Functions  */
void user_input();
void initString(vector*, char*);
void concatenate(vector* combined, vector* a, vector* b, int val_a, int val_b);
void slice(vector* sliced, vector* source, int start, int end);
void initList(vector* vec);
void resize(vector* list);
void insertItem(vector* list, int index, int item);

int main(){
    user_input();
    return 0;
}

void user_input(){
    int user_input;
    int string_start, string_end;
    char *string_a = (char*)malloc(sizeof(char)*15);
    char *string_b = (char*)malloc(sizeof(char)*15); 
    vector a; 
    vector b;
    vector new;

    printf("Options: \n");
    printf("1. Concatenate two strings. \n");
    printf("2. Slice a string.\n");
    printf("Choose input: ");
    scanf("%d", &user_input);
    getchar();

    switch(user_input){
        case 1:
            printf("Input two strings (separated by space): ");
            scanf("%s %s", string_a, string_b);
            getchar();

            initString(&a,string_a);
            initString(&b,string_b);

            int a_length = strlen(string_a);
            int b_length = strlen(string_b);

            concatenate(&new, &a, &b, a_length, b_length);

            break;
        case 2:
            printf("Input one string and two integers (separated by space): ");
            scanf("%s %d %d", string_a, &string_start, &string_end);
            getchar();

            initString(&a,string_a);

            slice(&new, &a, string_start, string_end);

            break;
        default:
            printf("Invalid input. Try again.\n");
            break;
    }  

    free(string_a);
    free(string_b);
    getchar();
}


void insertItem(vector* list, int index, int item) {
 if (index >= 0 && index <= list->size) {
        if (list->size == list->capacity) {
            resize(list);
        }
        for (int i = list->size; i > index; i--) {
            list->arr[i] = list->arr[i - 1];
        }
    list->arr[index] = item;
    list->size++;
 }
    return;
}    

void resize(vector* list) {
        int newCapacity = 2 * list->size;
        char* newArr = (char*) malloc(sizeof(char) * newCapacity);
            for (int i = 0; i < list->size; i++) {
                newArr[i] = list->arr[i];
            }
        list->capacity = newCapacity;
        free(list->arr);
        list->arr = newArr;
}

void initList(vector* vec) {
    vec->size = 0;
    vec->capacity = 15;
    vec->arr = (char*) malloc(sizeof(char)*vec->capacity);
}

void initString(vector* vec, char* str){
    initList(vec);
    int i = 0; 
    for(i = 0 ; str[i]!='\0'; i++)
        insertItem(vec, i, str[i]);    

    vec->arr[i] = '\0';
}

void concatenate(vector* combined, vector* a, vector* b, int val_a, int val_b){
    char *new_string = (char*)malloc(sizeof(char)*15); 
    int index = 0;
    for (int i = 0; i < val_a; i++){
        new_string[index] = a->arr[i];
        index++;
    }
    for(int i = 0; i < val_b; i++) {
      new_string[index] = b->arr[i];
      index++;
    }
    new_string[index] = '\0';

    initString(combined, new_string);
    printf("%s",combined->arr);
    free(new_string);
}

void slice(vector* sliced, vector* source, int start, int end){
    char *new_string = (char*)malloc(sizeof(char)*15); 
    int index = 0;
    for (int i = start; i < end; i++){
        new_string[index] = source->arr[i];
        index++;
    }
    new_string[index] = '\0';
    
    initString(sliced, new_string);
    printf("%s",sliced->arr);
    free(new_string);
} 