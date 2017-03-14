#ifndef CAMERA_H
#define CAMERA_H

#include "base3D.h"

class Camera : public Base3D
{
    public:
        Camera();
        ~Camera();
        
        void updateInteraction(float);
        
        int getCameraMode();
        
        void applyTransformation();
        
    private:
        float _cameraSpeed;
        float _turnSpeed;
        
        int _cameraMode;
        
        void _updateMouse(float);
        void _updateKeyboard(float);
};

#endif
