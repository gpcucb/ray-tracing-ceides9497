#ifndef INTERSECCION_H
#define INTERSECCION_H
class Interseccion
{
private:
	bool exito;
	float distancia;
public:
	Interseccion();
	Interseccion(bool exito);
	Interseccion(bool exito, float distancia);
	~Interseccion();
	bool getExito();
};

#endif