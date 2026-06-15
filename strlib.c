#include "strlib.h"


int str_length(const char *s) {
    const char *p = s;   
    
    /* iterate until hitting the null char */
    while (*p != '\0')          
        p++;


    return (int)(p - s);       
    }


void str_copy(char *dst, const char *src, int dst_size){
    /*setting pointer*/
    char *d = dst;              
    const char *s = src;        
    int written = 0;

/* stop at end of src*/
    while (*s != '\0' && written < dst_size - 1){ 
        
        /*copy both 1 char and ,ove both pointers*/
        *d++ = *s++;            
        written++;

        }
    /*terminate pointer*/
    *d = '\0';                  
    }




int str_compare(const char *a, const char *b){

    /* advance both pointers while characters match*/
    while (*a != '\0' && *a== *b){ 
        a++;
        b++;
        }

    /*will determine the order of the print in tool program*/
    return (unsigned char)*a - (unsigned char)*b;
        }


void str_reverse(char *s) {
    /*start at beggining of string */
    char *left = s;          
    char *right = s;
    char tmp;

    /*run until null char*/
    while (*right != '\0')     

        right++;
        right--;   
    

    /* swap chars until pointer meet in the middle*/
    while (left < right) {      
        tmp    = *left;
        *left  = *right;
        *right = tmp;
        left++;
        right--;
        }

        
     }



int str_count_char(const char *s, char c) {


    int count = 0;


    /*run untill null byte*/
    while (*s != '\0') {

   /*incriment where char matches */
        if (*s== c)            
            count++;
            s++;                    
            }
   
   
            return count;
        }




void str_to_upper(char *s){

    /*run till null char*/
    while (*s != '\0'){

        if (*s >= 'a' && *s <= 'z')  /* only act on lowercase chars*/
            /*move letter to uppercase equivalant*/
            *s = *s - 32;         
            
        /*move to next char*/
        s++;
     }
    }




void array_stats(const int arr[], int len,int *out_min, int *out_max, double *out_avg){
    int i;
    long long sum;


    *out_min = arr[0];     
    *out_max = arr[0];
    sum = 0;
    

    for (i = 0; i < len; i++){

        /* new smallest found */
        if (arr[i] < *out_min){ *out_min = arr[i]; 
         } 
        if (arr[i] > *out_max) *out_max = arr[i];  /* new largest found */
        sum += arr[i];
        }


        *out_avg = (double)sum / len; 

        }


int array_find(const int arr[], int len, int target) {

    int i;
    

    /*iterate through array*/
    for (i = 0; i < len; i++) {

        /* if found return the index*/
        if (arr[i] == target)
            return i;          
        }


    /*if not found*/
    return -1;  

    }
