#include "Deck.h"
using namespace std;
#include <random>

Deck::Deck() : remainingCards(16)
{   int cardIndex = 0;
    grid = new Card*[16];

    for (int i = 1; i <= 6 ; ++i) {
        grid[cardIndex++]= new StandardCard(i);
        grid[cardIndex++]= new StandardCard(i);
    }
    grid[cardIndex++]= new PenaltyCard();
    grid[cardIndex++]= new PenaltyCard();
    grid[cardIndex++]= new BonusCard();
    grid[cardIndex++]= new BonusCard();

    shuffle();

}

/*Deck::Deck(int rows, int cols) : rows(), cols(cols), remainingCards(16)
{   int cardIndex = 0;
    grid = new Card*[16];

    for (int i = 1; i <= 6 ; ++i) {
        grid[cardIndex++]= new StandardCard(i);
        grid[cardIndex++]= new StandardCard(i);
    }
    grid[cardIndex++]= new PenaltyCard();
    grid[cardIndex++]= new PenaltyCard();
    grid[cardIndex++]= new BonusCard();
    grid[cardIndex++]= new BonusCard();

    shuffle();

}*/

Deck::~Deck() {
    for (int i = 0; i < 16; ++i) {
        if (grid[i] != nullptr) {
            delete grid[i];
            grid[i] = nullptr;
        }
    }
    delete[] grid;
}


void Deck::shuffle() {
    srand(time(0));
    for (int i = 0; i < 16; ++i) {
        int swapIndex = rand() % 16;
        swap(grid[i], grid[swapIndex]);
    }
}
void Deck::displayGrid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i*4+j] != nullptr) {
                grid[i*4+j]->display();
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void Deck::resetGrid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i*4+j] != nullptr) {
                grid[i*4+j]->hide();
            }
        }
    }
}

Card* Deck::getCard(int x, int y) {
    if (x < 0 || x >= 4 || y < 0 || y >= 4) {
        return nullptr;
    }

    if (grid[x * 4 + y] == nullptr) {
        return nullptr;
    }

    return grid[x * 4 + y];
}


void Deck::removeCard(int x, int y) {
    if (grid[x * 4 + y] != nullptr) {
        delete grid[x * 4 + y];
        grid[x * 4 + y] = nullptr;
        remainingCards--;
    }
}



Card** Deck::getGrid() {
    return grid;
}
int Deck::getRemainingCards() {
    return remainingCards;
}
void Deck::setRemainingCards(int num) {
    remainingCards = num;
}

