#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include"def.h"

void reset(struct block g[WIDTH][LENGTH]){
  for(int y = 0; y < LENGTH; y++){
    for(int x = 0; x < WIDTH; x++){
      g[x][y].exposed=false;}
  }
}

bool hasHitMine(struct block g[WIDTH][LENGTH]){
  for(int y = 0; y < LENGTH; y++){
    for(int x = 0; x < WIDTH; x++)
      if(g[x][y].hasMine == true && g[x][y].exposed){
        return true;}
  }
  return false;
}

int suroundingMines(int x, int y, struct block g[WIDTH][LENGTH]){
  //produce a number of mines surounding
  int localNumOfMines = 0;
  int startY, stopY, startX, stopX;
  //sets start and stop to avoid a null pointer error
  //sets startX
  if(x<=0)
    startX = 0;
  else
    startX = x-1;
  //sets stopX
  if(x>=WIDTH-1)
    stopX = x;
  else
    stopX = x+1;
  //sets startY
  if(y<=0)
    startY = 0;
  else
    startY = y-1;
  //sets stopY
  if(y>=LENGTH-1)
    stopY = y;
  else
    stopY = y+1;

  for(int i = startY; i <= stopY; i++){
    for(int j = startX; j <= stopX; j++){
      if(g[j][i].hasMine == true)
        localNumOfMines++;
    }
  }

  return localNumOfMines;
}


/**
 * [clearEdge description]
 * @param x              [x location of block]
 * @param y              [y location of block]
 * @param [g]            [mine grid]
 * @param calledFromZero [set to false when called from outside of fuction]
 * this fuction is a recursive fuction, when calling from ouside alwase set calledFromZero to false;
 */
void clearEdge(int x, int y, struct block g[WIDTH][LENGTH], bool calledFromSelf){
  int startY, stopY, startX, stopX;
  //sets start and stop to avoid a null pointer error
  //sets startX
  if(x<=0)
    startX = 0;
  else
    startX = x-1;
  //sets stopX
  if(x>=WIDTH-1)
    stopX = x;
  else
    stopX = x+1;
  //sets startY
  if(y<=0)
    startY = 0;
  else
    startY = y-1;
  //sets stopY
  if(y>=LENGTH-1)
    stopY = y;
  else{
    stopY = y+1;}

    for(int i = startY; i <= stopY; i++){
      for(int j = startX; j <= stopX; j++){
        //if block is 0 and not exposed
        if(suroundingMines(j, i, g) == 0 && !g[j][i].exposed){
          g[j][i].exposed = true;
          clearEdge(j, i, g, true);}
        if(calledFromSelf == true){
          g[j][i].exposed = true;}
      }
    }
}

/**
 * [getInput description]
 * @param [name] [description]
 */
bool getInput(struct block g[WIDTH][LENGTH]){
  int x, y;
  printf("Enter X: ");
  scanf(" %d", &x);
  printf("Enter Y: ");
  scanf(" %d", &y);
  if (g[x][y].exposed != true){
    g[x][y].exposed = true;
    clearEdge(x, y, g, false);
    return true;}
  return false;
}

/**
 * generateMines: populates g with mines
 *
 */
void generateMines(struct block g[WIDTH][LENGTH]){
  srand(time(0));
  for(int y = 0; y < LENGTH; y++){
    for(int x = 0; x < WIDTH; x++){
      //25% chance of mined land
      g[x][y].hasMine = (rand() & 1) && (rand() & 1);
    }}
}


/**
 * exposeAll: exposes all blocks
 *
 */
void exposeAll(struct block g[WIDTH][LENGTH]){
  for(int y = 0; y < LENGTH; y++){
    for(int x = 0; x < WIDTH; x++){
      g[x][y].exposed = true;
    }}

}






/**
 * displayGrid: will display the pass grid
 * untouched ground = #
 * dug ground = o
 * mines = x
 */
void displayGrid(struct block g[WIDTH][LENGTH]){
  //clears screen
  for(int i = 0; i < 30; i++)
    printf("\n");

  //prints X axis
  printf(" ");
  for(int x = 0; x < WIDTH; x++)
    printf(" %d", x);
  printf("\n");

  //prints g and Y axis
  for(int y = 0; y < LENGTH; y++){
    printf("%d ", y);
    for(int x = 0; x < WIDTH; x++){
      //if block is exposed and has mine
      if ((g[x][y].exposed == true) && (g[x][y].hasMine == true)){
        printf("\033[1;31m");
        printf("X");
        printf("\033[0m");}
      //if block is exposed has does not have mine
      if ((g[x][y].exposed == true) && (g[x][y].hasMine == false)){
        printf("\033[0;32m");
        printf("%d", suroundingMines(x, y, g));
        printf("\033[0m");}
      //if block is not exposed
      if ((g[x][y].exposed == false))
        printf("#");

      //prints out space for athestics
      printf(" ");
    }
    printf("\n");
  }
}
