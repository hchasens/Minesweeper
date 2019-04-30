#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "def.h"


//topScores.txt


void readScores(){
        for(int i = 0; i < 30; i++)
                printf("\n");
        int scores;
        FILE* file = fopen("scores.txt", "r");

        if (!file) {
                printf("Missing Dependancys\n");
                exit(0);
        }
        // attempt to read the next line and store
        // the value in the "number" variable
        int no = 1;
        printf("Past Scores: \n");
        while (fscanf(file, "%d", &scores ) == true) {
                printf("     %d: %d \n", no, scores);
                no++;
        }
        fclose(file);
        printf("\n");

}



void saveScores(int score){
        FILE* file = fopen("scores.txt", "a");
        fprintf(file, "\n%d", score);
        fclose(file);
}


void clearScores(){
        FILE* file = fopen("scores.txt", "w");
        fclose(file);
}
