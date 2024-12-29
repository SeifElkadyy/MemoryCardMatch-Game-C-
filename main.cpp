#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    cout << "Welcome to the Memory MatchCard Game!" << endl;

    // Initialize players
    string name1, name2;
    cout << "Enter Player 1's name: ";
    cin >> name1;
    cout << "Enter Player 2's name: ";
    cin >> name2;

    Player player1(name1, 0);
    Player player2(name2, 0);

    // Initialize the game
    Game game(player1, player2);
    game.initializeGame();

    // Main game loop
    while (true) {
        game.playTurn();

        // Check if the game is over
        if (game.getDeck().getRemainingCards() == 0) {
            cout << "Game Over! Final Scores:" << endl;
            player1.displayScore();
            player2.displayScore();

            if (player1.getScore() > player2.getScore()) {
                cout << player1.getName() << " wins!" << endl;
            } else if (player2.getScore() > player1.getScore()) {
                cout << player2.getName() << " wins!" << endl;
            } else {
                cout << "It's a tie!" << endl;
            }
            break;
        }
    }

    cout << "Thank you for playing!" << endl;
    return 0;
}
