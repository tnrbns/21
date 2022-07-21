/* 
Rubinos, Tyna - BSCS II
Exercise #9 - Student Information System
Create a student information system using linked lists.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student{
    int student_no_yr;
    int student_no_num;
    char last_name[15];
    char first_name[15];
    char course[15];
    int year_lvl;
    int age;
    char sex[15];
    int final_grade;
    struct student *next;
};

struct student *head;

void user_input();
void enrol_student(int student_no_yr, int student_no_num, char* last_name, char* first_name, char* course, int year_lvl, int age, char* sex, int final_grade);
int find_student(int student_no_yr, int student_no_num);
void edit_student_nos(int student_no_yr, int student_no_num, int new_student_no_yr, int new_student_no_num);
void edit_student(int student_no_yr, int student_no_num, char* first_name, char* last_name, char* course, int year_lvl, int age, char* sex, int final_grade);
void drop_student(int student_no_yr, int student_no_num);
void display_all();
void filter_by_last_name(char* last_name, int count);
void filter_by_student_number(int student_no_yr, int student_no_num, int count);
void filter_by_year_level(int year_lvl, int count);
void filter_by_course(char* course, int count);
void filter_by_sex(char* sex, int count);
void filter_by_passing(int count);
void filter_by_failing(int count);
void sort_by_last_name();
void sort_by_student_number(struct student *start);
void swap(struct student *a, struct student *b);

void printList(struct student *start);


int main(){
    user_input();
    return 0;
}

void user_input(){
    head = NULL;
    int user_input, count = 0, while_stop = 1;
    int student_no_year, student_no_num, year_lvl, age, final_grade;
    int new_stud_no_yr, new_stud_no_num;
    char first_name[15];
    char last_name[15];
    char course[15];
    char sex[15];
    
    while(while_stop==1){
        printf("Options:\n");
        printf("1. Enrol a student\n");
        printf("2. Drop a student\n");
        printf("3. Edit a student\n");
        printf("4. Display all students\n");
        printf("5. Filter students by last name\n");
        printf("6. Filter students by student number\n");
        printf("7. Filter students by year level\n");
        printf("8. Filter students by course\n");
        printf("9. Filter students by sex\n");
        printf("10. Filter students by passing\n");
        printf("11. Filter students by failing\n");
        printf("12. Sort students by last name\n");
        printf("13. Sort students by student number\n");
        printf("14. Exit\n");

        printf("\nChoose input: ");
        scanf("%d", &user_input);
        getchar();
            switch (user_input){
                case 1: /* Enrol a student */
                    printf("\nEnrol\n");
                    
                    printf("Student number: ");
                    scanf("%d-%d",&student_no_year,&student_no_num);

                        switch(find_student(student_no_year,student_no_num)){
                            case 0:
                                printf("Student %d-%d already exists!\n\n", student_no_year, student_no_num);
                                getchar();
                                break;

                            case 1:
                                do{
                                    printf("Last name: ");
                                    scanf("%s",&last_name);

                                        if (scanf("%[^\n]s", &last_name))
                                            printf("Input must have no spaces. Try again.\n");
                                        else if (strlen(last_name)>15)     
                                            printf("Input must have a maximum of 15 characters. Try again.\n");

                                }while(isspace(*last_name)||strlen(last_name)>15);

                                do{
                                    printf("First name: ");
                                    scanf("%s",&first_name);

                                        if (scanf("%[^\n]s", &first_name))
                                            printf("Input must have no spaces. Try again.\n");
                                        else if (strlen(first_name)>15)     
                                            printf("Input must have a maximum of 15 characters. Try again.\n");

                                }while(isspace(*first_name)||strlen(first_name)>15);

                                do{
                                    printf("Course: ");
                                    scanf("%s",&course);

                                        if (scanf("%[^\n]s", &course))
                                            printf("Input must have no spaces. Try again.\n");
                                        else if (strlen(course)>15)     
                                            printf("Input must have a maximum of 15 characters. Try again.\n");

                                }while(isspace(*course)||strlen(course)>15);

                                printf("Year level: ");
                                scanf("%d",&year_lvl);

                                printf("Age: ");
                                scanf("%d",&age);

                                do{
                                    printf("Sex: ");
                                    scanf("%s",&sex);

                                        if (scanf("%[^\n]s", &sex))
                                            printf("Input must have no spaces. Try again.\n");
                                        else if (strlen(sex)>15)     
                                            printf("Input must have a maximum of 15 characters. Try again.\n");

                                }while(isspace(*sex)||strlen(sex)>15);

                                printf("Final grade: ");
                                scanf("%d",&final_grade);

                                enrol_student(student_no_year, student_no_num, last_name, first_name, course, year_lvl, age, sex, final_grade);

                                printf("\n%d-%d added!\n\n", student_no_year, student_no_num);
                                count++;
                                getchar();                               
                                break;    
                        }
                    getchar();                               
                    break;

                case 2: /* Drop a student */
                    printf("\nDrop\n");
                    
                    printf("Student number: ");
                    scanf("%d-%d",&student_no_year,&student_no_num);
                    getchar();
                    
                    switch(find_student(student_no_year, student_no_num)){
                        case 0:
                                drop_student(student_no_year, student_no_num);
                                printf("\n%d-%d dropped!\n", student_no_year,student_no_num);
                                count--; 
                                getchar();
                            break;
                        case 1:
                                printf("\nStudent %d-%d not found!\n\n", student_no_year,student_no_num);
                                getchar();
                            break;    
                        }     
                    break;

                case 3: /* Edit a student */
                    printf("\nStudent number: ");
                    scanf("%d-%d",&student_no_year,&student_no_num);

                    switch(find_student(student_no_year, student_no_num)){
                        case 0:
                            while_stop=2;

                            while(while_stop==2){
                            printf("\nEdit:\n");
                            printf("1. Student number\n");
                            printf("2. Last name\n");
                            printf("3. First name\n");
                            printf("4. Course\n");
                            printf("5. Year level\n");
                            printf("6. Age\n");
                            printf("7. Sex\n");
                            printf("8. Final grade\n");
                            printf("9. Back\n");

                            printf("\nChoose input: ");
                            scanf("%d", &user_input);
                                switch (user_input){
                                        case 1:
                                            printf("Student number (%d-%d): ",student_no_year,student_no_num);
                                            scanf("%d-%d",&new_stud_no_yr,&new_stud_no_num);

                                            edit_student_nos(student_no_year, student_no_num, new_stud_no_yr, new_stud_no_num);
                                            
                                            student_no_year = new_stud_no_yr;
                                            student_no_num = new_stud_no_num;

                                            printf("\nStudent number updated!\n");
                                            getchar();
                                            
                                            break;

                                        case 2:
                                            do{
                                                printf("Last name (%s): ", last_name);
                                                scanf("%s",&last_name);

                                                    if (scanf("%[^\n]s", &last_name))
                                                        printf("Input must have no spaces. Try again.\n");
                                                    else if (strlen(last_name)>15)     
                                                        printf("Input must have a maximum of 15 characters. Try again.\n");
                                                }while(isspace(*last_name)||strlen(last_name)>15);
                                            
                                            edit_student(student_no_year, student_no_num, first_name, last_name, course, year_lvl, age, sex, final_grade);
                                            
                                            printf("\nLast name updated!\n");
                                            getchar();

                                            break;

                                        case 3:
                                        do{
                                                printf("First name (%s): ", first_name);
                                                scanf("%s",&first_name);

                                                    if (scanf("%[^\n]s", &first_name))
                                                        printf("Input must have no spaces. Try again.\n");
                                                    else if (strlen(first_name)>15)     
                                                        printf("Input must have a maximum of 15 characters. Try again.\n");
                                                }while(isspace(*first_name)||strlen(first_name)>15);
                                            
                                            edit_student(student_no_year, student_no_num, first_name, last_name, course, year_lvl, age, sex, final_grade);

                                            printf("\nFirst name updated!\n");
                                            getchar();

                                            break;

                                        case 4:
                                            do{
                                                printf("Course (%s): ", course);
                                                scanf("%s",&course);

                                                    if (scanf("%[^\n]s", &course))
                                                        printf("Input must have no spaces. Try again.\n");
                                                    else if (strlen(course)>15)     
                                                        printf("Input must have a maximum of 15 characters. Try again.\n");
                                                }while(isspace(*course)||strlen(course)>15);

                                            edit_student(student_no_year, student_no_num, first_name, last_name, course, year_lvl, age, sex, final_grade);

                                            printf("\nCourse updated!\n");
                                            getchar();

                                            break;

                                        case 5:
                                            printf("Year level (%d): ", year_lvl);
                                            scanf("%d",&age);

                                            edit_student(student_no_year, student_no_num, first_name, last_name, course, year_lvl, age, sex, final_grade);

                                            printf("\nYear level updated!\n");
                                            getchar();

                                            break;

                                        case 6:
                                            printf("Age (%d): ", age);
                                            scanf("%d",&age);

                                            edit_student(student_no_year, student_no_num, first_name, last_name, course, year_lvl, age, sex, final_grade);

                                            printf("\nAge updated!\n");
                                            getchar();

                                            break;   

                                        case 7:
                                            do{
                                                printf("Sex (%s): ", sex);
                                                scanf("%s",&sex);

                                                    if (scanf("%[^\n]s", &sex))
                                                        printf("Input must have no spaces. Try again.\n");
                                                    else if (strlen(sex)>15)     
                                                        printf("Input must have a maximum of 15 characters. Try again.\n");
                                            }while(isspace(*sex)||strlen(sex)>15);

                                            edit_student(student_no_year, student_no_num, first_name, last_name, course, year_lvl, age, sex, final_grade);

                                            printf("\nSex updated!\n");
                                            getchar();

                                            break;

                                        case 8:
                                            printf("Final grade (%d): ", final_grade);
                                            scanf("%d",&final_grade);
                                            
                                            edit_student(student_no_year, student_no_num, first_name, last_name, course, year_lvl, age, sex, final_grade);

                                            printf("\nFinal grade updated!\n");
                                            getchar();
                                            break;

                                        case 9:
                                            while_stop = 1;
                                            printf("\n");
                                            break;

                                        default:
                                            printf("Invalid input. Try again.\n");
                                            break;
                                }
                            getchar();  
                            }  
                            break;

                        case 1:
                            printf("\nStudent %d-%d not found!\n\n", student_no_year,student_no_num);
                            getchar();
                            break;

                        default:
                            break;
                        }    
                    break;

                case 4: /* Display all students */
                    display_all();
                    printf("\nDisplaying %d of %d student(s)\n", count, count);
                    getchar();
                    break; 

                case 5: /* Filter by last name */
                    do{
                        printf("Last name: ", last_name);
                        scanf("%s",&last_name);

                            if (scanf("%[^\n]s", &last_name))
                                printf("Input must have no spaces. Try again.\n");
                            else if (strlen(last_name)>15)     
                                printf("Input must have a maximum of 15 characters. Try again.\n");
                        }while(isspace(*last_name)||strlen(last_name)>15);
                    
                    filter_by_last_name(last_name,count);
                    getchar();
                    break;

                case 6: /* Filter by student number */
                    printf("Student number: ");
                    scanf("%d-%d",&student_no_year,&student_no_num);

                    filter_by_student_number(student_no_year, student_no_num, count);
                    getchar();
                    break;

                case 7: /* Filter by year level */
                    printf("Year level: ");
                    scanf("%d",&year_lvl);

                    filter_by_year_level(year_lvl, count);
                    getchar();
                    break;

                case 8: /* Filter by course */
                    do{
                        printf("Course: ");
                        scanf("%s",&course);

                            if (scanf("%[^\n]s", &course))
                                printf("Input must have no spaces. Try again.\n");
                            else if (strlen(course)>15)     
                                printf("Input must have a maximum of 15 characters. Try again.\n");
                        }while(isspace(*course)||strlen(course)>15);

                    filter_by_course(course, count);                        
                    getchar();
                    break;

                case 9: /* Filter by sex */
                    do{
                        printf("Sex: ");
                        scanf("%s",&sex);

                            if (scanf("%[^\n]s", &sex))
                                printf("Input must have no spaces. Try again.\n");
                            else if (strlen(sex)>15)     
                                printf("Input must have a maximum of 15 characters. Try again.\n");
                    }while(isspace(*sex)||strlen(sex)>15);

                    filter_by_sex(sex, count);
                    getchar();
                    break;

                case 10: /* Filter by passing */
                    filter_by_passing(count);
                    getchar();
                    break;

                case 11: /* Filter by failing */
                    filter_by_failing(count);
                    getchar();
                    break;

                case 12: /* Sort by last name */
                    sort_by_last_name(head);
                    display_all();

                    printf("\nDisplaying %d of %d student(s)\n", count, count);
                    getchar();
                    break;

                case 13: /* Sort by student number */
                    sort_by_student_number(head);
                    display_all();

                    printf("\nDisplaying %d of %d student(s)\n", count, count);

                    getchar();
                    break;

                case 14: /* Exit */
                    while_stop = 0;
                    break;   

                default:
                    printf("Invalid input. Try again.\n");
                    break;
        }
    }
}

