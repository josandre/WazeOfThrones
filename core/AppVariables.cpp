//
// Created by tsegura on 4/22/2023.
//

#include "AppVariables.h"
#include "header/MapDAO.h"

AppVariables::AppVariables() {
    MapDAO citiDao;
    this->map = citiDao.InitMap();
    this->city = {""};
    this->fromCity = {""};
    this->toCity = {""};
    this->menuOption = -1;
    this->selectedCity = -1;
}

Vector2f AppVariables::GetCameraPosition() {
    return cameraPosition;
}
void AppVariables::SetCameraPosition(Vector2f cameraPosition) {
    AppVariables::cameraPosition = cameraPosition;
}

float AppVariables::GetCameraZoom() {
    return cameraZoom;
}
void AppVariables::SetCameraZoom(float cameraZoom) {
    AppVariables::cameraZoom = cameraZoom;
}

Map *AppVariables::GetMap() const {
    return map;
}
void AppVariables::SetMap(Map *map) {
    AppVariables::map = map;
}

vector<int> AppVariables::GetAdjacentCities() {
    return adjacentCities;
}
void AppVariables::SetAdjacentCities(vector<int> adjacentCities) {
    AppVariables::adjacentCities = adjacentCities;
}

vector<int> AppVariables::GetPathRoutes() {
    return pathRoutes;
}
void AppVariables::SetPathRoutes(vector<int> pathRoutes) {
    AppVariables::pathRoutes = pathRoutes;
}

string* AppVariables::GetCity() {
    return &city;
}

void AppVariables::SetCity(string city) {
    AppVariables::city = city;
}

string* AppVariables::GetFromCity() {
    return &fromCity;
}
void AppVariables::SetFromCity(string fromCity) {
    AppVariables::fromCity = fromCity;
}

string* AppVariables::GetToCity() {
    return &toCity;
}
void AppVariables::SetToCity(string toCity) {
    AppVariables::toCity = toCity;
}

int AppVariables::GetMenuOption() {
    return menuOption;
}
void AppVariables::SetMenuOption(int menuOption) {
    AppVariables::menuOption = menuOption;
}

int AppVariables::GetSelectCityOption() {
    return selectCityOption;
}
void AppVariables::SetSelectCityOption(int selectCityOption) {
    AppVariables::selectCityOption = selectCityOption;
}

int AppVariables::GetSelectedRouteOption() {
    return selectedRouteOption;
}
void AppVariables::SetSelectedRouteOption(int selectedRouteOption) {
    AppVariables::selectedRouteOption = selectedRouteOption;
}

int AppVariables::GetSelectedCity() {
    return selectedCity;
}
void AppVariables::SetSelectedCity(int selectedCity) {
    AppVariables::selectedCity = selectedCity;
}
