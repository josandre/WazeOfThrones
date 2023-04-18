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
#include "../Map.h"
#include "CheckAdjacentCities.h"
#include "SearchCity.h"
#include "ShortestRoute.h"
#include "LongestRoute.h"

#define NODES_RADIUS 8.0f
#define ROUTES_THICKNESS 4.0f

using namespace sf;
using namespace std;

class SfmlApp {
private:
    CheckAdjacentCities* checkAdjacentCitiesUI;
    SearchCity* searchCity;
    ShortestRoute* shortestRoute;
    LongestRoute* longestRoute;

    Map* map;
    string city;
    string outputText;
    string fromCity;
    string toCity;
    int menuOption;

    int selectCityOption;
    int selectedCity;
    vector<int> adjacentCities;
    vector<int> pathRoutes;

public:
    explicit SfmlApp();

    Map* InitMap();

    void CheckForCityClick(Vector2f mousePosition);
    Vector2f normalizeVector(Vector2f source);
    RectangleShape DrawLine(Vector2f from, Vector2f to, float thickness, Color color);
    void DrawUI(RenderWindow& window, Time delta, View view);
    void Print(string msj);
    void Run();
};


#endif //WAZEOFTHRONES_SFMLAPP_H
