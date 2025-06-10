#pragma once
#include <string>
#include "SFML/Graphics.hpp"

namespace Estro {
    class Asset {
        public:
            virtual void load(std::string filename) {};

            [[nodiscard]] inline bool isValid() const {return _valid;}
        protected:
            bool _valid = false;
    };

    class Texture : public Asset {
        public:
            sf::Texture data;

            void load(std::string filename) override;

            ~Texture();
    };
}