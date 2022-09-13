#ifndef YATHZEE_H_INCLUDED
#define YATHZEE_H_INCLUDED

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

//yathzee 4 preprocessors
void sortDice(int dice[DICE]);
int sumCategory(int dice[DICE], int category);
int sumUpper(int scoreCard[CATEGORIES][COLS]);
int sumLower(int scoreCard[CATEGORIES][COLS]);
int checkSmStraight(int dice [DICE]);
int checkLgStraight(int dice[DICE]);
int checkYahtzee(int dice [DICE]);
int checkFourKind(int dice[DICE]);
int checkThreeKind(int tempdice[DICE]);
int checkBonus(int scoreCard[CATEGORIES][COLS]);
int sumChance(int dice[DICE]);
int checkFullHouse(int dice[DICE]);

//enum for indexes
enum scores {
    one, two, three, four, five, six,
    threekind, fourkind, fullhouse, smstraight, lgstraight,
    yahtzee, chance};

#endif // YATHZEE_H_INCLUDED
