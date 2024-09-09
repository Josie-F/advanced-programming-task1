#include <iostream>

#include "GameComponent.h"

using namespace std;

#pragma once
class Game {
private:
    // Number components in array
    int componentCount;
    int componentsSize;  // added this to keep track of max components set for
                         // the array so you can't add more than the max.
    GameComponent** components;
    // typedef representing a type of function that returns void and has no
    // parameters used for initialise and terminate.
    typedef void (*FP)();
    // Pointer to standalone function
    FP initialise;
    // Pointer to standalone function.
    FP terminate;
    // const used for the sleep functionality to wait a second.
    const int TICKS_1000MS =
        1000000;  // this is in microseconds - needed for MAC's usleep()

public:
    void Add(GameComponent*);
    Game(int maxComponents);
    void Run();
    void SetInitialise(FP init);
    void SetTerminate(FP term);
};