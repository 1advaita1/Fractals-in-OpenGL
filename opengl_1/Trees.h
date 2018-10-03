#pragma once
void plot_line(int x, int y, int l, int i, float theta) //creates tree with root (x,y), stem length l, angle theta, and tilted by angle theta*i
{

	if (l == 0) return; //loop exit condition
	else {
		glBegin(GL_LINES);
		glVertex2i(x, y); //creates left branch
		glVertex2i(x - l * sin(theta*(i + 1)), y + l * cos(theta*(i + 1)));

		glVertex2i(x, y); //creates right branch
		glVertex2i(x - l * sin(theta*(i - 1)), y + l * cos(theta*(i - 1)));
		glEnd();

		plot_line(x - l * sin(theta*(i + 1)), y + l * cos(theta*(i + 1)), l / 1.56, i + 1, theta); //recurses from the tip of the left branch
		plot_line(x - l * sin(theta*(i - 1)), y + l * cos(theta*(i - 1)), l / 1.56, i - 1, theta); //recurses from the tip of the right branch

	}
}

void plot_line_bel(int x, int y, int l, int i, float theta) //same as above, but in downward direction
{

	if (l == 0) return;
	else {
		glBegin(GL_LINES);
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i + 1)), y - l * cos(theta*(i + 1)));
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i - 1)), y - l * cos(theta*(i - 1)));
		glEnd();

		plot_line_bel(x - l * sin(theta*(i + 1)), y - l * cos(theta*(i + 1)), l / 1.56, i + 1, theta);
		plot_line_bel(x - l * sin(theta*(i - 1)), y - l * cos(theta*(i - 1)), l / 1.56, i - 1, theta);

	}
}

void plot_line_up_bel(int x, int y, int l, int i, float theta) //tree with different parameters
{

	if (l == 0) return;
	else {
		glBegin(GL_LINES);
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i + 1)), y - l * cos(theta*(i + 1)));
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i - 1)), y - l * cos(theta*(i - 1)));
		glEnd();

		plot_line_up_bel(x - l * sin(theta*(i + 1)), y - l * cos(theta*(i + 1)), l / 1.9, i + 1, theta);
		plot_line_up_bel(x - l * sin(theta*(i - 1)), y - l * cos(theta*(i - 1)), l / 1.9, i - 1, theta);

	}
}


