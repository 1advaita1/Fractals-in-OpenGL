#pragma once
#include <glut.h>
#include "Trees.h"
void plot_point(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(1, 0.4, 0.2);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}
void plot_point_low(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(1, 0.4, 0.2);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glEnd();
}



void plot_lines(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}
void plot_lines_low(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glEnd();
}

void plot_poly(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3i(0, 0, 0);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}
void plot_poly_low(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glEnd();
}

