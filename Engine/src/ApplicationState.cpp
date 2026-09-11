#include "ApplicationState.h"

#include <algorithm>

namespace Engine {

std::string convertAppStateEnumToString(const ApplicationState& appState) {
    switch(appState) {
        case ApplicationState::UNINITIALIZED:
            return "UNINITIALIZED";
        case ApplicationState::INITIALIZED:
            return "INITIALIZED";
        case ApplicationState::RUNNING:
            return "RUNNING";
        case ApplicationState::SHUTTING_DOWN:
            return "SHUTTING_DOWN";
        default:
            return "";
    }
}

// std::optional<ApplicationState> convertStringToAppStateEnum(std::string_view stringState) {
//     std::string upperStr(stringState);

//     std::transform(upperStr.begin(), upperStr.end(), upperStr.begin(), [](unsigned char c) {
//         return std::toupper(c);
//     });

//     std::optional<ApplicationState> appStateEnum = std::nullopt;

//     if(upperStateStr == "UNINITIALIZED") {
//         appStateEnum = ApplicationState::UNINITIALIZED;
//     }
//     else if(upperStateStr == "INITIALIZED") {
//         appStateEnum = ApplicationState::INITIALIZED;
//     }
//     else if(upperStateStr == "RUNNING") {
//         appStateEnum = ApplicationState::RUNNING;
//     }
//     else if(upperStateStr == "SHUTTING_DOWN") {
//         appStateEnum = ApplicationState::SHUTTING_DOWN;
//     }

//     return appStateEnum;
// }

} // ENGINE NAMESPACE