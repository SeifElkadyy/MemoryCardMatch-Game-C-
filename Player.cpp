#include "Player.h"
using namespace std;

Player::Player() : name("Unamed"), score(0) {}
Player::Player(string name, int score) : name(name), score(score) {}
Player::~Player() {}

void Player::displayScore() {
    cout << "Player: " << name << "'s score: " << score << endl;
}

string Player::getName() const{
    return name;
}
void Player::setName(const string name) {
    this-> name = name;
}
int Player::getScore() {
    return score;
}
void Player::setScore(int score) {
    this->score = score;
}

void Player::gainPoint() {
    score += 1;
}

void Player::losePoint() {
    score -= 1;
}
