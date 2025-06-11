#pragma once
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace Estro {
    /*!@brief A basic struct that can store assets.*/
    class Asset {
        public:
        virtual ~Asset() = default;

        virtual void load(std::string filename) = 0;

            [[nodiscard]] inline bool isValid() const {return _valid;}
        protected:
            bool _valid = false;
    };

    /*!@ingroup Graphics
     */
    class Texture : public Asset {
        public:
            sf::Texture data;

            void load(std::string filename) override;

            ~Texture() override;
    };

    class Sound : public Asset {
        public:
            sf::Sound sound;

            void load(std::string filename) override;

            ~Sound() override;
    };
}
