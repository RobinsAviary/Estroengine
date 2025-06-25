#pragma once

namespace Estro {
    /*!@ingroup Input
     */
    namespace Keys {
        /*!@ingroup Input
         *@brief All the keys on the keyboard in an enum for use with input functions.
         *@sa isKeyDown(), isKeyPressed(), isKeyReleased()
         */
        enum Key {
            Q,
            W,
            E,
            R,
            T,
            Y,
            U,
            I,
            O,
            P,
            A,
            S,
            D,
            F,
            G,
            H,
            J,
            K,
            L,
            Z,
            X,
            C,
            V,
            B,
            N,
            M,
            Space,
            LeftAlt,
            RightAlt,
            LeftCtrl,
            RightCtrl,
            LeftShift,
            RightShift,
            Enter,
            Left,
            Right,
            Up,
            Down,
            Escape,
            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,
            F9,
            F10,
            F11,
            F12,
            Insert,
            Home,
            Delete,
            End,
            PageUp,
            PageDown,
            Tab,
            Grave,
            Apostrophe,
            Slash,
            Backslash,
            OpenBracket,
            CloseBracket,
            One,
            Two,
            Three,
            Four,
            Five,
            Six,
            Seven,
            Eight,
            Nine,
            Zero,
            NumAdd,
            NumSubtract,
            NumMultiply,
            NumDivide,
            NumZero,
            NumOne,
            NumTwo,
            NumThree,
            NumFour,
            NumFive,
            NumSix,
            NumSeven,
            NumEight,
            NumNine,
        };
    }

    /*!@ingroup Input
     * @brief An enum of the joysticks on a controller for use with input functions.
     */
    namespace Joysticks {
        /*!@ingroup Input*/
        enum Joystick {
            Left,
            Right
        };
    }

    /*!@ingroup Input*/
    namespace Buttons {
        /*!@ingroup Input
         * @brief An enum of buttons for use with with input functions
         */
        enum Button {
            A,
            B,
            X,
            Y,
            Left,
            Right,
            Down,
            Up,
            LeftShoulder,
            RightShoulder,
            Start,
            Select,
            LeftStick,
            RightStick
        };
    }
}