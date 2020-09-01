#include <iostream>
#include <string>
#include <fstream>
#include <locale.h>
#include <Windows.h>
#include "Figure/Vector.h"
#include "Figure/Cursor.h"
#include "Figure/Sphere.h"

double 
			cameraX = 0.0, cameraY = 0.0, 
			mouseX = 0.0,  mouseY = 0.0,
			rotateAngle = 1;
bool 
			isVector = true, isPositive = true;
int
			func = 0, figure = 0, figureCount = 3;
double 
			sizeCursor = 1, sizeSphere = 1;

Vector v(0, 0, 0, 1, 1, 1, "white");
Cursor c(0, 0, 0, sizeCursor, "white");
Sphere s(sizeSphere, "white");

GLvoid init(GLvoid);
GLvoid drawCoordinates();
GLvoid display();
void idleCallback();
void processNormalKeys(unsigned char key, int x, int y);

void setFigure();
void setColor(unsigned char key);
void setRotate(unsigned char key);
void setMove(unsigned char key);
void resize(unsigned char key);

void processSpecialKeys(int key, int x, int y);
void mouseMotionCallback(int x, int y);
void instruction();

int main(int argc, char** argv)
{	
	setlocale(0, "");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("OpenGL render simple 3d figure");
	init();
	glutDisplayFunc(display);
	glutIdleFunc(idleCallback);

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutMotionFunc(mouseMotionCallback);

	glViewport(0, 0, (GLsizei)500, (GLsizei)500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
	glMatrixMode(GL_MODELVIEW);

	glutMainLoop();
	return 0;
}

GLvoid init(GLvoid)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

GLvoid drawCoordinates()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);

	glVertex3f(-4.0, 0.0f, 0.0f); // red x
	glVertex3f(4.0, 0.0f, 0.0f);

	glVertex3f(4.0, 0.0f, 0.0f);
	glVertex3f(3.5, 0.1f, 0.0f);

	glVertex3f(4.0, 0.0f, 0.0f);
	glVertex3f(3.5, -0.1f, 0.0f);
	glEnd();

	glColor3f(0.0, 1.0, 0.0); // green y
	glBegin(GL_LINES);
	glVertex3f(0.0, -2.0f, 0.0f);
	glVertex3f(0.0, 2.0f, 0.0f);

	glVertex3f(0.0, 2.0f, 0.0f);
	glVertex3f(0.1, 1.5f, 0.0f);

	glVertex3f(0.0, 2.0f, 0.0f);
	glVertex3f(-0.1, 1.5f, 0.0f);
	glEnd();

	glColor3f(0.0, 0.0, 1.0); // blue z
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0f, -4.0f);
	glVertex3f(0.0, 0.0f, 4.0f);


	glVertex3f(0.0, 0.0f, 4.0f);
	glVertex3f(0.0, 0.1f, 3.5f);

	glVertex3f(0.0, 0.0f, 4.0f);
	glVertex3f(0.0, -0.1f, 3.5f);
	glEnd();

}

GLvoid display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();
	glTranslatef(0, 0, -10.0f);
	glRotatef(cameraX, 0, 1, 0);
	glRotatef(cameraY, 1, 0, 0);

	glScalef(1.0, 2.0, 1.0);
	figure = (figure + figureCount) % figureCount;
	switch (figure)
	{
	case 0:
		drawCoordinates();
		v.Draw();
		break;
	case 1:
		c.Draw();
		break;
	case 2:
		s.Draw();
		break;
	}
	glFlush();

	Sleep(70);
}

void idleCallback()
{
	glutPostRedisplay();
}

void processNormalKeys(unsigned char key, int x, int y) {
	switch (key) {
	case 9:
		figure++;
		break;
	case 32:
		setFigure();
		break;
	case 43:
		isPositive = true;
		break;
	case 45:
		isPositive = false;
		break;
	case 49:
		func = 1;
		break;
	case 50:
		func = 2;
		break;
	case 51:
		func = 3;
		break;
	case 98: case 103: case 114: case 119:
		setColor(key);
		break;		
	case 27:
		exit(0);
		break;
	}
	if (func == 1)
		setRotate(key);
	else if (func == 2)
		setMove(key);
	else if (func == 3) {
		resize(key);
	}
}

void setFigure() 
{
	int
		startX = 0, startY = 0, startZ = 0,
		endX = 0,		endY = 0,		endZ = 0;
	switch (figure)
	{
	case 0:
		system("cls");
		std::cout << "введите начальные данные:\nx - ";
		std::cin >> startX;
		std::cout << "y - ";
		std::cin >> startY;
		std::cout << "z - ";
		std::cin >> startZ;

		std::cout << "введите конечные данные:\nx - ";
		std::cin >> endX;
		std::cout << "y - ";
		std::cin >> endY;
		std::cout << "z - ";
		std::cin >> endZ;

		v.setVector(startX, startY, startZ, endX, endY, endZ);
		system("cls");
		break;
	}
}

