//
// Created by tsegura on 4/13/2023.
//

#ifndef WAZEOFTHRONES_MAP_H
#define WAZEOFTHRONES_MAP_H

#define CITY_CAPACITY 100

#include "City.h"
#include "Route.h"
#include "iostream"
#include "Hash.h"


class Map {
private:
    int lastCityIndex;
    int cityCount;
    City* rootCity;
    Route*** routes;
    Hash *table;

public:
    explicit Map();

    int miniDist(int [] , bool[]);

    string DijkstraAlgo(Map, int, int);

    int getCityCount();

    void printMatrix();

    City* GetRoot();
    Route*** GetRoutes();

    int CityIndex(string cityName);

    City* CityFromIndex(int cityIndex);

    bool AddCity(string name, float posX, float posY, int index);

    bool AddRoute(string from, string to, float distance, float time);

    Hash *getTable();

    void Print();
};


#endif //WAZEOFTHRONES_MAP_H
