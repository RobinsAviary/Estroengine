#include "../../../include/Estroassets.h"

using namespace Estro;

void Texture::load(std::string filename) {
    _valid = data.loadFromFile(filename);
}

Texture::~Texture() {
    _valid = false;
}

void Sound::load(std::string filename) {
    _valid = data.loadFromFile(filename);
}

Sound::~Sound() {
    _valid = false;
}

