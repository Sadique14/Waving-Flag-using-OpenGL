/**
**Waving Flag**
*Md. Farhan Sadique*
*Khulna University, Khulna.*
*md.farhansadique14@gmail.com*
**/
#include<Windows.h>
#include<gl/GL.h>
#include<gl/glut.h>
#include <iostream>
#include<stdio.h>
#include <chrono>
#include <thread>

GLdouble movingX1 = 450;
GLdouble movingY1 = 350;
GLdouble movingX2 = 450;
GLdouble movingY2 = 500;
double radius = 45;
int centerX;
int centerY;
int flag = 0;

void myInit(void)
{
	glClearColor(0.90, 0.90, 0.90, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 700.0, 0.0, 600.0);
}
void setPixel(double x, double y)
{
	GLint setX = round(x + centerX);
	GLint setY = round(y + centerY);
	glVertex2i(setX, setY);
	setX = round(y + centerX);
	setY = round(x + centerY);
	glVertex2i(setX, setY);
	setX = (y * (-1)) + centerX;
	setY = x + centerY;
	glVertex2i(setX, setY);
	setX = (x * (-1)) + centerX;
	setY = y + centerY;
	glVertex2i(setX, setY);
	setX = (x * (-1)) + centerX;
	setY = (y * (-1)) + centerY;
	glVertex2i(setX, setY);
	setX = (y * (-1)) + centerX;
	setY = (x * (-1)) + centerY;
	glVertex2i(setX, setY);
	setX = y + centerX;
	setY = (x * (-1)) + centerY;
	glVertex2i(setX, setY);
	setX = x + centerX;
	setY = (y * (-1)) + centerY;
	glVertex2i(setX, setY);
}
void myDisplay(void)
{
	while (true)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(0.60f, 0.60f, 0.60f);
		glRecti(197, 170, 200, 510);
		//rectangle
		glColor3f(0.00f, 0.60f, 0.00f);
		//glRecti(200, 350, 450, 500);
		glBegin(GL_LINES);
		glVertex2d(200, 350);
		glVertex2d(200, 500);
		glColor3f(0.00f, 1.00f, 0.00f);
		glVertex2d(200, 350);
		glVertex2d(movingX1, movingY1);
		glVertex2d(movingX1, movingY1);
		glVertex2d(movingX2, movingY2);
		glVertex2d(movingX2, movingY2);
		glVertex2d(200, 500);
		glEnd();
		//circle (Midpoint Circle Algorithm)
		glColor3f(1.00f, 0.00f, 0.00f);
		centerX = (int)((200 + movingX2) / 2);
		centerY = (int)((350 + movingY2) / 2);
		glBegin(GL_POINTS);
		double p = (5 / 4) - radius;
		double x = 0;
		double y = radius;
		while (x <= y)
		{
			setPixel(x, y);
			if (p < 0)
			{
				p = p + 2 * x + 3;
			}
			else
			{
				p = p + 2 * (x - y) + 5;
				y--;
			}
			x++;
		}
		glEnd();
		glFlush();

		std::this_thread::sleep_for(std::chrono::milliseconds(15));

		if (flag == 0)
		{
			movingX1--;
			movingY1 += 0.695;
			movingX2--;
			movingY2 += 0.695;
			radius -= 0.1;
			if (movingX1 == 380)
				flag = 1;
		}
		else if (flag == 1)
		{
			movingX1++;
			movingY1 -= 0.695;
			movingX2++;
			movingY2 -= 0.695;
			radius += 0.1;
			if (movingX1 == 450)
				flag = 0;
		}
	}
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("National Flag of Bangladesh");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}