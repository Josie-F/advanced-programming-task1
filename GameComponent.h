#include <iostream>

using namespace std;

#pragma once
// Non visual entities within a game.
class GameComponent {
private:
    static int instances;
    int id;
public:
    GameComponent();
    virtual void Update(const tm* currentTime);
};