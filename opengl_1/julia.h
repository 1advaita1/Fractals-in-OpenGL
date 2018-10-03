/*The method used in this code was inspired by the mandelbrot set implementation of Shibin K.Reeny. Visit her website for more information https://skr1986.wordpress.com/2012/11/12/mandelbrot-set-implementation-using-c-and-opengl/ */
//The black portion represents members of the Julia set. The colored portions represent the iterations for which their corresponding points finally started diverging
#pragma once
#include <glut.h>
#include <stdio.h>
float x0c, y0c;

//Sets structure to store color
struct Type_rgb {
	float r;
	float g;
	float b;
};

//pixels stores the colors of a particular location, and pattern stores the color of the previous iteration
struct Type_rgb pixels[841 * 1440], pattern[999];

//stores the colors of every individual pixel location in the array pixels.
void juliaset()
{
	float  x, y, xtemp;
	int iteration, max_iteration, loc = 0; //iteration is the variable containing the value of the present iteration; loc is the location of the current pixel
	printf("Start\n");

	float xdum, ydum; //to store x and y values at the beginning of the loop
	for (y = -1; y < 1.1; y = y + 0.0025) //iterates over all possible (x,y) points
		for (x = -2.5; x < 1.1; x = x + 0.0025) {
			xdum = x; ydum = y; //stores the inital (x,y) values
			iteration = 0; 
			max_iteration = 500; //value of maximum iterations

			while (((x*x) + (y*y) < (2 * 2)) && iteration < max_iteration)  //check the maximum iteration that the point (x,y) does not diverge for
			{
				xtemp = (x*x) - (y*y) + x0c;
				y = (2 * x*y) + y0c;
				x = xtemp;
				iteration = iteration + 1;
			}

			x = xdum; y = ydum; //reset (x,y)
			if (iteration >= max_iteration - 1) //iff iteration==max_iteration, (x,y) is a member of Julia set
			{
				pixels[loc].r = 0;
				pixels[loc].g = 0;
				pixels[loc].b = 0;
			}
			else //give that pixel the color of the previous iteration
			{
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
	float r, g, b; //Set initial color to white
	for (i = 0; i < 841 * 1440; i++) {
		pixels[i].r = 1;
		pixels[i].g = 1;
		pixels[i].b = 1;
	}

	i = 0;

	for (r = 0.1; r <= 0.9; r = r + 0.1) //Define colors for every iteration of divergence, going from blue to red
		for (g = 0.1; g <= 0.9; g = g + 0.1)
			for (b = 0.1; b <= 0.9; b = b + 0.1) {
				pattern[i].r = r;
				pattern[i].g = g;
				pattern[i].b = b;
				i++;
			}
	for (; i <= 999; i++) //Initialize the rest to white
	{
		pattern[i].r = 1;
		pattern[i].g = 1;
		pattern[i].b = 1;
	}
	juliaset();

}

void onDisplay()
{
	glClearColor(1, 1, 1, 0); //Set background to white
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(1440, 841, GL_RGB, GL_FLOAT, pixels); //Draw the pixels corresponding to every location, from the pixels array
	glutSwapBuffers();
}

void main_julia(int argc, char** argv)
{
	printf("\nEnter x and y co ordinates of c\n"); //Take in value of c
	scanf("%f %f", &x0c, &y0c);
	glutInit(&argc, argv);
	glutInitWindowSize(1440, 841);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Julia_Set");

	Init_julia();
	glutDisplayFunc(onDisplay); //Display the Julia set
	glutMainLoop();
	return;
}

