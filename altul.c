
#include <stdio.h>
#include <GL/glut.h>
#include "vector.h"
#include <math.h>

GLfloat light_pos[] = {5, 20, 5, 1};
GLfloat light_col[] = {1, 1, 1, 1};
GLfloat angle, step = 0.1, step1 = 5, anglev = 0;
GLfloat semn=1;
Vector eye, target;
int keystate[256], jump;
Vector impuls, Gforce;
GLfloat latime, inaltime, eyeheight;

void Reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei) width, (GLsizei) height); //coord colt stanga si dimensiunile
	gluPerspective(60, (GLfloat) width / (GLfloat) height, 0.1, 600000);//unghiul de deschidere al conului,raportul dim, dist de la ochi la con, total
	glMatrixMode(GL_MODELVIEW);
	latime = width;
	inaltime = height;

}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, target.x, target.y, target.z, 0, 1, 0);//eyex,eyey,eyez,targetx,targety,targetz,upx,upy,upz(inclin)
//teapot	
	//glTranslatef(4, 0, 0);	//inainte de desenat
	//glRotatef(alpha,vx,vy,vz);
	//glScalef(sx,sy,sz);

	//glutWireTeapot(1);
//cuburi	
	/*glPushMatrix();
		glTranslatef(5, 0, 0);
		glutWireCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 5, 0);
		glutWireCube(1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0, 0, 5);
		glutWireCube(1);
	glPopMatrix();*/

	glBegin(GL_QUADS); //mod de desenare: GL_TRIANGLES GL_TRIANGLE_STRIP GL_QUADS GL_QUAD_STRIP GL_LINES 
		//podea
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 0); //sau glVertex2f, glVertex4f
		glVertex3f(0, 0, 10);
		glVertex3f(10, 0, 10);
		glVertex3f(10, 0, 0);
		
		glNormal3f(0, 0, 1);
		//perete1
		glColor3f(0, 0, 0.6);
		glVertex3f(0, 5, 0);
		glVertex3f(0, 5, 10);
		glVertex3f(0, 0, 10);
		glVertex3f(0, 0, 0);
		
		glNormal3f(1, 0, 0);
		//perete2
		glColor3f(0, 0.2, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(10, 0, 0);
		glVertex3f(10, 5, 0);
		glVertex3f(0, 5, 0);
		
		glNormal3f(-1, 0, 0);
		//perete3
		glColor3f(0.6, 0, 0);
		glVertex3f(0, 0, 10);
		glVertex3f(0, 5, 10);
		glVertex3f(10, 5, 10);
		glVertex3f(10, 0, 10);

		glNormal3f(0, 0, -1);
		//usa
		glColor3f(0, 0.5, 0);
		glVertex3f(10, 5, 10);
		glVertex3f(10, 5, 0);
		glVertex3f(10, 3, 0);
		glVertex3f(10, 3, 10);
		glNormal3f(0, 0, -1);
		glVertex3f(10, 3, 10);
		glVertex3f(10, 3, 5.5);
		glVertex3f(10, 0, 5.5);
		glVertex3f(10, 0, 10);
		glNormal3f(0, 0, -1);
		glVertex3f(10, 0, 0);
		glVertex3f(10, 3, 0);
		glVertex3f(10, 3, 4.5);
		glVertex3f(10, 0, 4.5);
		

	glEnd();

	glPushMatrix();
		//cube
		glColor3f(0, 0, 1);
		glTranslatef(5, 1, 5);
		glutSolidCube(2);
		//teapot
		glColor3f(1, 0, 0);
		glRotatef(angle, 0, 1, 0);
		glTranslatef(0, 1.75, 0);
		glutSolidTeapot(1);
	glPopMatrix();

	/*glColor3f(1, 0, 0);
	glPushMatrix();
		glTranslatef(5, 3, 5);
		glutWireTeapot(1);
	glPopMatrix();*/


	glutSwapBuffers();

}

void initialize(void)
{
	glClearColor(0, 0, 0, 1); //r,g,b,alpha
	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_col);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_col);

	glEnable(GL_LIGHT0); //aprind lumina


	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	Gforce = createVector(0, -0.05, 0);
}

