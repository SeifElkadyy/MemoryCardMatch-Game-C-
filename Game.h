#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
using namespace std;

class Game
{
private:
    Deck d;
    Player p1;
    Player p2;
    bool currentPlayer;
public:
    Game();
    Game(const Player p1, const Player p2);
    ~Game();
    void initializeGame();

    Deck getDeck();

    Player getPlayer1() const;
    void setPlayer1(Player p1);

    Player getPlayer2() const;
    void setPlayer2(Player p2);

    bool getCurrentPlayer();

    bool checkPlayerSelection(int x1, int y1);
    void playTurn();

    bool handleCards(Card* card1, Card* card2, int x1, int y1, int x2, int y2);


};

#endif //GAME_H