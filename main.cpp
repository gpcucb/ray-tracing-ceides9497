#include "RayTracer.h"

int main()
{
	Vector eye(278, 273, -800);
	Vector center(278, 273, -800);
	Vector up(0, 1, 0);
	double	fieldOfView = 39.31;
	double	distanceTo = 0.035;
	Camara camera(eye, center, up, fieldOfView, distanceTo);

	Vector spherePosition = Vector(370, 120, 370);
	double radius = 120.0;
	Esfera sphere(spherePosition, radius);
	Vector vertixA = Vector(552.0, 8.0, 0.0);
	Vector vertixB = Vector(0.0, 0.0, 0.0);
	Vector vertixC = Vector(0.0, 0.0, 560.0);
	Triangulo triangle(vertixA, vertixB, vertixC);

	double	nx = 640.0;
	double	ny = 480.0;

	RayTracer rayTracer(nx, ny, camera);
	rayTracer.insertObject(&sphere);
	rayTracer.insertObject(&triangle);
	rayTracer.showObjects();
	rayTracer.rayTracing();

	return 0;
}