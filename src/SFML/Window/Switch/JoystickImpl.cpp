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
#include <stdio.h>
#include <SFML/Window/JoystickImpl.hpp>


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
void JoystickImpl::initialize()
{
    handle = 0;
    device = {0};
    state={0};

    // Set the controller type to Pro-Controller, and set the npadInterfaceType.
    device.deviceType = HidDeviceType_FullKey3;
    device.npadInterfaceType = NpadInterfaceType_Bluetooth;
    // Set the controller colors. The grip colors are for Pro-Controller on [9.0.0+].
    device.singleColorBody = RGBA8_MAXALPHA(255,255,255);
    device.singleColorButtons = RGBA8_MAXALPHA(0,0,0);
    device.colorLeftGrip = RGBA8_MAXALPHA(230,255,0);
    device.colorRightGrip = RGBA8_MAXALPHA(0,40,20);

    // Setup example controller state.
    state.batteryCharge = 4; // Set battery charge to full.
    state.joysticks[JOYSTICK_LEFT].dx = 0x1234;
    state.joysticks[JOYSTICK_LEFT].dy = -0x1234;
    state.joysticks[JOYSTICK_RIGHT].dx = 0x5678;
    state.joysticks[JOYSTICK_RIGHT].dy = -0x5678;


    int rc = hiddbgAttachHdlsWorkBuffer();
    printf("hiddbgAttachHdlsWorkBuffer(): 0x%x\n", rc);

    if (R_SUCCEEDED(rc)) {
        // Attach a new virtual controller.
        rc = hiddbgAttachHdlsVirtualDevice(&handle, &device);
        printf("hiddbgAttachHdlsVirtualDevice(): 0x%x\n", rc);
    }
}



////////////////////////////////////////////////////////////
void JoystickImpl::cleanup()
{
}


////////////////////////////////////////////////////////////
bool JoystickImpl::isConnected(unsigned int index)
{
    // To implement
    return hidIsControllerConnected((HidControllerID) index);
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
    caps.buttonCount = 4;
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
    // To implement
    return JoystickState();
}

} // namespace priv

} // namespace sf
