#include <glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#include "nurbs.h"
#define MAX_SUN_ROTATION_ANGLE 150
#define FIRST_QUARTER (1/4)
#define SUN_MORNING_QUARTER (FIRST_QUARTER*MAX_SUN_ROTATION_ANGLE)
#define SUN_EVENING_QUARTER ((1-FIRST_QUARTER)*MAX_SUN_ROTATION_ANGLE)

//static int a=0;
int light = 1;
void init_surface(void)
{
	int u, v;
	for (u = 0; u < 4; u++)
	{
		for (v = 0; v < 4; v++)
		{
			ctlpoints[u][v][0] = 2.0*((GLfloat)u - 1.5);
			ctlpoints[u][v][1] = 2.0*((GLfloat)v - 1.5);
			if ( (u == 1 || u == 2) && (v == 1 || v == 2))
				ctlpoints[u][v][2] = 3.0;
			else
				ctlpoints[u][v][2] = -3.0;
		}

	}
}


void nurb_init(void)
{
	init_surface();
	theNurb = gluNewNurbsRenderer();
	gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 25.0);
	gluNurbsProperty(theNurb, GLU_DISPLAY_MODE, GLU_FILL);

//defining the display list here
glNewList(NURB_DISPLAY_LIST,GL_COMPILE_AND_EXECUTE);

	//to draw the nurb surface
	glColor3f(0.0,1.0,0.0);
	glColorMaterial(GL_FRONT_AND_BACK,GL_EMISSION);
	glEnable(GL_COLOR_MATERIAL);
	GLfloat knots[8] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0};
	gluBeginSurface(theNurb);
	gluNurbsSurface(theNurb,8, knots, 8, knots,4 * 3, 3, &ctlpoints[0][0][0],4, 4, GL_MAP2_VERTEX_3);
	gluEndSurface(theNurb);

glEndList();	

}


void nurb_display(void)
{
	glMatrixMode(GL_MODELVIEW);
	
	GLfloat position[]={-2.0,-2.0,-2.0,1.0};

	//to rotate the solid sphere sun
	glPushMatrix();
    glRotatef((GLfloat)year,0.0,0.0,1.0);
	glTranslatef(-5.0,1.5,0.0);	
	
//code to decide the type of color of the sun
	if(light==1)
	{
		if(-rotateAngle<=(SUN_MORNING_QUARTER))
		{
			//a++;
			//glColor3ub(255,0,120);
			glColor3ub(232,33,4);
		}
		else if(-rotateAngle>(SUN_MORNING_QUARTER ) && -rotateAngle<(3*SUN_EVENING_QUARTER ))
		{
			//a++;
			//glColor3ub(255,255,0);
			glColor3ub(232,197,4);
		}
		else if(-rotateAngle>(3*SUN_EVENING_QUARTER ))
		{
			//a++;
			//glColor3f(255,0,120);
			glColor3ub(232,33,4);
		}
		else
		{
			//a=0;
			glColor3f(1.0,0.0,0.0);
		}
	}


	else if(light!=1)
	{
			glColor3ub(255,255,255);
	}
	
	glutSolidSphere(0.3,30,8);
	glPopMatrix();

//to rotate the light source
	glPushMatrix();
	glRotatef((GLfloat)year,0.0,0.0,1.0);
	glTranslatef(-4.5,1.50,0.0);
	glLightfv(GL_LIGHT0,GL_POSITION,position);
	glPopMatrix();

//to rotate the wire cube
	glPushMatrix();
	glRotatef((GLfloat)year,0.0,0.0,1.0);
	glTranslated(-4.5,1.50,0.0);
	glDisable(GL_LIGHTING);
	glColor3f(1.0,1.0,1.0);
	glutWireCube(0.1);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glColor3f(0.0,1.0,0.0);
	glColorMaterial(GL_FRONT_AND_BACK,GL_EMISSION);
	glEnable(GL_COLOR_MATERIAL);


//to display the 1st nurb as a mountain by using display list.
	glPushMatrix();
	glRotatef(-90.0, 1.,0.,0.);
	glTranslatef(-2.5,4.0,2.0);
	glCallList(NURB_DISPLAY_LIST);
	glPopMatrix();

//to display the 2nd nurb as a mountain by using display list.
	glPushMatrix();
	glRotatef(-90.0, 1.,0.,0.);
	glTranslatef(2.5,4.0,2.0);
	glCallList(NURB_DISPLAY_LIST);
	glPopMatrix();

}


void nurb_idle(void)
{
	//year=(year-1)%150;
	//year = year - 0.25;
	if(-year >= MAX_SUN_ROTATION_ANGLE)
		year = 0;//Start the SUN from original position, after rotating it by 150 degrees..

	year = year - 0.25;//This is negative for anti-clockwise rotation of SUN
	rotateAngle = (int)(year)%MAX_SUN_ROTATION_ANGLE;//This is negative for anti-clockwise rotation of SUN
}