void applyMotion()
{
	Vector force = createVector(0, 0, 0);
	if (keystate['w']) {
		Vector dir, target1 = target;
		target1.y = eye.y;
		dir = substractVectors(target1, eye);
		Vector dir1 = normalizeVector(dir);
		Vector Step = multiplyVector(dir1, step);
		force = addVectors(force, Step);
	}
	if (keystate['d'])
	{
		Vector dir, target1 = target;
		target1.y = eye.y;
		dir = substractVectors(target1, eye);
		dir = rotateVector(dir, -90, 0, 1, 0);
		Vector dir1 = normalizeVector(dir);
		Vector Step = multiplyVector(dir1, step);
		force = addVectors(force, Step);
	}
	if (keystate['s'])
	{
		Vector dir, target1 = target;
		target1.y = eye.y;
		dir = substractVectors(target1, eye);
		Vector dir1 = normalizeVector(dir);
		Vector Step = multiplyVector(dir1, -step);
		force = addVectors(force, Step);
	}
	if (keystate['a'])
	{
		Vector dir, target1 = target;
		target1.y = eye.y;
		dir = substractVectors(target1, eye);
		dir = rotateVector(dir, 90, 0, 1, 0);
		Vector dir1 = normalizeVector(dir);
		Vector Step = multiplyVector(dir1, step);
		force = addVectors(force, Step);
	}
	if (keystate[' '] && jump != 1)
	{
		impuls = addVectors(impuls, createVector(0, 0.5, 0));
		eyeheight = eye.y;
		jump = 1;
	}

	force = addVectors(force, impuls);

	eye = addVectors(eye, force);
	target = addVectors(target, force);

	if (eye.y <= eyeheight)
	{
		impuls = createVector(0, 0, 0);
		eye.y = eyeheight;
		jump = 0;
	}
	else
	{
		impuls = addVectors(impuls, Gforce);
	}
}


void timer(int value) //rotirea ceainicului
{
	angle++;
	if (angle >= 360) angle = 0;

	printf("%f %f %f\n", eye.x, eye.y, eye.z);
	
	applyMotion();

	glutPostRedisplay();
	
	glutTimerFunc(2, timer, value + 1);
	
	glutWarpPointer(latime/2, inaltime/2);
}

void keyboard(unsigned char c, int x, int y) //tasta care se citeste, pozitia mouse-ului
{
	keystate[c] = 1;
	switch (c)
	{
		case 27:
			exit(0);
			break;
	}
}

GLfloat orizontala(int x)
{
	GLfloat unghi = -60 + (2 * (GLfloat)x * 60) / latime;
	return unghi;
}

GLfloat verticala(int y)
{
	GLfloat unghi = -30 + (2 * (GLfloat)y * 30) / inaltime;
	return unghi;
}

void motion(int x, int y)
{
	
	GLfloat angle1 = orizontala(x);
	GLfloat angle2 = verticala(y);
	//printf("%f %f\n", angle1, angle2);
	//anglev += angle2 / 1000;
	//if (anglev > 89) anglev = 89;
	//if (anglev < -89) anglev = -89;

	//rotatie sus-jos
	Vector dir = substractVectors(target, eye);
	Vector dir1 = dir;
	dir1.y = 0;
	dir1 = rotateVector(dir1, 90, 0, 1, 0);
	dir = rotateVector(dir, angle2 / 5, dir1.x, dir1.y, dir1.z);
	target = addVectors(eye, dir);
	//rotatie stanga-dreapta
	dir = substractVectors( target, eye);
	dir = rotateVector(dir, -angle1 / 5, 0, 1, 0);
	target = addVectors(eye, dir);


	
	 //if ((x != latime/2) && ( y != inaltime/2) )
}

void neapasat(unsigned char c, int x, int y)
{
	keystate[c] = 0;
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(700, 500);
	glutCreateWindow("fereastra");
	
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	
	initialize();
	
	eye.x = 2; eye.y = 2.5; eye.z = 2;
	target.x = 5; target.y = 2.5; target.z = 5;
	eyeheight = eye.y;

	glutTimerFunc(2, timer, 0);
	
	glutKeyboardFunc(keyboard);

	glutPassiveMotionFunc(motion);

	glutKeyboardUpFunc(neapasat);

	// glutKeyboardDownFunc(neapasat);
	
	glutMainLoop();
	
	return 0;
}
//compilare: -l nume_biblioteca (cauta nume_biblioteca.so)
// gcc [-g(debugging)] [-o output(numele outputului)] [-l(linkare biblioteci)<libraries>][-Wall(warnings all)] source
//gcc [-g][-o output][-l<libraries][-Wall]source
