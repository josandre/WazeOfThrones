#include <iostream>
#include "core/header/ui/SfmlApp.h"
#include "core/header/Map.h"
#include "core/header/Hash.h"
#include "core/header/MapDAO.h"


using namespace std;

void SfmlTest() {
    SfmlApp* app = new SfmlApp();
    app->Run();
}

void GraphTest() {
    Map* map = new Map();
    map->AddCity("A", 0, 0, 1);
    map->AddCity("B", 0, 0, 1);
    map->AddCity("C", 0, 0, 1);

    map->AddRoute("A", "B", 10, 5);
    map->AddRoute("A", "C", 1, 3);
    map->AddRoute("B", "C", 2, 8);

}



void CitiDAOTest(){
    MapDAO citiDao;
    Map* map = citiDao.InitMap();
    cout << map->DijkstraAlgo(*map, 0, 1) << endl;

    //map->printMatrix();

}



int main() {
    //CitiDAOTest();
    SfmlTest();
    //GraphTest();

    return 0;
}
