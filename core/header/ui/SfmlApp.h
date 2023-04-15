//
// Created by tsegura on 4/13/2023.
//

#ifndef WAZEOFTHRONES_SFMLAPP_H
#define WAZEOFTHRONES_SFMLAPP_H

#include <SFML/Graphics.hpp>
#include <math.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>
#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>

using namespace sf;
using namespace std;

class SfmlApp {
private:
    string outputText;

public:
    Vector2f normalizeVector(Vector2f source);
    RectangleShape DrawLine(Vector2f from, Vector2f to, float thickness, Color color);
    void Print(string msj);
    void Run();
};


#endif //WAZEOFTHRONES_SFMLAPP_H
