# HM2D

*HM2D* is a 2D custom built game engine. The purpose of this project is to learn how game engines work in order to gain a greater understanding of the core subsystems in modern game development.

## Build

```
cmake -B build
cmake --build build
```

## Linux Prerequisites

`xorg-dev` is a meta-package that pulls in all X11 dev headers GLFW needs.

```
sudo apt install xorg-dev
```

## About GLAD loader

`Engine/vendor/glad` was generated locally with the [glad2 CLI](https://github.com/Dav1dde/glad)
(`pip install glad2`)

```
glad --api gl:core=4.6 --out-path <dir> c --loader
```

Few things to Note:
- **Files are `gl.h`/`gl.c`, not `glad.h`/`glad.c`.** `#include <glad/g1.h>`,
  not `<glad/glad.h>`
- **The load call is `gladLoadGL(GLADloadfunc load)`**. With GLFW:
  `gladLoadGL(reinterpret_cast<GLADloadfunc>(glfwGetProcAddress))`

## Structure

```
Engine/
  include/Engine/       <- public API -- The only headers Sandbox should see
  src/
  vendor/glad/          <- generated GLAD loader, only Engine depends on this
Sandbox/
  src/main.cpp          <- only ever includes Engine's public headers
```