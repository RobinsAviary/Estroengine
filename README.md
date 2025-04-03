# Estroengine v0.1.5
[![estroengine](https://robinsaviary.com/gifs/estroengine.gif)](https://blinkies.cafe/?s=0023-trans-pride)

A portable simple-to-use node-tree-based game engine built in C++.
The entire engine is header-only so it can be easily integrated.
[Premake](https://premake.github.io/) is a work-in-progress, though I am just using a simple include and templates for the backends themself. *(Also make sure you update the specific backend you're using in estroengine.hpp. I'm working on a way to hopefully avoid having to do this in the future.

### Example

This example is the minimum amount of required code to create and manage a window in a way that won't upset whatever system you're working on. Be sure to include an implementation file from `include\backends\`.

```
#include "estroengine.hpp"

rVector2<unsigned int> windowSize = {600, 400};
std::string windowTitle = "Estroengine"

rEngine engine;

int main() {
    rInit(windowSize, windowTitle);

    while (rIsGameLooping()) {
        engine.update();
    }

    return 0;
}
```

### Backends

Estroengine currently supports two libraries as backends:
* [raylib](https://www.raylib.com/)
* [SFML](https://www.sfml-dev.org/)

### Notes on individual libraries

Estroengine includes a standalone library, *estrovector*, which is a basic C#-style implementation of math vectors intended for general utility (Basically Vector2 and Vector3).

*Estropathing* is an interface for [Bensuperpc](https://github.com/bensuperpc)'s [A* implementation](https://github.com/bensuperpc/astar).

Gamepads are currently a work in progress and only supported on the SFML backend at the moment.

### Related Reading

I occasionally post about Estroengine on my website:

[![Robin's Aviary](https://robinsaviary.com/robins-aviary.gif)](https://robinsaviary.com)
