#include "keyboard.h"

bool Keyboard::_keyboard[256];

void Keyboard::keyDown(unsigned char key, int x, int y)
{
    _keyboard[key]=true;
}

void Keyboard::keyUp(unsigned char key, int x, int y)
{
    _keyboard[key]=false;
}

bool Keyboard::isPressed(char c)
{
    return _keyboard[c];
}

bool Keyboard::wasPressed(char c)
{
    if (_keyboard[c])
    {
        _keyboard[c] = false;
        return true;
    }
    else
        return false;
}
