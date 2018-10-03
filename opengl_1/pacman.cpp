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

void main(int argc, char **argv) {
	printf("1 for Trees, 2 for Circles, 3 for Dream Catcher, 4 for Yin Yang, 5 for Julia\n");
	int op;
	
	scanf("%d", &op);
	if (op == 1) main_tree(argc, argv);
	else if (op == 2) main_circle(argc, argv);
	else if (op == 3) main_dc(argc, argv);
	else if (op == 4) main_yy(argc, argv);
	else if (op == 5) main_julia(argc, argv);
	else return;
	
}



