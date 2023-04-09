#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
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

        shape.setPosition(x - radius, y - radius);
        shape.setRadius(radius);

        window.clear(Color::Black);
        window.draw(shape);

        window.display();
    }

    return 0;
}
