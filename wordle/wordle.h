#ifndef _WORDLE_H_
#define _WORDLE_H_
#include "termcodes.h"
#include <string>
using namespace std; 

struct Wordle {
    string code;
    Wordle();
    Wordle(char* code);
    ~Wordle();
    void playGame();
};

#endif
