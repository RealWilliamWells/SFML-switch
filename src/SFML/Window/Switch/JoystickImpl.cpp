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


static HidControllerKeys KEYS_BY_INDEX[] = {
    KEY_A,
    KEY_B,
    KEY_X,
    KEY_Y,
    KEY_LSTICK,
    KEY_RSTICK,
    KEY_L,
    KEY_R,
    KEY_ZL,
    KEY_ZR,
    KEY_PLUS,
    KEY_MINUS,
    KEY_DLEFT,
    KEY_DUP,
    KEY_DRIGHT,
    KEY_DDOWN
};

#define NUM_KEYS_BY_INDEX ((int) (sizeof(KEYS_BY_INDEX) / sizeof(HidControllerKeys)))


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
void JoystickImpl::initialize()
{
    // N/A for now
}



////////////////////////////////////////////////////////////
void JoystickImpl::cleanup()
{
}


////////////////////////////////////////////////////////////
bool JoystickImpl::isConnected(unsigned int index)
{
    // To implement
    return index == 0 || hidIsControllerConnected((HidControllerID) index);
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
    auto sfmlState = JoystickState();
    HidControllerID conID = CONTROLLER_P1_AUTO;
    u64 keys = hidKeysDown(conID);
    
    for (int i = 0; i < NUM_KEYS_BY_INDEX; i++)
        sfmlState.buttons[i] = (keys & KEYS_BY_INDEX[i]) != 0;


    JoystickPosition posLeft, posRight;
    hidJoystickRead(&posLeft, conID, JOYSTICK_LEFT);
    hidJoystickRead(&posLeft, conID, JOYSTICK_LEFT);
    hidJoystickRead(&posRight, conID, JOYSTICK_RIGHT);
    sfmlState.axes[Joystick::X] = posLeft.dx;
    sfmlState.axes[Joystick::Y] = posLeft.dy;
    sfmlState.axes[Joystick::U] = posRight.dx;
    sfmlState.axes[Joystick::V] = posRight.dy;
    // To implement
    return sfmlState;
}

} // namespace priv

} // namespace sf
