# Estroengine 0.5.0

[![estroengine](https://robinsaviary.com/gifs/estroengine.gif)](https://blinkies.cafe/?s=0023-trans-pride)

A **free** *and open source, portable, easy-to-use node-tree-based game engine* built in *C++20*.

Heavily inspired by engines such as [Godot](https://godotengine.org/), [Source](https://developer.valvesoftware.com/wiki/SDK_Docs), and [GameMaker](https://gamemaker.io/en).

## Why This Exists

I am a long-time GameMaker user (we're talking all the way back to days of 8.1). I found after a while I was rapidly outgrowing what GML could support, both in scope and in speed. Admittedly, I do actually still actively use game engines such as Godot, but I found that nothing could really match the "draw anything anywhere to the screen" energy that GameMaker really supported with it's wide function set.

The goal with this project is to marry the rendering ideas of GameMaker, with the flexibility/speed of C++, and the Node tree structure from Godot.

## Building

The current version of the repisitory includes a `CMakeLists.txt` (for [CMake](https://cmake.org/)) for building Estroengine (as a static library) as part of your project :) At the moment it does download/import [SFML](https://www.sfml-dev.org/) and [Box2D](https://box2d.org/) automatically for building.

## Learn

This project also features HTML documentation you can build with [Doxygen](https://www.doxygen.nl/).

## Backends

Estroengine currently supports two libraries as backends:
* [raylib](https://www.raylib.com/) (Web, Windows, MacOS, Linux) [Planned]
* [SFML](https://www.sfml-dev.org/) (Windows, MacOS, Linux) [Actively Developing]

## License

Estroengine is provided under the [Unlicense License](https://unlicense.org/).
Free for any type of use (personal, commercial, etc.) and credit of this library is not required - but always appreciated!

## Related Reading

I occasionally post about Estroengine on my website:

[![Robin's Aviary](https://robinsaviary.com/robins-aviary.gif)](https://robinsaviary.com)
