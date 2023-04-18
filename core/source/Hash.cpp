//
// Created by Jocselyn Aguilar on 14/4/23.
//

#include "../header/Hash.h"


Hash::Hash() {
    for (int i = 0; i < MAX; i++){
        this->city [i] = nullptr;
    }
}

void Hash::addCity(int index, City *city) {
    if (this->city[index] == nullptr){
        this->city[index] = city;
    }else {
        City * aux = this->city[index];
        while (aux->GetNext() != nullptr){
            aux = aux->GetNext();
        }

        aux->SetNext(city);
    }
}

bool Hash::equalSIgnoreCase(std::string str1, std::string str2) {
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return (str1 == str2);
}


City *Hash::getCity(string name) {
    for(int i = 0; i < this->MAX; i++){
        City *aux = this->city[i];
        if(equalSIgnoreCase(aux->GetName(), name)){
            return aux;
        }
    }
    return nullptr;
}

int Hash::hashing(int num) {
    cout << (num%(this->MAX - 1)) << endl;
    return (num%(this->MAX - 1));
}