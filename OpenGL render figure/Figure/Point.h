#pragma once
#include <iostream>
#include <GL/glut.h>
class Point
{
protected:
  double x, y, z;
  double red, green, blue;
public:
  Point();
  Point(double x, double y, double z);
  virtual GLvoid Draw(GLvoid);
  void get(double& x, double& y, double& z);
  void setColor(std::string color);
  void setRotate(char axis, double angle);
  void setMove(char axis, double distance);
};

