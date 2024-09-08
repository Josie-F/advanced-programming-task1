#include "GameComponent.h"

#include <time.h>

#include <iostream>

using namespace std;

// Function that displays the object's id and time at which the Update member
// function was invoked.
void GameComponent::Update(const tm* currentTime) {
    // time (+ 1 as its currently summer time)
    cout << "ID: " << id << " Updated at: " << currentTime->tm_hour + 1 << ":"
         << currentTime->tm_min << ":" << currentTime->tm_sec << endl;
    count++;
}

// Constructor for game component. Instances will be kept in memory and a new
// GameComponent/DrawableGameComponent will be assigned the id of instances
// which is incrememnted when a new GameComponent/DrawableGameComponent is
// created.
GameComponent::GameComponent() {
    instances++;
    id = instances;
    count = 0;
}
