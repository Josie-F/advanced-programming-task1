#include "GameComponent.h"

#include <time.h>

#include <iostream>

using namespace std;

// Display the objects id and time at which the Update member function was
// invoked.
void GameComponent::Update(const tm*) {
    // use the time header file to get the current time and transform into UTC
    // time (+ 1 as its currently summer time)
    time_t rawtime;
    tm* utcTime;
    time(&rawtime);
    utcTime = gmtime(&rawtime);
    cout << "ID: " << id << "Updated at: " << utcTime->tm_hour + 1 << ":"
         << utcTime->tm_min << ":" << utcTime->tm_sec << endl;
}

// Each entity has a unique ID number. This ID is generated automatically using
// the instances static member, which records a running total of the number of
// instances instantiated from either the GameComponent or DrawableGameComponent
// classes. Therefore the first object will have an id of 1, the second 2 etc..
GameComponent::GameComponent() {
    instances++;
    id = instances;
}
