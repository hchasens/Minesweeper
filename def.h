#ifndef SYMBOL
#define SYMBOL value
#include <stdbool.h>

//will not take grids of more then 100 in LENGTH or WIDTH
#define WIDTH 20
#define LENGTH 20

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
