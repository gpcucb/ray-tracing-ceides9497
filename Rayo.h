#ifndef RAYO_H
#define RAYO_H
#include "Vector.h"
class Rayo
{
private:
	Vector posicion;
	Vector direccion;
public:
	Rayo();
	Rayo(Vector posicion, Vector Direccion);
	~Rayo();
	Vector getPosicion(){ return this->posicion; }
	Vector getDireccion(){ return this->direccion; }
	void setPosicion(Vector posicion){ this->posicion = posicion; }
	void setDireccion(Vector direccion){ this->direccion = direccion; }
	void show();
};

#endif