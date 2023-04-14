//
// Created by tsegura on 4/13/2023.
//

#include "../../header/ui/SfmlApp.h"
#include "../../header/Map.h"

Vector2f SfmlApp::normalizeVector(Vector2f source) {
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0) {
        return Vector2(source.x / length, source.y / length);
    }

    return source;
}

RectangleShape SfmlApp::DrawLine(Vector2f from, Vector2f to, float thickness, Color color)
{
    RectangleShape line;
    line.setFillColor(color);

    Vector2f dir = (to - from);
    float rot = atan2(dir.y, dir.x) * (180.0f / M_PI);
    float dist = sqrt(pow(from.x - to.x, 2) + pow(from.y - to.y, 2));

    line.setPosition(from);
    line.setSize(Vector2f(dist, thickness));
    line.setRotation(rot);

    return line;
}

void SfmlApp::Run() {
    RenderWindow window(VideoMode(640, 480), "Waze of Thrones");

    // Define graph
    Map* map = new Map();
    map->AddCity("A", 100, 100);
    map->AddCity("B", 200, 100);
    map->AddCity("C", 150, 200);
    map->AddCity("D", 220, 200);
    map->AddCity("E", 150, 50);

    map->AddRoute("A", "B", 10, 5);
    map->AddRoute("B", "C", 2, 8);
    map->AddRoute("C", "D", 2, 8);
    map->AddRoute("E", "D", 2, 8);

    int x = 0;
    int y = 0;
    int radius = 5;

    while (window.isOpen())
    {
        Event event;

        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::MouseWheelScrolled)
            {
                radius += event.mouseWheelScroll.delta;
            }

            if (event.type == Event::MouseMoved)
            {
                x = event.mouseMove.x;
                y = event.mouseMove.y;
            }
        }
        window.clear(Color::Black);

        // Draw routes or arcs
        for (int i = 0; i < CITY_CAPACITY; i++) {
            City *from = map->CityFromIndex(i);

            if (from == nullptr) {
                continue;
            }
            for (int j = 0; j < CITY_CAPACITY; j++) {
                if (map->GetRoutes()[i][j] == nullptr) {
                    continue;
                }

                City *to = map->CityFromIndex(j);

                if (to != nullptr) {
                    Vector2f fromPos = Vector2f(from->GetPosX()  + radius, from->GetPosY()  + radius);
                    Vector2f toPos = Vector2f(to->GetPosX() + radius, to->GetPosY() + radius);

                    window.draw(DrawLine(fromPos, toPos, 3.0f, Color::White));
                }
            }
        }

        // Draw cities or nodes
        City* currentCity = map->GetRoot();
        while (currentCity != nullptr) {
            CircleShape cityNode;
            cityNode.setPosition(currentCity->GetPosX(), currentCity->GetPosY());
            cityNode.setRadius(radius);
            cityNode.setFillColor(Color::Cyan);

            window.draw(cityNode);

            currentCity = currentCity->GetNext();
        }

        window.display();
    }

}