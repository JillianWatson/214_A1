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

    double xpBase = 100 + (2.5 * MonsterLvl);
    double LvlCalc = MonsterLvl - HeroLvl;
    double xpAdvantage = xpBase * pow(1.2, LvlCalc);
    
    printf("The monster is level is %d.\nThe hero is level %d.", MonsterLvl, HeroLvl);
    printf("\nThe hero's base XP value is %.0lf.", xpBase);
    printf("\nThe hero's adjusted XP is %.0lf.\n", xpAdvantage);

}