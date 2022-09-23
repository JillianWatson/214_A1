#include <stdio.h>
#include <err.h>
#include <math.h>

// Function that takes two args to calculate the Xp amount for the hero when defeating a monster.
// int MonsterLvl: must be between 0 and 50 (inclusive). 
// int MonsterType: must be between 1 and 3 (inclusive). 
// return: the Xp amount for the monster
double CalcXpBase(int MonsterLvl, int MonsterType){
    if (MonsterType == 3){
        return 100 + pow(MonsterLvl, 1.9);
    }
    else if (MonsterType == 2){
        return 100 + pow(MonsterLvl, 1.2);
    }
    else{
        return 100 + (2.5 * MonsterLvl);
    }
}
// Function that takes 3 args to calculate the adjusted Xp amount for the Hero when defeating a monster.
// double XpBase: given by CalcXpBase function
// int MonsterLvl: must be between 0 and 50 (inclusive). 
// int MonsterType: must be between 1 and 3 (inclusive).
// return: the adjusted Xp amount for the Hero when defeating a monster. 
double CalcXpAdjusted(double XpBase, int MonsterLvl, int HeroLvl){
    double Helper = MonsterLvl - HeroLvl;
    return XpBase * pow(1.2, Helper);
}

// Asks for user input for the Monster and Hero stats, then computes XP by calling helper functions.
int main(){

    //declared empty variables that will later store the game stats by user input.
    int MonsterLvl, MonsterType, HeroLvl;

    // prompts user for input and stores the monster level.
    printf("What is the monster's level? ");
    scanf("%d", &MonsterLvl);
    //if user gives out of bounds stats, the user will continue to be prompted until in bounds. 
    while (MonsterLvl > 50 || MonsterLvl <= 0){
        printf("The monster's level is out of bounds. Please try again!\n What is the monster's level? ");
        scanf("%d", &MonsterLvl);
    }
    // prompts user for input and stores the monster type.
    printf("What is the monster's type?\n 1 -> normal (default), 2 -> elite, 3 -> boss: ");
    scanf("%d", &MonsterType);
    //if user gives out of bounds stats, the user will continue to be prompted until in bounds. 
    while (MonsterType > 3 || MonsterType < 1){
        printf("Please try again!\n Choose a monster type: 1 -> normal (default), 2 -> elite, 3 -> boss: ");
        scanf("%d", &MonsterType);
    }
    // prompts user for input and stores the Hero level.
    printf("What is the Hero's level? ");
    scanf("%d", &HeroLvl);
    //if user gives out of bounds stats, the user will continue to be prompted until in bounds. 
    while(HeroLvl > 50 || HeroLvl <= 0){
          printf("the Hero's level is out of bounds, please try again!\n What is the Hero's level? ");
        scanf("%d", &HeroLvl);
    }

    // Takes user input values and calls helper functions to calculate the XP stats for the game.   
    int XpBase = CalcXpBase(MonsterLvl, MonsterType);
    int XpAdjusted = CalcXpAdjusted(XpBase, MonsterLvl, HeroLvl);
    
    // prints the resulting stats for the game to the console. 
    printf("The monster is level is %d.\nThe hero is level %d.", MonsterLvl, HeroLvl);
    printf("\nThe monster's base XP value is %d.", XpBase);
    printf("\nThe monster's adjusted XP is %d.\n", XpAdjusted);

}