#include<glut.h>
#include<stdio.h>

#include "tree.h"

float x=0.0,y=0.0;
int i;// counter
float j=0.3;// step size

void Create_branch(void)
{
	glPushMatrix();
	glRotatef(-50,0.0,1.0,0.0);
	glRotatef(50,1.0,0.0,0.0);
	glCallList(BRANCH);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-80,0.0,1.0,0.0);
	glRotatef(80,1.0,0.0,0.0);
	glCallList(BRANCH);
	glPopMatrix();

	glPushMatrix();
	glRotatef(80.0,1.0,1.0,0.0);
	glCallList(BRANCH);
	glPopMatrix();

	//****************************

	
	glPushMatrix();
	glRotatef(-250,1.0,1.0,0.0);
	glCallList(BRANCH);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-280.0,1.0,1.0,0.0);
	glCallList(BRANCH);
	glPopMatrix();

	
	glPushMatrix();
	glRotatef(-350,1.0,1.0,0.0);
	glCallList(BRANCH);
	glPopMatrix();
	
	
	//**********************

	glPushMatrix();
	glRotatef(-75,0.0,1.0,0.0);
	glRotatef(75,1.0,0.0,0.0);
	glCallList(BRANCH);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-60,0.0,1.0,0.0);
	glRotatef(60,1.0,0.0,0.0);
	glCallList(BRANCH);
	glPopMatrix();

}



void tree_display(void)
{

	glMatrixMode(GL_MODELVIEW);
//**********************************************

////TREES BESIDE THE ROAD
	glPushMatrix();
	glTranslatef(-2.0,-1.0,0.0);
	glScalef(.75,.75,0.0);
	glCallList(TREE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.0,-1.0,0.0);
	glScalef(.75,.75,0.0);
	glCallList(TREE);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(4.0,-1.0,0.0);
	glScalef(.75,.75,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-4.0,-1.0,0.0);
	glScalef(.75,.75,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-3.0,-1.0,0.0);
	glScalef(.75,.75,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(3.0,-1.0,0.0);
	glScalef(.75,.75,0.0);
	glCallList(TREE);
	glPopMatrix();


//*********************************************	
//trees beside the mountain
	glPushMatrix();
	glTranslatef(-1.50,.50,0.0);
	glScalef(.5,.3,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-2.50,.50,0.0);
	glScalef(.5,.3,0.0);
	glCallList(TREE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.50,.50,0.0);
	glScalef(.5,.3,0.0);
	glCallList(TREE);
	glPopMatrix();
	
	
	glPushMatrix();
	glTranslatef(-4.50,.50,0.0);
	glScalef(.5,.3,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(4.50,.50,0.0);
	glScalef(.5,.3,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(3.50,.50,0.0);
	glScalef(.5,.3,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(2.50,.50,0.0);
	glScalef(.5,.3,0.0);
	glCallList(TREE);
	glPopMatrix();

//**********************************************
//trees on the left mountain
	glPushMatrix();
	glTranslatef(-1.0,1.50,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();



	glPushMatrix();
	glTranslatef(-3.0,1.50,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.0,1.50,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();
	

	
	glPushMatrix();
	glTranslatef(-1.5,1.0,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(-4.0,1.5,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(2.0,1.50,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();


//**********************************************

//trees on the right mountain
	glPushMatrix();
	glTranslatef(1.0,.50,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0,.50,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();
		
	glPushMatrix();
	glTranslatef(1.5,1.0,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.0,.5,0.0);
	glScalef(.2,.1,0.0);
	glCallList(TREE);
	glPopMatrix();
	
//**********************************************
}


void tree_init()
{
//the list to draw one branch in the tree
glNewList(BRANCH,GL_COMPILE);
		
		//glColor3f(0.0,0.80,0.0);
		glColor3ub(0,157,0);
		for(i=0;i<=3;i+=1)
		{
			glBegin(GL_LINE_STRIP);
				glVertex2f(x-0.2,y+j);
				glVertex2f(x,y);
				glVertex2f(x+0.2,y+j);
				glVertex2f(x,y);
				glVertex2f(x,y+j);
			glEnd();

			y=y+j;
		}


glEndList();//end of branch display list
	
	
//the list to genetate a tree
glNewList(TREE,GL_COMPILE);
	
		
	x=0.0,y=0.0;
	
	//code tro draw the stem of the tree
	//glColor3f(.50,0.2,0.0);
	glColor3ub(138,69,0);
	glBegin(GL_POLYGON);
		glVertex2f(x-0.1,y);
		glVertex2f(x-0.1,y-2);
		glVertex2f(x+0.05,y-2);
		glVertex2f(x+0.05,y);
	glEnd();

	//function that draws the collection of branches
	Create_branch();
	
glEndList();
	
}

