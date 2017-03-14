#ifndef KEYBOARD_H
#define KEYBOARD_H

class Keyboard
{
    public:
        static void
        keyDown(unsigned char key, int x, int y);

        static void
        keyUp(unsigned char key, int x, int y);

        static bool
        isPressed(char c);
        static bool
        wasPressed(char c);

    private:
        static bool _keyboard[256];
};

#endif
