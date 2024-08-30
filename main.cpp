#include <iostream>

#include "DrawableGameComponent.h"
#include "Game.h"
#include "GameComponent.h"
#include "time.h"

using namespace std;

// standalone functions
void terminateFunc() {
    cout << "Terminating game" << endl;
}
void initialiseFunc() {
    cout << "Initialising game" << endl;
}

int GameComponent::instances = 0;


int main() {
//Implement the classes and define the two standalone functions above main.
// Within main -
// 1. Create a dynamic instance of Game
// 2. Invoke SetInitialise passing it one of the standalone function addresses.
// 3. Invoke SetTerminate passing it the other standalone function address.
// 4. Add a GameComponent object with an id of 1 to the game object
// 5. Add a DrawableGameComponent object with an id of 2 and a position of x=0,
// y=0 to the game object.
// 6. Invoke the game object’s run member function.
    Game *newGame = new Game(10);
    newGame->SetInitialise(initialiseFunc);
    newGame->SetTerminate(terminateFunc);
    newGame->Add(new GameComponent);
    newGame->Add(new DrawableGameComponent(0,0));
    newGame->Run();
    return 0;
}