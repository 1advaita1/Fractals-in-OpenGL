//The functions in this header define the background colors and the orthographic projections of the windows for the different figures 

#pragma once
#include <glut.h>
#include "Trees.h"
#include "circles.h"

/*
	The following Init functions are used to initialize the screen for drawing 
	circle, dream catcher fractal and ying_yang fractal respectively
*/

void Init_circle()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	gluOrtho2D(0, 900, 0, 700);
}

void Init_dc()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.4, 0.5, 0.75);

	gluOrtho2D(0, 900, 0, 700);
}

void Init_yy()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	gluOrtho2D(0, 900, 0, 900);
}
