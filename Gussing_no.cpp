#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int maxRange = 100; // Maximum range for the random number
    srand(time(0)); // Initialize the random number generator with the current time
    int randomNumber = (rand() % maxRange) + 1; // Generate a random number between 1 and 100
    int playerGuess;
    int guessCount = 0;

    cout << "A random number has been generated between 1 and " << maxRange << ". Try to guess it!" << endl;

    // Continue looping until the player guesses the correct number
    while (true) {
        cout << "Enter your guess: ";
        cin >> playerGuess;
        guessCount++;

        if (playerGuess < randomNumber) {
            cout << "Your guess is too low. Try again." << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Your guess is too high. Try again." << endl;
        } else {
            // Player guessed correctly
            cout << "Congratulations! You've guessed the number in " << guessCount << " attempts!" << endl;
            break;
        }
    }

    return 0;
}
