#include <iostream>

#include "Application.h"

int main() {
    Engine::Application app;

    app.initialize();
    app.run();

    return 0;
}