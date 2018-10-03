#pragma once
#include <glut.h>
#include "Trees.h"
#pragma once
#include <glut.h>
#include "Trees.h"

//Plots points in the upper semicircle in the Infinite circles fractal
void plot_point(int x, int y)
{
	glBegin(GL_POINTS);
	glColor3f(1, 0.4, 0.2); //Sets color
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}

//Plots points in the lower semicircle in the Infinite circles fractal
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


//Plots the pattern in the upper semicircle in the dream catcher
void plot_lines(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}

//Plots the pattern in the lower semicircle in the dream catcher
void plot_lines_low(int x, int y)
{
	glBegin(GL_LINES);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glEnd();
}


//Plots the (black) pattern in the upper semicircle in the yin-yang
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

//Plots the white pattern in the upper semicircle in the yin-yang
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


//Draws a normal circle according to the Bresenham's algorithm (without the improvisation)
void bresenham_circle_yyp(int r)
{
	int x = 0, y = r;
	float d = (5.0 / 4.0) - r;

	plot_point(x, y);
	plot_point_low(x, y);
	int k;
	while (x < y)
	{
		x = x + 1;
		if (d < 0)
			d = d + 2 * x + 1;
		else
		{
			y = y - 1;
			d = d + 2 * (x - y) + 1;
		}

		plot_point(x, y);
		plot_point_low(x, y);
	}
	glFlush();
}
//Draws the patterned circle in the dream catcher
void bresenham_circle_dc(int r)
{
	int x = 0, y = r;
	float d = (5.0 / 4.0) - r;

	plot_lines(x, y);
	plot_lines_low(x, y);
	int k;
	while (x < y)
	{
		x = x + 1;
		if (d < 0)
			d = d + 2 * x + 1;
		else
		{
			y = y - 1;
			d = d + 2 * (x - y) + 1;
		}

		plot_lines(x, y);
		plot_lines_low(x, y);
	}
	glFlush();
}

//Draws the patterned circle in the yin yang
void bresenham_circle_yy(int r)
{
	int x = 0, y = r;
	float d = (5.0 / 4.0) - r;

	plot_poly(x, y);
	plot_poly_low(x, y);
	int k;
	while (x < y)
	{
		x = x + 1;
		if (d < 0)
			d = d + 2 * x + 1;
		else
		{
			y = y - 1;
			d = d + 2 * (x - y) + 1;
		}

		plot_poly(x, y);
		plot_poly_low(x, y);
	}
	glFlush();
}


//Creates the yin-yang
void yin_yang(int o, int r)
{

	xc = o - r;
	if (r == 0) return; //loop exit condition
	else //recursively plots itself
	{
		bresenham_circle_yy(r);
		xc = o + r;
		bresenham_circle_yy(r);
		yin_yang(o - r, r / 2);
		yin_yang(o + r, r / 2);
	}
}

//creates the circles fractal
void yin_yang_plain(int o, int r)
{

	xc = o - r;
	if (r == 0) return; //loop exit condition
	else //recursively plots itself
	{
		bresenham_circle_yyp(r);
		xc = o + r;
		bresenham_circle_yyp(r);
		yin_yang_plain(o - r, r / 2);
		yin_yang_plain(o + r, r / 2);
	}
}

//creates the dream catcher
void dream_catcher(int o, int r)
{

	xc = o - r;
	glBegin(GL_LINES); //plots stems for trees
	glVertex2i(o, yc + r / 1.15);
	glVertex2i(o, yc - r / 1.15);
	glEnd();
	plot_line(o, yc + r / 1.15, r / 3.05, 0, 0.575); //creates tree 1
	plot_line_bel(o, yc - r / 1.15, r / 3.2, 0, 0.55); //creates tree 2

	glBegin(GL_LINES); //creates tree 3
	glVertex2i(o, yc + 2 * r);
	glVertex2i(o, yc + 2 * r - r / 1.9);
	glEnd();
	plot_line_bel(o, yc + 2 * r - r / 1.9, r / 3.17, 0, 0.57);

	glBegin(GL_LINES); //creates tree 4
	glVertex2i(o, yc - 2 * r);
	glVertex2i(o, yc - 2 * r + r / 1.9);
	glEnd();
	plot_line(o, yc - 2 * r + r / 1.9, r / 3.17, 0, 0.57);


	if (r == 0) return; //loop exit condition
	else //recursively plots itself
	{
		bresenham_circle_dc(r);
		xc = o + r;
		bresenham_circle_dc(r);
		dream_catcher(o - r, r / 2);
		dream_catcher(o + r, r / 2);
	}
}

