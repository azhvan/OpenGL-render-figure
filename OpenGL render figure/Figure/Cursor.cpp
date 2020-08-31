#include "Cursor.h"

Cursor::Cursor()
{
  this->x = 0;
  this->y = 0;
  this->z = 0;
  this->size = 1;
  p[0] = new Point(x, y, z);
  p[1] = new Point(x - (size / 4), y - size, z);
  p[2] = new Point(x, y - size, z);
  p[3] = new Point(x, y - size - (size / 5), z);
  p[4] = new Point(x + (size / 10), y - size - (size / 5), z);
  p[5] = new Point(x + (size / 10), y - size, z);
  p[6] = new Point(x + (size / 4) + (size / 10), y - size, z);
  red = 1;
  green = 1;
  blue = 1;
}

Cursor::Cursor(double x, double y, double z, double size, std::string color)
{
  this->size = size;
  p[0] = new Point(x, y, z);
  p[1] = new Point(x - (size / 4), y - size, z);
  p[2] = new Point(x, y - size, z);
  p[3] = new Point(x, y - size - (size / 5), z);
  p[4] = new Point(x + (size / 10), y - size - (size / 5), z);
  p[5] = new Point(x + (size / 10), y - size, z);
  p[6] = new Point(x + (size / 4) + (size / 10), y - size, z);
  setColor(color);
}

GLvoid Cursor::Draw(GLvoid)
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glColor3d(red, green, blue);
  glBegin(GL_POLYGON);
  p[0]->get(x, y, z);
    glVertex3d(x, y, z);
  p[1]->get(x, y, z);
    glVertex3d(x, y, z);
  p[2]->get(x, y, z);
    glVertex3d(x, y, z);
  p[3]->get(x, y, z);
    glVertex3d(x, y, z);
  p[4]->get(x, y, z);
    glVertex3d(x, y, z);
  p[5]->get(x, y, z);
    glVertex3d(x, y, z);
  p[6]->get(x, y, z);
    glVertex3d(x, y, z);
  glEnd();

  glFlush();
  glutSwapBuffers();
}

void Cursor::setRotate(char axis, double angle)
{
  for (size_t i = 0; i < 7; i++)
    p[i]->setRotate(axis, angle);
}

void Cursor::setMove(char axis, double distance)
{
  for (size_t i = 0; i < 7; i++)
    p[i]->setMove(axis, distance);
}

void Cursor::resize(double size)
{
  this->size = size;
  p[0]->get(x, y, z);

  p[0] = new Point(x, y, z);
  p[1] = new Point(x - (size / 4), y - size, z);
  p[2] = new Point(x, y - size, z);
  p[3] = new Point(x, y - size - (size / 5), z);
  p[4] = new Point(x + (size / 10), y - size - (size / 5), z);
  p[5] = new Point(x + (size / 10), y - size, z);
  p[6] = new Point(x + (size / 4) + (size / 10), y - size, z);
}
