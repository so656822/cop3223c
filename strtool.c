#include <stdio.h>
#include "strlib.h"




int main(void){
    int choice = 0;

    /*print menu*/
    printf("\n= String & Array Toolkit =\n");
    printf("1. String length\n");
    printf("2. String copy (with truncation demo)\n");
    printf("3. String compare\n");
    printf("4. Reverse a string\n");
    printf("5. Count a character\n");
    printf("6. Convert to uppercase\n");
    printf("7. Array stats (min/max/avg)\n");
    printf("8. Find value in array\n");
    printf("9. Quit\n");


    /*run loop unitl user hits quit number*/
    while (choice != 9){


        printf("\nEnter choice (1-9):");
        scanf("%d", &choice);

        switch (choice){

            /*str len*/
            case 1:{
                
                /*init vars + get user input*/
                char buf[256];
                printf("Enter string: ");
                scanf("%255s", buf);

                /*call func in print*/
                printf("Length: %d\n", str_length(buf));


                break;
                }


            /*str copy*/
            case 2:{
                char src[256];
                char dst[8];

                printf("Enter string: ");
                scanf("%255s", src);
                str_copy(dst, src, sizeof(dst));
                printf("Copied: %s\n", dst);


                break;
                 }



            case 3:{

                /*init vars*/
                char a[256], b[256];
                int result;

                printf("Enter first string: ");
                scanf("%255s", a);


                printf("Enter second string: ");
                scanf("%255s", b);


                result= str_compare(a, b);


                if (result< 0){
                    printf("%s comes before %s\n", a, b);
                       }
                else if (result == 0){
                    printf("%s equals %s\n", a, b);

                      }

                else{ printf("%s comes after %s\n", a, b);}


                break;
                 }


            /*reverse string*/
            case 4: {

                char buf[256];
                printf("Enter string: ");
                scanf("%255s", buf);

                str_reverse(buf);



                printf("Reversed: %s\n", buf);

                break;
                }



            case 5:{

                char buf[256];
                char c;

                printf("Enter string: ");
                scanf("%255s", buf);

                printf("Enter character: ");
                scanf(" %c", &c);


                printf("Count: %d\n", str_count_char(buf, c));
                
                
                break;
                }

            /*tp uppercase*/
            case 6:{
                char buf[256];
                printf("Enter string: ");
                scanf("%255s", buf);

                str_to_upper(buf);

                printf("Upper: %s\n", buf);


                break;
                 }


            /* array stast*/
            case 7: {
                int count, i;
                int arr[100];
                int mn, mx;
                double avg;


                printf("Enter count then values: ");
                scanf("%d", &count);

                /*make arr w user input*/
                for (i = 0; i < count; i++)
                    scanf("%d", &arr[i]);

                /*call func passing values and pointers*/
                array_stats(arr, count, &mn, &mx, &avg);


                printf("min=%d  max=%d  avg=%.2f\n", mn, mx, avg);


                break;
                }



            case 8: {
                int count, i, target, result;
                int arr[100];

                /*get user input*/
                printf("Enter count then values: ");
                scanf("%d", &count);


                for (i = 0; i < count; i++)
                    scanf("%d", &arr[i]);

                /*prompt target num*/
                printf("Enter target: ");
                scanf("%d", &target);


                result = array_find(arr, count, target);
                if (result >= 0){
                    printf("Found at index %d.\n", result);


                }
                else {printf("Not found.\n");}
                break;
                 }
            



            /*quit loop*/
            case 9:
                printf("Goodbye!\n");
                break;



            default:
                break;
        }




    }




    return 0;




}





