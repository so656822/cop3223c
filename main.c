#include <stdio.h>
#include <string.h>
#include "roster.h"




static void eat_rest_of_line(void) {
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF) {
        
    }


}

static void do_add(Roster *r)
{
    char fn[32];
    char ln[32];
    int sid;
    double g;
    Student newstu;
    int outcome;

    printf("First name: ");
    scanf("%31s", fn);

    printf("Last name:  ");
    scanf("%31s", ln);

    printf("Student ID: ");
    scanf("%d", &sid);

    printf("GPA:        ");
    scanf("%lf", &g);
    eat_rest_of_line();

    newstu = create_student(fn, ln, sid, g);
    outcome=roster_add(r, newstu);

    if (outcome == 1){
        printf("Student added.\n");
        }


    else if(outcome == 0) {
        printf("Roster Full, Student Not Added\n");
    }
    
    
    else {
        printf("ID Already Exists, Student Not Added\n");
    }


}

static void do_remove(Roster *r) {
    int sid;

    printf("Enter student ID: ");
    scanf("%d", &sid);
    eat_rest_of_line();

    if(roster_remove(r, sid))
    {
        printf("Student removed.\n");
    }
    else
        printf("Student Not Found\n");
}

static void do_find_by_id(Roster *r){
    int sid;
    Student *hit;

    printf("Enter student ID: ");
    scanf("%d", &sid);
    eat_rest_of_line();

    hit = roster_find_by_id(r, sid);

    if (hit != NULL) {
        print_student(hit);
         }
    else{
        printf("Student not found.\n");
         }
    }

static void do_find_by_name(Roster *r) {
    char ln[32];
    Student *hit;

    printf("Enter last name: ");
    scanf("%31s", ln);
    eat_rest_of_line();

    hit=roster_find_by_name(r, ln);

    if(hit != NULL)
        print_student(hit);
    else
        printf("Student not found.\n");
}

int main(void) {
    Roster theroster;
    int pick;
    int keepgoing = 1;

    theroster.count = 0;


    /*main menu loop*/
    while (keepgoing){
        printf("\n= Student Roster System =\n");
        printf("1. Add student\n");
        printf("2. Remove student (by ID)\n");
        printf("3. Find student (by ID)\n");
        printf("4. Find student (by last name)\n");
        printf("5. Sort by name\n");
        printf("6. Sort by GPA\n");
        printf("7. Print roster\n");
        printf("8. Quit\n");
        printf("Enter choice (1-8): ");

        // scanf returns 0 if user types letters instead of a number
        if(scanf("%d", &pick) != 1) {
            eat_rest_of_line();
            printf("Invalid choice.\n");
            continue;
        }


        eat_rest_of_line();

        switch(pick) {
            case 1:
                do_add(&theroster);
                break;
            case 2:
                do_remove(&theroster);
                break;
            case 3:
                do_find_by_id(&theroster);
                break;
            case 4:
                do_find_by_name(&theroster);
                break;
            case 5:
                roster_sort_by_name(&theroster);
                break;
            case 6:
                roster_sort_by_gpa(&theroster);
                break;
            case 7:
                print_roster(&theroster);
                break;
            case 8:
                keepgoing = 0;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
       }

    return 0;
    }