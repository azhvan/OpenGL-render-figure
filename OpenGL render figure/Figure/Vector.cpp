#include "Vector.h"

Vector::Vector()
{
  start = new Point;
  end = new Point;
	red = 1;
	green = 1;
	blue = 1;
}

Vector::Vector(double s_x, double s_y, double s_z, double e_x, double e_y, double e_z, std::string color)
{
  start = new Point(s_x, s_y, s_z);
  end = new Point(e_x, e_y, e_z);

	this->setColor(color);
}

Vector::Vector(Vector& obj)
{
	obj.start = this->start;
	obj.end = this->end;
	obj.red = this->red;
	obj.green = this->green;
	obj.blue = this->blue;
}

GLvoid Vector::Draw(GLvoid)
{
	glLineWidth(1);
	glColor3d(red, green, blue);
	glBegin(GL_LINES);
	start->get(x, y, z);
		glVertex3d(x, y, z);
	end->get(x, y, z);
		glVertex3d(x, y, z);
	glEnd();
	start->Draw();
	end->Draw();
	glFlush();
	glutSwapBuffers();
}

void Vector::setVector(double s_x, double s_y, double s_z, double e_x, double e_y, double e_z, std::string color)
{
	start = new Point(s_x, s_y, s_z);
	end = new Point(e_x, e_y, e_z);

	this->setColor(color);
}

void Vector::setRotate(char axis, double angle)
{
	start->setRotate(axis, angle);
	end->setRotate(axis, angle);
}

void Vector::setMove(char axis, double distance)
{
	start->setMove(axis, distance);
	end->setMove(axis, distance);
}

void Vector::resize(double time)
{
	end->get(x, y, z);
	if (time > 0) {
		x = x * abs(time);
		y = y * abs(time);
		z = z * abs(time);
	}
	if (time < 0) {
		x = x / abs(time);
		y = y / abs(time);
		z = z / abs(time);
	}
	end = new Point(x, y, z);

}

