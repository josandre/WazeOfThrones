//
// Created by tsegura on 4/13/2023.
//

#include "../header/SfmlApp.h"

Vector2f SfmlApp::normalizeVector(Vector2f source) {
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0) {
        return Vector2(source.x / length, source.y / length);
    }

    return source;
}

RectangleShape SfmlApp::DrawLine(Vector2f from, Vector2f to, float thickness)
{
    RectangleShape line;
    line.setFillColor(Color::White);

    Vector2f dir = (to - from);
    float angle = atan2(dir.y, dir.x) * (180.0f / M_PI);
    float distance = sqrt(pow(from.x - to.x, 2) + pow(from.y - to.y, 2));

    line.setPosition(from);
    line.setSize(Vector2f(distance, thickness));
    line.setRotation(angle);

    return line;
}

void SfmlApp::Run() {
    RenderWindow window(VideoMode(640, 480), "Waze of Thrones");

    CircleShape shape;
    shape.setFillColor(Color::Cyan);

    int x = 0;
    int y = 0;
    int radius = 40;

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

        shape.setPosition(x, y);
        shape.setRadius(radius);

        window.clear(Color::Black);
        window.draw(shape);

        Vector2f center = Vector2f(40, 40);
        window.draw(DrawLine(center, shape.getPosition(), 10.0f));
        window.display();
    }

}