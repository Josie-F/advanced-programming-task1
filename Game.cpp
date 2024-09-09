#include "Game.h"

#include <iostream>

// Works for Mac
#include <unistd.h>

using namespace std;

// Function to add a new (GameComponent/DrawableGameComponent) object to the
// components array.
void Game::Add(GameComponent* component) {
    // check that we are not over arrays size
    if (componentCount < componentsSize) {  // get component count and check if
                                           // it's less than the array allows.
        components[componentCount] = component;
        componentCount++;
    } else {
        cout << "You've added the max amount of components - continuing "
                "without insertion of component \n";
    }
}

// Function to run the game. It calls initialise and then loops over the
// component array, running the update function every second, 5 times. It then
// terminates the game.
void Game::Run() {
    // invoke function address assigned to init pointer via setInit()
    initialise();
    // loop over components array and invoke the component update function.
    for (int i = 0; i < componentCount; i++) {
        int counter = 0;
        while (counter <
               5) {  // this loop does not execute simultaneously like the brief
                     // outcome shows. ID 1 will finish and then ID 2 will run.
            // use the time header file to get the current time and transform
            // into UTC time
            time_t rawtime;
            tm* utcTime;
            time(&rawtime);
            utcTime = gmtime(&rawtime);
            components[i]->Update(utcTime);
            usleep(TICKS_1000MS);
            counter++;
        }
    }
    //  invoke function address that is assigned to terminate pointer via
    //  setTerm()
    terminate();
}

// Function that assigns the address of a standalone function to the initialise
// data member.
void Game::SetInitialise(FP init) {
    initialise = init;
}

// Function that assigns the address of a standalone function to the terminate
// data member
void Game::SetTerminate(FP term) {
    terminate = term;
}

// Constructor for Game class
Game::Game(int maxComponents) {
    componentCount = 0;
    componentsSize = maxComponents;  // assign param to data member.
    // array of pointers of type GameComponent
    components = new GameComponent*[maxComponents];
}
