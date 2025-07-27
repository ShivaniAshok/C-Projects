/*
run-commands on vs:
go to your folder path type below 2 commands one after other
gcc guessing_game.c
guessing_game
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int random_num, guess, no_of_guess = 0;
    printf("Welcome to the world of Guessing Numbers\n");

    srand(time(NULL));               // current time in seconds since the Unix Epoch — which is:January 1, 1970 at 00 : 00 : 00 UTC
    random_num = (rand() % 100) + 1; // rand() % 100 generates bet 0 to 99 adding 1 gives range 1 to 100

    do
    {
        printf("Please enter your Guess between(1 to 100): ");
        scanf("%d", &guess);
        no_of_guess++;

        if (guess < random_num)
        {
            printf("The number you guessed is smaller.\n");
        }
        else if (guess > random_num)
        {
            printf("The number you guessed is larger.\n");
        }
        else
        {
            printf("Congratulations!!!You have successfully guessed the Number in %d attempts.\n ", no_of_guess);
        }
    } while (guess != random_num);

    printf("Thanks for Playing.");

    return 0;
}