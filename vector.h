#include <GL/glut.h>

#define PI 3.14159265359
#define DEG_TO_RAD PI / 180
#define RAD_TO_DEG 180 / PI

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
Vector rotateVector(Vector v, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);