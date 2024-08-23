#include <iostream>

#include "GameComponent.h"

using namespace std;

#pragma once
class Game {
private:
    int componentCount;
    GameComponent** components;
    typedef void(*FP);
    FP initialise;
    FP terminate;
    int const TICKS_1000MS;

public:
    void Add(GameComponent*);
    Game(int maxComponents);
    void Run();
    void SetInitialise(FP init);
    void SetTerminate(FP term);
};