//
// Created by rocha on 15/4/2023.
//

#include <vector>
#include <iostream>
#include "../header/City.h"
#include "../header/Map.h"

class CityDAO{
private:
    vector<City> cities;

public:
    CityDAO(){
        Map* map = new Map();
        // Agregar las ciudades y sus datos
        map->AddCity("Bastion Kar", 1.0, 2.0);
        map->AddCity("Invernalia", 1.0, 2.0);
        map->AddCity("Torrhen", 1.0, 2.0);
        map->AddCity("Puerto Blanco", 1.0, 2.0);
        map->AddCity("Varamar", 1.0, 2.0);
        map->AddCity("Los Dedos", 1.0, 2.0);
        map->AddCity("Nido de Águilas",1.0, 2.0);
        map->AddCity("El Valle",1.0, 2.0);
        map->AddCity("Aguas Dulces",1.0, 2.0);
        map->AddCity("Colmillo Dorado",1.0, 2.0);
        map->AddCity("Cueva",1.0, 2.0);
        map->AddCity("Harrenhal",1.0, 2.0);
        map->AddCity("Astas",1.0, 2.0);
        map->AddCity("Puerto Gaviota",1.0, 2.0);
        map->AddCity("Roca Casterly",1.0, 2.0);
        map->AddCity("Lannisport",1.0, 2.0);
        map->AddCity("El Dominio",1.0, 2.0);
        map->AddCity("Ladera",1.0, 2.0);
        map->AddCity("Senda Hueso",1.0, 2.0);
        map->AddCity("Aguas Negras",1.0, 2.0);
        map->AddCity("Desembarco del Rey",1.0, 2.0);
        map->AddCity("Bosque Alto",1.0, 2.0);
        map->AddCity("Bastion de Tormentas",1.0, 2.0);
        map->AddCity("Alto Jardín",1.0, 2.0);
        map->AddCity("Antigua",1.0, 2.0);
        map->AddCity("Asperon",1.0, 2.0);
        map->AddCity("Campo Estrella",1.0, 2.0);
        map->AddCity("Lanza del Sol",1.0, 2.0);
        map->AddCity("Yalth",1.0, 2.0);
    }

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
};