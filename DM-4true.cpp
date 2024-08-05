#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Choice { ROCK, PAPER, SCISSORS };

string getChoiceName(Choice choice) {
    switch (choice) {
        case ROCK: return "Rock";
        case PAPER: return "Paper";
        case SCISSORS: return "Scissors";
        default: return ""; // Fixed closing brace
    }
}

Choice getComputerChoice() {
    return static_cast<Choice>(rand() % 3);
}

Choice getPlayerChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
        cin >> choice;
        if (choice >= 0 && choice <= 2) {
            return static_cast<Choice>(choice);
        } else {
            cout << "Invalid choice. Please enter 0, 1, or 2." << endl;
        }
    }
}

void determineWinner(Choice playerChoice, Choice computerChoice) {
    cout << "You chose: " << getChoiceName(playerChoice) << endl;
    cout << "Computer chose: " << getChoiceName(computerChoice) << endl;

    if (playerChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
               (playerChoice == PAPER && computerChoice == ROCK) ||
               (playerChoice == SCISSORS && computerChoice == PAPER)) {
        cout << "You win!" << endl;
    } else {
        cout << "You lose!" << endl;
    }
}

int main() {
    srand(time(0));

    char playAgain;
    do {
        Choice playerChoice = getPlayerChoice();
        Choice computerChoice = getComputerChoice();
        determineWinner(playerChoice, computerChoice);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    // Goodbye message when the user chooses not to play again
    if (playAgain == 'n' || playAgain == 'N') {
        cout << "Goodbye!" << endl;
    }

    return 0;

}
