#include <stdio.h>
#include "mathlib.h"



int main(void) {
    /*init choice value*/
    int choice = 0;


    /*print message*/
    printf("\n= Math Toolkit =\n");
    printf("1. Clamp a value\n");
    printf("2. Compute a power\n");
    printf("3. Prime check\n");
    printf("4. GCD\n");
    printf("5. Array average\n");
    printf("6. Count digits\n");
    printf("7. Quit");


    /*run loop until choice is exit */
    while (choice != 7){
       
        /*get user input*/
        printf("\nEnter choice (1-7): ");
        scanf("%d", &choice);

        

        switch (choice){

            /*clamp case*/
            case 1:{
                int value, lo, hi, result;
                printf("Enter value, lo, hi: ");

                /*get user input*/
                scanf("%d %d %d", &value, &lo, &hi);

                /*call function*/
                result = clamp(value, lo, hi);


                /*print results + exit*/
                printf("clamp(%d, %d, %d) = %d\n", value, lo, hi, result);
                break;
                }



            /*power num*/
            case 2: {
                double base, result;
                int exp;

                printf("Enter base and exponent: ");
                scanf("%lf %d", &base, &exp);

                /*call func*/
                result = power(base, exp);
                printf("power(%.2f, %d) = %.2f\n", base, exp, result);


                 break;
                 }


            /*[prime check]*/


            case 3:{
                int n, result;

                printf("Enter n: ");
                scanf("%d", &n);

                /*call function*/
                result = is_prime(n);

                /*print based on func result*/
                if (result) {printf("%d is prime.\n", n);} 
                else {printf("%d is not prime.\n", n);}


                break;
                 }

            /*gcd*/
            case 4:{
                int a, b, result;

                printf("Enter a and b: ");
                scanf("%d %d", &a, &b);

                result = gcd(a, b);

                printf("gcd(%d, %d) = %d\n", a, b, result);

                break;
                }


            /* avg*/
            case 5: {
                int count, i;
                int arr[100];
                double result;

                
                printf("Enter count then values: ");
                scanf("%d", &count);

                /*make array with user input*/
                for (i = 0; i < count; i++) {
                    scanf("%d", &arr[i]);
                }

                /*call avg func*/
                result = average(arr, count);


                printf("average = %.2f\n", result);
              
              
                break;
                }


            /* count*/
            case 6:{
                /*init*/
                long long n;
                int result;

    
                printf("Enter integer: ");
                scanf("%lld", &n);

                /* call funct*/
                result = count_digits(n);
                printf("%lld has %d digits.\n", n, result); 

                break;
               }




            /*exit loop*/
            case 7:
                printf("Goodbye!\n");
                break;



            
            default:
                break;
       
       
            }




    }

    return 0;
}