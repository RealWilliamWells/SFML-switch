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
#include <SFML/Window/WindowStyle.hpp> // important to be included first (conflict with None)
#include <SFML/Window/Switch/WindowImplSwitch.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Err.hpp>
#include <switch.h>

////////////////////////////////////////////////////////////
// Private data
////////////////////////////////////////////////////////////
namespace sf
{
namespace priv
{
WindowImplSwitch* WindowImplSwitch::singleInstance = NULL;

////////////////////////////////////////////////////////////
WindowImplSwitch::WindowImplSwitch(WindowHandle handle)
{
    singleInstance = this;
}


////////////////////////////////////////////////////////////
WindowImplSwitch::WindowImplSwitch(VideoMode mode, const String& title, unsigned long style, const ContextSettings& settings)
{
    singleInstance = this;

    Result res = viInitialize(ViServiceType_Application);
    if (R_FAILED(res))
    {
        err() << "viInitialize failed" << std::endl;
    }

    NWindow* defaultPtr = nwindowGetDefault();
    m_window = *defaultPtr;
}


////////////////////////////////////////////////////////////
WindowImplSwitch::~WindowImplSwitch()
{
}


////////////////////////////////////////////////////////////
WindowHandle WindowImplSwitch::getSystemHandle() const
{
    return (WindowHandle) &m_window;
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::processEvents()
{
    appletMainLoop();
    hidInitialize();

    bool isTouchDown = switchTouchInput.isTouchDown(1);

    if (!isTouchAlreadyDown && isTouchDown) {
        Vector2i touchPos = switchTouchInput.getTouchPosition(1);

        Event event;
        event.type = Event::TouchBegan;
        event.touch.finger = 1;
        event.touch.x = touchPos.x;
        event.touch.y = touchPos.y;

        pushEvent(event);
        isTouchAlreadyDown = true;
    } else if (isTouchAlreadyDown && !isTouchDown) {
        Event event;
        event.type = Event::TouchEnded;
        event.touch.finger = 1;
        event.touch.x = 0;
        event.touch.y = 0;

        pushEvent(event);
        isTouchAlreadyDown = false;
    }
}


////////////////////////////////////////////////////////////
Vector2i WindowImplSwitch::getPosition() const
{
    // Not applicable
    return Vector2i(0, 0);
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setPosition(const Vector2i& position)
{
    // Not applicable
}


////////////////////////////////////////////////////////////
Vector2u WindowImplSwitch::getSize() const
{
    // TODO: Map to display size?
    return Vector2u(1280, 720);
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setSize(const Vector2u& size)
{
    // N/A
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setTitle(const String& title)
{
    // Not applicable
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setIcon(unsigned int width, unsigned int height, const Uint8* pixels)
{
    // Not applicable
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setVisible(bool visible)
{
    // Not applicable
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setMouseCursorVisible(bool visible)
{
    // Not applicable
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setMouseCursorGrabbed(bool grabbed)
{
    // Not applicable
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setMouseCursor(const CursorImpl& cursor)
{
    // Not applicable
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::setKeyRepeatEnabled(bool enabled)
{
    // Not applicable
}


////////////////////////////////////////////////////////////
void WindowImplSwitch::requestFocus()
{
    // Not applicable
}


////////////////////////////////////////////////////////////
bool WindowImplSwitch::hasFocus() const
{
    // TODO: use libnx somehow?
    return true;
}



} // namespace priv
} // namespace sf
