#include "vector.h"
#include <math.h>
#include <GL/glut.h>
Vector addVectors(Vector a, Vector b)
{
	Vector c;
	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return c;
}

Vector substractVectors(Vector a, Vector b)
{
	Vector c;
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return c;

}

Vector normalizeVector(Vector a)
{
	GLfloat m = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
	a.x /= m;
	a.y /= m;
	a.z /= m;
	return a;

}

Vector multiplyVector(Vector a, GLfloat scalar)
{
	a.x = a.x * scalar;
	a.y = a.y * scalar;
	a.z = a.z * scalar;
	return a;

}
