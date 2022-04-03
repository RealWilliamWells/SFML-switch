////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2013 Jonathan De Wachter (dewachter.jonathan@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <switch.h>
#include <SFML/Window/JoystickImpl.hpp>


static HidNpadButton KEYS_BY_INDEX[] = {
    HidNpadButton_A,
    HidNpadButton_B,
    HidNpadButton_X,
    HidNpadButton_Y,
    HidNpadButton_StickL,
    HidNpadButton_StickR,
    HidNpadButton_L,
    HidNpadButton_R,
    HidNpadButton_ZL,
    HidNpadButton_ZR,
    HidNpadButton_Plus,
    HidNpadButton_Minus,
    HidNpadButton_Left,
    HidNpadButton_Up,
    HidNpadButton_Right,
    HidNpadButton_Down
};

#define NUM_KEYS_BY_INDEX ((int) (sizeof(KEYS_BY_INDEX) / sizeof(HidNpadButton)))

#define JOY_RANGE_SCALE 0.003051758f;


namespace sf
{
    namespace priv
    {
        PadState padState;
        JoystickState sfmlJoystickState;

        ////////////////////////////////////////////////////////////
        JoystickImpl::JoystickImpl()
        {
            // do something
        }

        ////////////////////////////////////////////////////////////
        void JoystickImpl::initialize()
        {
            padState;
            sfmlJoystickState = JoystickState();

            // Configure our supported input layout: a single player with standard controller styles
            padConfigureInput(1, HidNpadStyleSet_NpadStandard);

            // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
            padInitializeDefault(&padState);
        }



        ////////////////////////////////////////////////////////////
        void JoystickImpl::cleanup()
        {
        }


        ////////////////////////////////////////////////////////////
        bool JoystickImpl::isConnected(unsigned int index)
        {
//            HidNpadIdType padID = HidNpadIdType_No1; // TODO: Actually check for controller at given index
            return index == 0;
        }


        ////////////////////////////////////////////////////////////
        bool JoystickImpl::open(unsigned int index)
        {
            return true;
        }


        ////////////////////////////////////////////////////////////
        void JoystickImpl::close()
        {

        }


        ////////////////////////////////////////////////////////////
        JoystickCaps JoystickImpl::getCapabilities() const
        {
            // To implement
            JoystickCaps caps = JoystickCaps();
            caps.buttonCount = NUM_KEYS_BY_INDEX;
            caps.axes[Joystick::X] = true;
            caps.axes[Joystick::Y] = true;
            return caps;
        }


        ////////////////////////////////////////////////////////////
        Joystick::Identification JoystickImpl::getIdentification() const
        {
            Joystick::Identification ident = Joystick::Identification();
            ident.name = sf::String("Generic Switch controller");
            ident.productId = ident.vendorId = 0;
            return ident;
        }


        ////////////////////////////////////////////////////////////
        JoystickState JoystickImpl::update()
        {
            padUpdate(&padState);
            u64 keys = padGetButtonsDown(&padState);

            for (int i = 0; i < NUM_KEYS_BY_INDEX; i++)
                sfmlJoystickState.buttons[i] = (keys & KEYS_BY_INDEX[i]) != 0;


            HidAnalogStickState posLeft, posRight;
            posLeft = padGetStickPos(&padState, HidNpadJoyDeviceType_Left);
            posRight = padGetStickPos(&padState, HidNpadJoyDeviceType_Right);
            sfmlJoystickState.axes[Joystick::X] = (float) posLeft.x * JOY_RANGE_SCALE;
            sfmlJoystickState.axes[Joystick::Y] = (float) posLeft.y * JOY_RANGE_SCALE;
            sfmlJoystickState.axes[Joystick::U] = (float) posRight.x * JOY_RANGE_SCALE;
            sfmlJoystickState.axes[Joystick::V] = (float) posRight.y * JOY_RANGE_SCALE;

            sfmlJoystickState.connected = true;

            // To implement
            return sfmlJoystickState;
        }

    } // namespace priv

} // namespace sf
