#include <stdio.h>
#include <GL/glut.h>

void Reshape(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei) width, (GLsizei) height); //coord colt stanga si dimensiunile
	gluPerspective(60, (GLfloat) width / (GLfloat) height, 0.1, 600000);//unghiul de deschidere al conului,raportul dim, dist de la ochi la con, total
	glMatrixMode(GL_MODELVIEW);

}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(10, 10, 10, 0, 0, 0, 0, 1, 0);//eyex,eyey,eyez,targetx,targety,targetz,upx,upy,upz(inclin)
	
	//glTranslatef(4, 0, 0);	//inainte de desenat
	//glRotatef(alpha,vx,vy,vz);
	//glScalef(sx,sy,sz);

	//glutWireTeapot(1);
	glPushMatrix();
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
	glPopMatrix();
	
	glutSwapBuffers();

}

void initialize(void)
{
	glClearColor(0, 0, 0, 1); //r,g,b,alpha
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(700, 500);
	glutCreateWindow("fereastra");
	
	glutReshapeFunc(Reshape);
	glutDisplayFunc(Display);
	
	initialize();

	glutMainLoop();
	
	return 0;
}
//compilare: -l nume_biblioteca (cauta nume_biblioteca.so)