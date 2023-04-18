//
// Created by tsegura on 4/17/2023.
//

#ifndef WAZEOFTHRONES_SEARCHCITY_H
#define WAZEOFTHRONES_SEARCHCITY_H
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



class SearchCity {

public:
    void ShowUI(string* city, Map *map, RenderWindow &window, View &view ) {
        ImGui::Begin("Ver ciudades adyascentes");
        ImGui::BeginGroup();

        ImGui::InputText("City", city, 100);

        if (ImGui::Button("Search", ImVec2(100, 40))) {
            map->getTable();
            City *cityFound = map->getTable()->getCity(*city);

            if(cityFound != nullptr){
                view.setCenter(Vector2f(cityFound->GetPosX(), cityFound->GetPosY()));
                view.setSize(window.getDefaultView().getSize());    // Reset size
                view.zoom(0.6);
                window.setView(view);

            }
        }
        if (ImGui::Button("Clear Output", ImVec2(100, 40))) {
            //outputText = "";
        }

        ImGui::EndGroup();
        ImGui::End();
    }
};


#endif //WAZEOFTHRONES_SEARCHCITY_H
