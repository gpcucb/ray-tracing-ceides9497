#include "RayTracer.h"


RayTracer::RayTracer()
{
}

RayTracer::RayTracer(float width, float height)
{
	infinity = numeric_limits<float>::infinity();
	this->nx = width;
	this->ny = height;
	//Camara
	Vector e(278, 273, -800);
	Vector center(278, 273, -700);
	Vector up(0, 1, 0);
	float fov = 39.31;
	float df = 0.035;
	Camara cam(e, center, up, fov, df);
	this->camera = cam;

	//Some colors
	Color fucsia(MyRGB(1.0, 0.2, 0.4));
	Color red = (MyRGB(1.0, 0.0, 0.0));
	Color yellow = (MyRGB(1, 1, 0));

	//Material values
	Color specular(MyRGB(1, 1, 1));
	float power = 60;
	float reflection = 0.5;

	//Valores de la esfera 1
	Vector position1(-100, -100, 370);
	float	radius = 120;

	//Valores de la esfera 2
	Vector position2(100, -100, 370);

	//Valores del triángulo
	Vector	a(30, -200, -200);
	Vector	b(20, -100, -400);
	Vector	c(100, -10, -200);

	//Light Values
	Color light_color(MyRGB(0.8, 0.6, 0.7));
	Vector light_position(0.0, 0.0, 200.0);
	Luz light(light_position, light_color);

	Esfera	sphere1(position1, radius, Material(yellow, specular, power, reflection));
	Esfera	sphere2(position2, radius, Material(fucsia, specular, power, reflection));
	Triangulo triangle(a, b, c, Material(red, specular, power, reflection));
	insertObject(&sphere1);
	insertObject(&sphere2);
	insertObject(&triangle);

}

RayTracer::~RayTracer()
{
}


void RayTracer::insertObject(Objeto *object)
{
	objetos.push_back(object);
}

void RayTracer::showObjects()
{
	for (auto &&object : objetos) {
		object->show();
	}
}

float RayTracer::mayor(float number, float number2){
	if (number>number2)
	{
		return number;
	}
	else
	{
		return number2;
	}
}

Color RayTracer::lambertianShading(Vector interseccionPoint, Vector insterseccionNormal, Rayo ray, Luz light, Objeto *objeto){
	Vector n = interseccionPoint.normalizar();
	Vector l = light.getPosicion().resta(interseccionPoint).normalizar();

	float nl = n.productoEscalar(l);
	float max;
	max = mayor(0, nl);
	Color kd = objeto->getMaterial().getDiffuse();
	Color kdI = kd.multiplicarColor(light.getColor());
	return kdI.escalarColor(max);
}


Color RayTracer::blinnPhongShading(Vector interseccionPoint, Vector insterseccionNormal, Rayo ray, Luz light, Objeto *objeto){
	Vector n = interseccionPoint.normalizar();
	Vector v = ray.getPosicion().resta(interseccionPoint).normalizar();
	Vector l = light.getPosicion().resta(interseccionPoint).normalizar();
	Vector h = v.suma(l).normalizar();

	float nh = n.productoEscalar(h);
	Color ks = objeto->getMaterial().getSpecular();
	float p = objeto->getMaterial().getPower();
	float max = mayor(0, nh);
	Color ksI = ks.multiplicarColor(light.getColor());
	return ksI.escalarColor(pow(max,2));
}

Color RayTracer::calcularPixel(float i, float j){
	Vector e = camera.getEje();
	Vector dir = camera.calculandoDireccionDelRayo(i, j, nx, ny);
	Rayo ray(e, dir);
	float t = this->infinity;
}


