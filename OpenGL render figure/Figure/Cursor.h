#pragma once
#include "Point.h"
class Cursor : public Point
{
private:
  double size;
  Point *p[7];
public:
  Cursor();
  Cursor(double x, double y, double z, double size, std::string color);

  GLvoid Draw(GLvoid);
  void setRotate(char axis, double angle);
  void setMove(char axis, double distance);
  void resize(double size);
};

