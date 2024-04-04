/*

    Author:  Cole Shanks

    Date Created: Nov 17, 2017
    Date last modified: March 29th, 2024

    --------------------------------

    Comp120 -- Assignment 3

    Black Jack Game

    --------------------------------

*/



#include <stdio.h>

#include <stdlib.h>

//#include <process.h>

#include <time.h>



#define DECK_SIZE 53

#define CARDS 51



void game ();

void clean ();                      /* Function prototypes */

void rules ();

void title ();

void DisplayCard (int);

void ShuffleDeck (int[]);

void InitializeDeck (int[]);

int randomInRange (int, int);

int ScoreCard (int);

char GetChoice ();



int main()

{

    srand((unsigned) time( NULL ) );

    char choice;



    title ();



    do

    {

        choice = GetChoice();



        while ((choice!='y') && (choice!='n') && (choice!='1'))      /* If invalid choice entered */

        {

            printf("\n");

            printf("Invalid entry. Please Enter y for Yes, n for No, and 1 to see the rules\n");

            scanf("%c",&choice);

            clean();

        }



        switch (choice)         /* Menu options to see rules or start game */

        {

            case '1':

            rules();

            break;





            case 'y':

            game();

            title ();

            break;

        }





    }while (choice != 'n' );



    printf("\t\t\tHope you enjoyed the game %c\n\n\t\t\t\tGoodbye\n\n", 02);        /* Exit message */

    system("PAUSE");



    return 0;

}





void clean ()                  /* Empties the input buffer */

{

    char dummy;

    do

    {

        scanf("%c",&dummy);    /* Reads a single character */

    } while (dummy != '\n');   /* If it was the newline character we are finished */

}



char GetChoice()               /* Returns the choice the user has entered */

{

    char choice;



    printf("\t\tWould you like to play?\t\tNever played before?\n");

    printf("\t\t-----------------------\t\tPress 1 to see the\n");

    printf("\t\t\t(Y/N)\t\t\trules of the game\n");
        printf("display thus please %c\n", 226); // prints heart 



    scanf("%c", &choice);

    clean();

    printf("\n\n");



    return choice;

}

void title ()                  /* Displays the title screen */

{

    printf("=========================================================\n\n");

    printf(" %c%c%c%c    %c         %c%c           %c%c%c%c%c     %c       %c             \n", 05,05,05,05,06,03,03,04,04,04,04,04,05,05);

    printf(" %c   %c   %c        %c  %c         %c          %c     %c                     \n", 05,05,06,03,03,04,05,05);

    printf(" %c   %c   %c       %c    %c       %c           %c   %c                       \n", 05,05,06,03,03,04,05,05);

    printf(" %c%c%c%c    %c      %c%c%c%c%c%c%c%c      %c           %c %c                 \n", 05,05,05,05,06,03,03,03,03,03,03,03,03,04,05,05);

    printf(" %c   %c   %c     %c        %c     %c           %c   %c                       \n", 05,05,06,03,03,04,05,05);

    printf(" %c   %c   %c    %c          %c     %c          %c     %c                     \n", 05,05,06,03,03,04,05,05);

    printf(" %c%c%c%c    %c   %c            %c     %c%c%c%c%c     %c       %c             \n", 05,05,05,05,06,03,03,04,04,04,04,04,05,05);

    printf("\n");

    printf("   %c%c%c%c%c         %c%c            %c%c%c%c%c     %c       %c              \n", 06,06,06,06,06,03,03,04,04,04,04,04,05,05);

    printf("     %c          %c  %c          %c          %c     %c                        \n", 06,03,03,04,05,05);

    printf("     %c         %c    %c        %c           %c   %c                          \n", 06,03,03,04,05,05);

    printf("     %c        %c%c%c%c%c%c%c%c       %c           %c %c                      \n", 06,03,03,03,03,03,03,03,03,04,05,05);

    printf("     %c       %c        %c      %c           %c   %c                          \n", 06,03,03,04,05,05);

    printf("   %c %c      %c          %c      %c          %c     %c                       \n", 06,06,03,03,04,05,05);

    printf("    %c%c     %c            %c      %c%c%c%c%c     %c       %c                 \n\n", 06,06,03,03,04,04,04,04,04,05,05);

    printf("=========================================================\n\n\n");

}



void rules()                    /* Displays the rules */

