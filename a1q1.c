#include <stdio.h>
#include <err.h>

int main(){
    int valueOne, valueThree;
    double valueTwo;
    printf("Enter an integer: ");
    if (scanf("%d", &valueOne) != 1){
        errx(1,"Input error. Please enter an integer value.");
    }
    printf("Enter a real number: ");
    if (scanf("%lf", &valueTwo) != 1.0){
        errx(1,"Input error. Please an a real number.");
    }
    printf("Enter an integer: ");
    if (scanf("%d", &valueThree) != 1){
        errx(1,"Input error. please enter an integer value.");
    }
    printf("\nMi amigo! Nice of you to join us for trick-or-treating! We're going to hit %d houses tonight.\n I hope you brought your running shoes. Lets make it a race! \n Who ever fills %lf pillow cases first will get to take %d pieces of candy from everyones bags!\n Are you ready? Let's go!", valueOne, valueTwo, valueThree);
    return 0;
    
}