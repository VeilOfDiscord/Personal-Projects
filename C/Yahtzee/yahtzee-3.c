#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Game Menu
#define RULES 1
#define GAME 2
#define EXIT 3
#define ROLLS 3
#define CATEGORIES 13

//Dice
#define DICE 5
#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6

//Dice Rolls
#define THREEKIND 7
#define FOURKIND 8
#define FULLHOUSE 9
#define SMSTRAIGHT 10
#define LGSTRAIGHT 11
#define YAHTZEE 12

//Others
#define CHANCE 13
#define TURNS 13

//Game Interfaces
int rollDeath ();
void gameRules ();
void clearScreen ();
int displayGameMenu ();
void initializeDice ();
void playGame ();
void displayDice ();
void resetKeep ();
void rollDice ();
//void displayExplicitDice ();
//void displayRandomDice ();

//All commented out printf functions were used to test if the program was running.

int main() {

    int play = 1;
    srand(time(0));
    printf("\t\t\t\tLET'S PLAY YAHTZEE!!! \n\n");

    while(play == 1){
        switch(displayGameMenu())
        {
            case RULES:
                clearScreen();
                gameRules ();
                break;

            case GAME:
                clearScreen();
                //displayRandomDice ();
                playGame ();
                break;

            case EXIT:
                printf("Thank you for playing Yahtzee!");
                play = 0;
                break;

            default:
                printf("Incorrect option, enter a number listed above and try again.\n\n");
                break;
        }

    }
    return 0;
}

//Main Menu
int displayGameMenu (){

    int select = 0;
    do
    {
        printf("%d. Display game rules.\n", RULES);
        printf("%d. Start a game of Yahtzee.\n",GAME);
        printf("%d. Exit the game.\n\n", EXIT);

        printf("\t\t\t-=Enter a <NUMBER> above to continue=-\t\t\n");

        scanf("%d", &select);
        //printf("%d", select);
    }
    while(select == RULES && select == GAME && select == EXIT);


return select;
}

//Randomizer
int rollDeath(){

    int dieValue = 0;
    dieValue = (rand() % 6 )+ 1;
    //printf( "rollDeath return dieValue %d\n", dieValue);

    return dieValue;
}

void gameRules (){
    printf("\t\t\t\tLET'S PLAY YAHTZEE!!! \n\n");
    printf("RULES OF THE GAME:\n");
    printf("\t1. The scorecard used for Yahtzee is composed of an upper section and a lower section.\n");
    printf("\t2. A total of 13 scoring combinations are divided amongst the sections.\n");
    printf("\t3. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box\n.");
    printf("\t4. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
    printf("\t5. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
    printf("\t6. If the sum of the cores in the upper section is greater than or equal to 63, then 35 more points are added\n");
    printf("\tto the players overall score as a bonus. The lower section contains a number of poker like combinations.\n\n\n");
}
void clearScreen (){
    //printf("\t\t\t\tHit <ENTER> to continue.\n");
    char enter;
    scanf( "%c",&enter );

    system ("cls");
  //system ("clear");
}

//Set everything to zero.
void initializeDice (int dice[DICE]){
    int die;

    for(die = 0; die < DICE; ++die){
        dice[die] = 0;
    }
}

//Press Play!
void playGame (){
    int roll, turn;
    int dice[DICE], keep[DICE];

    for(turn = 0; turn < TURNS; ++turn){

        //Turn Counter
        int current = turn + 1;
        printf("~Turn %d of game~\n\n", current);

        initializeDice(dice);

        //Rolling dice "Animation"
        for(roll = 0; roll < ROLLS; ++roll){
            resetKeep(keep);
            printf("Rolling dice . . .\n");
            printf("Done!\n\n");
            rollDice(dice, keep);
            displayDice(dice);
        }
    }
}

//Dice Rolls Output
void displayDice(int dice[DICE]){
    int die;                //Looping variable
    char enter;             //For Screen Pausing

    //Display first two lines of dice box
    printf("+-------+ +-------+ +-------+ +-------+ +-------+\n");
    printf("|       | |       | |       | |       | |       |\n");

    for(die = 0; die < DICE; ++die){
       // printf("%d", dice[die]);
        printf("|   %d   | ",dice[die]);

    }
    printf("\n");
    //Display last two lines of dice box
    printf("|       | |       | |       | |       | |       |\n");
    printf("+-------+ +-------+ +-------+ +-------+ +-------+\n");

    scanf("%c", &enter);
}

//Keep
void resetKeep (int keep[DICE]){
    int die;
    for(die = 0; die < DICE; ++die){
        keep[die] = 0;
    }
}

//House Roll
void rollDice(int dice[DICE], int keep[DICE]){
    int die;
    //printf( "\nrollDice start.\n");
    for(die = 0; die < DICE; ++die){
        //printf ( "die: %d ", die);
        if(keep[die] == 0){
            dice[die] = rollDeath();
        }
    }
    //printf( "rollDice exit.\n");
}

//Unused Dice Displays from previous iterations of Yahtzee below.

/*void displayExplicitDice (){
    printf("|------------------------------------------|\n");
    printf("|       |        |        |        |       |\n");
    printf("|   1   |    2   |    3   |    4   |   5   |\n");
    printf("|       |        |        |        |       |\n");
    printf("|------------------------------------------|\n");
}
*/
//Random Dice
/*void displayRandomDice (){
    int numRolls;                                               //looping variable
    int firstDie, secondDie, thirdDie, fourthDie, fifthDie;

    for(numRolls = 0; numRolls <= ROLLS; ++numRolls)
    {
        firstDie = rollDeath();
        secondDie = rollDeath();
        thirdDie = rollDeath ();
        fourthDie = rollDeath ();
        fifthDie = rollDeath ();

        printf("|------------------------------------------|\n");
        printf("|       |        |        |        |       |\n");
        printf("|   %d   |    %d   |    %d   |    %d   |   %d   |\n",firstDie, thirdDie,secondDie,fourthDie,fifthDie);
        printf("|       |        |        |        |       |\n");
        printf("|------------------------------------------|\n");
        printf("|------------------------------------------|\n");
        printf("|       |        |        |        |       |\n");
        printf("|   %d   |    %d   |    %d   |    %d   |   %d   |\n", fourthDie, secondDie,thirdDie,firstDie,fifthDie);
        printf("|       |        |        |        |       |\n");
        printf("|------------------------------------------|\n");
        printf("|------------------------------------------|\n");
        printf("|       |        |        |        |       |\n");
        printf("|   %d   |    %d   |    %d   |    %d   |   %d   |\n", secondDie, firstDie,fifthDie,firstDie,thirdDie);
        printf("|       |        |        |        |       |\n");
        printf("|------------------------------------------|\n\n\n");
   }
}
*/
