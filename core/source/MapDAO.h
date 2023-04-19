//
// Created by tsegura on 4/17/2023.
//

#ifndef WAZEOFTHRONES_MAPDAO_H
#define WAZEOFTHRONES_MAPDAO_H


#include "../header/Map.h"

class MapDAO {
public:
    Map* InitMap() {
        Map* map = new Map();
        map->AddCity("BASTION KAR", 1200.0, 180.0, 0);
        map->AddCity("INVERNALIA", 910.0, 270.0, 1);
        map->AddCity("TORRHEN", 660.0, 440.0, 2);
        map->AddCity("PUERTO BLANCO", 970.0, 520.0, 3);
        map->AddCity("VARAMAR", 900.0, 830.0, 4);
        map->AddCity("LOS DEDOS", 1.0, 2.0, 5);
        map->AddCity("Nido de Águilas",1.0, 2.0, 6);
        map->AddCity("El Valle",1.0, 2.0, 7);
        map->AddCity("Aguas Dulces",1.0, 2.0, 8);
        map->AddCity("Colmillo Dorado",1.0, 2.0, 9);
        map->AddCity("Cueva",1.0, 2.0, 10);
        map->AddCity("Harrenhal",1.0, 2.0, 11);
        map->AddCity("Astas",1.0, 2.0, 12);
        map->AddCity("Puerto Gaviota",1.0, 2.0, 13);
        map->AddCity("Roca Casterly",1.0, 2.0, 14);
        map->AddCity("Lannisport",1.0, 2.0, 15);
        map->AddCity("El Dominio",1.0, 2.0, 16);
        map->AddCity("Ladera",1.0, 2.0, 17);
        map->AddCity("Senda Hueso",1.0, 2.0, 18);
        map->AddCity("Aguas Negras",1.0, 2.0, 19);
        map->AddCity("Desembarco del Rey",1.0, 2.0, 20);
        map->AddCity("Bosque Alto",1.0, 2.0, 21);
        map->AddCity("Bastion de Tormentas",1.0, 2.0, 22);
        map->AddCity("Alto Jardín",1.0, 2.0, 23);
        map->AddCity("Antigua",1.0, 2.0, 24);
        map->AddCity("Asperon",1.0, 2.0, 25);
        map->AddCity("Campo Estrella",1.0, 2.0, 26);
        map->AddCity("Lanza del Sol",1.0, 2.0, 27);
        map->AddCity("Yalth",1.0, 2.0, 28);

        map->AddRoute("BASTION KAR", "INVERNALIA", 10, 5);
        map->AddRoute("BASTION KAR", "PUERTO BLANCO", 2, 8);
        map->AddRoute("PUERTO BLANCO", "INVERNALIA", 1, 8);

        map->AddRoute("INVERNALIA", "PUERTO BLANCO", 2, 8);
        map->AddRoute("INVERNALIA", "TORRHEN", 2, 8);

        map->AddRoute("PUERTO BLANCO", "VARAMAR", 2, 8);

        map->AddRoute("TORRHEN", "VARAMAR", 2, 8);
        return map;
    }
};


#endif //WAZEOFTHRONES_MAPDAO_H
