#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <math.h>  
using namespace std;
#define pi 3.1415926535897932384626433832795
class Vector
{
private:
	float x;
	float y;
	float z;
public:
	Vector();
	Vector(float x, float y, float z);
	~Vector();
	float getX(){ return this->x; }
	float getY(){ return this->y; }
	float getZ(){ return this->z; }
	void setX(float x){ this->x = x; }
	void setY(float y){ this->y = y; }
	void setZ(float z){ this->z = z; }
	void show();
	Vector suma(Vector v);
	Vector resta(Vector v);
	int modulo();
	Vector productoVectorial(Vector v);
	float productoEscalar(Vector v);
	Vector productoVectorPorNumero(float numero);
};

#endif