#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "wordle.h"
#include "termcodes.h"
using namespace std;

Wordle::Wordle() {}
Wordle::Wordle(char* code) : code{code} {}

Wordle::~Wordle() {}

// Returns the number of occurences of char c in string word before index
int countOccurences(const char c, const string word, const int index) {
    int occurences = 0;
    for (int i = 0; i < index; i++) {
        if (word[i] == c) occurences++;
    }
    return occurences;
}

// Returns true if char c was guessed at correct position in the guess elsewhere
bool correctElsewhere(const string guess, const string word, const char c) {
    int length = word.length();
    for (int i = 0; i < length; i++) {
        if (word[i] == c && guess[i] == c) {
            return true;
        }
    }
    return false;
}

// Returns true if char c should be printed in yellow
bool printYellow(const string guess, const char c, const string word, const int index) {
    int wordLength = word.length();
    int occurences = countOccurences(guess[index], word, wordLength);
    int prevGuessed = countOccurences(guess[index], guess, index);

    // If char c was guessed in the correct position elsewhere in the guess 
    // or has been guessed and printed yellow the number of times it occurs in word already
    // return false (to not print in yellow) 
    if (correctElsewhere(guess,word,guess[index]) || (prevGuessed > occurences - 1)) {
        return false;
    } else return true; 
}

void Wordle::playGame() {
    
    string guess;
    const string word = code;
    const int wordLength = code.length();
    bool guessed = false;  

    //ofstream myfile;
    //myfile.open("output.out");

    // Read guess
    cout << "Enter " << wordLength << " length word as guess: ";
    
    // Read in up to 6 guesses 
    for (int i = 0; i < 6; i++){ 
        
        if (cin >> guess) {
            string print = "";
            int guessLength = guess.length();

            // Checking if guess is wrong length
            if (guessLength > wordLength || guessLength < wordLength) {
                cout << "Incorrect guess size, please enter guess of length " << wordLength << ": ";
            
            // If guess is correct length
            } else {
                int correctLetters = 0; // keeping track of correct letters at correct index
                for (int k = 0; k < guessLength; k++) {
                        
                    // If char at index of guess is same char at same index of word
                    if (guess[k] == word[k]) {
                        correctLetters++;
                        cout << GREEN << guess[k];
                        cout << RESET;

                    // If char at index of guess is contained in word but at another index
                    } else if (word.find(guess[k]) != std::string::npos){
                        //int occurences = countOccurences(guess[k], word, wordLength);
                        //int prevGuessed = countOccurences(guess[k], guess, k);
                        
                        if (printYellow(guess,guess[k],word,k)) {
                            cout << YELLOW << guess[k];
                            cout << RESET; 
                        } else cout << guess[k];
                    } else cout << guess[k];
                }
                
                if (correctLetters == wordLength) {
                    guessed = true; 
                    break;
                } else if (i < 5){
                    cout << "\nEnter " << wordLength << " length word as guess: ";
                }
            }
        }
    }
    if (guessed) {
        cout << "\nCongrats you found the word!" << endl;
    } else {
        cout << "\nOut of guesses! The word was: " << word << endl;
    }
}

