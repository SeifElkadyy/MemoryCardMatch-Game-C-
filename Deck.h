#ifndef DECK_H
#define DECK_H
#include <iostream>
#include "Card.h"
#include <cmath>
using namespace std;

class Deck
{
private:
    Card** grid;
    /*int rows;
    int cols;*/
    int remainingCards;
public:
    Deck();
    ~Deck();
    void shuffle();
    void displayGrid();

    void resetGrid();
    void removeCard(int x, int y);

    Card** getGrid();
    int getRemainingCards();
    void setRemainingCards(int num);
    Card* getCard(int x, int y);
};

#endif //DECK_H