#pragma once
#include "Point.h"
class Vector : public Point
{
private:
  Point *start, *end;
public:
  Vector();
  Vector(double s_x, double s_y, double s_z, double e_x, double e_y, double e_z, std::string color);
  Vector(Vector &obj);

  GLvoid Draw(GLvoid);
  void setVector(double s_x, double s_y, double s_z, double e_x, double e_y, double e_z, std::string color);
  void setRotate(char axis, double angle);
  void setMove(char axis, double distance);
  void resize(double time);
};

