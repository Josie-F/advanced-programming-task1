#include <iostream>

using namespace std;

#pragma once
class DrawableGameComponent {
private:
    int x;
    int y;
    void Draw();
    void ChangeDirection();
public:
    enum Direction { Left, Right, Up, Down };
    Direction direction;
    DrawableGameComponent(int x, int y);
    int const SCREEN_HEIGHT;
    int const SCREEN_WIDTH;
    void Update(const tm* eventTime);
};