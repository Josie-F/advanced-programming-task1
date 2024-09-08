#include <iostream>

using namespace std;

#pragma once
// Non visual entities within a game.
class GameComponent {
private:
    static int instances; // static to keep it in memory during the lifetime of the program
    int id;
public:
    GameComponent();
    int count;
    virtual void Update(const tm* currentTime); // virtual as it will be overridden in child classes.
};