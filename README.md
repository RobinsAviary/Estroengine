# Estroengine v0.1.5
[![estroengine](https://robinsaviary.com/gifs/estroengine.gif)](https://blinkies.cafe/?s=0023-trans-pride)

A portable simple-to-use node-tree-based game engine built in C++.
The entire engine is header-only so it can be easily integrated.
[Premake](https://premake.github.io/) is a work-in-progress.

### Notes on individual libraries

Estroengine includes a standalone library, estrovector, which is a basic C#-style implementation of math vectors intended for general utility (Basically Vector2 and Vector3).

Estropathing is an interface for [Bensuperpc](https://github.com/bensuperpc)'s [A* implementation](https://github.com/bensuperpc/astar).

### Backends

Estroengine currently supports two libraries as backends:
* [raylib](https://www.raylib.com/)
* [SFML](https://www.sfml-dev.org/)

Gamepads are currently a work in progress and only supported on the SFML backend at the moment.

I occasionally post about Estroengine on my website:

[![Robin's Aviary](https://robinsaviary.com/robins-aviary.gif)](https://robinsaviary.com)
