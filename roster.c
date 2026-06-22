#include <stdio.h>
#include <string.h>
#include "roster.h"





static Grade gpa_to_grade(double g){

    /* anything outside 0 to 4 is not a real gpa*/
    if(g < 0.0 || g > 4.0){
        return GRADE_INCOMPLETE;
     }

    if (g>=3.5) {

        return GRADE_A;
    
    } else if(g >= 3.0){
        return GRADE_B;
    }
    else if (g >= 2.0) {
        return GRADE_C;

    } else if(g>=1.0) {
        return GRADE_D;

    }


    return GRADE_F;

    }




Student create_student(const char *first, const char *last, int id, double gpa){

    Student stu;
    memset(&stu,0,sizeof(Student));

    strncpy(stu.first_name, first, sizeof(stu.first_name) - 1);
    strncpy(stu.last_name,last,sizeof(stu.last_name)-1);

    stu.student_id = id;
    stu.gpa=gpa;
    stu.standing = gpa_to_grade(gpa);

    return stu;
}

int roster_add(Roster *r, Student s){
    int k;

    if (r->count >= MAX_STUDENTS){
        return 0;
    }

    
    // dont allow two students with the same id
    for(k = 0; k < r->count; k++)
    {
        if(r->students[k].student_id == s.student_id){


            return -1;
        }

    }





    r->students[r->count] = s;
    r->count ++;
    return 1;

}




int roster_remove(Roster *r, int student_id)
{
    int idx, m;
    int hit = -1;

    for (idx=0; idx<r->count; idx++) {
        if(r->students[idx].student_id == student_id) {

            hit = idx;
            break;
        }
    }

    if(hit==-1) {
        return 0;
    }

    // shift everything after the removed one back by one spot
    for(m = hit; m < r->count - 1; m++) {
        r->students[m] = r->students[m + 1];
    }

    r->count--;
    return 1;
    }



Student *roster_find_by_id(Roster *r, int student_id){
    int n;

    for (n = 0; n < r->count; n++){
        if (r->students[n].student_id == student_id)
            return &r->students[n];
      }


    return NULL;
    }

Student *roster_find_by_name(Roster *r, const char *last_name)
{
    int n;

    for(n = 0; n<r->count; n++) {
        if(strcmp(r->students[n].last_name, last_name)==0){
            return &r->students[n];
        }
    }
    return NULL;
}

void roster_sort_by_name(Roster *r) {
    int a,b;
    int res;

    Student hold;


    for (a = 0; a < r->count - 1; a++) {
        for(b = 0; b < r->count - 1 - a; b++){
            res = strcmp(r->students[b].last_name, r->students[b+1].last_name);
            if (res == 0) {
                res = strcmp(r->students[b].first_name, r->students[b + 1].first_name);
            }

            // swap the whole struct and not just the names
            if(res > 0)
            {
                hold = r->students[b];
                r->students[b] = r->students[b+1];
                r->students[b + 1] = hold;
            }


        }
    }
}



void roster_sort_by_gpa(Roster *r)
{
    int a, b;
    Student hold;

    for(a=0; a < r->count - 1; a++) {
        for (b = 0; b < r->count-1-a; b++) {
            if(r->students[b].gpa < r->students[b + 1].gpa){
                hold = r->students[b];
                r->students[b]=r->students[b+1];
                 r->students[b+1] = hold;
                 }

             }

         }


}


void print_student(const Student *s) {
    char lastbuf[40];

    // gotta check this or it will crash on a null pointer
    if(s == NULL) {
        printf("No Student to Print\n");
        return;
         }

    snprintf(lastbuf, sizeof(lastbuf), "%s,", s->last_name);

    printf("  [%06d] %-13s %-10s GPA: %.2f  Standing: %s\n",
        s->student_id,lastbuf, s->first_name, s->gpa, grade_to_string(s->standing));
}

void print_roster(const Roster *r){
    int q;

    printf("\xE2\x95\x94");
    for (q = 0; q < 52; q++) {
        printf("\xE2\x95\x90");
    }


    printf("\xE2\x95\x97\n");

    printf("\xE2\x95\x91  Student Roster (%d students)\n", r->count);

    printf("\xE2\x95\xA0");
    for(q=0;q<52;q++){
        printf("\xE2\x95\x90");
    }
    printf("\xE2\x95\xA3\n");

    for (q = 0; q < r->count; q++)
    {
        print_student(&r->students[q]);
    }

    printf("\xE2\x95\xA0");
    for (q = 0; q < 52; q++) {
        printf("\xE2\x95\x90");
    }

    printf("\xE2\x95\xA3\n");

    /*calling class avg func*/
    printf("\xE2\x95\x91  Class average GPA: %.2f\n", roster_average_gpa(r));

    printf("\xE2\x95\x9A");


    for(q = 0; q<52; q++){
        printf("\xE2\x95\x90");
        }


    printf("\xE2\x95\x9D\n");

    }

const char *grade_to_string(Grade g) {

    switch (g){
        case GRADE_A: return "A";
        case GRADE_B: return "B";
        case GRADE_C:return "C";
        case GRADE_D: return "D";
        case GRADE_F: return "F";
        default: return "Incomplete";
         }
}

double roster_average_gpa(const Roster *r){
    int q;
    double sum = 0.0;

    if (r->count==0)
        return 0.0;

    for(q = 0; q < r->count; q++) {
        sum += r->students[q].gpa;
    }

    return sum / r->count;
}