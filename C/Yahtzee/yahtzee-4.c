#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

//Game Menu
#define RULES 1
#define GAME 2
#define EXIT 3
#define ROLLS 3
#define CATEGORIES 13

//Contols
#define COL 1
#define COLS 2
#define ZERO 0

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

//Game Interfaces prototype functions
int rollDeath ();
void gameRules ();
void clearScreen ();
int displayGameMenu ();
void initializeDice ();
void playGame ();
void displayDice ();
void resetKeep ();
void rollDice ();
void initializeScores ();
int selectCategory ();
void selectDice ();
void updateScores ();
void displayScoreCard ();
void displayUpperSection ();
void displayLowerSection ();

//enum for indexes
enum scores {
    one, two, three, four, five, six,
    threekind, fourkind, fullhouse, smstraight, lgstraight,
    yahtzee, chance};
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
                printf("Invalid option, enter a number listed above and try again.\n\n");
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
    int scoreCard[CATEGORIES][COLS];
    int roll, turn, category;
    int dice[DICE], keep[DICE];
    initializeScores(scoreCard);

    for(turn = 0; turn < TURNS; ++turn){

        //Turn Counter
        int current = turn + 1;
        printf("~Turn %d of game~\n\n", current);

        initializeDice(dice);
        resetKeep(keep);
        fflush(stdin);

        //Rolling dice "Animation"
        for(roll = 0; roll < ROLLS; ++roll){
            printf("Rolling dice . . .\n");
            printf("Done!\n\n");
            rollDice(dice, keep);
            displayDice(dice);

            if(roll < TWO){
                selectDice(dice, keep);
                //printf("Print out\n\n");
            }
        }
    category = selectCategory();
    updateScores(scoreCard, category);
    displayScoreCard(scoreCard);
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

    //scanf("%c", &enter);
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

void initializeScores(int scoreCard[CATEGORIES][COLS]){
    int row, col;
    for(row = 0; row < CATEGORIES; ++row){
        for(col = 0; col < COLS; ++col){
            if(col == 0){
                scoreCard[CATEGORIES][COLS] = col;
            }
            else{
                scoreCard[CATEGORIES][COLS] = 0;
            }
        }
    }
}

int selectCategory(){
    int select;

    printf("%d. Ones\n", ONE);
    printf("%d. Twos\n", TWO);
    printf("%d. Threes\n", THREE);
    printf("%d. Fours\n", FOUR);
    printf("%d. Fives\n", FIVE);
    printf("%d. Sixes\n", SIX);
    printf("%d. Three of a kind\n", THREEKIND);
    printf("%d. Four of a kind\n", FOURKIND);
    printf("%d. Full house\n", FULLHOUSE);
    printf("%d. Small straight\n", LGSTRAIGHT);
    printf("%d. Large straight\n", SMSTRAIGHT);
    printf("%d. Yahtzee\n", YAHTZEE);
    printf("%d. Chance\n", CHANCE);

    scanf("%d", &select);
    fflush(stdin);

    return select;
}

void selectDice(int dice[DICE], int keep[DICE]){
    int die, valid;
    char data[10];
    char* value;

    resetKeep(keep);
    printf("\n");
    printf("Select dice to keep, enter values 1 through 5 with spaces between numbers.\n");

    fgets(data,10,stdin);
    value = strtok(data, " ");
    //printf("Print");

    while(value != NULL){
        valid = 0;
        while(valid == 0){
            printf("\n");
            switch(*value){
            case '1':
                printf("die 1 selected to keep.\n\n");
                keep[0] = 1;
                valid = 1;
                break;
            case '2':
                printf("die 2 selected to keep.\n\n");
                keep[1] = 1;
                valid = 1;
                break;

            case '3':
                printf("die 3 selected to keep.\n\n");
                keep[2] = 1;
                valid = 1;
                break;

            case '4':
                printf("die 4 selected to keep.\n\n");
                keep[3] = 1;
                valid = 1;
                break;

            case '5':
                printf("die 5 selected to keep.\n\n");
                keep[4] = 1;
                valid = 1;
                break;

            default:
                printf("Switch machine broke\n\n");
                valid = 1;
                break;
            }
        value = strtok(NULL, " ");
        }
        //printf("Print 3");
        //strtok(NULL, s);
    }
}

void updateScores(int scoreCard[CATEGORIES][COLS], int category){
    switch(category){
    case ONE:
        printf("\nScoring Ones...\n");
        break;


    case TWO:
        printf("\nScoring Twos...\n");
        break;

    case THREE:
        printf("\nScoring Threes...\n");
        break;

    case FOUR:
        printf("\nScoring Fours..\n");
        break;

    case FIVE:
        printf("\nScoring Fives...\n");
        break;

    case SIX:
        printf("\nScoring Sixes...\n");
        break;

    case THREEKIND:
        printf("\nScoring Three of a Kind...\n");
        break;

    case FOURKIND:
        printf("\nScoring Four of a Kind...\n");
        break;

    case FULLHOUSE:
        printf("\nScoring Full House...\n");
        break;

    case SMSTRAIGHT:
        printf("\nScoring Small Straight...\n");
        break;

    case LGSTRAIGHT:
        printf("\nScoring Large Straight...\n");
        break;

    case YAHTZEE:
        printf("\nScoring Yahtzee...\n");
        break;

    case CHANCE:
        printf("\nScoring Chance...\n");
        break;
    }
}

void displayScoreCard(int scoreCard[CATEGORIES][COLS]){
    printf("\t\tYAHTZEE SCORECARD\n");
    printf("\t===================================\n\n");
    displayUpperSection(scoreCard);
    displayLowerSection(scoreCard);

    printf("+--------------+---------+\n");
    printf("| TOTAL (Upper)|    0    |\n");
    printf("+--------------+---------+\n");
    printf("| GRAND TOTAL  |    0    |\n");
    printf("+--------------+---------+\n");

}

void displayUpperSection(int scoresCard[CATEGORIES][COLS]){
    printf("+-----------------+-------------+\n");
    printf("|  UPPER SECTION  |    SCORE    |\n");
    printf("+-----------------+-------------+\n");
    printf("|      ONES       |      %d      |\n",scoresCard[one][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|      TWOS       |      %d      |\n",scoresCard[two][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|      THREES     |      %d      |\n",scoresCard[three][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|      FOURS      |      %d      |\n",scoresCard[four][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|      FIVES      |      %d      |\n",scoresCard[five][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|      SIXES      |      %d      |\n",scoresCard[six][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|   TOTAL SCORE   |      0      |\n");
    printf("+-----------------+-------------+\n");
    printf("|      BONUS      |      0      |\n");
    printf("+-----------------+-------------+\n");
    printf("|      SCORE      |      0      |\n");
    printf("+-----------------+-------------+\n");
}

void displayLowerSection(int scoresCard[CATEGORIES][COLS]){
    printf("+-----------------+-------------+\n");
    printf("|  LOWER SECTION  |    SCORE    |\n");
    printf("+-----------------+-------------+\n");
    printf("| THREE OF A KIND |      %d      |\n",scoresCard[threekind][COLS]);
    printf("+-----------------+-------------+\n");
    printf("| FOUR OF A KIND  |      %d      |\n",scoresCard[fourkind][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|   FULL HOUSE    |      %d      |\n",scoresCard[fullhouse][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|   SM STRAIGHT   |      %d      |\n",scoresCard[smstraight][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|   LG STRAIGHT   |      %d      |\n",scoresCard[lgstraight][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|     YAHTZEE     |      %d      |\n",scoresCard[yahtzee][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|     CHANCES     |      %d      |\n",scoresCard[chance][COLS]);
    printf("+-----------------+-------------+\n");
    printf("|  TOTAL (lower)  |      0      |\n");
    printf("+-----------------+-------------+\n");




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
