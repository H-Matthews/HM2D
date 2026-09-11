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
# Note the filenames: glad2 outputs gl.h / gl.c, not glad.h / glad.c like
# older glad1-based tutorials use — #include <glad/gl.h> when you write
# GLFWWindow.cpp, and call gladLoadGL(...), not gladLoadGLLoader(...).
add_library(glad STATIC vendor/glad/src/gl.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# Engine has no .cpp files yet, so it's INTERFACE for now (include paths
# only, nothing compiled). Once you add real sources under src/, switch
# this to STATIC and list them, e.g.:
#
#   add_library(Engine STATIC
#       src/Application.cpp
#   )
#   target_link_libraries(Engine PRIVATE glfw glad)   # both already available below
add_library(Engine INTERFACE)

target_include_directories(Engine INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)