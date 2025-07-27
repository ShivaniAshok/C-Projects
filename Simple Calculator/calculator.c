/*
below commands to execute program:

gcc calculator.c
a

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double division(double, double);
double modulus(double, double); // modulus works for only int
void print_menu();

int main()
{
    int choice;
    double num1, num2, res = 0;

    print_menu();
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 7)
    {
        fprintf(stderr, "\nPlease enter a valid choice (1-7).\n");
        return 1;
    }

    if (choice == 7)
    {
        printf("Exiting calculator...\n");
        return 0;
    }

    printf("\nPlease enter the first num: ");
    scanf("%lf", &num1);

    printf("Now enter the second num: ");
    scanf("%lf", &num2);

    switch (choice)
    {
    case 1:
        res = num1 + num2;
        break;
    case 2:
        res = num1 - num2;
        break;
    case 3:
        res = num1 * num2;
        break;
    case 4:
        res = division(num1, num2);
        if (isnan(res))
            return 1;
        break;
    case 5:

        res = modulus(num1, num2);
        if (isnan(res))
            return 1;
        break;
    case 6:
        res = pow(num1, num2);
        break;
    }

    if (choice >= 1 && choice <= 6)
    {
        printf("\nResult of operation is: %.2lf\n", res);
    }

    return 0;
}

double division(double a, double b)
{
    if (b == 0)
    {
        fprintf(stderr, "Invalid Argument for Division\n");
        return NAN;
    }
    else
    {
        return a / b;
    }
}

double modulus(double a, double b)
{
    if ((int)b == 0) // modulus works for only int
    {
        fprintf(stderr, "Invalid Argument for Modulus\n");
        return NAN;
    }
    else
    {
        return (int)a % (int)b; // since num1 & num2 are double cast to int
    }
}

void print_menu()
{
    printf("\nWelcome to Simple Calculator\n");
    printf("\nChoose one of the following options: ");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");
}