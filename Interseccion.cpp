#include "Interseccion.h"


Interseccion::Interseccion()
{
}

Interseccion::Interseccion(bool exito)
{
	this->exito = exito;
}

Interseccion::Interseccion(bool exito, float distancia)
{
	this->exito = exito;
	this->distancia = distancia;
}


Interseccion::~Interseccion()
{
}

bool Interseccion::getExito(){
	return this->exito;
}
