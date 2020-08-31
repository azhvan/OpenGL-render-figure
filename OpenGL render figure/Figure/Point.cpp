#include "Point.h"

void Point::get(double& x, double& y, double& z)
{
	x = this->x;
	y = this->y;
	z = this->z;
}

Point::Point()
{
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;
}

Point::Point(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

GLvoid Point::Draw(GLvoid)
{
	glPointSize(4);
	glBegin(GL_POINTS);
		glColor3d(1.0, 1.0, 1.0);
		glVertex3d(this->x, this->y, this->z);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void Point::setColor(std::string color)
{
	if (color == "red") {
		red = 1;
		green = 0;
		blue = 0;
	}
	else if (color == "green") {
		red = 0;
		green = 1;
		blue = 0;
	}
	else if (color == "blue") {
		red = 0;
		green = 0;
		blue = 1;
	}
	else if (color == "white") {
		red = 1;
		green = 1;
		blue = 1;
	}
	else if (color == "black") {
		red = 0;
		green = 0;
		blue = 0;
	}
}

void Point::setRotate(char axis, double angle)
{
	if (axis == 'x') {
		x = x;
		y = y * cos(angle) - z * sin(angle);
		z = y * sin(angle) + z * cos(angle);
	}
	if (axis == 'y') {
		x = x * cos(angle) + z * sin(angle);
		y = y;
		z = z * cos(angle) - x * sin(angle);
	}
	if (axis == 'z') {
		x = x * cos(angle) - y * sin(angle);
		y = x * sin(angle) + y * cos(angle);
		z = z;
	}
}

void Point::setMove(char axis, double distance)
{
	if (axis == 'x')
		x = x + distance;
	else if (axis == 'y') 
		y = y + distance;
	else if (axis == 'z') 
		z = z + distance;	
}
