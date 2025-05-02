# Estroengine Pre-Alpha

(NOTE: This version of Estroengine is a full rewrite, with the hopes of making this the permanant base, now that I better understand how C++ is structured and compiled.)

[![estroengine](https://robinsaviary.com/gifs/estroengine.gif)](https://blinkies.cafe/?s=0023-trans-pride)

An *open source, portable, easy-to-use node-tree-based game engine* built in *C++20*.

Heavily inspired by engines such as [Godot](https://godotengine.org/), [Source](https://developer.valvesoftware.com/wiki/SDK_Docs), and [GameMaker](https://gamemaker.io/en).

### Installation / Building

I am in the process of making Estroengine much more user-friendly. The final setup will use [CMake](https://cmake.org/).

### Backends

Estroengine currently supports two libraries as backends:
* [raylib](https://www.raylib.com/) (Web, Windows, MacOS, Linux)
* [SFML](https://www.sfml-dev.org/) (Windows, MacOS, Linux)

### Notes on sub-libraries

Estroengine includes a standalone library, *estrovector*, which is a basic C#-style implementation of math vectors intended for general utility (Basically Vector2 and Vector3).

*Estrocolors* is another technically standalone library that adds a simple but versatile Color struct.

### Related Reading

I occasionally post about Estroengine on my website:

[![Robin's Aviary](https://robinsaviary.com/robins-aviary.gif)](https://robinsaviary.com)
