/**
 * Assignemnt 3: Minesweeper
 * Authors: Hunter Chasens and
 * Version: Alpha 1.0
 *
 * This is a CLI Minesweeper game, you input the cordanates,
 *
 *
 * Discription of a block:
 *        blocks are the structure that make up grid
 *        each block contains its cordanates, in 'x' and 'y' intagers
 *        and two boolean values, 'hasMine' and 'exposed'
 *
 * Discription of point:
 *        A point is set of x and y cordanates
 *
 * Discription of grid:
 *        grid is the land of Minesweeper
 *        a grid is a two dimetional array of blocks
 */

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#include"def.h"


//Start of Member Field
  //main minesweeper feild
struct block grid[WIDTH][LENGTH];

//auxilerary structure used for

//End of Member Field




int main(){
  //readScores();
  mainMenu(grid);
  return 0;
}
