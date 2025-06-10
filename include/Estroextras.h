#pragma once

#include "Estroengine.h"

namespace Estro {
    /*!@brief Clears the screen every frame with a stored color.
    @ingroup Graphics
    */
    class ColorBackground : public Node {
    public:
        //!@brief The color to clear the screen with.
        Color color = Colors::Estrogen;

        void draw() override;
    };
}
