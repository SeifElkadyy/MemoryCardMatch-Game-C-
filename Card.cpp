#include "Card.h"
using namespace std;

Card::Card(int number) : number(number), isFaceUp(false) {}
Card::~Card() {}
void Card::display() {
    if (isFaceUp)
        cout << number << " ";
    else
        cout << "* ";
}

void Card::reveal() {
    isFaceUp = true;
}
void Card::hide() {
    isFaceUp = false;
}

int Card::getNumber() const {
    return number;
}
void Card::setNumber(int number) {
    this->number = number;
}
bool Card::getFaceUp() {
    return isFaceUp;
}
void Card::setFaceUp(bool isFaceUp) {
    this->isFaceUp = isFaceUp;
}

// -------------------------

StandardCard::StandardCard(int n) : Card(n) {}
StandardCard::~StandardCard() {}

// ------------------------

BonusCard::BonusCard() : Card(7) {}
BonusCard::~BonusCard() {}

// ------------------------

PenaltyCard::PenaltyCard() :  Card(8) {}
PenaltyCard::~PenaltyCard() {}

