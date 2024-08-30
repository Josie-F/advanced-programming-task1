#include "DrawableGameComponent.h"

#include <iostream>

using namespace std;

// Update:
//  1. Displays the object’s id and time of invocation.
//  2. Increments / decrements the x or y values depending upon the current
//  direction (Up, Down, Left, Right) .
//  3. Invokes the Draw() member function
//  4. Invokes the ChangeDirection member function.
//  Note: The x & y values should not exceed the screen size. Valid values are
//  • x in the range 0 .. 80
//  • y in the range 0..20
//  x and y values should be clamped if necessary. E.g. if y = -1 set it to 0
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

//: Displays the current direction along with the x and y values.
void DrawableGameComponent::Draw() {
    cout << "Direction: " << GetDirectionString(&direction) << " X: " << x << " Y:" << y << endl;
}

// Assigns a new random direction to the direction data member.
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

DrawableGameComponent::DrawableGameComponent(int x, int y) {
    x = 0;
    y = 0;
    direction = Right;
    count = 0;
}

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