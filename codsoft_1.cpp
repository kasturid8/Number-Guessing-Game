#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> // For numeric_limits

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Define the range and default difficulty for the random number
    int lowerBound = 1;
    int upperBound = 100;
    int difficulty = 1;
    char playAgain;

    int secretNumber;
    int userGuess;
    int attempts;
    int bestScore = -1;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do {
        // Ask the user to choose the difficulty level
        std::cout << "Select the difficulty level:" << std::endl;
        std::cout << "1. Easy (between 1 and 100)" << std::endl;
        std::cout << "2. Medium (between 1 and 500)" << std::endl;
        std::cout << "3. Hard (between 1 and 1000)" << std::endl;
        std::cout << "Enter the number corresponding to the difficulty level: ";

        while (!(std::cin >> difficulty)) {
            // If the user enters a non-numeric value, clear the input buffer and ask again
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: ";
        }

        // Set the appropriate difficulty range based on user choice
        switch (difficulty) {
            case 1:
                lowerBound = 1;
                upperBound = 100;
                break;
            case 2:
                lowerBound = 1;
                upperBound = 500;
                break;
            case 3:
                lowerBound = 1;
                upperBound = 1000;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                continue;
        }

        // Generate a new random number within the selected difficulty range
        secretNumber = std::rand() % (upperBound - lowerBound + 1) + lowerBound;
        attempts = 0;

        std::cout << "I have selected a number between " << lowerBound << " and " << upperBound << "." << std::endl;

        do {
            // Ask the user for their guess
            std::cout << "Enter your guess: ";
            while (!(std::cin >> userGuess)) {
                // If the user enters a non-numeric value, clear the input buffer and ask again
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number: ";
            }
            attempts++;

            // Check if the user's guess is correct
            if (userGuess == secretNumber) {
                std::cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts." << std::endl;

                // Update best score if it's the first attempt or fewer attempts than the previous best score
                if (bestScore == -1 || attempts < bestScore) {
                    bestScore = attempts;
                    std::cout << "You achieved the new best score!" << std::endl;
                }

            } else if (userGuess < secretNumber) {
                std::cout << "Too low! Try again." << std::endl;
            } else {
                std::cout << "Too high! Try again." << std::endl;
            }

        } while (userGuess != secretNumber);

        // Ask the user if they want to play again
        std::cout << "Do you want to play again? (y/n): ";
        std::cin >> playAgain;

        // If the user enters 'y' or 'Y', repeat the game
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing! Your best score is " << bestScore << " attempts." << std::endl;

    return 0;
}

