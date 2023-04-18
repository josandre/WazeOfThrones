#include <iostream>
#include "core/header/ui/SfmlApp.h"
#include "core/header/Map.h"
#include "core/header/Hash.h"
#include "core/source/CityDao.cpp"

using namespace std;

void SfmlTest() {
    SfmlApp* app = new SfmlApp();
    app->Run();
}

void CitiDAOTest(){
    CityDAO citiDao;
    citiDao.printCities();
}

void GraphTest() {
    Map* map = new Map();
    map->AddCity("A", 0, 0);
    map->AddCity("B", 0, 0);
    map->AddCity("C", 0, 0);

    map->AddRoute("A", "B", 10, 5);
    map->AddRoute("A", "C", 1, 3);
    map->AddRoute("B", "C", 2, 8);

    map->Print();
}



int main() {
    SfmlTest();
    //GraphTest();

    //CitiDAOTest();
    return 0;
}
