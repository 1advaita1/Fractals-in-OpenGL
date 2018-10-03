/*The method used in this code was inspired by the julia set implementation of Shibin K.Reeny. Visit her website for more information https://skr1986.wordpress.com/2012/11/12/julia-set-implementation-using-c-and-opengl/ */

#pragma once
#include <glut.h>
#include <stdio.h>
float x0c, y0c;
struct Type_rgb {
	float r;
	float g;
	float b;
};
struct Type_rgb pixels[841 * 1440], pattern[999];

void juliaset()
{
	float  x, y, xtemp;
	int iteration, max_iteration, loc = 0;
	printf("\nstart");

	float xdum, ydum;
	for (y = -1; y < 1.1; y = y + 0.0025)
		for (x = -2.5; x < 1.1; x = x + 0.0025) {
			xdum = x; ydum = y;
			iteration = 0;
			max_iteration = 500;
			while (((x*x) + (y*y) < (2 * 2)) && iteration < max_iteration) {
				xtemp = (x*x) - (y*y) + x0c;
				y = (2 * x*y) + y0c;

				x = xtemp;
				iteration = iteration + 1;
			}
			x = xdum; y = ydum;
			if (iteration >= max_iteration - 1) {
				pixels[loc].r = 0;
				pixels[loc].g = 0;
				pixels[loc].b = 0;
			}
			else {
				pixels[loc].r = pattern[iteration].r;
				pixels[loc].g = pattern[iteration].g;
				pixels[loc].b = pattern[iteration].b;
			}
			loc = loc + 1;
		}
}

void Init_julia()
{
	glViewport(0, 0, 1440, 841);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1440, 0, 841);

	int i;
	float r, g, b;
	for (i = 0; i < 841 * 1440; i++) {
		pixels[i].r = 1;
		pixels[i].g = 1;
		pixels[i].b = 1;
	}

	i = 0;
	for (r = 0.1; r <= 0.9; r = r + 0.1)
		for (g = 0.1; g <= 0.9; g = g + 0.1)
			for (b = 0.1; b <= 0.9; b = b + 0.1) {
				pattern[i].r = r;
				pattern[i].g = g;
				pattern[i].b = b;
				i++;
			}
	for (; i <= 999; i++) {
		pattern[i].r = 1;
		pattern[i].g = 1;
		pattern[i].b = 1;
	}
	juliaset();

}

void onDisplay()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(1440, 841, GL_RGB, GL_FLOAT, pixels);
	glutSwapBuffers();
}

void main_julia(int argc, char** argv)
{
	printf("\nEnter x and y co ordinates of c\n");
	scanf("%f %f", &x0c, &y0c);
	glutInit(&argc, argv);
	glutInitWindowSize(1440, 841);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Julia_Set");

	Init_julia();
	glutDisplayFunc(onDisplay);
	glutMainLoop();
	return;
}

