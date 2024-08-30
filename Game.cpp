#include "Game.h"

#include <iostream>

// Works for Mac
#include <unistd.h>

using namespace std;

// adds a new (GameComponent/DrawableGameComponent) object to an array of
// pointers of type GameComponent (components).
void Game::Add(GameComponent* component) {
    components[componentCount] = component;
    componentCount++;
    // check that we are not over the max components
    //  if (componentCount < components.size()) {
    // } else {
    // }
}

// : Invokes the functions whose address has been assigned (using SetInitialise)
// to the Initialise pointer . This standalone function should just display the
// words “Initialising game” within the console. Run implements a loop which
// iterates through the components array invoking the component’s Update member
// functions. The time of invocation is passed as an argument to the Update
// member function. The component’s Update member function should be invoked
// once every second. But should only execute 5 times. Finally the function
// whose address has been assigned (using SetTerminate) to the terminate pointer
// should be invoked. This function should just display the words “terminating
// game” within the console.
void Game::Run() {
    // use the time header file to get the current time and transform into UTC
    // time
    time_t rawtime;
    tm* utcTime;
    time(&rawtime);
    utcTime = gmtime(&rawtime);
    int invocationNumber = 0;

    // invoke function address that is assigned to init pointer via setInit()
    initialise();
    // loop over the component array and invoke the comp update function. Time
    // is passed as arg to update. invoke every second, 5 times. LOOP HERE
    for (int i = 0; i < componentCount; i++) {
        cout << invocationNumber << endl;
        while (invocationNumber < 5) {
            components[i]->Update(utcTime); // this time is always the same, need to update
            invocationNumber++;
            usleep(1000000);  // maybe theres a nicer way of doing this.
        }
    }
    //  invoke function address that is assigned to terminate pointer via
    //  setTerm()
    terminate();
}

// assigns the address of a standalone function to the Initialise data member.
void Game::SetInitialise(FP init) {
    initialise = init;
}

// assigns the address of a standalone function to the terminate data member
void Game::SetTerminate(FP term) {
    terminate = term;
}

Game::Game(int maxComponents) {
    componentCount = 0;
    // array of pointers of type GameComponent
    components = new GameComponent*[maxComponents];
}
