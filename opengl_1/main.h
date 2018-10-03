#pragma once
// Center of the cicle = (320, 240)
int xc = 450, yc = 450;
#include <glut.h>
//#include "main.h"
#include "draw.h"
#include "init.h"
#include "points.h"
#include "Trees.h"
#include "circles.h"
void main_tree(int argc, char **argv)
{
	/* Initialise GLUT library */
	glutInit(&argc, argv);
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* Set the initial window position and size */
	glutInitWindowPosition(350, 95);
	glutInitWindowSize(900, 700);
	/* Create the window with title "DDA_Line" */
	glutCreateWindow("Tree");
	/* Initialize drawing colors */
	Init_circle();
	/* Call the displaying function */
	glutDisplayFunc(draw_tree);
	glutReshapeWindow(901, 701);	/* Keep displaying untill the program is closed */
	glutMainLoop();
}


void main_circle(int argc, char **argv)
{
	/* Initialise GLUT library */
	glutInit(&argc, argv);
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* Set the initial window position and size */
	glutInitWindowPosition(350, 95);
	glutInitWindowSize(900, 700);
	/* Create the window with title "DDA_Line" */
	glutCreateWindow("Circles");
	/* Initialize drawing colors */
	Init_circle();
	/* Call the displaying function */
	glutDisplayFunc(draw_circle);
	/* Keep displaying untill the program is closed */
	glutMainLoop();
}

void main_dc(int argc, char **argv)
{
	/* Initialise GLUT library */
	glutInit(&argc, argv);
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* Set the initial window position and size */
	glutInitWindowPosition(350, 95);
	glutInitWindowSize(900, 700);
	/* Create the window with title "DDA_Line" */
	glutCreateWindow("Dream Catcher");
	/* Initialize drawing colors */
	Init_dc();
	/* Call the displaying function */
	glutDisplayFunc(draw_dc);
	/* Keep displaying untill the program is closed */
	glutMainLoop();
}

void main_yy(int argc, char **argv)
{
	/* Initialise GLUT library */
	glutInit(&argc, argv);
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* Set the initial window position and size */
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(600, 600);
	/* Create the window with title "DDA_Line" */
	glutCreateWindow("Yin Yang");
	/* Initialize drawing colors */
	Init_yy();
	/* Call the displaying function */
	glutDisplayFunc(draw_yy);
	/* Keep displaying untill the program is closed */
	glutMainLoop();
}

