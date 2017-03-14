#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <SFML/Audio.hpp>



using namespace std;

#include "camera.h"
#include "keyboard.h"
#include "mouse.h"

const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
float a=0.0f,b=0.0f,k=0.01f,o=0.0f;

Camera *cam;

void glAirplane()
{
//glTranslatef(-5,0,0);
   glBegin(GL_TRIANGLE_FAN);

            glColor3f(1.0f,0.0f,0.0f);


            glVertex3f(1.0f,0.0f,0.0f); //varful
            glColor3f(0.0f,1.0f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f); //baza avionului
            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(0.0f,0.1f,0.2f); //aripa
            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(0.0f,0.4f,0.2f); //partea din stanga aripa

            glEnd();

            glBegin(GL_TRIANGLE_FAN);
            glColor3f(1.0f,0.0f,0.0f);

            glVertex3f(1.0f,0.0f,0.0f);
            glColor3f(0.0f,1.0f,0.0f);
            glVertex3f(0.0f,0.0f,0.0f);
            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(0.0f,-0.1f,0.2f);
            glColor3f(0.0f,0.0f,1.0f);
            glVertex3f(0.0f,-0.4f,0.2f);


            glEnd();
}

void glMap()
{

     glBegin(GL_LINE_LOOP);  //triunghi sus
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(14.0f, -7.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(14.0f, 7.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(1.3f, 0.0f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP); //triunghi jos
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-14.0f, 7.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-14.0f, -7.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(1.3f, 0.0f, 0.0f);
        glEnd();

     /*  // glBegin(GL_LINE_STRIP); //dreapta centru
        //    glColor3f(-1.0f,0.0f,1.0f);
          //  glVertex3f(-0.5f,7.0f,0.0f);
            //glVertex3f(1.3f,0.0f,0.0f);
            //glVertex3f(-0.5f,-7.0f,0.0f);
        //glEnd();*/




        glBegin(GL_LINE_LOOP); //triunghi dreapta
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(14.0f, -12.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(14.0f, 12.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(1.3f, 0.0f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
            glColor3f(0.0f, 1.0f, 0.0f); //triunghi stanga
            glVertex3f(-14.0f, 7.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-7.0f, -7.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(1.3f, 0.0f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
            glColor3f(1.0f, 1.0f, 0.0f);
            glVertex3f(14.0f, -30.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(14.0f, 30.0f, 0.0f);

            glColor3f(0.0f, 1.0f, .0f);
            glVertex3f(1.3f, 0.0f, 0.0f);
        glEnd();

        glBegin(GL_LINE_LOOP);
            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-14.0f, 30.0f, 0.0f);

            glColor3f(0.0f, 1.0f, 0.0f);
            glVertex3f(-14.0f, -30.0f, 0.0f);

            glColor3f(0.0f, 1.0f, .0f);
            glVertex3f(1.3f, 0.0f, 0.0f);
        glEnd();

       /*  glBegin(GL_LINE_STRIP);
            //linia 1:
           glVertex3f(-0.3f, 0.7f, 0.0f);
           glVertex3f(7.0f, 4.0f, 0.0f);
           glVertex3f(0.3f,-.07f,0.0f);
           glVertex3f(-1.3f,-0.7f,-1.0f);*/
            //glEnd();
        /* while (z<=14)
         {
        glBegin(GL_LINES);
            //linia 1:
           glVertex3f(x, y, z);
           glVertex3f(x+1, y, z+1);
            glEnd();
            z++;
            x++;
            y++;
         }*/


        /*glBegin(GL_LINE_STRIP);
            glColor3f(0.0f,1.0f,0.0f);
            glVertex3f(2.69f,1.33f,0.0f);
            glColor3f(1.0f,0.0f,0.0f);
            glVertex3f(-0.8f,0.99f,0.0f);
            glColor3f(0.5f,0.5f,0.5f);
            glVertex3f(-0.8f,-0.99f,0.0f);
            glVertex3f(2.69f,-1.33f,0.0f);*/




}

void glWalls()
{



glScalef(4.9f,4.9f,0.0f);
glTranslatef(-0.14f,0.0f,0.0f);

      glBegin(GL_LINES); //linie stanga
                glColor3f(0.0f,1.0f,0.0f);
                glVertex3f(0.69f,0.24f,0.0f);
                glVertex3f(0.07f,0.24f,0.0f);
          glEnd();


          glBegin(GL_LINES); // linie dreapta
                glColor3f(0.0f,1.0f,0.0f);

                glVertex3f(0.69f,-0.24f,1.0f);
                glVertex3f(0.07f,-0.24f,1.0f);
                glEnd();


          glBegin(GL_LINES); //linie jos
                glColor3f(0.0f,1.0f,0.0f);
                glVertex3f(0.07f,0.24f,1.0f);
                glVertex3f(0.07f,-0.24f,1.0f);
                glEnd();
//first line

        glBegin(GL_LINES);
              glColor3f(0.0f,1.0f,0.0f);
              glVertex3f(0.97f,0.5f,0.0f);
              glVertex3f(-0.3f,0.5f,0.0f);
              glEnd();

           glBegin(GL_LINES);
               glColor3f(0.0f,1.0f,0.0f);
               glVertex3f(0.97f,-0.5f,0.0f);
               glVertex3f(-0.3f,-0.5f,0.0f);
               glEnd();

           glBegin(GL_LINES);
               glColor3f(0.0f,1.0f,0.0f);
               glVertex3f(-0.3f,-0.5f,0.0f);
               glVertex3f(-0.3f,0.5f,0.0f);
               glEnd();
//2nd line

         glBegin(GL_LINES); //linie stanga
                glColor3f(0.0f,1.0f,0.0f);
                glVertex3f(1.44f,0.9f,0.0f);
                glVertex3f(-0.86f,0.9f,0.0f);
          glEnd();


          glBegin(GL_LINES); // linie dreapta
                glColor3f(0.0f,1.0f,0.0f);

                glVertex3f(1.44f,-0.9f,0.0f);
                glVertex3f(-0.86f,-0.9f,0.0f);
                glEnd();


          glBegin(GL_LINES); //linie jos
               glColor3f(0.0f,1.0f,0.0f);
                glVertex3f(-0.86f,0.9f,0.0f);
                glVertex3f(-0.86f,-0.9f,0.0f);
                glEnd();
                //3rd line

            glBegin(GL_LINES); //linie stanga
                glColor3f(0.0f,1.0f,0.0f);
                glVertex3f(0.52f,0.1f,0.0f);
                glVertex3f(0.259f,0.1f,0.0f);
          glEnd();

          glBegin(GL_LINES); //linie dreapta
                glColor3f(0.0f,1.0f,0.0f);
                glVertex3f(0.52f,-0.1f,0.0f);
                glVertex3f(0.259f,-0.1f,0.0f);
          glEnd();

          glBegin(GL_LINES);//linie jos
                glColor3f(0.0f,1.0f,0.0f);
                glVertex3f(0.259f,-0.1f,0.0f);
                glVertex3f(0.259f,0.1f,0.0f);
         glEnd();





}

void glStar()
{
     glScalef(1.5f,1.5f,0.0f);
    glTranslatef(2.14f,0.0f,0.0f);
    glTranslatef(-0.3f,0.0f,0.0f);
    glTranslatef(-2.2f,-0.0f,0.0f);
    glTranslatef(0.0f,0.5f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);
  //  glRotatef(-60,0,0,1);

    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.3f,-0.2f,0.0f);
    glVertex3f(0.6f,0.0f,.0f);
    glEnd();

/*
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f,0.0f,0.0f);
    glVertex3f(0.3f,0.2f,0.0f);
    glVertex3f(0.1f,-0.4f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.1f,0.0f,0.0f);
    glVertex3f(0.5f,-0.4f,0.0f);
    glVertex3f(0.4f,0.0f,0.0f);
    glEnd();*/

    glBegin(GL_POLYGON);
    glVertex3f(0.3f,0.25f,0.0f);
    glVertex3f(0.1f,-0.4f,0.0f);
    glVertex3f(0.3f,-0.2f,0.0f);
    glVertex3f(0.5f,-0.4f,0.0f);
    glVertex3f(0.3f,0.2f,0.0f);
    glEnd();
}

void glStar2()
{
     glScalef(1.5f,1.5f,0.0f);
    glTranslatef(2.14f,0.0f,0.0f);
    glTranslatef(-0.3f,0.0f,0.0f);
    glTranslatef(-2.2f,-0.0f,0.0f);
   // glTranslatef(0.0f,0.5f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);
  //  glRotatef(-60,0,0,1);

    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.3f,-0.2f,0.0f);
    glVertex3f(0.6f,0.0f,.0f);
    glEnd();

/*
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f,0.0f,0.0f);
    glVertex3f(0.3f,0.2f,0.0f);
    glVertex3f(0.1f,-0.4f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.1f,0.0f,0.0f);
    glVertex3f(0.5f,-0.4f,0.0f);
    glVertex3f(0.4f,0.0f,0.0f);
    glEnd();*/

    glBegin(GL_POLYGON);
    glVertex3f(0.3f,0.25f,0.0f);
    glVertex3f(0.1f,-0.4f,0.0f);
    glVertex3f(0.3f,-0.2f,0.0f);
    glVertex3f(0.5f,-0.4f,0.0f);
    glVertex3f(0.3f,0.2f,0.0f);
    glEnd();
}

void glStar3()
{
     glScalef(1.5f,1.5f,0.0f);
    glTranslatef(2.14f,0.0f,0.0f);
    glTranslatef(-0.3f,0.0f,0.0f);
    glTranslatef(-2.2f,-0.0f,0.0f);
    glTranslatef(0.0f,0.5f,0.0f);
    glColor3f(0.0f,1.0f,0.0f);
  //  glRotatef(-60,0,0,1);

    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f,0.0f,0.0f);
    glVertex3f(0.3f,-0.2f,0.0f);
    glVertex3f(0.6f,0.0f,.0f);
    glEnd();

/*
    glBegin(GL_TRIANGLES);
    glVertex3f(0.5f,0.0f,0.0f);
    glVertex3f(0.3f,0.2f,0.0f);
    glVertex3f(0.1f,-0.4f,0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(0.1f,0.0f,0.0f);
    glVertex3f(0.5f,-0.4f,0.0f);
    glVertex3f(0.4f,0.0f,0.0f);
    glEnd();*/

    glBegin(GL_POLYGON);
    glVertex3f(0.3f,0.25f,0.0f);
    glVertex3f(0.1f,-0.4f,0.0f);
    glVertex3f(0.3f,-0.2f,0.0f);
    glVertex3f(0.5f,-0.4f,0.0f);
    glVertex3f(0.3f,0.2f,0.0f);
    glEnd();
}



void initGL(int width, int height)
{
	cam = new Camera();


    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_PROJECTION);

    glEnable(GL_LIGHT0);

  ;

    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height,2.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);



}

static void
resize(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height,2.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
}

void renderBitmapString(float x, float y, void *font, char *string)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
            glLoadIdentity();
            glDisable(GL_LIGHTING);

            glColor3f(0.0f, 1.0f, 0.0f);
            glRasterPos2f(x,y);
            char *c;

            for (c=string; *c != '\0'; c++)
            {
                glutBitmapCharacter(font, *c);
            }

            glEnable(GL_LIGHTING);
        glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

static void
display(void)
{
   a+=k;

   b+=k/4;
    if(a>=7.5f)a=0;
    if(b>=19.40)b=0;


    static int frame,timebase=0;
    int time;
    char s[100];
    frame++;
	time=glutGet(GLUT_ELAPSED_TIME);



	static int lasttime=0;
    int rightnow = glutGet(GLUT_ELAPSED_TIME);
    float dt = ((float)(rightnow-lasttime))/1000.0f;

    //if(dt<0.033f)return;

    lasttime = rightnow;
    static float dtSum;

    dtSum += dt;


    if (dtSum >= 1.0f / 60.0f)
    {
        dtSum = 0.0f;
        static int frame,timebase=0;
        int time;
        char s[100];
        frame++;
        time=glutGet(GLUT_ELAPSED_TIME);
        if (time - timebase > 1000)
        {
            sprintf(s,"[FPS:%4.2f]",frame*1000.0/(time-timebase));
            glutSetWindowTitle(s);
            timebase = time;
            frame = 0;
        }
    }
    //toggle wireframe mode

    if (Keyboard::wasPressed('w'))
    {
        k+=0.1f;

    }

    if (Keyboard::wasPressed('s'))
    {
        k-=0.1f;

    }

    if (Keyboard::wasPressed('a'))
    {
        o+=0.2f;

    }
    if (Keyboard::wasPressed('d'))
    {
        o-=0.2f;

    }

  if(k>=0.513f)k=0.513f;

  if(k<=0.1f)k=0.1f;

  if(o>=2.3f)o=2.3f;
  if(o<=-2.3f)o=-2.3f;




    //---- Begin to draw frame ----//

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();


    cam->applyTransformation();
    cam->updateInteraction(dt);

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // draw shapes

    glPushMatrix();

        glTranslatef(0,-3,-10);

        glRotatef(90,0,0,1);
        glRotatef(50,0,1,0);
        glTranslatef(0.0f,o,0.0f);
        glAirplane();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(0,0,-10);

        glRotatef(90,0,0,1);
        glRotatef(50,0,1,0);
        glMap();
        glPopMatrix();


    glPushMatrix();

       glTranslatef(0.0f,0.0f-b/4+0.2,-20.0+b);
        glScalef(1.3f,1.2f,0.0f);
        glRotatef(b*10,0,0,1);
        glStar2();

     glPopMatrix();

      glPushMatrix();

       glTranslatef(-0.3f,0.0f,0.0f);
       glTranslatef(0.3f-b/5,0.0f-b/2,-20.0+b);
        glScalef(1.3f,1.2f,0.0f);
        glRotatef(b*10,0,0,1);
        glStar();

     glPopMatrix();

     glPushMatrix();

       glTranslatef(0.3f,0.0f,0.0f);
       glTranslatef(0.3f+b/3,0.2f-b/2,-20.0+b);
        glScalef(1.3f,1.2f,0.0f);
        glRotatef(b*10,0,0,1);
        glStar3();

     glPopMatrix();


        glTranslatef(0.0f,0.0f-a/9,-20.0+a);
       //glTranslatef(0.0f,0.0f,-20.0f);
        //glScalef(1.3f,1.2f,0.0f);
        glScalef(1.3f+a/40,1.2f+a/45,0.0f);
        glRotatef(90,0,0,1);
        glWalls();
        //glWalls2();

glPopMatrix();
//glPushMatrix();
//glTranslatef(1.0f,0.0f,0.0f);
//glScalef(1.0f,0.0f,0.0f);
//glutSolidDodecahedron();
//glPopMatrix();

/*glPushMatrix();
   //  glTranslatef(0.0f,0.0f-a/9,-20.0+a);
       glTranslatef(0.0f,0.0f,-20.0f);
        glScalef(1.3f,1.2f,0.0f);
      //  glScalef(1.3f+a/40,1.2f+a/45,0.0f);
        glRotatef(90,0,0,1);
//        glWalls2();
        glPopMatrix();*/







//glFlush();

    // end draw shapes


    char text[100];

    for (int i=0; i<16; ++i)
    {
        //sprintf(text,"%4.2f",cam->_base[i]);
      //  renderBitmapString(-0.99f+(i/4)*0.17, 0.90f-(i%4)*0.07, GLUT_BITMAP_9_BY_15, text);
    }


    //---- Finish drawing frame ----//

    glutSwapBuffers();
}

static void idle(){
glutPostRedisplay();
}

int
main(int argc, char *argv[])
{
    int width = 640;
    int height = 480;
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);


	glutKeyboardFunc(Keyboard::keyDown);
    glutKeyboardUpFunc(Keyboard::keyUp);


    //while (music.getStatus() == sf::Music::Playing)
    //    std::cout<<"playing"<<std::endl;



   // glutMotionFunc(Mouse::updatePosition);
    //glutPassiveMotionFunc(Mouse::updatePosition);
    //glutMouseFunc(Mouse::updateButton);

    glutIdleFunc(idle);



    initGL(width, height);

    // play music
    sf::Music music;
    if (!music.openFromFile("music.ogg"))
    {
        std::cout<<"file not found"<<std::endl;
    }
    else
    {
        std::cout<<"playing"<<std::endl;
        music.play();
    }



   // glutFullScreen();

    //glutSetCursor(GLUT_CURSOR_INFO);


    glutMainLoop();

    return EXIT_SUCCESS;
}
