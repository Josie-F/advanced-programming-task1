#include <iostream>

#include "GameComponent.h"

using namespace std;

#pragma once
// Represents visible 2D game entities.
class DrawableGameComponent : public GameComponent {
private:
    int x;
    int y;
    void Draw();
    void ChangeDirection();

public:
    enum Direction { Left, Right, Up, Down };
    Direction direction;
    DrawableGameComponent(int x, int y);
    // int const SCREEN_HEIGHT;
    // int const SCREEN_WIDTH;
    void Update(const tm* eventTime);
    int count;
    const char* GetDirectionString(Direction *direction);
};