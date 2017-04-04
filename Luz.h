#ifndef LUZ_H
#define LUZ_H
#include "Vector.h"
#include "Color.h"
class Luz
{
private:
	Vector posicion;
	Color color;
public:
	Luz();
	Luz(Vector posicion, Color color);
	~Luz();
	Vector getPosicion(){ return this->posicion; }
	Color getColor(){ return this->color; }
	void setPosicion(Vector posicion){ this->posicion = posicion; }
	void setColor(Color color){ this->color = color; }
};

#endif