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

void SfmlApp::Print(string msj) {
    this->outputText += msj + "\n";
}

void SfmlApp::Run() {
    // Constants
    Color backgroundColor = Color(200, 233, 240, 255);
    Color nodesColor = Color(177, 172, 154, 255);
    Color routesColor = Color(145, 145, 145, 255);

    float nodesRadius = 8.0f;
    float routesThickness = 4.0f;

    // Background variables
    Texture backgroundTexture;
    backgroundTexture.loadFromFile("../resources/WazeOfThronesMap.png");
    backgroundTexture.setSmooth(true);
    backgroundTexture.setRepeated(false);
    Sprite background(backgroundTexture);

    // Scroll variables
    Vector2f clickPosition;
    bool moving = false;
    float zoom = 2.0f;
    float zoomMultiplier = 0.1f;

    Clock deltaClock;

    outputText = "";
    string inputText1 = {""};

    RenderWindow window(VideoMode(896, 504), "Waze of Thrones");
    window.setFramerateLimit(60);
    View view = window.getDefaultView();

    // Initial zoom
    view.setSize(window.getDefaultView().getSize());
    view.zoom(zoom);
    window.setView(view);

    ImGui::SFML::Init(window);

    // Define graph
    Map* map = new Map();
    map->AddCity("BASTION KAR", 1200, 180);
    map->AddCity("INVERNALIA", 910, 270);
    map->AddCity("TORRHEN", 660, 440);
    map->AddCity("PUERTO BLANCO", 970, 520);
    map->AddCity("VARAMAR", 900, 830);

    map->AddRoute("BASTION KAR", "INVERNALIA", 10, 5);
    map->AddRoute("BASTION KAR", "PUERTO BLANCO", 2, 8);

    map->AddRoute("INVERNALIA", "PUERTO BLANCO", 2, 8);
    map->AddRoute("INVERNALIA", "TORRHEN", 2, 8);

    map->AddRoute("PUERTO BLANCO", "VARAMAR", 2, 8);

    map->AddRoute("TORRHEN", "VARAMAR", 2, 8);

    while (window.isOpen())
    {
        Event event;

        // Input Events
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;

                case Event::MouseButtonPressed:
                    // Save the position where the use clicked
                    if (event.mouseButton.button == 1) {
                        moving = true;
                        clickPosition = window.mapPixelToCoords(Vector2i(event.mouseButton.x, event.mouseButton.y));
                    }
                    break;

                case Event::MouseButtonReleased:
                    // Stop moving
                    if (event.mouseButton.button == 1) {
                        moving = false;
                    }
                    break;

                case Event::MouseMoved:
                    if (moving == true) {
                        // Calculate movement from previous frame
                        Vector2f mousePosition = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
                        Vector2f deltaPos = clickPosition - mousePosition;

                        // Update view
                        view.setCenter(view.getCenter() + deltaPos);
                        window.setView(view);

                        // Update click position
                        clickPosition = window.mapPixelToCoords(Vector2i(event.mouseMove.x, event.mouseMove.y));
                    }
                    break;

                case Event::MouseWheelScrolled:
                    if (moving == false) {
                        zoom -= event.mouseWheelScroll.delta * zoomMultiplier;
                        zoom = clamp(zoom, 0.5f, 3.0f);

                        // Update view
                        view.setSize(window.getDefaultView().getSize());    // Reset size
                        view.zoom(zoom);    // Apply zoom
                        window.setView(view);
                    }

                    break;
                case Event::KeyPressed:
                    if (event.key.code == Keyboard::Enter)
                    {
                        Print("Enter Just Pressed");
                    }
                    break;
            }
        }

        // Draw UI
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::Begin("Output");
        ImGui::Text(outputText.c_str());
        ImGui::End();

        ImGui::Begin("Controls");
        ImGui::BeginGroup();
        ImGui::InputText("Input", &inputText1, 100);

        if (ImGui::Button("Print", ImVec2(100, 40))) {
            Print(inputText1);
        }
        if (ImGui::Button("Clear Output", ImVec2(100, 40))) {
            outputText = "";
        }

        ImGui::EndGroup();
        ImGui::End();

        window.clear(backgroundColor);
        window.draw(background);

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
                    Vector2f fromPos = Vector2f(from->GetPosX() + nodesRadius, from->GetPosY() + nodesRadius);
                    Vector2f toPos = Vector2f(to->GetPosX() + nodesRadius, to->GetPosY() + nodesRadius);

                    window.draw(DrawLine(fromPos, toPos, routesThickness, routesColor));
                }
            }
        }

        // Draw cities or nodes
        City* currentCity = map->GetRoot();
        while (currentCity != nullptr) {
            CircleShape cityNode;
            cityNode.setPosition(currentCity->GetPosX(), currentCity->GetPosY());
            cityNode.setRadius(nodesRadius);
            cityNode.setFillColor(nodesColor);

            window.draw(cityNode);

            currentCity = currentCity->GetNext();
        }

        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}