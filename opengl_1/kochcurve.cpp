// Compiling in windows: g++ -o kochcurve kochcurve.cpp -lfreeglut -lopengl32 -lglu32 -lwinmm -lgdi32
#include <GL/glut.h> // freeglut with MinGW compiler
#include <bits/stdc++.h>

// dimensions of screen
float width = 1366;
float height = 768;
float l = 1366; // initial length of line segment
int levels = 12; // no of times recursive fractal is called

using namespace std;

void draw_koch_curve(float l, int levels);

// initialize opengl
void Init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, width, 0, height);
}

// handle key presses
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: //Escape key
          exit(0); //Exit the program
        case 'u': {
            cout << "UP" << endl;
            draw_koch_curve(l, ++levels);
        }
        case 'd': {
            cout << "DOWN" << endl;
            draw_koch_curve(l, --levels);
        }
        case 'l': {
            cout << "LEFT" << endl;
            draw_koch_curve(--l, levels);
        }
        case 'r': {
            cout << "RIGHT" << endl;
            draw_koch_curve(++l, levels);
        }
    }
}

// draw a basic line
void draw_a_line(float x0, float y0, float x1, float y1) {
    glLineWidth(1.5);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(x0, y0, 1);
    glVertex3f(x1, y1, 1);
    glEnd();


}

// recursive fractal function call which gets called `levels` number of times
void handle_a_line(float x0, float y0, float x1, float y1, int levels) {
    if(levels<0) return;
    if(levels==0) {
        draw_a_line(x0, y0, x1, y1);
        return;
    }
    float p0x = (x1+2*x0)/3;
    float p0y = (y1+2*y0)/3;
    float p1x = (2*x1+x0)/3;
    float p1y = (2*y1+y0)/3;
    float eqx = (p0x+p1x+sqrt(3)*(p0y-p1y))/2;
    float eqy = (p0y+p1y+sqrt(3)*(p1x-p0x))/2;
    levels--;
    handle_a_line(x0, y0, p0x, p0y, levels);
    handle_a_line(p1x, p1y, x1, y1, levels);
    handle_a_line(p0x, p0y, eqx, eqy, levels);
    handle_a_line(eqx, eqy, p1x, p1y, levels);
    // draw_a_line(x0, y0, p0x, p0y);
    // draw_a_line(x1, y1, p1x, p1y);
    // draw_a_line(p0x, p0y, eqx, eqy);
    // draw_a_line(p1x, p1y, eqx, eqy);
}

// start drawing koch curve
void draw_koch_curve(float l, int levels) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    if(l<=0) return;
    if(levels<=0) return;
    draw_a_line((width-l)/2, height/2, (width+l)/2, height/2);
    levels--;
    if(levels>0) {
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        handle_a_line((width-l)/2, height/2, (width+l)/2, height/2, levels);
        //draw_all_points();
    }
}

// callback which gets called for every frame
void onDisplay() {
	draw_koch_curve(l, levels);
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Koch curve");

	Init();

	glutDisplayFunc(onDisplay);
    glutKeyboardFunc(handleKeypress);
	glutMainLoop();
	return 0;
}
