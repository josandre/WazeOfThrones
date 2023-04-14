//
// Created by tsegura on 4/13/2023.
//

#include "../header/Map.h"

int Map::CityIndex(string cityName) {
    if (this->rootCity == nullptr) {
        return -1;
    }

    City* currentCity = this->rootCity;
    int index = 0;

    while (currentCity != nullptr) {
        if (currentCity->GetName() == cityName) {
            return index;
        }
        currentCity = currentCity->GetNext();
        index++;
    }

    return -1;
}

City *Map::CityFromIndex(int cityIndex) {
    if (cityIndex >= this->cityCount) {
        return nullptr;
    }

    City* currentCity = this->rootCity;
    int cont = 0;

    while (currentCity != nullptr) {
        if (cont == cityIndex) {
            break;
        }
        currentCity = currentCity->GetNext();
        cont++;
    }

    return currentCity;
}

Map::Map() {
    this->lastCityIndex = 0;
    this->cityCount = 0;
    this->rootCity = nullptr;
    this->routes = new Route**[CITY_CAPACITY];

    for (int i = 0; i < CITY_CAPACITY; i++)
    {
        routes[i] = new Route*[CITY_CAPACITY];
        for (int j = 0; j < CITY_CAPACITY; j++)
        {
            routes[i][j] = nullptr;
        }
    }
}

City* Map::GetRoot() {
    return this->rootCity;
}

Route ***Map::GetRoutes() {
    return this->routes;
}

bool Map::AddCity(string name, float posX, float posY) {
    City* newCity = new City(name, posX, posY);

    // Root case
    if (this->rootCity == nullptr) {
        this->rootCity = newCity;
        this->cityCount++;
        return true;
    }

    if (CityIndex(name) != -1) {
        return false;
    }

    City* currentCity = this->rootCity;
    while (currentCity->GetNext() != nullptr) {
        currentCity = currentCity->GetNext();
    }

    currentCity->SetNext(newCity);
    this->cityCount++;
}

bool Map::AddRoute(string from, string to, float distance, float time) {
    int fromIndex = CityIndex(from);
    int toIndex = CityIndex(to);

    // Make sure the nodes exist in the graph
    if (fromIndex == -1 || toIndex == -1) {
        return false;
    }

    Route* newRoute = new Route("", distance, time);
    this->routes[fromIndex][toIndex] = newRoute;
    return true;
}

void Map::Print() {
    for (int i = 0; i < CITY_CAPACITY; i++) {
        City *from = CityFromIndex(i);

        if (from == nullptr) {
            continue;
        }

        std::cout << from->GetName();
        for (int j = 0; j < CITY_CAPACITY; j++) {
            if (routes[i][j] == nullptr) {
                continue;
            }

            City *to = CityFromIndex(j);
            if (to != nullptr) {
                std::cout << " -> " << to->GetName();
            }
        }

        std::cout << std::endl;
    }
}