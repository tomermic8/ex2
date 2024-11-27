/******************
Name: tomer michels
ID: 322440892
Assignment: ex2
*******************/

#include <math.h>
#include <stdio.h>

int main() {
    // Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
    /* Example:
    * n = 3:
    * 0   0
    *   o
    * \___/
    */

    int option = 0;
    while (option != 7) {
        char eyes, nose, mouth;
        int facesize;
        printf("Choose an option:\n");
        printf("\t1. Happy Face\n");
        printf("\t2. Balanced Number\n");
        printf("\t3. Generous Number\n");
        printf("\t4. Circle Of Joy\n");
        printf("\t5. Happy Numbers\n");
        printf("\t6. Festival Of Laughter\n");
        printf("\t7. Exit\n");
        scanf(" %d", &option);
        scanf("%*c");
        switch (option) {
            case 1:
                printf("Enter symbols for the eyes, nose, and mouth:\n");
            scanf(" %c %c %c", &eyes, &nose, &mouth);
            printf("Enter face size:\n");
            scanf(" %d", &facesize);
            while (facesize < 0 || facesize % 2 == 0) {
                printf("The face's size must be an odd and positive number, please try again:\n");//check face size not even number//
                scanf(" %d", &facesize);
            }
            printf("%c", eyes);//print first eye
            for (int i = 0; i < facesize; i++) {//create the space between the eyes
                printf(" ");
            }
            printf("%c\n", eyes);//print second eye
            for (int i = 0; i <= facesize / 2; i++) {//create the space till half of face size
                printf(" ");
            }
            printf("%c\n", nose);

            printf("\\");
            for (int i = 0; i < facesize; i++) {//print the mouthe face size times
                printf("%c", mouth);
            }
            printf("/\n");

            break;

            // Case 2: determine whether the sum of all digits to the left of the middle digit(s)
            // and the sum of all digits to the right of the middle digit(s) are equal
            /* Examples:
            Balanced: 1533, 450810, 99
            Not blanced: 1552, 34
            Please notice: the number has to be bigger than 0.
            */

            case 2:
                int balancenum;
                printf("Enter a number:\n");
                scanf("%d", &balancenum);
                while (balancenum <= 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &balancenum);
                }
                int balancedigits = balancenum;//create another balancenum
                int numofdigits = 0;
                while (balancedigits > 0) {
                    balancedigits = balancedigits / 10;//loosing one digit till number is 0
                    numofdigits++;//count the digits
                }
                int sum1 = 0, sum2 = 0;

                if (numofdigits % 2 == 0) {//first case, for even number of digits
                    numofdigits = numofdigits / 2;//get half of the number digits
                    for (int i = 0; i < (numofdigits); i++) {//run till the half of digits count
                        sum1 = sum1 + (balancenum % 10);//sum the last digit
                        balancenum = balancenum / 10;//erase last digit
                    }

                    for (int i = 0; i < numofdigits; i++) {
                        sum2 = sum2 + balancenum % 10;//sum the last digit
                        balancenum = balancenum / 10;//erase last digit
                    }
                } else {//second case for odd number of digits
                    numofdigits = numofdigits / 2;//run till one bedore half of digits
                    for (int i = 0; i < numofdigits; i++) {
                        sum1 = sum1 + (balancenum % 10);//sum the last digit
                        balancenum = balancenum / 10;//erase last digit
                    }
                    balancenum = balancenum / 10;//erase the midlle digit
                    for (int i = 0; i < numofdigits; i++) {
                        sum2 = sum2 + (balancenum % 10);//sum the last digit
                        balancenum = balancenum / 10;//erase last digit
                    }
                }
                if (sum1 == sum2) {
                    printf("This number is balanced and brings harmony!\n");
                } else {
                    printf("This number is not balanced\n");
                }
                break;
            // Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
            /* Examples:
            Abudant: 12, 20, 24
            Not Abudant: 3, 7, 10
            Please notice: the number has to be bigger than 0.
            */

            case 3:

                int abundant;
                printf("Enter a number:\n");
                scanf("%d", &abundant);

                while (abundant <= 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &abundant);
                }
                int devidersofabundant = 0;//will be the sum of the devisors
                for (int i = 1; i < abundant; i++) {//run for all numbers from 1 till the checing number
                    if (abundant % i == 0) {//check if the number devides by i
                        devidersofabundant = devidersofabundant + i;//if devides, sum it to sum of devisors
                    }
                }
                if (devidersofabundant > abundant) {//check if sum is greater than the number
                    printf("This number is generous!\n");
                } else {
                    printf("This number does not share.\n");
                }
                break;

            // Case 4: determine wether a number is a prime.
            /* Examples:
            This one brings joy: 3, 5, 11
            This one does not bring joy: 15, 8, 99
            Please notice: the number has to be bigger than 0.
            */

            case 4:

                int prime;
            int primebool = 0;
            int primereversebool = 0;
            printf("Enter a number:\n");
            scanf("%d", &prime);

            while (prime <= 0) {
                printf("Only positive number is allowed, please try again:\n");
                scanf("%d", &prime);
            }

            for (int i = 2; i < prime; i++) {//run for all numbers from 2 to the user number, not including 1 and prime itself as we asked
                if (prime % i == 0) {//check if number is prime for every number at the loop
                    primebool = 1;//at least one devisor=not prime
                    break;
                }
            }
            int digits = 0;
            int primedigits = prime;

            while (primedigits > 0) {//till number will be 0
                digits++;//count the digits
                primedigits = primedigits / 10;//erase last digit
            }
            int dig = 1;
            for (int i = 1; i < digits; i++) {
                dig = dig * 10;//create number whice is multiply of 10 as the digits count
            }
            int reverseprime=0;
            for (int i = 1; i <= digits; i++) {
                reverseprime = reverseprime + ((prime % 10) * dig);//smaller number in prime will be biggest number in reverse prime
                prime = prime / 10;//erase the last digit we just switched
                dig = dig / 10;//devide the 10 multiply by 10 for the next number
            }

            for (int i = 2; i < reverseprime; i++) {//run for all numbers from 2 to the user number, not including 1 and prime itself as we asked
                if (reverseprime % i == 0) {//check if number is prime for every number at the loop
                    primereversebool = 1;//at least one devisor=not prime
                    break;
                }
            }

            if (primebool == 0 && primereversebool == 0) {//check if both prime, 0=no devisors
                printf("This number completes the circle of joy!\n");
            } else {
                printf("The circle remains incomplete.\n");
            }
                break;
            // Happy numbers: Print all the happy numbers between 1 to the given number.
            // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
            /* Examples:
            Happy :) : 7, 10
            Not Happy :( : 5, 9
            Please notice: the number has to be bigger than 0.
            */

            case 5:

                int happynum;
                printf("Enter a number:\n");
                scanf("%d", &happynum);

                while (happynum <= 0) {
                    printf("Only positive number is allowed, please try again:\n");
                    scanf("%d", &happynum);
                }
                printf("Between 1 and %d only these numbers bring happiness: 1", happynum);//1 is always happy

                for (int i = 2; i <= happynum; i++) {
                    int happycheck = i;//checking eace number till happynum
                    int digithezka = 0;//create the new number for the sum of digits multiply themself

                    while (happycheck > 0) {//till we have number
                        digithezka = digithezka + ((happycheck % 10) * (happycheck % 10));//multiply last digit with itself and sum it to the new number
                        happycheck = happycheck / 10;//erase the digit we have just multiply
                        while (happycheck == 0) {//end of the number
                            if (digithezka < 11) {//number we gest is 10 ore less
                                if (digithezka == 1 || digithezka == 7 || digithezka == 10) {//1,7 and 10 are happy numbers
                                    printf(" %d", i);//i is the original number we check, and its happy
                                    happycheck = 0;
                                    break;
                                }

                                happycheck = 0;//2,3,4,5,6,8,9 not happy, we can move to next number to checl if happy
                                break;
                            }
                            happycheck = digithezka;//we didnt get 11 and less so we need to do the operation again because we dont know if the number is happy, happycheck gets the new number we got
                            digithezka = 0;//the new number will start from 0 again
                        }
                    }
                }
                printf("\n");
                break;

            // Festival of Laughter: Prints all the numbers between 1 the given number:
            // and replace with "Smile!" every number that divided by the given smile number
            // and replace with "Cheer!" every number that divided by the given cheer number
            // and replace with "Festival!" every number that divided by both of them
            /* Example:
            6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
            */

            case 6:

                int smile = 0;
                int cheer = 0;
                printf("Enter a smile and cheer number:\n");
                scanf(" smile: %d, cheer: %d", &smile, &cheer);//need to get at exacly format

                while (cheer <= 0 || smile <= 0 || smile == cheer) {//when not in the format
                    scanf("%*[^\n]%*c");
                    printf(
                        "Only 2 different positive numbers in the given format are allowed for the festival, please try again:\n");
                    scanf(" smile: %d, cheer: %d", &smile, &cheer);
                }


                int max;
                printf("Enter maximum number for the festival:\n");
                scanf(" %d", &max);
                while (max <= 0) {
                    printf("Only positive maximum number is allowed, please try again:\n");
                    scanf(" %d", &max);
                }
                for (int i = 1; i <= max; i++) {//run for every number till festival
                    if (i % smile != 0 && i % cheer != 0) {//not devise in cheer or smile
                        printf("%d\n", i);//print the number itself
                    }

                    if (i % cheer == 0) {
                        if (i % smile == 0) {//devides both numbers
                            printf("Festival!\n");
                        } else {
                            printf("Cheer!\n");//devides only cheer
                        }
                    }
                    if (i % smile == 0 && i % cheer != 0) {//devides only smile
                        printf("Smile!\n");
                    }
                }

                break;
            case 7:
                break;//get out of the loop
            default:
                printf("This option is not available, please try again.\n");//didnt get number from 1 to 7
        }
    }
    printf("Thank you for your journey through Numeria!\n");//wher we get 7 get out of the loop print this and end the code
}

//	return 0;
