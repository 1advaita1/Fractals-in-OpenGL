#pragma once
#include <glut.h>
#include "init.h"
#include "points.h"
#include "Trees.h"
#include "circles.h"

void draw_tree(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int r = 200;
	int o = xc;
	glColor3f(0.3, 1, 0.2);
	plot_line(450, 110, r, 0, 0.45);
	glFlush();
	r /= 2;
	
	glutSwapBuffers();
	
}
void draw_circle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int r = 270;
	bresenham_circle_yyp(r);
	int o = xc;
	r /= 2;
	yin_yang_plain(o, r);

}

void draw_yy(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3i(0, 0, 0);
	glVertex2i(0, 0);
	glVertex2i(0, yc);
	glVertex2i(1000, yc);
	glVertex2i(1000, 0);
	glEnd();
	int r = 300;
	bresenham_circle_yy(r);
	int o = xc;
	r /= 2;
	yin_yang(o, r);

}


void draw_dc(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	int r = 330;
	bresenham_circle_dc(r);
	int o = xc;
	r /= 2;
	dream_catcher(o, r);

}