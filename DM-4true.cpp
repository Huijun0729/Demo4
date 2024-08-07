#include <iostream>
#include <cstdlib>
#include <ctime>




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

    return 0;;;;;
}


