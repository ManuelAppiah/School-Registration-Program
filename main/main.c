#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -o alias file_name.c

#define MAX_STUDENTS 8
#define RESULT_LENGTH 100
#define SUBJECT_NUMBER 4

void get(char file_path[],  char array[MAX_STUDENTS][RESULT_LENGTH]);

int main()
{

    char results[MAX_STUDENTS][RESULT_LENGTH], students[MAX_STUDENTS][RESULT_LENGTH], individual_result[SUBJECT_NUMBER];
    get("students.txt", students);
    get("results.txt", results);
    // Arranging student in order to accept an option from the user.
    printf("# Student Name      Results\n");
    int i;
    for( i=0; i < 7; i++){
        printf("%d %s   %s\n", i + 1,  students[i], results[i]);
    }
    int option;
    char student_result[RESULT_LENGTH] = " ";

    printf("\n\nPick a student >> ");
    scanf("%d", &option);
    printf("\nThe student result is %s", results[option - 1]);
    strcpy(student_result, results[option -1]);//copy string value at student_results to results.

    // getting the individual numbers
    char element;
    char number[3] = "";
    int number_as_int;
    float sum = 0;
    int string_length = strlen(student_result);
    printf("\n");
    for(int i=0; i < string_length ; i++){
        element = student_result[i];
        if(element != ','){
         strncat(number, &element, 1);
        }
        else{
            printf("%s\n", number);
            number_as_int = atoi(number);
            sum += number_as_int;
            strcpy(number, "");
        }
    }
    printf("\n Average grade is %.2f\n\n", sum/3);

    // Read school courses and cut-off marks from file
    FILE *fp_courses;
    char courses[1000];
    char course_name[50];
    float cut_off_mark;

    printf("\n Enter the name of the school courses file: ");
    scanf("%s", courses);

    fp_courses = fopen(courses, "r");
    if (fp_courses == NULL) {
        printf("Error opening school courses file. Type the right file name!\n");
        return 1;
    }

    printf("\nSCHOOL COURSES AND THEIR CUT-OFFS:\n");
    fread(courses, sizeof(char), 1000, fp_courses);// Takes the whole file and prints it.
     printf("%s", courses);
     fclose(fp_courses);
        if (sum/3 >= 80)
    {
        printf("\nCongratulations %c you have been placed in the Electrical Engineering Department!\n");
    }
    else if (sum/3 >= 75 && sum/3 < 80)
     {
        printf("\nCongratulations  you have been placed in the Computer Engineering Department!\n");
     }
     else if ( sum/3 >= 70 && sum/3 < 75)
    {
        printf("\nCongratulations you have been placed in the Mechanical Engineering Department !\n");
    }
    else if (sum/3 >= 65 && sum/3 < 70)
    {
        printf("\nCongratulations  you have been placed in the Biomedical Engineering Department!\n");
    }
    else if (sum/3 >= 60 && sum/3 < 65)
    {
        printf("\nCongratulations you have been placed in the Industrial Engineering Department!\n");
    }
    else if (sum/3 >= 50 && sum/3 < 60)
    {
        printf("\nCongratulations you have been placed in the Agricultural Engineering Department!\n");
    }

    else
    {
        printf("\nSorry you have not qualified for any course. Reapply again.\n");
    }


    return 0;
}


void get(char file_path[], char array[MAX_STUDENTS][RESULT_LENGTH]){
 FILE *file = fopen(file_path, "r");
 int line = 0;
 char result[RESULT_LENGTH] = "";
    while(!ferror(file) && !feof(file)){
        fgets(result, 100, file);
        result[strlen(result) - 1] = '\0';
        strcpy(array[line], result);
        line++;
    }
    fclose(file);
}






