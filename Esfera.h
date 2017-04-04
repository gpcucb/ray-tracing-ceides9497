#ifndef ESFERA_H
#define ESFERA_H
#include "Objeto.h"
class Esfera: public Objeto
{
private:
	Vector posicion;
	float radio;	
	Material material;
public:
	Esfera();
	Esfera(Vector posicion, float radio,Material material);
	~Esfera();
	float getRadio(){ return this->radio; }
	Vector getPosicion(){ return this->posicion; }
	void setRadio(float radio){ this->radio = radio; }
	void setPosicion(Vector posicion){ this->posicion = posicion; }
	Interseccion calcularinterseccion(Rayo rayo,float t);
	void show();
	float getDiscriminante(float a, float b, float c);
};

#endif