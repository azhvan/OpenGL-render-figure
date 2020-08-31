#pragma once
#include "Point.h"
class Sphere : public Point
{
private:
  double size = 1;
  double camX, camY;
public:
  Sphere();
  Sphere(double size, std::string color);
  Sphere(Sphere& obj);

  GLvoid Draw(GLvoid);
  void setRotate(char axis, double angle);
  void setMove(char axis, double distance);
  void resize(double size);
};

