#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "yathzee.h"

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

    return dieValue;
}

//Game rules interface
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

//Screen clearing function
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
    updateScores(scoreCard, category, dice);
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

//User dices kept here
void resetKeep (int keep[DICE]){
    int die;
    for(die = 0; die < DICE; ++die){
        keep[die] = 0;
    }
}

//House Rolls the dice
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

//Preparing the scores, setting them to 0
void initializeScores(int scoreCard[CATEGORIES][COLS])
{
    int row;
    int col;

    for(row = 0; row < CATEGORIES; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            if(col == ZERO)
                scoreCard[row][col] = row;
            else
                scoreCard[row][col] = ZERO;
        }
    }
}

//Scoring categories
int selectCategory(){
    int select;

    printf("\n\nSelect category for dice\n");
    printf("%d. Ones\n", ONE);
    printf("%d. Twos\n", TWO);
    printf("%d. Threes\n", THREE);
    printf("%d. Fours\n", FOUR);
    printf("%d. Fives\n", FIVE);
    printf("%d. Sixes\n", SIX);
    printf("%d. Three of a kind\n", THREEKIND);
    printf("%d. Four of a kind\n", FOURKIND);
    printf("%d. Full house\n", FULLHOUSE);
    printf("%d. Small straight\n", SMSTRAIGHT);
    printf("%d. Large straight\n", LGSTRAIGHT);
    printf("%d. Yahtzee\n", YAHTZEE);
    printf("%d. Chance\n", CHANCE);

    scanf("%d", &select);

    fflush(stdin);

    return select;
}

//Dice selection/ which to keep interface
void selectDice(int dice[DICE], int keep[DICE]){
    int die = 0;
    int valid = 0;
    char data[20];
    char * value;

    resetKeep(keep);

    printf("\nSelect dice to keep, enter values 1 through 5 with spaces between numbers.\n");

    fgets(data,20,stdin);

    value = strtok(data, " ");
    //printf("Print");

    while(value != NULL)
        {
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
        }
        value = strtok(NULL, " ");
        //printf("Print 3");
        //strtok(NULL, s);
    }
}

void updateScores(int scoreCard[CATEGORIES][COLS], int category, int dice[five]){
    switch(category){
    case ONE:
        printf("\nScoring Ones...\n");
        scoreCard[one][COL] = sumCategory(dice, category);
        break;


    case TWO:
        printf("\nScoring Twos...\n");
        scoreCard[two][COL] = sumCategory(dice, category);
        break;

    case THREE:
        printf("\nScoring Threes...\n");
        scoreCard[three][COL] = sumCategory(dice, category);
        break;

    case FOUR:
        printf("\nScoring Fours..\n");
        scoreCard[four][COL] = sumCategory(dice, category);
        break;

    case FIVE:
        printf("\nScoring Fives...\n");
        scoreCard[five][COL] = sumCategory(dice, category);
        break;

    case SIX:
        printf("\nScoring Sixes...\n");
        scoreCard[six][COL] = sumCategory(dice, category);
        break;

    case THREEKIND:
        printf("\nScoring Three of a Kind...\n");
        scoreCard[threekind][COL] = checkThreeKind(dice);
        break;

    case FOURKIND:
        printf("\nScoring Four of a Kind...\n");
        scoreCard[fourkind][COL] = checkFourKind(dice);
        break;

    case FULLHOUSE:
        printf("\nScoring Full House...\n");
        scoreCard[fullhouse][COL] = checkFullHouse(dice);
        break;

    case SMSTRAIGHT:
        printf("\nScoring Small Straight...\n");
        scoreCard[smstraight][COL] = checkSmStraight(dice);
        break;

    case LGSTRAIGHT:
        printf("\nScoring Large Straight...\n");
        scoreCard[lgstraight][COL] = checkLgStraight(dice);
        break;

    case YAHTZEE:
        printf("\nScoring Yahtzee...\n");
        scoreCard[yahtzee][COL] = checkYahtzee(dice);
        break;

    case CHANCE:
        printf("\nScoring Chance...\n");
        scoreCard[chance][COL] = sumChance(dice);
        break;
        }
    }

void displayScoreCard(int scoreCard[CATEGORIES][COLS]){
    int total = 0;
    int grandTotal = 0;

    printf("\t\tYAHTZEE SCORECARD\n");
    printf("\t===================================\n\n");

    //printf("first: %d\n", sumLower(scoreCard));
    displayUpperSection(scoreCard);
    displayLowerSection(scoreCard);

    total = (sumUpper(scoreCard) + checkBonus(scoreCard));

    //printf("\n\nbelow total:%d\n", sumLower(scoreCard));

    grandTotal = total + sumLower(scoreCard);

    //printf("\n\nbelow grand total:%d\n", sumLower(scoreCard));

    printf("\n\n+--------------+----------+\n");
    printf("| TOTAL (Upper)|    %d    |\n", total);
    printf("+--------------+----------+\n");
    printf("| GRAND TOTAL  |    %d    |\n", grandTotal);
    printf("+--------------+----------+\n");

    //printf("\n\nbelow below%d\n", sumLower(scoreCard));

}

