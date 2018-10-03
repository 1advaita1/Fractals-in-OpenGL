#pragma once
void plot_line(int x, int y, int l, int i, float theta)
{

	if (l == 0) return;
	else {
		glBegin(GL_LINES);
		//glVertex2i(x, y);
		//glVertex2i(x-l*sin(theta*i), y +  l*cos(theta*i));
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i + 1)), y + l * cos(theta*(i + 1)));
		glVertex2i(x, y);
		glVertex2i(x - l * sin(theta*(i - 1)), y + l * cos(theta*(i - 1)));
		glEnd();

		//plot_line(x - l * sin(theta*i), y + l * cos(theta*i),l/2,i,theta);
		plot_line(x - l * sin(theta*(i + 1)), y + l * cos(theta*(i + 1)), l / 1.56, i + 1, theta);
		plot_line(x - l * sin(theta*(i - 1)), y + l * cos(theta*(i - 1)), l / 1.56, i - 1, theta);

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


