#include "DrawableGameComponent.h"

#include <iostream>

using namespace std;

// Update function which shows id and time of invocation. It then increments/decrement x and y depending on the current direction.
// Draw is called to show the current direction and coordinates and the direction is then changed.
// x and y are clamped to specific ranges.
void DrawableGameComponent::Update(const tm* eventTime) {
    GameComponent::Update(eventTime); 
    switch (direction) {
        case Up:
            y++;
            if (y == 21) {
                y = SCREEN_HEIGHT;  // clamp the y to the edge of screen. range is 0..20
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
                x = SCREEN_WIDTH;  // clamp the x to the edge of screen. range is 0..80
            }
            break;

        default:
            break;
    }
    Draw();       
    ChangeDirection(); 
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
    }
    direction = newDirection;  // set new direction
}

// Constructor for the DrawableGameComponent
DrawableGameComponent::DrawableGameComponent(int x, int y) {
    this->x = x; // brief mentions this should be set to 0, however I am using the parameter. 
    this->y = y;
    direction = Right;
}

DrawableGameComponent::DrawableGameComponent() {
    x = 0; // created a constructor which doesnt take in x and y values and sets the values to 0. 
    y = 0;
    direction = Right;
}

// Helper function to get current direction in its string form. Not mentioned in brief. 
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