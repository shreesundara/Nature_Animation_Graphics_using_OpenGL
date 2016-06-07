#include<glut.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define BIRDS 4

#include "nurbs.h"

#include "tree.h"
extern int light;

void mymenu(int id)
{
	switch(id)
	{
		case 1:exit(0);
			   break;

		case 2:light=0;
			   break;

		case 3:light=1;
			   break;
        
		case 4:showPoints=1;
			    break;

	     case 5:showPoints=0;
			    break;
      }

	glutPostRedisplay();
}


void river()
{

//TO DISPLAY THE RIVER
	glColor3ub(16,166,255);//1st tri
	glBegin(GL_POLYGON);
		glVertex2f(-5.0,-5.0);
		glVertex2f(-5.0,-2.0);
		glVertex2f(5.0,-2.0);
		glVertex2f(5.0,-5.0);
	glEnd();
}

void road()
{
//code which calls the display list to render the birds	
//*****************************
glPushMatrix();
glCallList(BIRDS);
glPopMatrix();

glPushMatrix();
glTranslatef(0.3,.30,0.30);
glCallList(BIRDS);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.35,-.20,0.30);
glCallList(BIRDS);
glPopMatrix();

glPushMatrix();
glTranslatef(0.4,.15,0.30);
glCallList(BIRDS);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.2,-.250,0.30);
glCallList(BIRDS);
glPopMatrix();

//************************************

//FIRST DIVEDER
	glColor3ub(255,255,255);//1st tri
	glBegin(GL_POLYGON);
		glVertex2f(-4.0,-1.0);
		glVertex2f(-4.0,-1.2);
		glVertex2f(-2.0,-1.2);
		glVertex2f(-2.0,-1.);
	glEnd();

//SECOND DIVEDER
	glColor3ub(255,255,255);//1st tri
	glBegin(GL_POLYGON);
		glVertex2f(-1.0,-1.0);
		glVertex2f(-1.0,-1.2);
		glVertex2f(1.0,-1.2);
		glVertex2f(1.0,-1.0);
	glEnd();
	
//THIRD DIVEDER
	glColor3ub(255,255,255);//1st tri
	glBegin(GL_POLYGON);
		glVertex2f(4.0,-1.0);
		glVertex2f(4.0,-1.2);
		glVertex2f(2.0,-1.2);
		glVertex2f(2.0,-1.0);
	glEnd();

glDisable(GL_LIGHTING);

//THE ROAD
	glColor3ub(192,192,192);//1st tri
	glBegin(GL_POLYGON);
		glVertex2f(-5.0,0.0);
		glVertex2f(-5.0,-2.0);
		glVertex2f(5.0,-2.0);
		glVertex2f(5.0,0.0);
	glEnd();
	glEnable(GL_LIGHTING);
}


void disp(void)
{	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	GLfloat mat_diffuse[] = { .5, .0, 0.0, 1.0 };
	GLfloat mat_emmissive[] = { .7, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { .7,0.,.0, 1.0 };
	GLfloat mat_specular[] = { 1., 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 7.0 };
	
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mat_emmissive);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);	

	glColor3f(0.0,1.0,0.0);
	glColorMaterial(GL_FRONT_AND_BACK,GL_EMISSION);
	glEnable(GL_COLOR_MATERIAL);

	if(light==1)		
   	{
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glClearColor(.70,.80,1.0,1.0);
	}
	  else if(light!=1)
  	{
	  glDisable(GL_LIGHTING);
	  glDisable(GL_LIGHT0);
	  glClearColor(.0,.0,.0,.0);
	}

	river();

	tree_display();

	road();

	if (showPoints)
	{
		glPointSize(5.0);
		glDisable(GL_LIGHTING);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POINTS);
		int i,j;
		for (i = 0; i < 4; i++)
		 {
			for (j = 0; j < 4; j++)
			{
				glVertex3f(ctlpoints[i][j][0],
				ctlpoints[i][j][1], ctlpoints[i][j][2]);
			}
		}
		glEnd();
		glEnable(GL_LIGHTING);
	}

	nurb_display();

	glFlush();
}

void idle(void)
{
	nurb_idle();
	glutPostRedisplay();
		
}

void init(void)
{
	nurb_init();

	tree_init();
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(636,380);
	glutInitWindowPosition(0,0);
	glutCreateWindow("NATURE ANIMATION");
	glClearColor(.0,.0,.0,1.0);
	glEnable(GL_DEPTH_TEST);
	glOrtho(-05.0,05.0,-05.0,05.0,-05.0,05.0);//for 10 it doesn't work
	init();
	glutDisplayFunc(disp);
	glutIdleFunc(idle);
	
//****************************
//display list for birds
glNewList(BIRDS,GL_COMPILE_AND_EXECUTE);

//BIRDS
	glColor3ub(255,255,255);
	glBegin(GL_LINE_STRIP);
		glVertex2f(0.8,2.15);
		glVertex2f(1,2);
		glVertex2f(1.2,2.15);
	glEnd();
	
glEndList();
	
//*************defining the menus
	
	glutCreateMenu(mymenu);
	glutAddMenuEntry("QUIT",1);
	glutAddMenuEntry("(NIGHT) SWITCH OFF LIGHTING EFFECTS",2);
	glutAddMenuEntry("(DAY) SWITCH ON  LIGHTING EFFECTS",3);
	glutAddMenuEntry("SHOW CONTROL POINTS",4);
	glutAddMenuEntry("DO NOT SHOW CONTROL POINTS",5);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();

	return 0;
}