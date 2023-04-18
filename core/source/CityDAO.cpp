//
// Created by rocha on 15/4/2023.
//

#include <vector>
#include <iostream>
#include "../header/City.h"
#include "../header/Map.h"

class CityDAO{
private:
  //  vector<City> cities;
    Map* map = new Map();

public:
    CityDAO(){
        // Agregar las ciudades y sus datos
        map->AddCity("Bastion Kar", 1.0, 2.0, 0);
        map->AddCity("Invernalia", 1.0, 2.0, 2);
        map->AddCity("Torrhen", 1.0, 2.0, 3);
        map->AddCity("Puerto Blanco", 1.0, 2.0, 4);
        map->AddCity("Varamar", 1.0, 2.0, 5);
        map->AddCity("Los Dedos", 1.0, 2.0, 6);
        map->AddCity("Nido de Águilas",1.0, 2.0, 7);
        map->AddCity("El Valle",1.0, 2.0, 8);
        map->AddCity("Aguas Dulces",1.0, 2.0, 9);
        map->AddCity("Colmillo Dorado",1.0, 2.0, 10);
        map->AddCity("Cueva",1.0, 2.0, 11);
        map->AddCity("Harrenhal",1.0, 2.0, 12);
        map->AddCity("Astas",1.0, 2.0, 13);
        map->AddCity("Puerto Gaviota",1.0, 2.0, 14);
        map->AddCity("Roca Casterly",1.0, 2.0, 15);
        map->AddCity("Lannisport",1.0, 2.0, 16);
        map->AddCity("El Dominio",1.0, 2.0, 17);
        map->AddCity("Ladera",1.0, 2.0, 18);
        map->AddCity("Senda Hueso",1.0, 2.0, 19);
        map->AddCity("Aguas Negras",1.0, 2.0, 20);
        map->AddCity("Desembarco del Rey",1.0, 2.0, 21);
        map->AddCity("Bosque Alto",1.0, 2.0, 22);
        map->AddCity("Bastion de Tormentas",1.0, 2.0, 23);
        map->AddCity("Alto Jardín",1.0, 2.0, 24);
        map->AddCity("Antigua",1.0, 2.0, 25);
        map->AddCity("Asperon",1.0, 2.0, 26);
        map->AddCity("Campo Estrella",1.0, 2.0, 27);
        map->AddCity("Lanza del Sol",1.0, 2.0, 28);
        map->AddCity("Yalth",1.0, 2.0, 29);
    }

    /*
    // Obtener ciudades por índice
    City* getCitiesByIndex(int index){
        if(index < 0 || index >= cities.size()){
            return nullptr;
        }
        return &cities[index];
    }

    void printCities(){

        for (int i = 0; i < cities.size(); i++) {

            City city = cities[i];
            cout << "City " << i << ": " << city.GetName() << endl;

           // City* city = getCitiesByIndex(i);
           // cout << "City " << i << ": " << city->GetName() << endl;
        }
    }
     */
};