{

    //system("cls");

    printf("\n\n\t\t\tRules of BlackJack\n");

    printf("\t\t\t------------------\n");

    printf("%c The object of the game is to have the value of your cards reach 21\n  without going over\n", 04);

    printf("%c You will initially be dealt 2 cards\n", 04);

    printf("%c Aces hold the value 1\n", 04);

    printf("%c Cards 2 through 10 hold their corresponding value\n", 04);

    printf("%c Jack, Queen, and King hold a value of 10\n", 04);

    printf("%c Each turn, you will have the option to hit (get another card)\n", 04);

    printf("  or stay (don't get another card)\n");

    printf("%c Going over 21 will result in a loss for that round\n\n", 04);

    printf("\n\t\t\t  User Commands\n");

    printf("\t\t\t  -------------\n");

    printf("\t%c Press y for Yes\t\t", 03);

    printf("%c Press h to Hit\n", 03);

    printf("\t%c Press n for No\t\t", 03);

    printf("%c Press s to Stay\n\n\n\n", 03);

}



void game()                     /* Runs the game */

{

    int i = CARDS;

    int condition = 0;

    int humanScore = 0;         /* Declare and */

    int deck[DECK_SIZE];        /* initialize  */

    int computerScore = 0;      /* variables   */

    int HumanCherries = 10;

    int ComputerCherries = 10;

    int humanCard_1;

    int humanCard_2;

    int computerCard_1;

    int computerCard_2;

    int humanNextCards;

    int humanNextCards_2;

    int humanNextCards_3;

    int humanNextCards_4;

    int computerNextCards;

    int computerNextCards_2;

    int computerNextCards_3;

    int computerNextCards_4;

    int humanDealCount = 0;

    int computerDealCount = 0;

    char userDecision;

    char KeepPlaying;

    char dummy;





    InitializeDeck(deck);       /* Initialize deck before game starts */



    do

    {

        //system("cls");          /* Clears the screen */

        printf("==============================================\n"); /* Display how many player and computer cherries remaining */

        printf("Human: %d(Cherries)\tComputer: %d(Cherries)\n", HumanCherries, ComputerCherries);

        printf("-------------------\t----------------------\n");



        ShuffleDeck (deck);                                 /* Shuffle deck before new round */

        humanCard_1 = deck[i];                              /* Store first human card dealt to call at end of round */

        humanScore = humanScore + ScoreCard(deck[i]);       /* Score card value */

        DisplayCard(deck[i]); printf("\t\t\t");             /* Display card on screen */

        i--;                                                /* Moves to next card in the deck */



        computerCard_1 = deck[i];                           /* Store first computer card dealt to call at end of round */

        computerScore = computerScore + ScoreCard(deck[i]); /* Score card value */

        DisplayCard(deck[i]); printf("\t\t\t");             /* Display card on screen */

        i--;                                                /* Moves to next card in the deck */



        printf("\n");



        humanCard_2 = deck[i];                              /* Store second human card dealt to call at end of round */

        humanScore = humanScore + ScoreCard(deck[i]);       /* Score card value */

        DisplayCard(deck[i]); printf("\t\t\t");             /* Display card on screen */

        i--;                                                /* Moves to next card in the deck */



        computerCard_2 = deck[i];                           /* Store second computer card dealt to call at end of round */

        computerScore = computerScore + ScoreCard(deck[i]); /* Score card value */

        printf("%c",178);                                   /* Display hidden computer card */

        i--;                                                /* Moves to next card in the deck */



        printf("\n\nScore: %d\n", humanScore);              /* Display player hand score */





        printf("\nWould you like to hit or stay?\t\t");     /* Prompts the user to hit or stay */

        scanf("%c", &userDecision);

        clean();



        while ((userDecision!='h') && (userDecision!='s'))  /* If invalid choice entered */

        {

            printf("\n");

            printf("Invalid entry. Please Enter h for Hit, and s for Stay\n");

            scanf("%c",&userDecision);

            clean();

        }



        while ((userDecision == 'h') && (humanScore < 21))  /* While user is below 21, ask if he/she */

        {                                                   /* would like to hit */

            printf("\n");



            switch (humanDealCount)                         /* Keeps track of how many additional cards */

            {                                               /* the player is dealt                      */

                case 0: humanNextCards = deck[i];    break;

                case 1: humanNextCards_2 = deck[i];  break;

                case 2: humanNextCards_3 = deck[i];  break;

                case 3: humanNextCards_4 = deck[i];  break;

            }



            humanScore = humanScore + ScoreCard(deck[i]);   /* Score card value */

            printf("You got:  ");

            DisplayCard(deck[i]);                           /* Display card on screen */



            humanDealCount++;                               /* Increase count for number of human dealt cards */

            i--;                                            /* Moves to next card in the deck */



            printf("\n\nScore: %d\n", humanScore);          /* Display player hand score */



            if (humanScore > 21)                            /* If player went bust */

            {                                               /* break out of loop   */

                break;

            }



            if (humanScore == 21)                           /* If player scored a BlackJack */

            {                                               /* break out of loop            */

                break;

            }



            printf("\nWould you like to hit or stay?\t\t"); /* Prompts the user to hit or stay */

            scanf("%c",&userDecision);

            clean();



            while ((userDecision!='h') && (userDecision!='s'))  /* If invalid choice entered */

            {

                printf("\n");

                printf("Invalid entry. Please Enter h for Hit, and s for Stay\n");

                scanf("%c",&userDecision);

                clean();

            }

        }



        while ((computerScore < 15) && (humanScore < 21))   /* Computer continues to hit until it */

        {                                                   /* reaches 15, or player busts        */



                switch (computerDealCount)                  /* Keeps track of how many additional cards */

                {                                           /* the computer is dealt                    */

                    case 0: computerNextCards = deck[i];    break;

                    case 1: computerNextCards_2 = deck[i];  break;

                    case 2: computerNextCards_3 = deck[i];  break;

                    case 3: computerNextCards_4 = deck[i];  break;

                }



            computerScore = computerScore + ScoreCard(deck[i]);

            printf("\n\t\t\tComputer got:  ");

            DisplayCard(deck[i]);                           /* Display card on screen */

            printf("\n\t\t\t");                             /* Score card value */



            computerDealCount++;                            /* Increase count for number of computer dealt cards */

            i--;                                            /* Moves to next card in the deck */

        }



        printf("\nYour Hand\t\tComputer Hand\n---------\t\t-------------\n");



        DisplayCard(humanCard_1); printf("\t\t\t");     /* Display first card player was dealt */

        DisplayCard(computerCard_1); printf("\n");      /* Display first card computer was dealt */

        DisplayCard(humanCard_2); printf("\t\t\t");     /* Display second card player was dealt */

        DisplayCard(computerCard_2); printf("\n");      /* Display second card computer was dealt */



        if (humanDealCount > 0)

        {

            DisplayCard(humanNextCards);                            /* If player hit at least once, display that card */

            humanDealCount--;                                       /* Decrease count by one */

        }



        if (computerDealCount > 0)

        {

            printf("\t\t\t"); DisplayCard(computerNextCards);       /* If computer hit at least once, display that card */

            computerDealCount--;                                    /* Decrease count by one */

        }



        if (humanDealCount > 0)

        {

            printf("\n"); DisplayCard(humanNextCards_2);            /* If player hit twice, display that card */

            humanDealCount--;                                       /* Decrease count by one */

        }



        if (computerDealCount > 0)

        {

            printf("\n\t\t\t"); DisplayCard(computerNextCards_2);   /* If computer hit twice, display that card */

            computerDealCount--;                                    /* Decrease count by one */

        }



        if (humanDealCount > 0)

        {

            printf("\n"); DisplayCard(humanNextCards_3);            /* If player hit three times, display that card */

            humanDealCount--;                                       /* Decrease count by one */

        }



        if (computerDealCount > 0)

        {

            printf("\n\t\t\t"); DisplayCard(computerNextCards_3);   /* If computer hit three times, display that card */

            computerDealCount--;                                    /* Decrease count by one */

        }



        if (humanDealCount > 0)

        {

            printf("\n"); DisplayCard(humanNextCards_4);            /* If player hit four times, display that card */

        }



        if (computerDealCount > 0)

        {

            printf("\n\t\t\t"); DisplayCard(computerNextCards_4);   /* If computer hit four times, display that card */

        }





        printf("\n\n\nScore: %d\t\tScore: %d\n", humanScore, computerScore);    /* Display player and computer scores */



        while (condition == 0)

        {



            if (humanScore == 21)                                         /* If player scored a BlackJack */

            {

                printf("\nBLACKJACK! You won this round!");

                condition = 1;                                            /* Condition equal to one means */

                break;                                                    /* a player victory             */

            }



            if (computerScore == 21)

            {

                printf("\nBLACKJACK! The computer won this round!");

                condition = 2;                                            /* Condition equal to two means */

                break;                                                    /* a computer victory           */

            }





            if (humanScore > 21)                                          /* If player went bust */

            {

                printf("\nYou went bust!\nThe Computer won this round!");

                condition = 2;

                break;

            }



            if (computerScore > 21)                                       /* If computer went bust */

            {

                printf("\nThe computer went bust!\nYou won this round!");

                condition = 1;

                break;

            }



            if (computerScore > humanScore)                               /* Computer win */

            {

                printf("\nThe Computer won this round!");

                condition = 2;

                break;

            }



            if (humanScore > computerScore)                               /* player win */

            {

                printf("\nYou won this round!");

                condition = 1;

                break;

            }

             if (computerScore == humanScore)                             /* Tie */

            {

                printf("\nIts a tie!");

                break;

            }



        }

            switch (condition)

        {

            case 1:

            HumanCherries++;                        /* Take a computer cherry and give to player */

            ComputerCherries--;

            break;



            case 2:                                 /* Take a player cherry and give to computer */

            HumanCherries--;

            ComputerCherries++;

            break;

        }





        i = CARDS;

        condition = 0;              /* Reset round based */

        humanScore = 0;             /* variables to zero */

        computerScore = 0;

        humanDealCount = 0;

        computerDealCount = 0;





        if (ComputerCherries == 0)      /* Player has won the game */

        {

            printf("\n\n\n   %c %c %c %c %c %c %c %c %c %c", 04,04,04,04,04,04,04,04,04,04);

            printf(" Congratulations, you won the game! ");

            printf("%c %c %c %c %c %c %c %c %c %c", 04,04,04,04,04,04,04,04,04,04);

            printf("\n\n\t\tPress any key to return to the main menu");

            scanf("%c", &dummy);        /* Scan dummy so it does not immediately break to home screen */

            clean();

            break;

        }

        if (HumanCherries == 0)         /* Computer has won the game */

        {

            printf("\n\n\n    %c %c %c %c %c %c %c %c %c %c", 04,04,04,04,04,04,04,04,04,04);

            printf(" Too bad, you lost the game! ");

            printf("%c %c %c %c %c %c %c %c %c %c", 04,04,04,04,04,04,04,04,04,04);

            printf("\n\n\t\tPress any key to return to the main menu");

            scanf("%c", &dummy);        /* Scan dummy so it does not immediately break to home screen */

            clean();

            break;

        }



        printf("\n\nWould you like to keep playing?\n");    /* Keep game going while user enters yes */

        scanf("%c", &KeepPlaying);

        clean();



        while((KeepPlaying!='y') && (KeepPlaying!='n'))     /* If invalid choice entered */

        {

            printf("\n");

            printf("Invalid entry. Please Enter y for Yes, and n for No\n");

            scanf("%c",&KeepPlaying);

            clean();

        }                                                                               /* Exit game when player or computer */

    }while ((HumanCherries > 0) && (ComputerCherries > 0) && (KeepPlaying == 'y'));     /* runs out of cherries              */



}





