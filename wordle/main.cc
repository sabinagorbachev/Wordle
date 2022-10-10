#include "wordle.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Incorrect number of arguments" << endl;
    exit(1);
  }
  if (argc==2) {
    Wordle wordle {argv[1]};
    wordle.playGame();
  }
  return 0;
}
