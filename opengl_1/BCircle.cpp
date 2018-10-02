
#include <stdio.h>
#include <math.h>
#include <glut.h>

// Center of the cicle = (320, 240)
int xc = 430, yc = 375;

// Plot eight points using circle's symmetrical property
void plot_point(int x, int y)
{
	glBegin(GL_LINES);
	//glColor3f(0.2,0.2,0.8);
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
	glBegin(GL_LINES);
	//glColor3f(0.2,0.8,0.5);
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


void plot_line(int x, int y, int l, int i, float theta)
{
	
	if (l == 0) return;
	else {   
		glBegin(GL_LINES);
			//glVertex2i(x, y);
			//glVertex2i(x-l*sin(theta*i), y +  l*cos(theta*i));
			glVertex2i(x, y);
			glVertex2i(x - l * sin(theta*(i+1)), y + l  * cos(theta*(i+1)));
			glVertex2i(x, y);
			glVertex2i(x - l * sin(theta*(i-1)), y + l  * cos(theta*(i-1)));
		glEnd();

		//plot_line(x - l * sin(theta*i), y + l * cos(theta*i),l/2,i,theta);
		plot_line(x - l * sin(theta*(i + 1)), y + l * cos(theta*(i + 1)),l/1.56,i+1,theta);
		plot_line(x - l * sin(theta*(i - 1)), y + l * cos(theta*(i - 1)),l/1.56,i-1,theta);
		
	}
}

void plot_line_bel(int x, int y, int l, int i, float theta)
{

	if (l == 0) return;
	else {
		glBegin(GL_LINES);
		//glVertex2i(x, y);
		//glVertex2i(x - l * sin(theta*i), y - l * cos(theta*i));
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i + 1)), y - l * cos(theta*(i + 1)));
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i - 1)), y - l * cos(theta*(i - 1)));
		glEnd();

		//plot_line_bel(x - l * sin(theta*i), y - l * cos(theta*i), l / 2, i, theta);
		plot_line_bel(x - l * sin(theta*(i + 1)), y - l * cos(theta*(i + 1)), l / 1.56, i + 1, theta);
		plot_line_bel(x - l * sin(theta*(i - 1)), y - l * cos(theta*(i - 1)), l / 1.56, i - 1, theta);

	}
}

void plot_line_up_bel(int x, int y, int l, int i, float theta)
{

	if (l == 0) return;
	else {
		glBegin(GL_LINES);
		//glVertex2i(x, y);
		//glVertex2i(x - l * sin(theta*i), y - l * cos(theta*i));
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i + 1)), y - l * cos(theta*(i + 1)));
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i - 1)), y - l * cos(theta*(i - 1)));
		glEnd();

		//plot_line_bel(x - l * sin(theta*i), y - l * cos(theta*i), l / 2, i, theta);
		plot_line_up_bel(x - l * sin(theta*(i + 1)), y - l * cos(theta*(i + 1)), l / 1.9, i + 1, theta);
		plot_line_up_bel(x - l * sin(theta*(i - 1)), y - l * cos(theta*(i - 1)), l / 1.9, i - 1, theta);

	}
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
	glBegin(GL_LINES);
	glVertex2i(o, yc+r/1.15);
	glVertex2i(o, yc-r/1.15);
	glEnd();

	plot_line(o,yc+r/1.15, r/3.05,0,0.575);
	plot_line_bel(o, yc - r/1.15, r /3.2, 0,0.55);


	glBegin(GL_LINES);
	glVertex2i(o, yc+2*r);
	glVertex2i(o, yc+2*r - r / 1.9);
	glEnd();

	plot_line_bel(o, yc +2*r - r / 1.9, r / 3.17, 0, 0.57);

	glBegin(GL_LINES);
	glVertex2i(o, yc - 2 * r);
	glVertex2i(o, yc - 2 * r + r / 1.9);
	glEnd();

	plot_line(o, yc - 2 * r + r / 1.9, r / 3.17, 0, 0.57);


	if (r == 0) return;
	else {
		bresenham_circle(r);
		xc = o + r;
		bresenham_circle(r);
		//glColor3f(r / (r+100), r /(r+ 300), r /(r+ 300));
		//glColor3f(r / 300, r / 300, r / 300);
		yin_yang(o - r, r / 2);
		yin_yang(o + r, r / 2);
	}
}


// Function to draw two concentric circles
void concentric_circles(void)
{
	/* Clears buffers to preset values */
	glClear(GL_COLOR_BUFFER_BIT);

	int r= 300;
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
	glColor3f(0.4, 0.5, 0.75);

	/* glViewport(0 , 0 , 640 , 480); */
	/* glMatrixMode(GL_PROJECTION); */
	/* glLoadIdentity(); */
	gluOrtho2D(0, 900, 0, 700);
}

void main(int argc, char **argv)
{
	/* Initialise GLUT library */
	glutInit(&argc, argv);
	/* Set the initial display mode */
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	/* Set the initial window position and size */
	glutInitWindowPosition(350, 95);
	glutInitWindowSize(900, 700);
	/* Create the window with title "DDA_Line" */
	glutCreateWindow("bresenham_circle");
	/* Initialize drawing colors */
	Init();
	/* Call the displaying function */
	glutDisplayFunc(concentric_circles);
	/* Keep displaying untill the program is closed */
	glutMainLoop();
}

