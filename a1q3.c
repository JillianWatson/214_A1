#include <stdio.h>
#include <err.h>
#include <math.h>

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

double CalcXpAdjusted(double XpBase, int MonsterLvl, int HeroLvl){
    double Helper = MonsterLvl - HeroLvl;
    return XpBase * pow(1.2, Helper);
}

int main(){

    int MonsterLvl, MonsterType, HeroLvl;

    printf("What is the monster's level? ");
    scanf("%d", &MonsterLvl);
    while (MonsterLvl > 50 || MonsterLvl <= 0){
        printf("The monster's level is out of bounds. Please try again!\n What is the monster's level? ");
        scanf("%d", &MonsterLvl);
    }
    
    printf("What is the monster's type?\n 1 -> normal (default), 2 -> elite, 3 -> boss: ");
    scanf("%d", &MonsterType);
    while (MonsterType > 3 || MonsterType < 1){
        printf("Please try again!\n Choose a monster type: 1 -> normal (default), 2 -> elite, 3 -> boss: ");
        scanf("%d", &MonsterType);
    }

    printf("What is the Hero's level? ");
    scanf("%d", &HeroLvl);
    while(HeroLvl > 50 || HeroLvl <= 0){
          printf("the Hero's level is out of bounds, please try again!\n What is the Hero's level? ");
        scanf("%d", &HeroLvl);
    }
    
    int XpBase = CalcXpBase(MonsterLvl, MonsterType);
    int XpAdjusted = CalcXpAdjusted(XpBase, MonsterLvl, HeroLvl);
    
    printf("The monster is level is %d.\nThe hero is level %d.", MonsterLvl, HeroLvl);
    printf("\nThe monster's base XP value is %d.", XpBase);
    printf("\nThe monster's adjusted XP is %d.\n", XpAdjusted);

}