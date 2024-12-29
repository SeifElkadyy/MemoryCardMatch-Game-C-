#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Card {
private:
    int number;
    bool isFaceUp;
public:
    Card(int number);
    virtual ~Card();
    virtual void display() ;
    void reveal();
    void hide();

    int getNumber() const;
    void setNumber(int number);
    bool getFaceUp();
    void setFaceUp(bool state);
};

class StandardCard : public Card
{
public:
    StandardCard(int num);
    ~StandardCard();
};

class BonusCard : public Card
{
public:
    BonusCard();
    ~BonusCard();
};

class PenaltyCard : public Card
{
public:
    PenaltyCard();
    ~PenaltyCard();
};

#endif //CARD_H