#pragma region Color
void setBlue()
{
	switch (figure)
	{
	case 0:
		v.setColor("blue");
		break;
	case 1:
		c.setColor("blue");
		break;
	case 2:
		s.setColor("blue");
		break;
	}
}

void setGreen()
{
	switch (figure)
	{
	case 0:
		v.setColor("green");
		break;
	case 1:
		c.setColor("green");
		break;
	case 2:
		s.setColor("green");
		break;
	}
}

void setRed()
{
	switch (figure)
	{
	case 0:
		v.setColor("red");
		break;
	case 1:
		c.setColor("red");
		break;
	case 2:
		s.setColor("red");
		break;
	}
}

void setWhite()
{
	switch (figure)
	{
	case 0:
		v.setColor("white");
		break;
	case 1:
		c.setColor("white");
		break;
	case 2:
		s.setColor("white");
		break;
	}
}

void setColor(unsigned char key)
{
	switch (key)
	{
	case 98:
		setBlue();
		break;
	case 103:
		setGreen();
		break;
	case 114:
		setRed();
		break;
	case 119:
		setWhite();
		break;
	}
}
#pragma endregion

#pragma region Rotate
void rotateX() 
{
	double angle = 0.1;
	if (!isPositive)
		angle *= -1;
		switch (figure)
		{
		case 0:
			v.setRotate('x', angle);
			break;
		case 1:
			c.setRotate('x', angle);
			break;
		case 2:
			s.setRotate('x', angle);
			break;
		}
}

void rotateY()
{
	double angle = 0.1;
	if (!isPositive)
		angle *= -1;
	switch (figure)
	{
	case 0:
		v.setRotate('y', angle);
		break;
	case 1:
		c.setRotate('y', angle);
		break;
	case 2:
		s.setRotate('y', angle);
		break;
	}
}

void rotateZ()
{
	double angle = 0.1;
	if (!isPositive)
		angle *= -1;
	switch (figure)
	{
	case 0:
		v.setRotate('z', angle);
		break;
	case 1:
		c.setRotate('z', angle);
		break;
	case 2:
		s.setRotate('z', angle);
		break;
	}
}

void setRotate(unsigned char key)
{
	switch (key)
	{
	case 120:
		rotateX();
		break;
	case 121:
		rotateY();
		break;
	case 122:
		rotateZ();
		break;
	}	
}
#pragma endregion

#pragma region Move
void moveX() 
{
	double distance = 0.1;
	if (!isPositive)
		distance *= -1;
	switch (figure)
	{
	case 0:
		v.setMove('x', distance);
		break;
	case 1:
		c.setMove('x', distance);
		break;
	case 2:
		s.setMove('x', distance);
		break;
	}
}

void moveY()
{
	double distance = 0.1;
	if (!isPositive)
		distance *= -1;
	switch (figure)
	{
	case 0:
		v.setMove('y', distance);
		break;
	case 1:
		c.setMove('y', distance);
		break;
	case 2:
		s.setMove('y', distance);
		break;
	}
}

void moveZ()
{
	double distance = 0.1;
	if (!isPositive)
		distance *= -1;
	switch (figure)
	{
	case 0:
		v.setMove('z', distance);
		break;
	case 1:
		c.setMove('z', distance);
		break;
	case 2:
		s.setMove('z', distance);
		break;
	}
}

void setMove(unsigned char key)
{
	switch (key)
	{
	case 120:
		moveX();
		break;
	case 121:
		moveY();
		break;
	case 122:
		moveZ();
		break;
	}
}
#pragma endregion

#pragma region Resize
void resize(unsigned char key)
{
	double changeTo = 0.1, time = 1.1;
	if (key == 45) {
		changeTo *= -1;
		time *= -1;
	}
	switch (figure)
	{
	case 0:
		v.resize(time);
		break;
	case 1:
		c.resize(sizeCursor += changeTo);
		break;
	case 2:
		s.resize(sizeSphere += changeTo);
		break;
	}
}
#pragma endregion

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		cameraX += rotateAngle;
		break;
	case GLUT_KEY_LEFT:
		cameraX -= rotateAngle;
		break;
	case GLUT_KEY_UP:
		cameraY += rotateAngle;
		break;
	case GLUT_KEY_DOWN:
		cameraY -= rotateAngle;
		break;
	case GLUT_KEY_F1:
		instruction();
		break;
	}
}

void mouseMotionCallback(int x, int y)
{
	cameraX += (x - mouseX);
	cameraY += (y - mouseY);
	mouseX = x;
	mouseY = y;
}

void instruction()
{
	system("cls");
	std::ifstream in("Read_me.txt");
	std::string text;
	if (in.is_open())
	{
		while (std::getline(in, text)) {
			std::cout << text << std::endl;
		}
	}
	in.close();
}
