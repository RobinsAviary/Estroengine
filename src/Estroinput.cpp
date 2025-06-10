#include "../include/Estroinput.h"
#include <map>

#include "SFML/Window.hpp"

sf::Keyboard::Key KeyToSFKey(Estro::Keys::Key key) {
    std::map<Estro::Keys::Key, sf::Keyboard::Key> map {
        {Estro::Keys::A, sf::Keyboard::Key::A},
        {Estro::Keys::Apostrophe, sf::Keyboard::Key::Apostrophe},
        {Estro::Keys::B, sf::Keyboard::Key::B},
        {Estro::Keys::Backslash, sf::Keyboard::Key::Backslash},
        {Estro::Keys::C, sf::Keyboard::Key::C},
        {Estro::Keys::CloseBracket, sf::Keyboard::Key::RBracket},
        {Estro::Keys::OpenBracket, sf::Keyboard::Key::LBracket},
        {Estro::Keys::D, sf::Keyboard::Key::D},
        {Estro::Keys::Delete, sf::Keyboard::Key::Delete},
        {Estro::Keys::Down, sf::Keyboard::Key::Down},
        {Estro::Keys::E, sf::Keyboard::Key::E},
        {Estro::Keys::Eight, sf::Keyboard::Key::Num8},
        {Estro::Keys::End, sf::Keyboard::Key::End},
        {Estro::Keys::OpenBracket, sf::Keyboard::Key::LBracket},
        {Estro::Keys::CloseBracket, sf::Keyboard::Key::RBracket},
        {Estro::Keys::Enter, sf::Keyboard::Key::Enter},
        {Estro::Keys::Escape, sf::Keyboard::Key::Escape},
        {Estro::Keys::F, sf::Keyboard::Key::F},
        {Estro::Keys::F1, sf::Keyboard::Key::F1},
        {Estro::Keys::F2, sf::Keyboard::Key::F2},
        {Estro::Keys::F3, sf::Keyboard::Key::F3},
        {Estro::Keys::F4, sf::Keyboard::Key::F4},
        {Estro::Keys::F5, sf::Keyboard::Key::F5},
        {Estro::Keys::F6, sf::Keyboard::Key::F6},
        {Estro::Keys::F7, sf::Keyboard::Key::F7},
        {Estro::Keys::F8, sf::Keyboard::Key::F8},
        {Estro::Keys::F9, sf::Keyboard::Key::F9},
        {Estro::Keys::F10, sf::Keyboard::Key::F10},
        {Estro::Keys::F11, sf::Keyboard::Key::F11},
        {Estro::Keys::F12, sf::Keyboard::Key::F12},
    };


}

bool Estro::isKeyDown(Keys::Key key) {



}

bool Estro::isKeyPressed(Keys::Key key) {

}

bool Estro::isKeyReleased(Keys::Key key) {

}

