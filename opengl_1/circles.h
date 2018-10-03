#pragma once
#include <glut.h>
#include "points.h"
#include "Trees.h"
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
void yin_yang(int o, int r)
{

	xc = o - r;
	if (r == 0) return;
	else {
		bresenham_circle_yy(r);
		xc = o + r;
		bresenham_circle_yy(r);
		yin_yang(o - r, r / 2);
		yin_yang(o + r, r / 2);
	}
}

void yin_yang_plain(int o, int r)
{

	xc = o - r;
	if (r == 0) return;
	else {
		bresenham_circle_yyp(r);
		xc = o + r;
		bresenham_circle_yyp(r);
		yin_yang_plain(o - r, r / 2);
		yin_yang_plain(o + r, r / 2);
	}
}

void dream_catcher(int o, int r)
{

	xc = o - r;
	glBegin(GL_LINES);
	glVertex2i(o, yc + r / 1.15);
	glVertex2i(o, yc - r / 1.15);
	glEnd();

	plot_line(o, yc + r / 1.15, r / 3.05, 0, 0.575);
	plot_line_bel(o, yc - r / 1.15, r / 3.2, 0, 0.55);


	glBegin(GL_LINES);
	glVertex2i(o, yc + 2 * r);
	glVertex2i(o, yc + 2 * r - r / 1.9);
	glEnd();

	plot_line_bel(o, yc + 2 * r - r / 1.9, r / 3.17, 0, 0.57);

	glBegin(GL_LINES);
	glVertex2i(o, yc - 2 * r);
	glVertex2i(o, yc - 2 * r + r / 1.9);
	glEnd();

	plot_line(o, yc - 2 * r + r / 1.9, r / 3.17, 0, 0.57);


	if (r == 0) return;
	else {
		bresenham_circle_dc(r);
		xc = o + r;
		bresenham_circle_dc(r);
		dream_catcher(o - r, r / 2);
		dream_catcher(o + r, r / 2);
	}
}

