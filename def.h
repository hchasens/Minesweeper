#ifndef SYMBOL
#define SYMBOL value
#include <stdbool.h>

//will not take grids of more then 100 in LENGTH or WIDTH
#define WIDTH 20
#define LENGTH 20

//difficulty 3 easy, 2 middium, 1 hard
//difficulty algorithm is logrithem, in hard each block at a 50% chance of being mined, in middium 25% and in easy 12.5%
#define DIFFICULTY 2

//defines block
struct block{
  bool hasMine, exposed;};


void displayGrid(struct block g[WIDTH][LENGTH]);
void generateMines(struct block g[WIDTH][LENGTH]);
void exposeAll(struct block g[WIDTH][LENGTH]);
bool hasHitMine(struct block g[WIDTH][LENGTH]);
bool getInput(struct block g[WIDTH][LENGTH]);
void reset(struct block g[WIDTH][LENGTH]);

void readScores();
void saveScores(int score);
void clearScores();

void mainMenu(struct block g[WIDTH][LENGTH]);



#endif
