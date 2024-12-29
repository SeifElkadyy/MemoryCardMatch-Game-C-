#include "Game.h"
using namespace std;
#include <random>

Game::Game() : p1(Player()), p2(Player()), d(Deck()), currentPlayer(true)  {}
Game::Game(Player p1, Player p2) : p1(p1), p2(p2), d(Deck()), currentPlayer(true) {}
Game::~Game() {}

void Game::initializeGame() {
    cout << "Beginning game..." << endl;
    d.shuffle();

    cout << "Deck grid: " << endl;
    d.displayGrid();

    p1.setScore(0);
    p2.setScore(0);
    cout << p1.getName() << " and " << p2.getName() << " may start the game!" << endl;
}

Deck Game::getDeck() {
    return d;
}
Player Game::getPlayer1() const {
    return p1;
}
Player Game::getPlayer2() const {
    return p2;
}
void Game::setPlayer1(const Player p1) {
    this->p1 = p1;
}
void Game::setPlayer2(const Player p2) {
    this->p2 = p2;
}
bool Game::getCurrentPlayer() {
    return currentPlayer;
}
/*void Game::switchToNextPlayer(bool skipNextTurn){
    if (skipNextTurn) {
        // Skip the current player's next turn by toggling twice
        currentPlayer = !currentPlayer;
    }
    currentPlayer = !currentPlayer;
}*/

bool Game::checkPlayerSelection(int x1, int y1) {
    if (x1 < 0 || x1 >= 4 || y1 < 0 || y1 >= 4) {
        return false;
    }
    return true;
}

bool Game::handleCards(Card* card1, Card* card2, int x1, int y1, int x2, int y2) {
    Player& currentPlayerRef = currentPlayer ? p1 : p2;

    PenaltyCard* penaltyCard1 = dynamic_cast<PenaltyCard*>(card1);
    PenaltyCard* penaltyCard2 = dynamic_cast<PenaltyCard*>(card2);
    BonusCard* bonusCard1 = dynamic_cast<BonusCard*>(card1);
    BonusCard* bonusCard2 = dynamic_cast<BonusCard*>(card2);
    StandardCard* standardCard1 = dynamic_cast<StandardCard*>(card1);
    StandardCard* standardCard2 = dynamic_cast<StandardCard*>(card2);

    if (standardCard1 && standardCard2) {
        if (standardCard1->getNumber() == standardCard2->getNumber()) {
            cout << "Matching Cards!" << endl;
            currentPlayerRef.gainPoint();
            cout << currentPlayerRef.getName() << "'s score: " << currentPlayerRef.getScore() << endl;

            d.removeCard(x1, y1);
            d.removeCard(x2, y2);
            return true;
        } else {
            cout << "Cards do not match." << endl;
            standardCard1->hide();
            standardCard2->hide();
            currentPlayer = !currentPlayer;
            return false;
        }
    }

    if (penaltyCard1 && penaltyCard2) {
        cout << "Two penalty cards revealed! Player can type 1 to lose two points, 2 to lose one point and skip next turn. " << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Player's choice: lose 2 points" << endl;
            currentPlayerRef.losePoint();
            currentPlayerRef.losePoint();
        } else {
            cout << "Player's choice: lose 1 point, skip next turn." << endl;
            currentPlayerRef.losePoint();
            currentPlayer = !currentPlayer;
        }
        d.removeCard(x1, y1);
        d.removeCard(x2, y2);
        return false;
    } else if (penaltyCard1 || penaltyCard2) {
        cout << "Penalty card revealed! " << currentPlayerRef.getName() << " loses 1 point." << endl;
        currentPlayerRef.losePoint();

        Card* penaltyCardRef = penaltyCard1 ? card1 : card2;
        d.removeCard(penaltyCardRef == card1 ? x1 : x2, penaltyCardRef == card1 ? y1 : y2);

        penaltyCardRef == card1 ? card2->hide() : card1->hide();
        currentPlayer = !currentPlayer;
        return false;
    }

    if (bonusCard1 && bonusCard2) {
        cout << "Two bonus cards revealed! Player can type 1 to gain two points, 2 to gain one point and play again. " << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Player's choice: gain 2 points" << endl;
            currentPlayerRef.gainPoint();
            currentPlayerRef.gainPoint();
        } else {
            cout << "Player's choice: gain 1 point and play again." << endl;
            currentPlayerRef.gainPoint();
            return true;
        }
        d.removeCard(x1, y1);
        d.removeCard(x2, y2);
        return false;
    } else if (bonusCard1 || bonusCard2) {
        cout << "Bonus card revealed! " << currentPlayerRef.getName() << " gains 1 point." << endl;
        currentPlayerRef.gainPoint();

        Card* bonusCardRef = bonusCard1 ? card1 : card2;
        d.removeCard(bonusCardRef == card1 ? x1 : x2, bonusCardRef == card1 ? y1 : y2);

        bonusCardRef == card1 ? card2->hide() : card1->hide();
        currentPlayer = !currentPlayer;
        return false;
    }

    currentPlayer = !currentPlayer;
    return false;
}


void Game::playTurn() {
    while (d.getRemainingCards() > 0) {
        cout << "It's " << (currentPlayer ? p1.getName() : p2.getName()) << "'s turn!" << endl;

        int x1, y1, x2, y2;

        Card* card1 = nullptr;
        while (true) {
            cout << "Enter first card's coordinates (row & column): ";
            cin >> x1 >> y1;
            if (checkPlayerSelection(x1, y1)) {
                card1 = d.getCard(x1, y1);
                if (card1 != nullptr) {
                    card1->reveal();
                    d.displayGrid();
                    break;
                }
            }
            cout << "Invalid selection! Please try again." << endl;
        }

        Card* card2 = nullptr;
        while (true) {
            cout << "Enter second card's coordinates (row & column): ";
            cin >> x2 >> y2;
            if (checkPlayerSelection(x2, y2) && (x1 != x2 || y1 != y2)) {
                card2 = d.getCard(x2, y2);
                if (card2 != nullptr) {
                    card2->reveal();
                    d.displayGrid();
                    break;
                }
            }
            cout << "Invalid selection or duplicate card! Please try again." << endl;
        }

        if (!handleCards(card1, card2, x1, y1, x2, y2)) {
        }
    }

    cout << "All cards matched! Game over." << endl;
    cout << "Final Scores: " << endl;
    p1.displayScore();
    p2.displayScore();
    if (p1.getScore() > p2.getScore()) {
        cout << p1.getName() << " wins!" << endl;
    } else if (p2.getScore() > p1.getScore()) {
        cout << p2.getName() << " wins!" << endl;
    } else {
        cout << "It's a tie!" << endl;
    }
}
