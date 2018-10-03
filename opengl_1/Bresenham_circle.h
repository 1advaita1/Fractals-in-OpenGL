// In windows: g++ -o circledrawing circledrawing.cpp -lfreeglut -lopengl32 -lglu32 -lwinmm -lgdi32
#include <algorithm>
#include <stdio.h>
#include <glut.h>

int r;
//Function to initialize the scene for drawing
void Init_bresenham_circle() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-250, 250, -250, 250);
}

/*
	Function to draw circle using Bresenham's mid point circle drawing algorithm.
	The algorithm exploits 8 point symmetry of the circle, using which, only 
	one among the 8 symmetical parts of the circle are drawn and rest are replicated from 
	the first part.
*/
void circle_drawing(int r) {
	// This algo draws the circle between y=x and x=0
	int x = 0;
	int y = r;
	int d = 1 - r;
	int deltaE = 3;
	int deltaSE = -2 * r + 5;
	glBegin(GL_POINTS);
	glColor3f(1, 1, 1);
	glVertex2i(r, 0);
	glVertex2i(-r, 0);
	glVertex2i(0, r);
	glVertex2i(0, -r);
	glEnd();

	while (y>x) {
		if (d<0) {
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}
		else {
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			y--;
		}
		x++;
		glBegin(GL_POINTS);
		glColor3f(1, 1, 1);
		glVertex2i(x, y);
		glVertex2i(x, -y);
		glVertex2i(-x, y);
		glVertex2i(-x, -y);
		glVertex2i(y, x);
		glVertex2i(-y, x);
		glVertex2i(y, -x);
		glVertex2i(-y, -x);
		glEnd();
	}
}

void display_circle() {
	circle_drawing(r);
	glutSwapBuffers();
}

/*
	main_bresenham function asks the user to enter the radius (r) of the circle.
	The radius of the circle is constrained to value <= 100
*/

void main_bresenham_circle(int argc, char** argv)
{
	printf("Enter radius <= 100\n");
	scanf("%d", &r);
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Circle Drawing");

	Init_bresenham_circle();

	glutDisplayFunc(display_circle);

	glutMainLoop();
	return;
}
