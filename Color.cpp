#include "Color.h"


Color::Color()
{
}

Color::Color(MyRGB color)
{
	this->color = color;
}

Color::~Color()
{
}

Color Color::sumarColor(Color bColor){
	float newRed = this->color.getRed() + bColor.getColor().getRed();
	float newGreen = this->color.getGreen() + bColor.getColor().getGreen();
	float newBlue = this->color.getBlue() + bColor.getColor().getBlue();
	MyRGB nuevoColor(newRed, newGreen, newBlue);
	Color nuevo(nuevoColor);
	return nuevo;
}

Color Color::restarColor(Color bColor){
	float newRed = this->color.getRed() - bColor.getColor().getRed();
	float newGreen = this->color.getGreen() - bColor.getColor().getGreen();
	float newBlue = this->color.getBlue() - bColor.getColor().getBlue();
	MyRGB nuevoColor(newRed, newGreen, newBlue);
	Color nuevo(nuevoColor);
	return nuevo;
}

Color Color::multiplicarColor(Color bColor){
	float newRed = this->color.getRed() * bColor.getColor().getRed();
	float newGreen = this->color.getGreen() * bColor.getColor().getGreen();
	float newBlue = this->color.getBlue() * bColor.getColor().getBlue();
	MyRGB nuevoColor(newRed, newGreen, newBlue);
	Color nuevo(nuevoColor);
	return nuevo;
}

Color Color::escalarColor(float num){
	float newRed = this->color.getRed() * num;
	float newGreen = this->color.getGreen() * num;
	float newBlue = this->color.getBlue() * num;
	MyRGB nuevoColor(newRed, newGreen, newBlue);
	Color nuevo(nuevoColor);
	return nuevo;
}