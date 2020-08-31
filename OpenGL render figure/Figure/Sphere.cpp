#include "Sphere.h"

Sphere::Sphere()
{
  red = 1;
  green = 1;
  blue = 1;
}

Sphere::Sphere(double size, std::string color)
{
  this->setColor(color);
  this->size = size;
}

GLvoid Sphere::Draw(GLvoid)
{
  glRotatef(camX, 0, 1, 0);
  glRotatef(camY, 1, 0, 0);
  glColor3d(red, green, blue);
  GLUquadricObj* pObj = gluNewQuadric();
  gluQuadricDrawStyle(pObj, GLU_LINE);
  glTranslatef(x, y, z);
  gluSphere(pObj, size, 100, 100);
  glFlush();
  glutSwapBuffers();
}

void Sphere::setRotate(char axis, double angle)
{
  if (axis == 'x') {
    camX += angle;
  }
  if (axis == 'y') {
    camY += angle;
  }
}

void Sphere::setMove(char axis, double distance)
{
  if (axis == 'x') {
    x += distance;
  }
  if (axis == 'y') {
    y += distance;
  }
  if (axis == 'z') {    
    z += distance;
  }
}

void Sphere::resize(double size)
{
  this->size = size;
}
