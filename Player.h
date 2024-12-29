#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;

class Player
{
private:
    string name;
    int score;
public:
    Player();
    Player(string name, int score);
    ~Player();
    void displayScore();

    string getName() const;
    void setName(const string name);

    int getScore();
    void setScore(int num);

    void gainPoint();
    void losePoint();
};

#endif //PLAYER_H