#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;
int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;
    cout << "Welcome to the Guess the Number game!" << endl;

    cout << "I've selected a random number between 1 and 100. Can you guess it?" << endl;
    int guessedNumber = 0;
    int attempts = 0;
    while (guessedNumber != secretNumber) {
        cout << "Enter your guess: ";
        if (!(cin >> guessedNumber)) {
            cout << "Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;  }
        if (guessedNumber < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guessedNumber > secretNumber) {
            cout << "Too high! Try again." << endl;}
        attempts++; }
    cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts." << endl;
    return 0;}

