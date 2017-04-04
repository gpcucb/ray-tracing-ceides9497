#include "MyRGB.h"

MyRGB::MyRGB()
{
}

MyRGB::MyRGB(float red, float green, float blue)
{
	this->red = moderar(red);
	this->green = moderar(green);
	this->blue = moderar(blue);
}


MyRGB::~MyRGB()
{
}

void MyRGB::show(){
	cout << "RED: " << red << ", GREEN: " << green << ", BLUE: " << blue << endl;
}

float MyRGB::moderar(float var){
	if (var > 1)
	{
		return 1;
	}
	if (var < 0)
	{
		return 0;
	}
	return var;
}

