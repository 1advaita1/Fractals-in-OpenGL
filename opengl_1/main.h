//The functions in this header define the window sizes of the different figures

#pragma once
int xc = 450, yc = 450; //defines centre coordinates
#include <glut.h>
#include "draw.h"
#include "init.h"
#include "Trees.h"
#include "circles.h"

void main_tree(int argc, char **argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(350, 95);
	glutInitWindowSize(900, 700);
	glutCreateWindow("Tree");
	Init_circle();
	glutDisplayFunc(draw_tree);
	glutReshapeWindow(901, 701);	        
	glutMainLoop();
}


void main_circle(int argc, char **argv)
{
	xc = 450; yc = 340;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(350, 50);
	glutInitWindowSize(900, 700);
	glutCreateWindow("Circles");
	Init_circle();
	glutDisplayFunc(draw_circle);
	glutMainLoop();
}

void main_dc(int argc, char **argv)
{
	xc = 450; yc = 340; 
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(325, 80);
	glutInitWindowSize(900, 700);
	glutCreateWindow("Dream Catcher");
	Init_dc();
	glutDisplayFunc(draw_dc);
	glutMainLoop();
}

void main_yy(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(425, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Yin Yang");
	Init_yy();
	glutDisplayFunc(draw_yy);
	glutMainLoop();
}

