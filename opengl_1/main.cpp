#include <stdio.h>
#include <math.h>
#include <glut.h>
#include "main.h"
#include "draw.h"
#include "init.h"
#include "Trees.h"
#include "circles.h"
#include "julia.h"
#include "Bresenham.h"
#include "Bresenham_circle.h"



/*
	The main function prompts the user to choose the graphical image to be viewed.
	The code from each graphical image is included in the form of header files which are linked with this cpp file
	The user can choose from a range of images:
		
		0 followed by suboption 0 - Bresenham's line
		0 followed by suboption 1 - Bresenham's circle
		1 - Tree Fractal
		2 - Circle Fractal
		3 - Dream Catcher Fractal
		4 - Ying Yang Fractal
		5 - Julia Fractal
		6 - Kochcurve Fractal
*/

void main(int argc, char **argv) //Plot figure according to user's choice
{
	printf("0 for Bresenham, 1 for Trees, 2 for Circles, 3 for Dream Catcher, 4 for Yin Yang, 5 for Julia\n");
	int option;
	
	scanf("%d", &option); //Take input from user and call the respective functions from main.h 
	if (option == 0) 
	{
		int sub_option;
		printf("0 for line and 1 for circle\n");
		scanf("%d", &sub_option);
		if (sub_option==0)	main_bresenham(argc,argv);
		else main_bresenham_circle(argc,argv);
	}
	else if (option == 1) main_tree(argc, argv);
	else if (option == 2) main_circle(argc, argv);
	else if (option == 3) main_dc(argc, argv);
	else if (option == 4) main_yy(argc, argv);
	else if (option == 5) main_julia(argc, argv);
	else return;
	
}
