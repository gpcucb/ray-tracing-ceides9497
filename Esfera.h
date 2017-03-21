#ifndef ESFERA_H
#define ESFERA_H
#include "Vector.h"
#include "Rayo.h"
class Esfera
{
private:
	float radio;
	Vector posicion;
public:
	Esfera();
	Esfera(float radio, Vector posicion);
	~Esfera();
	float getRadio(){ return this->radio; }
	Vector getPosicion(){ return this->posicion; }
	void setRadio(float radio){ this->radio = radio; }
	void setPosicion(Vector posicion){ this->posicion = posicion; }
	bool interseccion(Rayo rayo,float t);
	float getDiscriminante(float a, float b, float c);
};

#endif