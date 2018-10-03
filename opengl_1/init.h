#pragma once
#include <glut.h>
#include "points.h"
#include "Trees.h"
#include "circles.h"


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
