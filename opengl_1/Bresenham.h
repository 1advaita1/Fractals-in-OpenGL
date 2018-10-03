#pragma once
#include <algorithm>
#include <stdio.h>
#include <glut.h>

int h0, k0, h1, k1;
void Init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void midpoint_line(int h0, int k0, int h1, int k1) {
	int dx = h1 - h0;
	int dy = k1 - k0;

	if (dx == 0) {
		int miny = std::min(k0, k1);
		int maxy = std::max(k0, k1);
		for (int i = miny; i <= maxy; i++) {
			glBegin(GL_POINTS);
			glColor3f(1, 1, 1);
			glVertex2i(h0, i);
			glEnd();
		}
		return;
	}

	float m = dy / (float)dx;
	if (m>0) {
		if (h1<h0) {
			int t = h0;
			h0 = h1;
			h1 = t;
			t = k0;
			k0 = k1;
			k1 = t;
			dx = -dx;
			dy = -dy;
		}
		int d = 2 * dy - dx;
		int incrE = 2 * dy;
		int incrNE = 2 * (dy - dx);
		int x = h0, y = k0;
		glBegin(GL_POINTS);
		glColor3f(1, 1, 1);
		glVertex2i(x, y);
		glEnd();

		while (x<h1) {
			if (d <= 0) {  // Choose E
				d += incrE;
			}
			else {
				d += incrNE; // Choose NE
				y++;
			}
			x++;
			glBegin(GL_POINTS);
			glColor3f(1, 1, 1);
			glVertex2i(x, y);
			glEnd();
		}
	}
	else if (m<0) {
		if (h0<h1) {
			int t = h0;
			h0 = h1;
			h1 = t;
			t = k0;
			k0 = k1;
			k1 = t;
			dx = -dx;
			dy = -dy;
		}
		int d = 2 * dy - dx;
		int incrE = 2 * dy;
		int incrNE = 2 * (dy - dx);
		int x = h0, y = k0;
		glBegin(GL_POINTS);
		glColor3f(1, 1, 1);
		glVertex2i(x, y);
		glEnd();

		while (x>h1) {
			if (d <= 0) {  // Choose E
				d += incrE;
			}
			else {
				d += incrNE; // Choose NE
				y++;
			}
			x--;
			glBegin(GL_POINTS);
			glColor3f(1, 1, 1);
			glVertex2i(x, y);
			glEnd();
		}
	}
	else if (m == 0) {
		int minx = std::min(h0, h1);
		int maxx = std::max(h0, h1);
		for (int i = minx; i <= maxx; i++) {
			glBegin(GL_POINTS);
			glColor3f(1, 1, 1);
			glVertex2i(i, k0);
			glEnd();
		}
		return;
	}

}

void display_line() {
	midpoint_line(h0, k0, h1, k1);
	glutSwapBuffers();
}

void main_bresenham(int argc, char** argv)
{
	printf("Enter x1, y1, x2, y2");
	scanf("%d %d %d %d", &h0, &k0, &h1, &k1);
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham's Line Drawing");

	Init();

	glutDisplayFunc(display_line);

	glutMainLoop();
	return;
}
