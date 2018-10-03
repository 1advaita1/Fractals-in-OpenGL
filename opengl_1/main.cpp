#include <stdio.h>
#include <math.h>
#include <glut.h>
#include "main.h"
#include "draw.h"
#include "init.h"
#include "points.h"
#include "Trees.h"
#include "circles.h"
#include "julia.h"
#include "kochcurve.h"
#include "Bresenham.h"
#include "Bresenham_circle.h"

/*
	The main function prompts the user to choose the graphical image to be viewed.
	The code from each graphical image is included in the form of header files which are linked with this cpp file/
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
void main(int argc, char **argv) {
	printf("Select from the following: \n0 for Bresenham,\n1 for Trees,\n2 for Circles,\n3 for Dream Catcher,\n4 for Yin Yang,\n5 for Julia,\n6 for Kochcurve\n");
	int option;
	
	scanf("%d", &option);
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
	else if (option == 6) main_kochcurve(argc, argv);
	else return;
	
}



