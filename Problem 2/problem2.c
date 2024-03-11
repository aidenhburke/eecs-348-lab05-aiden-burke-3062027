/*
Program: EECS 348 Lab 05 Problem 2
Function: Create a program that will take an input football score and return all possible ways to achieve that score
Author: Aiden Burke
Date Modified: 03/10/2024
*/
#include <stdio.h>

void scoreCombinations(int score, int td2, int td1, int td0, int fg, int saf) {
    if (score <= 0) {
        printf("%d TD + 2pt, %d TD + XP, %d TD, %d FG, %d Safety\n", td2, td1, td0, fg, saf);
        return;
    }

    if (score == 6 || score > 7) {
        scoreCombinations(score - 6, td2, td1, td0+1, fg, saf);
    }

    if (score == 3 || score > 4) {
        scoreCombinations(score - 3, td2, td1, td0, fg+1, saf);
    }

    if (score == 2 || score > 3) {
        scoreCombinations(score - 2, td2, td1, td0, fg, saf+1);
    }

    if (score == 8 || score > 9) {
        scoreCombinations(score - 8, td2+1, td1, td0, fg, saf);
    }

    if (score == 7 || score > 8) {
        scoreCombinations(score - 7, td2, td1+1, td0, fg, saf);
    }
}

int main(){
    int score;
    do {
        printf("Enter 0 or 1 to STOP\nEnter score: ");
        scanf("%d", &score);
        if(score < 2){
            printf("Stopping Program...");
            break;
        } else{
            printf("possible combination of scoring plays for a score of %d\n", score);
            scoreCombinations(score, 0, 0, 0, 0, 0);
        }
    } while(1);

    return 0;
}
