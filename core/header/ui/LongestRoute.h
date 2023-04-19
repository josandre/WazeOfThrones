//
// Created by tsegura on 4/17/2023.
//

#ifndef WAZEOFTHRONES_LONGESTROUTE_H
#define WAZEOFTHRONES_LONGESTROUTE_H

#include <SFML/Graphics.hpp>
#include <math.h>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <imgui-SFML.h>
#include <imgui.h>
#include <misc/cpp/imgui_stdlib.h>
#include "../Map.h"

using namespace sf;
using namespace std;

class LongestRoute {
public:
    char* items[2] = { "Seleccionar origen", "Seleccionar destino" };
    char* current_item = items[0];

    void Clear() {
        current_item = items[0];
    }

    void ShowUI(string* fromCity, string* toCity, int* selectCityOption) {
        ImGui::Begin("Ruta más larga");
        ImGui::BeginGroup();

        // To select which city to pick
        if (ImGui::BeginCombo("##combo", current_item)) // The second parameter is the label previewed before opening the combo.
        {
            for (int n = 0; n < IM_ARRAYSIZE(items); n++)
            {
                bool is_selected = (current_item == items[n]); // You can store your selection however you want, outside or inside your objects
                if (ImGui::Selectable(items[n], current_item, is_selected)) {
                    current_item = items[n];
                    *selectCityOption = n;
                }

                if (is_selected) {
                    ImGui::SetItemDefaultFocus();   // You may set the initial focus when opening the combo (scrolling + for keyboard navigation support)
                }
            }
            ImGui::EndCombo();
        }

        // Text fields
        ImGui::InputText("Origen", fromCity, 100);
        ImGui::InputText("Destino", toCity, 100);

        if (ImGui::Button("Mostrar Ruta", ImVec2(100, 40))) {
            //Print(fromCity);
        }

        ImGui::EndGroup();
        ImGui::End();
    }
};


#endif //WAZEOFTHRONES_LONGESTROUTE_H
