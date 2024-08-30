#include <iostream>

#include "GameComponent.h"

using namespace std;

#pragma once
class Game {
private:
    // Number components in array
    int componentCount;
    GameComponent** components;
    // is a typedef representing a type of function that returns void and has no
    // parameters.
    typedef void(*FP)();
    // Pointer to standalone function
    FP initialise;
    // Pointer to standalone function.
    FP terminate;
    // int const TICKS_1000MS; // when to init this?

public:
    void Add(GameComponent*);
    Game(int maxComponents);
    void Run();
    void SetInitialise(FP init);
    void SetTerminate(FP term);
};