void displayUpperSection(int scoresCard[CATEGORIES][COLS]){
    int bonus;
    int totalScore;
    int total;

    bonus = checkBonus(scoresCard);
    totalScore = sumUpper(scoresCard);
    total = bonus + totalScore;

    printf("+-----------------+-------------+\n");
    printf("|  UPPER SECTION  |    SCORE    |\n");
    printf("+-----------------+-------------+\n");
    printf("|      ONES       |      %d      |\n",scoresCard[one][COL]);
    printf("+-----------------+-------------+\n");
    printf("|      TWOS       |      %d      |\n",scoresCard[two][COL]);
    printf("+-----------------+-------------+\n");
    printf("|      THREES     |      %d      |\n",scoresCard[three][COL]);
    printf("+-----------------+-------------+\n");
    printf("|      FOURS      |      %d      |\n",scoresCard[four][COL]);
    printf("+-----------------+-------------+\n");
    printf("|      FIVES      |      %d      |\n",scoresCard[five][COL]);
    printf("+-----------------+-------------+\n");
    printf("|      SIXES      |      %d      |\n",scoresCard[six][COL]);
    printf("+-----------------+-------------+\n");
    printf("|   TOTAL SCORE   |      %d      |\n", totalScore);
    printf("+-----------------+-------------+\n");
    printf("|      BONUS      |      %d      |\n", bonus);
    printf("+-----------------+-------------+\n");
    printf("|      SCORE      |      %d      |\n", total);
    printf("+-----------------+-------------+\n");
}

void displayLowerSection(int scoresCard[CATEGORIES][COLS]){
    int total;

    total = sumLower(scoresCard);

    printf("+-----------------+-------------+\n");
    printf("|  LOWER SECTION  |    SCORE    |\n");
    printf("+-----------------+-------------+\n");
    printf("| THREE OF A KIND |      %d      |\n",scoresCard[threekind][COL]);
    printf("+-----------------+-------------+\n");
    printf("| FOUR OF A KIND  |      %d      |\n",scoresCard[fourkind][COL]);
    printf("+-----------------+-------------+\n");
    printf("|   FULL HOUSE    |      %d      |\n",scoresCard[fullhouse][COL]);
    printf("+-----------------+-------------+\n");
    printf("|   SM STRAIGHT   |      %d      |\n",scoresCard[smstraight][COL]);
    printf("+-----------------+-------------+\n");
    printf("|   LG STRAIGHT   |      %d      |\n",scoresCard[lgstraight][COL]);
    printf("+-----------------+-------------+\n");
    printf("|     YAHTZEE     |      %d      |\n",scoresCard[yahtzee][COL]);
    printf("+-----------------+-------------+\n");
    printf("|     CHANCES     |      %d      |\n",scoresCard[chance][COL]);
    printf("+-----------------+-------------+\n");
    printf("|  TOTAL (lower)  |      %d      |\n", total);
    printf("+-----------------+-------------+\n");
}


int sumCategory(int dice[DICE], int category)
{
    int sum;
    int die;

    for(die = 0; die < DICE; die++)
    {
        switch(category)
        {
        case ONE:
            if(dice[die] == ONE)
                sum += dice[die];
            break;

        case TWO:
            if(dice[die] == TWO)
                sum += dice[die];
            break;

        case THREE:
            if(dice[die] == THREE)
                sum += dice[die];
            break;

        case FOUR:
            if(dice[die] == FOUR)
                sum += dice[die];
            break;

        case FIVE:
            if(dice[die] == FIVE)
                sum += dice[die];
            break;

        case SIX:
            if(dice[die] == SIX)
                sum += dice[die];
            break;
        }
    }
    return sum;
}

int sumChance(int dice[DICE])
{
    int sum;
    int die;

    for(die = 0; die < dice[die]; ++die){
        sum += dice[die];
    }
    return sum;
}

int checkLgStraight(int dice[DICE])
{
    int sum;

// Combinations of a large Straight
// 1, 2, 3, 4, 5
// 2, 3, 4, 5, 6

    sortDice(dice);

    if(dice[two]    == dice[one]   + 1 &&
       dice[three]  == dice[two]   + 1 &&
       dice[four]   == dice[three] + 1 &&
       dice[five]   == dice[four]  + 1)
       {
        sum = 40;
       }
    else
        {
        sum = 0;
        }
    return sum;
}

