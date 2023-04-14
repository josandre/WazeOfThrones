//
// Created by tsegura on 4/13/2023.
//

#include "../header/City.h"

City::City(string name) {
    this->name = name;
    this->next = nullptr;
}

string City::GetName() {
    return this->name;
}
void City::SetName(string value) {
    this->name = value;
}

City *City::GetNext() {
    return this->next;
}
void City::SetNext(City *value) {
    this->next = value;
}

int City::GetIndex() {
    return this->index;
}
void City::SetIndex(int value) {
    this->index = value;
}