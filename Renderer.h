#ifndef RENDERER_H
#define RENDERER_H
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <list>
#include <map>
#include <string>
#include <GL/glut.h>
#include "Color.h"
#include "Objeto.h"
#include "Camara.h"
#include "Luz.h"
using namespace std;
class Renderer
{
private:
	Color **buffer;
	bool isDrawing;
	int x, y;
	int window;
protected:
	Color backgroundColor;
	int width;
	int height;

public:
	Renderer();
	Renderer(int width, int height, float backRed, float backGreen, float backBlue);
	virtual ~Renderer();

	void reset();
	void initGL();
	void drawScene();
	void reshape();
	void idle();
	void saveImage();
	void render(string filename);
	void reshape(int width, int height);


	virtual void keyboard(int key, int x, int y);
	virtual Color calculatePixel(int i, int j);
};

#endif