#include "Esfera.h"


Esfera::Esfera()
{
}

Esfera::Esfera(float radio, Vector posicion)
{
	this->radio = radio;
	this->posicion = posicion;
}

Esfera::~Esfera()
{
}

void Esfera::interseccion(Rayo rayo){
	float a, b, c;
	Vector e_c;
	Vector e = rayo.getPosicion();
	Vector d = rayo.getDireccion();
	
	a = d.productoEscalar(d);
	e_c = e.resta(this->posicion);
	b = d.productoVectorPorNumero(2).productoEscalar(e_c);
	c = e_c.productoEscalar(e_c) - pow(radio, 2);

	cout << "a: "<<a<<", b: "<<b<<", c: "<<c<<endl;
}
