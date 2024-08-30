#include "GameComponent.h"

#include <time.h>

#include <iostream>

using namespace std;

// Display the objects id and time at which the Update member function was
// invoked.
void GameComponent::Update(const tm* currentTime) {
    // time (+ 1 as its currently summer time)
    cout << "ID: " << id << " Updated at: " << currentTime->tm_hour + 1 << ":"
         << currentTime->tm_min << ":" << currentTime->tm_sec << endl;
        count++;
}

// Each entity has a unique ID number. This ID is generated automatically using
// the instances static member, which records a running total of the number of
// instances instantiated from either the GameComponent or DrawableGameComponent
// classes. Therefore the first object will have an id of 1, the second 2 etc..
GameComponent::GameComponent() {
    instances++;
    id = instances;
    count = 0;
}
