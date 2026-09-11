include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# Wayland support needs wayland-scanner at build time, which usually isn't
# installed by default. X11 alone is enough (it still works under Wayland
# sessions via XWayland), so skip Wayland rather than requiring that tool.
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG        3.4
    GIT_SHALLOW    TRUE
)
FetchContent_MakeAvailable(glfw)

# GLAD — OpenGL 4.6 Core loader, generated via the glad2 CLI (see
# README.md for how to regenerate with a different version/extensions).
add_library(glad STATIC vendor/glad/src/gl.c)
target_include_directories(glad PUBLIC vendor/glad/include)

set(SRC src/Application.cpp
        src/ApplicationState.cpp)

add_library(Engine STATIC ${SRC})
target_link_libraries(Engine PRIVATE glfw glad)

target_include_directories(Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)