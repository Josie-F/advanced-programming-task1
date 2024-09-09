#include <iostream>

#include "DrawableGameComponent.h"
#include "Game.h"
#include "GameComponent.h"

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
    Game *newGame = new Game(10);
    newGame->SetInitialise(initialiseFunc);
    newGame->SetTerminate(terminateFunc);
    newGame->Add(new GameComponent);
    newGame->Add(new DrawableGameComponent(0, 0));
    newGame->Run();
    return 0;
}