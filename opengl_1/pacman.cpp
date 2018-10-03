
#include <stdio.h>
#include <math.h>
#include <glut.h>

// Center of the cicle = (320, 240)
int xc = 450, yc = 450;

// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3i(0,0,0);
	glVertex2i(xc + x, yc + y);
	//glVertex2i(xc + x, yc - y);
	glVertex2i(xc + y, yc + x);
	//glVertex2i(xc + y, yc - x);
	//glVertex2i(xc - x, yc - y);
	//glVertex2i(xc - y, yc - x);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc - y, yc + x);
	glEnd();
}
void plot_point_low(int x, int y)
{
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	//glVertex2i(xc + x, yc + y);
	glVertex2i(xc + x, yc - y);
	//glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	//glVertex2i(xc - x, yc + y);
	//glVertex2i(xc - y, yc + x);
	glEnd();
}

// Function to draw a circle using bresenham's
// circle drawing algorithm
void bresenham_circle(int r)
{
	int x = 0, y = r;
	float pk = (5.0 / 4.0) - r;

	/* Plot the points */
	/* Plot the first point */

	plot_point(x, y);
	plot_point_low(x, y);
	int k;
	/* Find all vertices till x=y */
	while (x < y)
	{
		x = x + 1;
		if (pk < 0)
			pk = pk + 2 * x + 1;
		else
		{
			y = y - 1;
			pk = pk + 2 * (x - y) + 1;
		}

		plot_point(x, y);
		plot_point_low(x, y);
	}
	glFlush();
}

int xtemp = xc;
void yin_yang(int o, int r)
{

	xc = o - r;
	if (r == 0) return;
	else {
		bresenham_circle(r);
		xc = o + r;
		bresenham_circle(r);
		//glColor3f(r / 8000, r / 4000, r / 200);
		//glColor3f(r / 8000, r / 1000, r / 300);
		yin_yang(o - r, r / 2);
		yin_yang(o + r, r / 2);
	}
}


// Function to draw two concentric circles
void concentric_circles(void)
{
	/* Clears buffers to preset values */
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3i(0, 0, 0);
	glVertex2i(0, 0);
	glVertex2i(0, yc);
	glVertex2i(1000, yc);
	glVertex2i(1000, 0);
	glEnd();
	int r = 400;
	bresenham_circle(r);
	int o = xc;
	r /= 2;
	yin_yang(o, r);

}

void Init()
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

void main(int argc, char **argv)
{
	/* Initialise GLUT library */
	glutInit(&argc, argv);
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* Set the initial window position and size */
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(600, 600);
	/* Create the window with title "DDA_Line" */
	glutCreateWindow("bresenham_circle");
	/* Initialize drawing colors */
	Init();
	/* Call the displaying function */
	glutDisplayFunc(concentric_circles);
	/* Keep displaying untill the program is closed */
	glutMainLoop();
}

