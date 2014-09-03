#include <GL/glut.h>

typedef struct vector
{
	GLfloat x;
	GLfloat y;
	GLfloat z;
}Vector;

Vector addVectors(Vector a, Vector b);
Vector substractVectors(Vector a, Vector b);
Vector normalizeVector(Vector a);
Vector multiplyVector(Vector a, GLfloat scalar);
Vector createVector(GLdouble x, GLdouble y, GLdouble z);
