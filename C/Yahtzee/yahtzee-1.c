#include <stdio.h>
#include <stdlib.h>

    void gameRules ();
    void displayExplicitDice ();
    void clearScreen ();
int main() {
    gameRules ();
    clearScreen ();
    displayExplicitDice ();

return 0;
}

void gameRules (){
    printf("\t\t\t\tLET'S PLAY YAHTZEE!!!!!! \n\n");
    printf("RULES OF THE GAME:\n");
    printf("\t1. The scorecard used for Yahtzee is composed of an upper section and a lower section.\n");
    printf("\t2. A total of 13 scoring combinations are divided amongst the sections.\n");
    printf("\t3. The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box\n.");
    printf("\t4. If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
    printf("\t5. Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
    printf("\t6. If the sum of the cores in the upper section is greater than or equal to 63, then 35 more points are added\n");
    printf("\tto the players overall score as a bonus. The lower section contains a number of poker like combinations.\n\n");
}
void clearScreen (){
    printf("\t\t\t\tHit <ENTER> to play!\n");
    char enter;
    scanf( "%c",&enter );

    system ("cls");
  //system ("clear");
}


    void displayExplicitDice (){
    printf("|------------------------------------------|\n");
    printf("|       |        |        |        |       |\n");
    printf("|   1   |    2   |    3   |    4   |   5   |\n");
    printf("|       |        |        |        |       |\n");
    printf("|------------------------------------------|\n");


}



