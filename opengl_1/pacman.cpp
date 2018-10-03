#include <stdio.h>
#include <math.h>
#include <glut.h>
#include "main.h"
#include "draw.h"
#include "init.h"
#include "points.h"
#include "Trees.h"
#include "circles.h"


void main(int argc, char **argv) {
	printf("1 for Dream Catcher, 2 for Yin Yang");
	int op;
	scanf("%d", &op);
	if (op == 1) main_dc(argc, argv);
	else if (op == 2) main_yy(argc, argv);
	else return;
}



