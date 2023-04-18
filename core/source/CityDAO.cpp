//
// Created by rocha on 15/4/2023.
//

#include <vector>
#include <iostream>
#include "../header/City.h"

class CityDAO{
private:
    vector<City> cities;

public:
    CityDAO(){
        // Agregar las ciudades y sus datos
        cities.push_back(City("Bastion Kar",1.0, 2.0));
        cities.push_back(City("Invernalia",1.0, 2.0));
        cities.push_back(City("Torrhen",1.0, 2.0));
        cities.push_back(City("Puerto Blanco",1.0, 2.0));
        cities.push_back(City("Varamar",1.0, 2.0));
        cities.push_back(City("Los Dedos",1.0, 2.0));
        cities.push_back(City("Nido de Águilas",1.0, 2.0));
        cities.push_back(City("El Valle",1.0, 2.0));
        cities.push_back(City("Aguas Dulces",1.0, 2.0));
        cities.push_back(City("Colmillo Dorado",1.0, 2.0));
        cities.push_back(City("Cueva",1.0, 2.0));
        cities.push_back(City("Harrenhal",1.0, 2.0));
        cities.push_back(City("Astas",1.0, 2.0));
        cities.push_back(City("Puerto Gaviota",1.0, 2.0));
        cities.push_back(City("Roca Casterly",1.0, 2.0));
        cities.push_back(City("Lannisport",1.0, 2.0));
        cities.push_back(City("El Dominio",1.0, 2.0));
        cities.push_back(City("Ladera",1.0, 2.0));
        cities.push_back(City("Senda Hueso",1.0, 2.0));
        cities.push_back(City("Aguas Negras",1.0, 2.0));
        cities.push_back(City("Desembarco del Rey",1.0, 2.0));
        cities.push_back(City("Bosque Alto",1.0, 2.0));
        cities.push_back(City("Bastion de Tormentas",1.0, 2.0));
        cities.push_back(City("Alto Jardín",1.0, 2.0));
        cities.push_back(City("Antigua",1.0, 2.0));
        cities.push_back(City("Asperon",1.0, 2.0));
        cities.push_back(City("Campo Estrella",1.0, 2.0));
        cities.push_back(City("Lanza del Sol",1.0, 2.0));
        cities.push_back(City("Yalth",1.0, 2.0));
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