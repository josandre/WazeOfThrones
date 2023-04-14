//
// Created by tsegura on 4/13/2023.
//

#ifndef WAZEOFTHRONES_CITY_H
#define WAZEOFTHRONES_CITY_H

#include <string>

using namespace std;

class City {
private:
    string name;
    City* next;
    int index;

public:
    explicit City(string name);

    string GetName();
    void SetName(string value);

    City* GetNext();
    void SetNext(City* value);

    int GetIndex();
    void SetIndex(int value);
};


#endif //WAZEOFTHRONES_CITY_H
