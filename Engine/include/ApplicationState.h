#pragma once

#include <string>
#include <optional>

namespace Engine {
    enum class ApplicationState {
        UNINITIALIZED = 0,
        INITIALIZED,
        RUNNING,
        SHUTTING_DOWN
    };

    std::string convertAppStateEnumToString(ApplicationState appState);
    // std::optional<ApplicationState> convertStringToAppStateEnum(std::string_view stringState);
}