void enrol_student(int student_no_yr, int student_no_num, char* last_name, char* first_name, char* course, int year_lvl, int age, char* sex, int final_grade){
    struct student *studentrec =(struct student*)malloc(sizeof(struct student));

    studentrec->student_no_yr = student_no_yr;
    studentrec->student_no_num = student_no_num;
    strcpy(studentrec->last_name, last_name);
    strcpy(studentrec->first_name, first_name);
    strcpy(studentrec->course, course);
    studentrec->year_lvl = year_lvl;
    studentrec->age = age;
    strcpy(studentrec->sex, sex);
    studentrec->final_grade = final_grade;
    studentrec->next = NULL;

    if(head==NULL)
        head = studentrec;
    else{
        studentrec->next = head;
        head = studentrec;
    }
}

int find_student(int student_no_yr, int student_no_num){
    struct student *temp = head;
    while(temp!=NULL){
        if(temp->student_no_yr==student_no_yr&&temp->student_no_num==student_no_num){
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

void drop_student(int student_no_yr, int student_no_num){
    struct student *temp1 = head;
    struct student *temp2 = head; 

    while(temp1!=NULL){
        
        if(temp1->student_no_yr==student_no_yr&&temp1->student_no_num==student_no_num){
            if(temp1==temp2){
                head = head->next;
                free(temp1);
            }
            else{
                temp2->next = temp1->next;
                free(temp1); 
            }
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;        
    }

}

void edit_student_nos(int student_no_yr, int student_no_num, int new_student_no_yr, int new_student_no_num){
    struct student *temp = head;
    while(temp!=NULL){
        if(temp->student_no_yr==student_no_yr&&temp->student_no_num==student_no_num){
            temp->student_no_yr = new_student_no_yr;
            temp->student_no_num = new_student_no_num;
            return;
        }
        temp = temp->next;
    }
}

void edit_student(int student_no_yr, int student_no_num, char* first_name, char* last_name, char* course, int year_lvl, int age, char* sex, int final_grade){
    struct student *temp = head;
    while(temp!=NULL){
        if(temp->student_no_yr==student_no_yr&&temp->student_no_num==student_no_num){
            temp->student_no_yr = student_no_yr;
            temp->student_no_num = student_no_num;
            strcpy(temp->last_name, last_name);
            strcpy(temp->first_name, first_name);
            strcpy(temp->course, course);
            temp->year_lvl = year_lvl;
            temp->age = age;
            strcpy(temp->sex, sex);
            temp->final_grade = final_grade;
            return;
        }
        else
            temp = temp->next;
    }
}

void display_all(){
    struct student *temp = head;
    while(temp!=NULL){
        printf("\nStudent number: %d-%d\n", temp->student_no_yr, temp->student_no_num);
        printf("Last name: %s\n", temp->last_name);
        printf("First name: %s\n", temp->first_name);
        printf("Course: %s\n", temp->course);
        printf("Year level: %d\n", temp->year_lvl);
        printf("Age: %d\n", temp->age);
        printf("Sex: %s\n", temp->sex);
        printf("Final grade: %d\n", temp->final_grade);
        temp = temp->next;
    }
}

void filter_by_last_name(char* last_name, int count){
    struct student *temp = head;
    int subcount = 0;
    while(temp!=NULL){
        if(strcmp(temp->last_name,last_name)==0){
            printf("\nStudent number: %d-%d\n", temp->student_no_yr, temp->student_no_num);
            printf("First name: %s\n", temp->first_name);
            printf("Course: %s\n", temp->course);
            printf("Year level: %d\n", temp->year_lvl);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final grade: %d\n", temp->final_grade);
            subcount++;
            temp = temp->next;
        }
        else 
            temp = temp->next;
    }

    printf("\nDisplaying %d of %d student(s)\n\n", subcount, count);
    getchar();
}


void filter_by_student_number(int student_no_yr, int student_no_num, int count){
    struct student *temp = head;
    int subcount = 0;
    while(temp!=NULL){
        if(temp->student_no_yr==student_no_yr&&temp->student_no_num==student_no_num){
            printf("\nLast name: %s\n", temp->last_name);
            printf("First name: %s\n", temp->first_name);
            printf("Course: %s\n", temp->course);
            printf("Year level: %d\n", temp->year_lvl);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final grade: %d\n", temp->final_grade);
            subcount++;
            temp = temp->next;
        }
        else 
            temp = temp->next;
    }

    printf("\nDisplaying %d of %d student(s)\n\n", subcount, count);
    getchar();
}

void filter_by_year_level(int year_lvl, int count){
    struct student *temp = head;
    int subcount = 0;
    while(temp!=NULL){
        if(temp->year_lvl==year_lvl){
            printf("\nStudent number: %d-%d\n", temp->student_no_yr, temp->student_no_num);
            printf("Last name: %s\n", temp->last_name);
            printf("First name: %s\n", temp->first_name);
            printf("Course: %s\n", temp->course);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final grade: %d\n", temp->final_grade);
            subcount++;
            temp = temp->next;
        }
        else 
            temp = temp->next;
    }
    
    printf("\nDisplaying %d of %d student(s)\n\n", subcount, count);
    getchar();
}

void filter_by_course(char* course, int count){
    struct student *temp = head;
    int subcount = 0;
    while(temp!=NULL){
        if(strcmp(temp->course,course)==0){
            printf("\nStudent number: %d-%d\n", temp->student_no_yr, temp->student_no_num);
            printf("Last name: %s\n", temp->last_name);
            printf("First name: %s\n", temp->first_name);
            printf("Year level: %d\n", temp->year_lvl);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final grade: %d\n", temp->final_grade);
            subcount++;
            temp = temp->next;
        }
        else 
            temp = temp->next;
    }

    printf("\nDisplaying %d of %d student(s)\n\n", subcount, count);
    getchar();
}

void filter_by_sex(char* sex, int count){
    struct student *temp = head;
    int subcount = 0;
    while(temp!=NULL){
        if(strcmp(temp->sex,sex)==0){
            printf("\nStudent number: %d-%d\n", temp->student_no_yr, temp->student_no_num);
            printf("Last name: %s\n", temp->last_name);
            printf("First name: %s\n", temp->first_name);
            printf("Course: %s\n", temp->course);
            printf("Year level: %d\n", temp->year_lvl);
            printf("Age: %d\n", temp->age);
            printf("Final grade: %d\n", temp->final_grade);
            subcount++;
            temp = temp->next;
        }
        else 
            temp = temp->next;
    }

    printf("\nDisplaying %d of %d student(s)\n\n", subcount, count);
    getchar();
}

void filter_by_passing(int count){
    struct student *temp = head;
    int subcount = 0;
    while(temp!=NULL){
        if(temp->final_grade>59){
            printf("\nStudent number: %d-%d\n", temp->student_no_yr, temp->student_no_num);
            printf("Last name: %s\n", temp->last_name);
            printf("First name: %s\n", temp->first_name);
            printf("Course: %s\n", temp->course);
            printf("Year level: %d\n", temp->year_lvl);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final grade: %d\n", temp->final_grade);
            subcount++;
            temp = temp->next;
        }
        else 
            temp = temp->next;
    }

    printf("\nDisplaying %d of %d student(s)\n\n", subcount, count);
}

void filter_by_failing(int count){
    struct student *temp = head;
    int subcount = 0;
    while(temp!=NULL){
        if(temp->final_grade<60){
            printf("\nStudent number: %d-%d\n", temp->student_no_yr, temp->student_no_num);
            printf("Last name: %s\n", temp->last_name);
            printf("First name: %s\n", temp->first_name);
            printf("Course: %s\n", temp->course);
            printf("Year level: %d\n", temp->year_lvl);
            printf("Age: %d\n", temp->age);
            printf("Sex: %s\n", temp->sex);
            printf("Final grade: %d\n", temp->final_grade);
            subcount++;
            temp = temp->next;
        }
        else 
            temp = temp->next;
    }

    printf("\nDisplaying %d of %d student(s)\n\n", subcount, count);
}

void sort_by_last_name(struct student *start){
	int swapped;
	struct student *ptr1;
	struct student *lptr = NULL;

	if (start == NULL)
		return;

	do{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr){
			if (strcmp(ptr1->last_name,ptr1->next->last_name)>0){
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
            else if(strcmp(ptr1->last_name,ptr1->next->last_name)==0 && strcmp(ptr1->first_name,ptr1->next->first_name)>0){
                swap(ptr1, ptr1->next);
				swapped = 1;
            }
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}while (swapped);
}

void sort_by_student_number(struct student *start){
	int swapped, i;
	struct student *ptr1;
	struct student *lptr = NULL;

	if (start == NULL)
		return;

	do{
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr){
			if ((ptr1->student_no_yr >= ptr1->next->student_no_yr) && (ptr1->student_no_num > ptr1->next->student_no_num)){
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	}while (swapped);
}

void swap(struct student *a, struct student *b){
    int temp_studno_yr;
    int temp_studno_num;
    char temp_lname[15];
    char temp_fname[15];
    char temp_course[15];
    int temp_yrlvl;
    int temp_age;
    char temp_sex[15];
    int temp_fgrade;

    temp_studno_yr = a->student_no_yr;
    temp_studno_num = a->student_no_num;
    strcpy(temp_lname,a->last_name);
    strcpy(temp_fname,a->first_name);
    strcpy(temp_course,a->course);
    temp_yrlvl = a->year_lvl;
    temp_age = a->age;
    strcpy(temp_sex,a->sex);
    temp_fgrade = a->final_grade;

    a->student_no_yr = b->student_no_yr;
    a->student_no_num = b->student_no_num;
    strcpy(a->last_name,b->last_name);
    strcpy(a->first_name,b->first_name);
    strcpy(a->course,b->course);
    a->year_lvl = b->year_lvl;
    a->age = b->age;
    strcpy(a->sex,b->sex);
    a->final_grade = b->final_grade;

    b->student_no_yr = temp_studno_yr;
    b->student_no_num = temp_studno_num;
    strcpy(b->last_name, temp_lname);
    strcpy(b->first_name, temp_fname);
    strcpy(b->course, temp_course);
    b->year_lvl = temp_yrlvl;
    b->age = temp_age;
    strcpy(b->sex, temp_sex);
    b->final_grade = temp_fgrade;
}