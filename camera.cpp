#include "camera.h"

#include <GL/freeglut.h>

#include "mouse.h"
#include "keyboard.h"

enum { EYE_IN_HAND, WORLD_IN_HAND };

Camera::Camera():
    _cameraSpeed(2.0f),
    _turnSpeed(90.0f)
{
    _cameraMode = EYE_IN_HAND;
}

Camera::~Camera()
{
    
}

int Camera::getCameraMode()
{
    return _cameraMode;
}

void Camera::updateInteraction(float dt)
{
    _updateMouse(dt);
    _updateKeyboard(dt);
}

void Camera::_updateMouse(float dt)
{
    if (_cameraMode == 0)
    {
        translate(Mouse::getRightDiffX()*dt/10, 0, 0);
        translate(0, Mouse::getRightDiffY()*dt/10, 0);
        
        translate(0, 0, Mouse::getLeftDiffY()*dt/10);
        rotate(Mouse::getLeftDiffX()*dt, 0, 1, 0);
    }
    else
    {
        rotateWorld(Mouse::getLeftDiffX()*dt, 0, 1, 0);
        rotateWorld(-Mouse::getLeftDiffY()*dt, 1, 0, 0);
        
        translate(0, 0, -Mouse::getRightDiffY()*dt/10);
    }
}

void Camera::_updateKeyboard(float dt)
{
    static bool trigger = false;
    
    if (Keyboard::isPressed('-'))
    {
        if (!trigger)
        {
            if (_cameraMode == 0) _cameraMode = 1;
            else _cameraMode = 0;
        }
        trigger = true;
    }
    else
    {
        trigger = false;
    }
}

void Camera::applyTransformation()
{
	glMatrixMode(GL_MODELVIEW);
	
	float viewmatrix[16]={
        //Remove the three - for non-inverted z-axis
	  _base[0], _base[4], -_base[8], 0,
	  _base[1], _base[5], -_base[9], 0,
	  _base[2], _base[6], -_base[10], 0,

	  -(_base[0]*_base[12] +
	  _base[1]*_base[13] +
	  _base[2]*_base[14]),

	  -(_base[4]*_base[12] +
	  _base[5]*_base[13] +
	  _base[6]*_base[14]),

	  //add a - like above for non-inverted z-axis
	  (_base[8]*_base[12] +
	  _base[9]*_base[13] +
	  _base[10]*_base[14]), 1
    };
	
	glMultMatrixf(viewmatrix);
}
