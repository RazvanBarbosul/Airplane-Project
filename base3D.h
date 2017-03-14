#ifndef BASE3D_H
#define BASE3D_H

class Base3D
{
    public:
        Base3D();
        ~Base3D();
        
        float getX();
        float getY();
        float getZ();
        
        void translate(float x, float y, float z);
        void translateGlobal(float x, float y, float z);
        
        void rotate(float deg, float x, float y, float z);
        void rotateWorld(float deg, float x, float y, float z);
        
        void globalToLocalPosition(float &, float &, float &);
        
        virtual void applyTransformation() = 0;
        
        float _base[16];
};

#endif
