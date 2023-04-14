//
// Created by tsegura on 4/13/2023.
//

#ifndef WAZEOFTHRONES_SFMLAPP_H
#define WAZEOFTHRONES_SFMLAPP_H

#include <SFML/Graphics.hpp>
#include <math.h>

using namespace sf;
using namespace std;

class SfmlApp {
private:

public:
    Vector2f normalizeVector(Vector2f source);
    RectangleShape DrawLine(Vector2f from, Vector2f to, float thickness, Color color);
    void Run();
};


#endif //WAZEOFTHRONES_SFMLAPP_H
