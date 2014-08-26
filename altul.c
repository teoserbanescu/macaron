#include <stdio.h>
#include <GL/glut.h>

GLfloat light_pos[] = {5, 20, 5, 1};
GLfloat light_col[] = {1, 1, 1, 1};

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	gluLookAt(2, 2.5, 2, 10, 2.5, 5.5, 0, 1, 0);//eyex,eyey,eyez,targetx,targety,targetz,upx,upy,upz(inclin)
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
		glColor3f(0, 0, 1);
		glTranslatef(5, 1, 5);
		glutSolidCube(2);
		glColor3f(1, 0, 0);
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

	glutMainLoop();
	
	return 0;
}
//compilare: -l nume_biblioteca (cauta nume_biblioteca.so)
// gcc [-g(debugging)] [-o output(numele outputului)] [-l(linkare biblioteci)<libraries>][-Wall(warnings all)] source
//gcc [-g][-o output][-l<libraries][-Wall]source
