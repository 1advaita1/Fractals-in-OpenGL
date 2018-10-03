#pragma once
#include <glut.h>
//#include "main.h"
//#include "draw.h"
//#include "init.h"
#include "points.h"
#include "Trees.h"
#include "circles.h"


void Init_circle()
{
	/* Set clear color to white */
	glClearColor(1.0, 1.0, 1.0, 0);
	/* Set fill color to black */

	/* glViewport(0 , 0 , 640 , 480); */
	/* glMatrixMode(GL_PROJECTION); */
	/* glLoadIdentity(); */
	gluOrtho2D(0, 900, 0, 700);
}

void Init_dc()
{
	/* Set clear color to white */
	glClearColor(1.0, 1.0, 1.0, 0);
	/* Set fill color to black */
	glColor3f(0.4, 0.5, 0.75);

	/* glViewport(0 , 0 , 640 , 480); */
	/* glMatrixMode(GL_PROJECTION); */
	/* glLoadIdentity(); */
	gluOrtho2D(0, 900, 0, 700);
}

void Init_yy()
{
	/* Set clear color to white */
	glClearColor(1.0, 1.0, 1.0, 0);
	/* Set fill color to black */
	//glColor3f(0.4, 0.5, 0.75);
	/* glViewport(0 , 0 , 640 , 480); */
	/* glMatrixMode(GL_PROJECTION); */
	/* glLoadIdentity(); */
	gluOrtho2D(0, 900, 0, 900);
}
