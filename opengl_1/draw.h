#pragma once
#include <glut.h>
#include "init.h"
#include "Trees.h"
#include "circles.h"

//Display callback function for drawing tree
void draw_tree(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //Clear buffer
	int l = 200; //Sets the length of the main branch of the tree
	int o = xc; //Sets the x coordinate of the root of the tree. The 'o' stands for origin.
	glColor3f(0.3, 1, 0.2); //Sets the color of the tree
	plot_line(450, 110, l, 0, 0.45); //Creates the tree
	glFlush(); //Forces the above program to complete in finite time 
	glutSwapBuffers(); //Swaps buffers
	
}


//Display callback function for drawing the circle fractal
void draw_circle(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int r = 270;
	bresenham_circle_yyp(r); //Draws bigger circle
	int o = xc;
	r /= 2;
	yin_yang_plain(o, r); //Plots circle fractal
}

//Display callback function for drawing the yin-yang
void draw_yy(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON); //Colors the lower background black
	glColor3i(0, 0, 0);
	glVertex2i(0, 0);
	glVertex2i(0, yc);
	glVertex2i(1000, yc);
	glVertex2i(1000, 0);
	glEnd();
	int r = 300;
	bresenham_circle_yy(r); //Draws the yin yang
	int o = xc;
	r /= 2;
	yin_yang(o, r);
}

//Display callback function for drawing the dream-catcher
void draw_dc(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	int r = 330;
	bresenham_circle_dc(r);
	int o = xc;
	r /= 2;
	dream_catcher(o, r); //Draws the dream catcher

}