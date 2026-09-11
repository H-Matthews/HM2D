#pragma once

#include "ApplicationState.h"

// #include "core/StateStack/StateStack.hpp"
// #include "core/Messaging/MessageNetwork.hpp"

#include <string>
#include <functional>
#include <optional>

namespace Engine {

class Application {
  public:
    // Application(AppSpecConfig appConfig);
    void initialize();
    void run();
};

} // namespace Core