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
    DrawableGameComponent();  // not shown in brief but added to accommodate for
                              // the brief mentioning setting x and y to 0,
                              // instead of using the parameters
    DrawableGameComponent(int x, int y);
    const int SCREEN_HEIGHT = 20;
    const int SCREEN_WIDTH = 80;
    void Update(const tm* eventTime);
    const char* GetDirectionString(
        Direction* direction);  // not shown in brief however added as a helper
                                // function.
};