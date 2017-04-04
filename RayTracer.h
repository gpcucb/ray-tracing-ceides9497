#ifndef RAY_TRACER_H
#define RAY_TRACER_H
#include "Esfera.h"
#include "Triangulo.h"
#include "Camara.h"
#include "MyRGB.h"
#include <vector>
#include "Renderer.h"
class RayTracer
{
private:
	float nx, ny;
	Camara camera;
	float infinity;
	vector<Objeto*> objetos;
public:
	RayTracer();
	RayTracer(float width, float height);
	~RayTracer();
	RayTracer(float nx, float ny , Camara camara);
	void insertObject(Objeto*);
	void showObjects();
	void rayTracing();
	MyRGB rayTrace(Rayo ray);
	MyRGB calculateColor(Objeto *pObject, Rayo ray);
	float mayor(float number, float number2);
	Color lambertianShading(Vector, Vector, Rayo, Luz, Objeto *);
	Color blinnPhongShading(Vector, Vector, Rayo, Luz, Objeto *);
	Color calcularPixel(float i,float j);
};

#endif