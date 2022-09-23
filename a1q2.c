#include <stdio.h>
#include <err.h>
#include <math.h>

int main(){

    int MonsterLvl, HeroLvl;
    
    printf("What is the monster's level? ");
    if (scanf("%d", &MonsterLvl) != 1){
        errx(1, "Input error, please enter an integer. "); 
    }
    printf("What is the hero's level? ");
    if (scanf("%d", &HeroLvl) != 1){
        errx(1, "Input error, please enter an integer. ");
    }

    int xpBase = 100 + (2.5 * MonsterLvl);
    int LvlCalc = MonsterLvl - HeroLvl;
    int xpAdvantage = xpBase * pow(1.2, LvlCalc);
    
    printf("The monster is level is %d.\nThe hero is level %d.", MonsterLvl, HeroLvl);
    printf("\nThe hero's base XP value is %d.", xpBase);
    printf("\nThe hero's adjusted XP is %d.\n", xpAdvantage);

}