void InitializeDeck(int deck[])             /* Takes an integer array and assigns it values */

{                                           /* for a full deck of cards                     */

    int i;



    for (i = 0; i < DECK_SIZE; i++)

    {

        deck[i] = i;

    }

}





int randomInRange(int lower, int upper)     /* Generates a random number between the given boundaries */

{

    return rand() % ( upper - lower + 1) + lower;

}





void ShuffleDeck (int deck[])               /* Shuffles the deck of cards */

{

    int i;

    int c;

    int holder;



    for (i = DECK_SIZE - 2; i > 0; i--)

    {

        c = randomInRange(0, i);



        holder = deck[i];

        deck[i] = deck[c];

        deck[c] = holder;

    }

}



void DisplayCard (int card)                 /* Displays rank and suit of a card */

{

    int holder = card;



    card = card % 13;



    switch (card)

    {

        case 0: printf("A");         break;

        case 1: printf("2");         break;

        case 2: printf("3");         break;

        case 3: printf("4");         break;

        case 4: printf("5");         break;

        case 5: printf("6");         break;

        case 6: printf("7");         break;

        case 7: printf("8");         break;

        case 8: printf("9");         break;

        case 9: printf("10");        break;

        case 10: printf("J");        break;

        case 11: printf("Q");        break;

        case 12: printf("K");        break;

    }



    int suit = holder / 13;



    switch (suit)

    {

        case 0: printf("%c", 06);   break;

        case 1: printf("%c", 03);   break;

        case 2: printf("%c", 04);   break;

        case 3: printf("%c", 05);   break;

    }

}



int ScoreCard (int score)                   /* Returns the value of a card */

{

    score = score % 13;



    switch(score)

    {

        case 0: score = 1;        break;

        case 1: score = 2;        break;

        case 2: score = 3;        break;

        case 3: score = 4;        break;

        case 4: score = 5;        break;

        case 5: score = 6;        break;

        case 6: score = 7;        break;

        case 7: score = 8;        break;

        case 8: score = 9;        break;

        case 9: score = 10;       break;

        case 10: score = 10;      break;

        case 11: score = 10;      break;

        case 12: score = 10;      break;

    }



    return score;

}
