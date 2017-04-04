#ifndef COLOR_H
#define COLOR_H
#include "MyRGB.h"
class Color
{
private:
	MyRGB color;
public:
	Color();
	Color(MyRGB color);
	~Color();
	Color sumarColor(Color bColor);
	Color restarColor(Color bColor);
	Color multiplicarColor(Color bColor);
	Color escalarColor(float num);
	MyRGB getColor(){ return this->color; }
	void setColor(MyRGB color){ this->color = color; }
};

#endif