#ifndef MY_RGB_H
#define MY_RGB_H
#include <iostream>
using namespace std;
class MyRGB
{
private:
	float red;
	float green;
	float blue;
public:
	MyRGB();
	MyRGB(float red, float green, float blue);
	~MyRGB();
	float getRed(){ return this->red; }
	float getBlue(){ return this->blue; }
	float getGreen(){ return this->green; }
	void setRed(float red){ this->red = red; }
	void setBlue(float blue){ this->blue = blue; }
	void setGreen(float green){ this->green = green; }
	float moderar(float var);
	void show();
	
};

#endif