#ifndef MOUSE_H
#define MOUSE_H

class Mouse
{
    public:
        
        static void updatePosition(int x, int y);
        
        static void updateButton(int button, int state, int x, int y);
        
        static int getLeftDiffX();
        static int getLeftDiffY();
        static int getMiddleDiffX();
        static int getMiddleDiffY();
        static int getRightDiffX();
        static int getRightDiffY();
        static int getX();
        static int getY();
        
    private:
        
        static int _currentX, _currentY, _lastX_left, _lastY_left, _lastX_middle, _lastY_middle, _lastX_right, _lastY_right;
        static bool _leftButton, _middleButton, _rightButton;
        
        static void
        _mouseLogic();
};

#endif