int checkSmStraight(int dice[DICE])
{
    int sum;

// Combinations of a small Straight
// 1, 2, 3, 4
// 2, 3, 4, 5
// 3, 4, 5, 6

    sortDice(dice);

     if(dice[two]   == (dice[one]   + 1) &&
       dice[three]  == (dice[two]   + 1) &&
       dice[four]   == (dice[three] + 1))
        {
        sum = 30;
        }
    else if(dice[three] == (dice[two]   + 1) &&
            dice[four]  == (dice[three] + 1) &&
            dice[five]  == (dice[four]  + 1))
        {
        sum = 30;
        }
    else
    {
        sum = 0;
    }
    return sum;
}

int checkYahtzee(int dice[DICE]){
    int sum;

    if(dice[one] == dice[two] &&
       dice[two] == dice[three] &&
       dice[three] == dice[four] &&
       dice[four] == dice[five] &&
       dice[five] == dice[six]){
        sum = 50;
    }
    else{
        sum = 0;
    }
    return sum;
}

int checkFourKind(int dice[DICE]){
    int sum;
    int die;
    int count;

//Index values for a Three of a kind
// 0, 1, 2
// 1, 2, 3
// 2, 3, 4

    sortDice(dice);

    if(dice[one] == dice[two]){
        die = one;
    }
    else if (dice[two] == dice[three]){
        die = two;
    }
    /*
    else if (dice[three] == dice[four]){
        die = three;
    }
    */

    for(die < DICE; die++;){
        if (dice[die] == (dice[die]+ 1)){
            count++;
        }
    }
    if(count > 0){
        for(die = 0; die < DICE; die++){
            sum += dice[die];
        }
    }
    else
    {
    sum = 0;
    }

    return sum;
}

int checkThreeKind(int dice[DICE]){
    int sum;
    int die;
    int count;

//Index values for a Three of a kind
// 0, 1, 2
// 1, 2, 3
// 2, 3, 4

    sortDice(dice);

    if(dice[one] == dice[two]){
        die = one;
    }
    else if (dice[two] == dice[three]){
        die = two;
    }
    else if (dice[three] == dice[four]){
        die = three;
    }

    for(die < DICE; die++;){
        if (dice[die] == (dice[die]+ 1)){
            count++;
        }
    }
    if(count > 0){
        for(die = 0; die < DICE; die++){
            sum += dice[die];
        }
    }
    else
    {
    sum = 0;
    }

    return sum;
}

int checkFullHouse(int dice[DICE]){
    int sum;
    int die;
    int count;
    int pair;
    int threeOfKind;

    sortDice(dice);

    //Can I just call checkThreeKind Function?
    if(dice[one] == dice[two]){
        die = 0;
    }
    else if (dice[two] == dice[three]){
        die = 1;
    }
    else if (dice[three] == dice[four]){
        die = 2;
    }

    for(die < DICE; die++;){
        if (dice[die] == (dice[die]+ 1)){
            count += 1;
        }
    }
    if(count > 0){
    for(die = 0; die < DICE; die++){
            threeOfKind += dice[die];
        }
    }
    else
    {
    threeOfKind = 0;
    }

//Index positions for the pairs
// 0, 1
// 3, 4
    if(threeOfKind != 0){
        if(dice[one] == dice[two]){
            sum = 25;
        }
        else if (dice[four] == dice[five]){
            sum = 25;
        }
        else{
            sum = 0;
        }
    }
    else{
        sum = 0;
    }

    return sum;
}

int sumUpper(int scoreCard[CATEGORIES][COLS]){
    int sum = 0;
    int i;
    //Loop through the 2d array to add the score of each of the six categories to variable sum

    for(i = 0; i <= DICE; ++i){
        sum += scoreCard[i][COL];
    }

    return sum;
}

int sumLower(int scoreCard[CATEGORIES][COLS]){
    int sum = 0;
    int i;
    //Loop through the 2d array to add the score of each of the six categories to variable sum

    for(i = 0; i <= DICE; ++i){
        sum += scoreCard[i+6][COL];
    }
    return sum;
}

int checkBonus(int scoreCard[CATEGORIES][COLS]){
    int i;
    int sum;
    int score;
    //Loop through the 2d array to add the score of each of the six categories of the upper section (i.e. enum one through six) to variable sum

    for(i = 0; i <= DICE; ++i){
        score += scoreCard[i][COL];
    }

    if(score >= 63){
        sum = 35;
    }
    else{
        sum = 0;
    }

    return sum;
}

void sortDice(int dice[DICE]){
   int temp, i, j, k;

   for (j = 0; j < DICE; ++j)
   {
      for (k = j + 1; k < DICE; ++k)
      {
         if (dice[j] > dice[k])
         {
            temp = dice[j];
            dice[j] = dice[k];
            dice[k] = temp;
         }
      }
   }
}
