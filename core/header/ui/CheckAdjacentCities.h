//
// Created by tsegura on 4/17/2023.
//

#ifndef WAZEOFTHRONES_CHECKADJACENTCITIES_H
#define WAZEOFTHRONES_CHECKADJACENTCITIES_H

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

using namespace sf;
using namespace std;

class CheckAdjacentCities {
public:
    void ShowUI(string* fromCity, string* toCity) {
        ImGui::Begin("Ver ciudades adyascentes");
        ImGui::BeginGroup();

        ImGui::InputText("From", fromCity, 100);
        ImGui::InputText("To", toCity, 100);

        if (ImGui::Button("Print", ImVec2(100, 40))) {
            //Print(fromCity);
        }
        if (ImGui::Button("Clear Output", ImVec2(100, 40))) {
            //outputText = "";
        }

        ImGui::EndGroup();
        ImGui::End();
    }
};


#endif //WAZEOFTHRONES_CHECKADJACENTCITIES_H
