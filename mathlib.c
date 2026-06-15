#include "mathlib.h"

int clamp(int value, int lo, int hi){

    /*if value is below lower bound, return lower bound*/
    if (value < lo) {
        return lo;
    }

    /*if value is above upper bound, return upper bound*/
    if (value > hi) {
        return hi;
    }

  
    return value;
}


double power(double base, int exp){
    /*initialize vars*/
    double result= 1.0;
    int n= exp;
    int i;



    /*invert num if negative*/
    if (n < 0){
        n= -n;
    }

    /*loop to multiply base by itself n times*/
    for (i = 0; i < n; i++){
        result = result*base;
    }




    /*if original exponent was negative return reciprocal of result*/
    if (exp < 0) {
        result = 1.0 / result;
         }
    return result;
    }   



int is_prime(int n){
    int i;


    /*numbers less than 2 are not prime*/
    if (n < 2){
        return 0;
    }



    /*check for divisors from 2 up to sqrt of n - return 0 if a match*/
    for (i = 2; i * i <= n; i++) {

        if (n % i == 0){return 0;}

        }

    /*no divisors found*/
    return 1;
    }

    
int gcd(int a, int b) {
     /*loop ends when reaches 0 = gcd found*/
    while (b != 0) {
        int temp= b;

        /*remainder becomes new b*/
        b =a % b;

        /*old b becomes new a*/
        a =temp;
     }


    return a;
    }




double average(int arr[], int len) {
    /*init vars*/
    double sum =0.0;
    int i;


    /*end function to avoid division by 0*/
    if (len <= 0) {
        return 0.0;
    }


    /*loop to all elements in array*/
    for (i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum / len;
    }

int count_digits(long long n) {
    /*init count*/
    int count = 0;

    /*0 contains one digit*/
    if (n == 0){
        /*return and end function*/
        return 1;
        }

    /*convert negative number so count works*/
    if (n < 0){
        n= -n;
        }

    /*remove 1 digit and and iterate count until reaches 0*/
    while (n > 0){

        count++;
        n /=10;
        }

    return count;
    }




