#include "Renderer.h"
#include <iostream>
#include <cmath>


Renderer::Renderer()
{
}


Renderer::Renderer(int width, int height, float backRed, float backGreen, float backBlue)
{
	MyRGB fondo(backRed, backGreen, backBlue);
	Color back(fondo);
	this->backgroundColor = back;
	this->width = width;
	this->height = height;
	buffer = new Color*[this->width];

	for (int i = 0; i < this->width; i++)
		buffer[i] = new Color[this->height];

	reset();
}

Renderer::~Renderer() {
	cout << "Cleaning up everything" << endl;
	for (int i = 0; i < this->width; i++)
		delete[] buffer[i];
	delete[] buffer;
}

void Renderer::reset() {
	isDrawing = true;
	x = 0;
	y = 0;
}

Color Renderer::calculatePixel(int i, int j) {
	MyRGB rgb(0, 0, 0);
	Color color(rgb);

	return color;
}

void Renderer::keyboard(int key, int x, int y) {
	switch (key) {
	case 27:
		glutDestroyWindow(window);
		exit(0);
	default:
		break;
	}
	glutPostRedisplay();
}

void Renderer::initGL() {
	glClearColor(backgroundColor.getColor().getRed(), backgroundColor.getColor().getGreen(), backgroundColor.getColor().getBlue(), 0.0f);
}
/*
void Renderer::render(string filename){
	glutInit;
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(10, 10);
	window = glutCreateWindow("Dibujo");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(reshape);


}*/

void Renderer::drawScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width - 1, 0.0, height - 1, 1, -1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_POINTS);

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			glColor3f(buffer[i][j].getColor().getRed(), buffer[i][j].getColor().getGreen(), buffer[i][j].getColor().getBlue());
			glVertex2i(i, j);
		}
	}	
	glEnd();
	glFlush();
}

void Renderer::reshape(int width, int height) {
	this->width = width;
	this->height = height;
	for (int i = 0; i < this->width; i++)
		delete[] buffer[i];
	delete[] buffer;

	buffer = new Color*[this->width];

	for (int i = 0; i < this->width; i++)
		buffer[i] = new Color[this->height];
	glViewport(0, 0, this->width, this->height);
	reset();
}

void Renderer::idle() {
	if (isDrawing) {
		buffer[x][y] = calculatePixel(x, y);
		++x;

		if (x >= width) {
			x = 0;
			++y;
			glutPostRedisplay();
		}

		if (y >= height) {
			isDrawing = false;
			glutPostRedisplay();
		}
	}
}

void Renderer::saveImage() {
	//TODO Implement this
}