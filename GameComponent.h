#include <iostream>

using namespace std;

#pragma once
class GameComponent {
private:
    int id;
    int instances;

public:
    GameComponent();
    void Update(const tm*);
};