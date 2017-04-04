#ifndef OBJETO_H
#define OBJETO_H
#include "Vector.h"
#include "Rayo.h"
#include "Interseccion.h"
#include "Material.h"
class Objeto
{
private:
	Material material;
public:
	Objeto(Material material);
public:	
	void setMaterial(Material material){ this->material = material; }
	Material getMaterial(){ return this->material; }
	virtual void show() = 0;
	virtual Interseccion calcularinterseccion(Rayo,float) = 0;
};

#endif