//
// Created by tsegura on 4/17/2023.
//

#ifndef WAZEOFTHRONES_MAPDAO_H
#define WAZEOFTHRONES_MAPDAO_H


#include "Map.h"

class MapDAO {
public:
    Map* InitMap() {
        Map* map = new Map();

        // Cities
        map->AddCity("BASTION KAR", 1200.0, 180.0, 0);
        map->AddCity("INVERNALIA", 910.0, 270.0, 1);
        map->AddCity("TORRHEN", 660.0, 440.0, 2);
        map->AddCity("PUERTO BLANCO", 970.0, 520.0, 3);
        map->AddCity("VARAMAR", 900.0, 830.0, 4);
        map->AddCity("LOS DEDOS", 1110.0, 790.0, 5);
        map->AddCity("NIDO DE AGUILAS",1240.0, 870.0, 6);
        map->AddCity("EL VALLE",1015.0, 940.0, 7);
        map->AddCity("AGUAS DULCES",860.0, 985.0, 8);
        map->AddCity("COLMILLO DORADO",715.0, 1050.0, 9);
        map->AddCity("CUEVA",825.0, 1190.0, 10);
        map->AddCity("HARRENHAL",940.0, 1105.0, 11);
        map->AddCity("ASTAS",1100.0, 1140.0, 12);
        map->AddCity("PUERTO GAVIOTA",1150.0, 1000.0, 13);
        map->AddCity("ROCA CASTERLY",675.0, 1180.0, 14);
        map->AddCity("LANNISPORT",640.0, 1320.0, 15);
        map->AddCity("EL DOMINIO",790.0, 1430.0, 16);
        map->AddCity("LADERA",945.0, 1375.0, 17);
        map->AddCity("SENDA HUESO",1015.0, 1480.0, 18);
        map->AddCity("Aguas Negras",920.0, 1260.0, 19);
        map->AddCity("DESEMBARCO DEL REY",1030.0, 1310.0, 20);
        map->AddCity("BOSQUE ALTO",1130.0, 1400.0, 21);
        map->AddCity("BASTION DE TORMENTAS",1120.0, 1520.0, 22);
        map->AddCity("ALTO JARDIN",840.0, 1580.0, 23);
        map->AddCity("ANTIGUA",680.0, 1680.0, 24);
        map->AddCity("ASPERON",830.0, 1815.0, 25);
        map->AddCity("CAMPO ESTRELLA",925.0, 1730.0, 26);
        map->AddCity("LANZA DEL SOL",1130.0, 1770.0, 27);
        map->AddCity("YALTH",1100.0, 1835.0, 28);

        // Routes
        map->AddRoute("BASTION KAR", "INVERNALIA", 10, 5);
        map->AddRoute("BASTION KAR", "PUERTO BLANCO", 2, 8);
        map->AddRoute("PUERTO BLANCO", "INVERNALIA", 1, 8);

        map->AddRoute("INVERNALIA", "TORRHEN", 2, 8);

        map->AddRoute("PUERTO BLANCO", "VARAMAR", 2, 8);

        map->AddRoute("TORRHEN", "VARAMAR", 2, 8);
        return map;
    }
};


#endif //WAZEOFTHRONES_MAPDAO_H
