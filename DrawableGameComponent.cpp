#include "DrawableGameComponent.h"

#include <iostream>

using namespace std;

// Update function which shows id and time of invocation. It then increments/decrement x and y depending on the current direction.
// Draw is called to show the current direction and coordinates and the direction is then changed.
// x and y are clamped to specific ranges.
void DrawableGameComponent::Update(const tm* eventTime) {
    GameComponent::Update(eventTime);  // call base class = 1.
    switch (direction) {
        case Up:
            y++;
            if (y == 21) {
                y = 20;  // clamp the y to the edge of screen. range is 0..20
            }
            break;
        case Down:
            y--;
            if (y == -1) {
                y = 0;
            }
            break;
        case Left:
            x--;
            if (x == -1) {
                x = 0;
            }
            break;
        case Right:
            x++;
            if (x == 81) {
                x = 80;  // clamp the x to the edge of screen. range is 0..80
            }
            break;

        default:
            break;
    }
    Draw();             // 3
    ChangeDirection();  // 4
    count++;
}

// Function which displays current direction along with x and y values.
void DrawableGameComponent::Draw() {
    cout << "Direction: " << GetDirectionString(&direction) << " X: " << x << " Y:" << y << endl;
}

// Function which assigns a new random direction.
// Direction must be different to the current direction.

void DrawableGameComponent::ChangeDirection() {
    srand(time(NULL)); // needed for random to be different on invocations.
    Direction newDirection = Direction(rand() % 4);
    // make sure it doesnt choose the same direction
    if (newDirection == direction) {
        ChangeDirection();
        return;
    }
    direction = newDirection;  // set new direction
}

// Constructor for the DrawableGameComponent
DrawableGameComponent::DrawableGameComponent(int x, int y) {
    x = 0;
    y = 0;
    direction = Right;
    count = 0;
}

// Helper function to get current direction in its string form. 
const char* DrawableGameComponent::GetDirectionString(Direction *direction) {
    switch (*direction) {
        case Right:
            return "Right";
        case Left:
            return "Left";
        case Up:
            return "Up";
        case Down:
            return "Down";
        default:
            return "Direction not recognised";
    }
    return "No case";
}