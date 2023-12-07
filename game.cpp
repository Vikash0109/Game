#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

class GuessGame {
private:
    int targetNumber;
    int playerGuess;
    bool isGameOver;

public:
    // Constructor
    GuessGame() {
        // Seed the random number generator
        std::srand(std::time(0));
        targetNumber = std::rand() % 100 + 1;  // Generate a random number between 1 and 100
        isGameOver = false;
    }

    // Function to start the game
    void startGame() {
        std::cout << "Welcome to Guess the Number Game!\n";
        std::cout << "Try to guess the number between 1 and 100.\n\n";

        while (!isGameOver) {
            takeGuess();
            checkGuess();
        }

        std::cout << "Congratulations! You guessed the correct number.\n";
    }

private:
    // Function to get the player's guess
    void takeGuess() {
        std::cout << "Enter your guess: ";
        std::cin >> playerGuess;
    }

    // Function to check the player's guess
    void checkGuess() {
        if (playerGuess == targetNumber) {
            isGameOver = true;
        } else {
            std::cout << "Wrong guess! Try again.\n";
            std::cout << (playerGuess < targetNumber ? "Too low.\n" : "Too high.\n");
        }
    }
};

int main() {
    GuessGame game;
    game.startGame();

    return 0;
}