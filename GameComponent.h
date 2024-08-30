#include <iostream>

using namespace std;

#pragma once
// Non visual entities within a game.
class GameComponent {
private:
    int id;
    int instances;

public:
    GameComponent();
    void Update(const tm*);
};