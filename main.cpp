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
}

void GraphTest() {
    Map* map = new Map();
    map->AddCity("A", 0, 0, 1);
    map->AddCity("B", 0, 0, 1);
    map->AddCity("C", 0, 0, 1);

    map->AddRoute("A", "B", 10, 5);
    map->AddRoute("A", "C", 1, 3);
    map->AddRoute("B", "C", 2, 8);

    map->Print();
}


void testHashing(){
    Hash *table = new Hash;
  //  table->addCity(table->hashing(0), new City("Winterfell", 1, 1));
  //  table->addCity(table->hashing(1), new City("Poniente", 3, 3));
    City *city = table->getCity("Poniente");

    if (city != nullptr) {
        cout << city->GetName();
    } else{
        cout << "The values was not found";
    }
}

int main() {
    testHashing();
    SfmlTest();
    //GraphTest();

    //CitiDAOTest();
    return 0;
}
