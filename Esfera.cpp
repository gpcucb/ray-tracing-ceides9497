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

bool Esfera::interseccion(Rayo rayo,float t){
	float a, b, c;
	Vector e_c;
	Vector e = rayo.getPosicion();
	Vector d = rayo.getDireccion();
	
	a = d.productoEscalar(d);
	e_c = e.resta(this->posicion);
	b = d.productoVectorPorNumero(2).productoEscalar(e_c);
	c = e_c.productoEscalar(e_c) - pow(radio, 2);

	//cout << "a: "<<a<<", b: "<<b<<", c: "<<c<<endl;

	float discriminante = getDiscriminante(a,b,c);

	if (discriminante < 0.0)
		return false;

	float t0 = ((b * -1) - sqrt(discriminante))/(2 * a);
	float t1 = ((b * -1) + sqrt(discriminante)) / (2 * a);
	bool interseccion = false;
	if ((t0 > 0.0) && (t0 < t)){
		t = t0;
		interseccion = true;
	}	
	if ((t1 > 0.0) && (t1 < t)){
		t = t1;
		interseccion = true;
	}

	return interseccion;
		
}

float Esfera::getDiscriminante(float a, float b, float c){
	return pow(b, 2) - (4 * a * c);
}
