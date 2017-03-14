#include "base3D.h"

#include <GL/freeglut.h>

Base3D::Base3D()
{
    memset(_base, 0, 16*sizeof(float));
	_base[0] = 1.0f;
	_base[5] = 1.0f;
	_base[10] = -1.0f;
	_base[15] = 1.0f;
}

Base3D::~Base3D()
{
    delete [] _base;
}

float Base3D::getX()
{
    return _base[12];
}

float Base3D::getY()
{
    return _base[13];
}

float Base3D::getZ()
{
    return _base[14];
}

void Base3D::translate(float x, float y, float z)
{
	float dx=x*_base[0] + y*_base[4] + z*_base[8];
	float dy=x*_base[1] + y*_base[5] + z*_base[9];
	float dz=x*_base[2] + y*_base[6] + z*_base[10];
	_base[12] += dx;
	_base[13] += dy;
	_base[14] += dz;
}

void Base3D::translateGlobal(float x, float y, float z)
{
	_base[12] += x;
	_base[13] += y;
	_base[14] += z;
}

void Base3D::rotate(float deg, float x, float y, float z)
{
    glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    	glLoadMatrixf(_base);
    	glRotatef(deg, x,y,z);
    	glGetFloatv(GL_MODELVIEW_MATRIX, _base);
	glPopMatrix();
}

void Base3D::rotateWorld(float deg, float x, float y, float z)
{
	float memoX=0.0f, memoY=0.0f, memoZ=0.0f;
	globalToLocalPosition(memoX, memoY, memoZ);
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    	glLoadMatrixf(_base);
    	glTranslatef(memoX, memoY, memoZ);
    	glRotatef(deg, x,y,z);
    	glTranslatef(-memoX, -memoY, -memoZ);
    	glGetFloatv(GL_MODELVIEW_MATRIX, _base);
	glPopMatrix();
}

void Base3D::globalToLocalPosition(float &x, float &y, float &z)
{
    float newx = (x-_base[12])*_base[0] + (y-_base[13])*_base[1] + (z-_base[14])*_base[2];
    float newy = (x-_base[12])*_base[4] + (y-_base[13])*_base[5] + (z-_base[14])*_base[6];
    float newz = (x-_base[12])*_base[8] + (y-_base[13])*_base[9] + (z-_base[14])*_base[10];
    
    x = newx;
    y = newy;
    z = newz;
}
