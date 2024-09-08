#include "Game.h"

#include <iostream>

// Works for Mac
#include <unistd.h>

using namespace std;

// Function to add a new (GameComponent/DrawableGameComponent) object to the components array.
void Game::Add(GameComponent* component) {
    components[componentCount] = component;
    componentCount++;
    // check that we are not over the max components
    //  if (componentCount < components.size()) {
    // } else {
    // }
}

// Function to run the game. It calls initialise and then loops over the component array, running the update function every second, 5 times.
// It then terminates the game.
void Game::Run() {
    int invocationNumber = 0;

    // invoke function address assigned to init pointer via setInit()
    initialise();
    // loop over components array and invoke the component update function.
    for (int i = 0; i < componentCount; i++) {
        while (components[i]->count < 5) { // invocation needs to move because it is not happening simultaneously
            // use the time header file to get the current time and transform
            // into UTC time
            time_t rawtime;
            tm* utcTime;
            time(&rawtime);
            utcTime = gmtime(&rawtime);
            components[i]->Update(utcTime);
            invocationNumber++;
            usleep(TICKS_1000MS);
        }
    }
    //  invoke function address that is assigned to terminate pointer via setTerm()
    terminate();
}

// Function that assigns the address of a standalone function to the initialise data member.
void Game::SetInitialise(FP init) {
    initialise = init;
}

// Function that assigns the address of a standalone function to the terminate data member
void Game::SetTerminate(FP term) {
    terminate = term;
}

// Constructor for Game class
Game::Game(int maxComponents) {
    componentCount = 0;
    // array of pointers of type GameComponent
    components = new GameComponent*[maxComponents];
}
