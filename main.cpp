#include <iostream>
#include "core/header/SfmlApp.h"

using namespace std;

void SfmlTest() {
    SfmlApp* app = new SfmlApp();
    app->Run();
}

int main() {
    SfmlTest();
    return 0;
}
