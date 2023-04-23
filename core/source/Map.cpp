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

void Map::printMatrix() {
    for(int i = 0; i < 29; i++){
        cout << CityFromIndex(i)->GetName() << " : ";
        for(int j = 0; j < 29; j++ ){
            auto test = GetRoutes()[i][j];

            if(test != nullptr) {
                cout << test->GetDistance() << " ";
            }else{
                cout << "0" << " ";
            }
        }

        cout << "\n";
    }
}

Map::Map() {
    this->table = new Hash();

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

int Map::miniDist(int distance[], bool Tset[]) {
    int minimum = INT_MAX, ind;

    for(int k= 0; k < 6; k++)
    {
        if(Tset[k] == false && distance[k] <= minimum)
        {
            minimum=distance[k];
            ind = k;
        }
    }
    return ind;
}

string Map::DijkstraAlgo(Map* map, int src, int to)
{
    int distance[29];
    bool Tset[29];


    for(int k = 0; k < 29; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0;

    for(int k = 0; k < 29; k++)
    {
        int m = miniDist(distance,Tset);
        Tset[m] = true;

        for(int k = 0; k < 29; k++)
        {

            if(!Tset[k] && map->GetRoutes()[m][k] && distance[m] != INT_MAX && distance[m] + map->GetRoutes()[m][k]->GetDistance() < distance[k])
                distance[k] = distance[m] + map->GetRoutes()[m][k]->GetDistance();
        }
    }

   /* cout<<"Vertex\t\tDistance from source vertex"<<endl;
    cout << map.CityFromIndex(src)->GetName() << "\t\t\t" << distance[to] << "\t\t\t"
         << map.CityFromIndex(to)->GetName() << endl;
         */

    map->GetRoutes()[0][1]->SetIsHighlighted(true);
    cout << "HOLA!" << endl;
    return map->CityFromIndex(src)->GetName() + "\t\t\t" + to_string(distance[to]) + "\t\t\t" + map->CityFromIndex(to)->GetName();
}


City* Map::GetRoot() {
    return this->rootCity;
}

Route ***Map::GetRoutes() {
    return this->routes;
}

bool Map::AddCity(string name, float posX, float posY, int index) {
    City* newCity = new City(name, posX, posY, index);
    this->table->addCity(newCity->GetIndex(), newCity);

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
    int toIndex = CityIndex(to);
    int fromIndex = CityIndex(from);

    // Make sure the nodes exist in the graph
    if (fromIndex == -1 || toIndex == -1) {
        return false;
    }

    // Double side route
    Route* newRoute = new Route("", distance, time);
    this->routes[fromIndex][toIndex] = newRoute;
    this->routes[toIndex][fromIndex] = newRoute;
    return true;
}

void Map::ClearHighlights() {
    City* currentCity = this->rootCity;

    while (currentCity != nullptr) {
        currentCity->SetIsHighlighted(false);
        currentCity = currentCity->GetNext();
    }

    for (int i = 0; i < CITY_CAPACITY; i++) {
        for (int j = 0; j < CITY_CAPACITY; j++) {
            if (routes[i][j] == nullptr) {
                continue;
            }

            routes[i][j]->SetIsHighlighted(false);
        }
    }
}

void Map::HighlightAdjacentCities(string from) {
    ClearHighlights();
    int cityIndex = CityIndex(from);

    if (cityIndex != -1) {
        for (int i = 0; i < CITY_CAPACITY; i++) {
            if (routes[cityIndex][i] == nullptr) {
                continue;
            }

            CityFromIndex(i)->SetIsHighlighted(true);
            routes[cityIndex][i]->SetIsHighlighted(true);
        }
    }

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

Hash *Map::getTable() {
    return this->table;
}

int Map::getCityCount() {
    this->cityCount;
}