#include "Application.h"

#include <iostream>

namespace Engine {

void Application::initialize() {
    std::cout << "INITIALIZING " << std::endl;
}

void Application::run() {
    std::cout << "RUNNING " << std::endl;
}

} // NAMESPACE CORE