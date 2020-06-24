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
#include <SFML/System/Lock.hpp>
#include <SFML/System/Err.hpp>
#include <SFML/Window/InputImpl.hpp>
#include "switch.h"


namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
bool InputImpl::isKeyPressed(Keyboard::Key key)
{
    // Not applicable
    return false;
}

////////////////////////////////////////////////////////////
void InputImpl::setVirtualKeyboardVisible(bool visible)
{
    // todo: use swkbd to implement
}

////////////////////////////////////////////////////////////
bool InputImpl::isMouseButtonPressed(Mouse::Button button)
{
    // TODO: use touch?

    return false;
}


////////////////////////////////////////////////////////////
Vector2i InputImpl::getMousePosition()
{
    // TODO: use touch?
    return {0, 0};
}


////////////////////////////////////////////////////////////
Vector2i InputImpl::getMousePosition(const WindowBase& relativeTo)
{
    // TODO: use touch?
    return {0, 0};
}


////////////////////////////////////////////////////////////
void InputImpl::setMousePosition(const Vector2i& position)
{
    // Injecting events is impossible on Android
}


////////////////////////////////////////////////////////////
void InputImpl::setMousePosition(const Vector2i& position, const WindowBase& relativeTo)
{
    // Not implemented
}


////////////////////////////////////////////////////////////
bool InputImpl::isTouchDown(unsigned int finger)
{
    return (finger < hidTouchCount());
}


////////////////////////////////////////////////////////////
Vector2i InputImpl::getTouchPosition(unsigned int finger)
{
    touchPosition touch;
    hidTouchRead(&touch, finger);
    return {(int) touch.px, (int) touch.py};
}


////////////////////////////////////////////////////////////
Vector2i InputImpl::getTouchPosition(unsigned int finger, const WindowBase& relativeTo)
{
    return getTouchPosition(finger);
}

} // namespace priv

} // namespace sf
