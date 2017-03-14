#include "mouse.h"

#include <GL/freeglut.h>

int Mouse::_currentX = 0;
int Mouse::_currentY = 0;
int Mouse::_lastX_left = 0;
int Mouse::_lastY_left = 0;
int Mouse::_lastX_middle = 0;
int Mouse::_lastY_middle = 0;
int Mouse::_lastX_right = 0;
int Mouse::_lastY_right = 0;
bool Mouse::_leftButton = false;
bool Mouse::_middleButton = false;
bool Mouse::_rightButton = false;

void Mouse::updatePosition(int x, int y)
{
    _currentX = x;
    _currentY = y;
    
    _mouseLogic();
}

void Mouse::updateButton(int button, int state, int x, int y)
{
    switch (button)
    {
        case GLUT_LEFT_BUTTON:
            _leftButton = (state==GLUT_DOWN);
            break;
        case GLUT_MIDDLE_BUTTON:
            _leftButton = (state==GLUT_DOWN);
            break;
        case GLUT_RIGHT_BUTTON:
            _rightButton = (state==GLUT_DOWN);
            break;
    }
    updatePosition(x, y);
}

int Mouse::getLeftDiffX()
{
    return (_currentX - _lastX_left);
}

int Mouse::getLeftDiffY()
{
    return -(_currentY - _lastY_left);
}

int Mouse::getMiddleDiffX()
{
    return (_currentX - _lastX_middle);
}

int Mouse::getMiddleDiffY()
{
    return -(_currentY - _lastY_middle);
}

int Mouse::getRightDiffX()
{
    return (_currentX - _lastX_right);
}

int Mouse::getRightDiffY()
{
    return -(_currentY - _lastY_right);
}

int Mouse::getX()
{
    return _currentX;
}

int Mouse::getY()
{
    return _currentY;
}

void Mouse::_mouseLogic()
{
    if (!_leftButton)
    {
        _lastX_left = _currentX;
        _lastY_left = _currentY;
    }
    
    if (!_middleButton)
    {
        _lastX_middle = _currentX;
        _lastY_middle = _currentY;
    }
    
    if (!_rightButton)
    {
        _lastX_right = _currentX;
        _lastY_right = _currentY;
    }
}
