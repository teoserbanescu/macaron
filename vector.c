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

Vector createVector(GLdouble x, GLdouble y, GLdouble z) 
{
	Vector v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}

Vector rotateVector(Vector v, GLdouble angle, GLdouble x, GLdouble y, GLdouble z) 
{
	// Normalizes the rotation vector
	Vector n = createVector(x, y, z);
	n = normalizeVector(n);
	x = n.x;
	y = n.y;
	z = n.z;

	GLdouble r = angle * DEG_TO_RAD;
	GLdouble c = cos(r);
	GLdouble s = sin(r);

	// Rotates the vector
	Vector out;
	out.x = (x * x * (1 - c) + c) * v.x + (x * y * (1 - c) - z * s) * v.y + (x * z * (1 - c) + y * s) * v.z;
	out.y = (y * x * (1 - c) + z * s) * v.x + (y * y * (1 - c) + c) * v.y + (y * z * (1 - c) - x * s) * v.z;
	out.z = (x * z * (1 - c) - y * s) * v.x + (y * z * (1 - c) + x * s) * v.y + (z * z * (1 - c) + c) * v.z;

	return out;
}
