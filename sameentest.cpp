#include<bits/stdc++.h>
#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
///For music
#include <Mmsystem.h>
#include<windows.h>
#include<fstream>

using namespace std;
#pragma comment(lib, "Winmm.lib")
#define int GLint
#define PI 3.1416


float cpos1=200,cpos2=400,cpos3=-250,cpos4=50,cpos5=490,sp1=0.6f,bul=0, tpos = 500, jpos = 500, tankpos = 0, rpos = 2;
float sun_x=450 ,sun_y=480,sp_x=0.5f,sp_y=0.7f,plane_x=0.0f, plane_speed=4.0f,_rain = 0.0, truckSpeed = 1.0f, jeepSpeed = 2.0f, tankSpeed = 1.0f;

bool rainday = false, day = true,fire=true, night = false;
float TruckTireRotateAngle = 0.0f;
int _TruckMoveReverse = 0;

//toggle day night
void timeCheck()
{
    if (night) day = 0;
    else if(day) night = 0;
}

///Circle
void circle(GLfloat x, GLfloat y, GLfloat rad){
    GLint triangle_amt=60,i;
    GLfloat t_pi=2*PI;
    glBegin(GL_TRIANGLE_FAN);
    //glColor3ub(43,78,88);
    glVertex2f(x,y);
    for(i=0;i<=triangle_amt;i++){
        GLfloat dx=rad*cos(i*t_pi/triangle_amt), dy=rad*sin(i*t_pi/triangle_amt);
        glVertex2f(x+dx,y+dy);
    }
    glEnd();
}
///Cloud Model-1 Structure
void cloudModel1(){
    if(day)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();

   glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();

    glPopMatrix();

}
///Cloud Model-2 Structure
void cloudModel2(){
    if(day)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
}
///Cloud Model-3 Structure
void cloudModel3(){

    if(day)glColor3f(1.25,0.924,0.930);
    else glColor3ub(54,74,156);

    glPushMatrix();
    glPushMatrix();
    circle(305,205,10);///Left
    circle(320,210,15);///Top
    circle(334,207,10);///Right
    circle(320, 207, 10);///Bottom
    glPopMatrix();
    glPopMatrix();
}

///Sky
void sky(){
    glPushMatrix();
    if(day)glColor3ub(199,214,224);
    else glColor3ub(24,50,100);

    glBegin(GL_POLYGON);
    glVertex2i(0,300);
    glVertex2i(1000,300);
    if (day) glColor3ub(166,199,222);
    else glColor3ub(0,3,7);
    glVertex2i(1000,500);
    glVertex2i(0,500);
    glEnd();
    glPopMatrix();
}



void tilla1(){

	glBegin(GL_POLYGON);
	glColor3ub(20,35,27);

	glVertex2i(0, 300);
	glVertex2i(300, 300);
	glVertex2i(150, 370);
glEnd();
}

void tilla2(){
     glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(20,35,27);

	glVertex2i(250, 300);
	glVertex2i(550, 300);
	glVertex2i(400, 380);


	glEnd();
	glPopMatrix();
}

void tilla3(){
     glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(20,40,20);

	glVertex2i(500, 300);
	glVertex2i(750, 300);
	glVertex2i(650, 370);


	glEnd();
	glPopMatrix();
}
void tilla4(){
     glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3ub(34,55,20);

	glVertex2i(700, 300);
	glVertex2i(1000, 300);
	glVertex2i(900, 380);


	glEnd();
	glPopMatrix();
}
///Sun
void sun(){
    if(day){
        glPushMatrix();
        glColor3ub(252, 212, 64);
        glTranslatef(sun_x,sun_y,0.0);
        circle(0,0,30);
        glPopMatrix();
    }
}
///Moon
void moon(){
    if(!day){
        glPushMatrix();

        glColor3ub(255, 255, 255);
        glTranslatef(0.0,100.0,0.0);
        circle(320,360,20);
        glColor3ub(4, 11, 51);
        circle(320,380,15);
        glPopMatrix();
    }
}
///Star
void star(){
    if(!day){
        glPushMatrix();
        glColor3ub(255,255,255);
        glPointSize(4);
        glBegin(GL_POINTS);

        glVertex2i(100,400);
        glVertex2i(120,420);
        glVertex2i(150,450);
        glVertex2i(170,470);
        glVertex2i(200,430);
        glVertex2i(230,470);
        glVertex2i(350,460);
        glVertex2i(900,400);
        glVertex2i(580,470);
        glVertex2i(840,460);
        glVertex2i(750,400);
        glVertex2i(950,400);
        glVertex2i(760,420);
        glVertex2i(690,450);
        glVertex2i(550,470);
        glVertex2i(790,430);
        glVertex2i(830,470);
        glVertex2i(690,460);
        glVertex2i(590,400);
        glVertex2i(490,430);
        glVertex2i(330,470);
        glVertex2i(390,460);
        glVertex2i(460,400);
        glVertex2i(390,360);
        glVertex2i(930,370);
        glVertex2i(30,370);
        glVertex2i(290,360);
        glVertex2i(60,360);
        glEnd();

        glPopMatrix();
    }
}

///cloud1
void cloud1(){

        glPushMatrix();
        glTranslatef(cpos1,170,0);
         glTranslatef(50,50,0);
        cloudModel1();
        glPopMatrix();

}
///cloud2
void cloud2(){
    if(day){
        glPushMatrix();
        glTranslatef(cpos2,270,0);
         glTranslatef(25,0,0);
        cloudModel2();
        glPopMatrix();
    }
}
///cloud3
void cloud3(){

        glPushMatrix();
        glTranslatef(cpos3,200,0);
         glTranslatef(-50,50,0);
        cloudModel3();
        glPopMatrix();

}
///cloud4
void cloud4(){
    glPushMatrix();
    glTranslatef(cpos4,250,0);
     glTranslatef(-50,20,0);
    cloudModel2();
    glPopMatrix();
}

///cloud5
void cloud5(){
    glPushMatrix();
    glTranslatef(cpos5,220,0);
     glTranslatef(-25,25,0);
    cloudModel1();
    glPopMatrix();
}

///Airplane Design
void airPlane(){
    glPushMatrix();
    glTranslatef(plane_x,370,0);

    glPushMatrix();
    glTranslatef(0,75,0);
    ///body
    glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON); //rectangular body
        glVertex2f(0.0, 30.0*0.4);
        glVertex2f(0.0, 55.0*0.4);
        glVertex2f(135.0*0.4, 55.0*0.4);
        glVertex2f(135.0*0.4, 30.0*0.4);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POLYGON); //upper triangle construction plane
        glVertex2f(135.0*0.4, 55.0*0.4);
        glVertex2f(150.0*0.4, 50.0*0.4);
        glVertex2f(155.0*0.4, 45.0*0.4);
        glVertex2f(160.0*0.4, 40.0*0.4);
        glVertex2f(135.0*0.4, 40.0*0.4);
        glEnd();

        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINE_LOOP); //outline of upper triangle plane
        glVertex2f(135.0*0.4, 55.0*0.4);
        glVertex2f(150.0*0.4, 50.0*0.4);
        glVertex2f(155.0*0.4, 45.0*0.4);
        glVertex2f(160.0*0.4, 40.0*0.4);
        glVertex2f(135.0*0.4, 40.0*0.4);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON); //lower triangle
        glVertex2f(135.0*0.4, 40.0*0.4);
        glVertex2f(160.0*0.4, 40.0*0.4);
        glVertex2f(160.0*0.4, 37.0*0.4);
        glVertex2f(145.0*0.4, 30.0*0.4);
        glVertex2f(135.0*0.4, 30.0*0.4);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON); //back wing
        glVertex2f(0.0, 55.0*0.4);
        glVertex2f(0.0, 80.0*0.4);
        glVertex2f(10.0*0.4, 80.0*0.4);
        glVertex2f(40.0*0.4, 55.0*0.4);
        glEnd();
        // glPopMatrix();

        // glPushMatrix();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON); //left side wing
        glVertex2f(65.0*0.4, 55.0*0.4);
        glVertex2f(50.0*0.4, 70.0*0.4);
        glVertex2f(75.0*0.4, 70.0*0.4);
        glVertex2f(90.0*0.4, 55.0*0.4);
        glEnd();

        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POLYGON); //rightside wing
        glVertex2f(70.0*0.4, 40.0*0.4);
        glVertex2f(100.0*0.4, 40.0*0.4);
        glVertex2f(80.0*0.4, 15.0*0.4);
        glVertex2f(50.0*0.4, 15.0*0.4);

        glEnd();
glPopMatrix();
    glPopMatrix();


}
void field(){
glPushMatrix();

    if(day) glColor3ub(120, 130, 59);
    else glColor3ub(28,52,45);

    glBegin(GL_POLYGON);
    glVertex2i(0,0);
    glVertex2i(1000,0);
    if(day) glColor3ub(170,170,120);
    else glColor3ub(40,70,50);
    glVertex2i(1000,300);
    glVertex2i(0,300);
    glEnd();
    glPopMatrix();



}
void treemodel(){
    if(day) glColor3ub(0, 173, 36);
    else glColor3ub(17, 102, 30);
    circle(130,130,7);
    circle(125,126,7);
    circle(135,126,7);
    circle(130,125,7);

    glColor3ub(2, 41, 10);
    glBegin(GL_POLYGON);
    glVertex2i(129,104);
    glVertex2i(129,126);
    glVertex2i(131,126);
    glVertex2i(131,104);
    glEnd();
}
void tree1(){
    glPushMatrix();
    glTranslatef(-100,195,0);
    treemodel();
    glPopMatrix();
}
 void tree2(){
    glPushMatrix();
    glTranslatef(100,195,0);
    treemodel();
    glPopMatrix();
}
 void tree3(){
    glPushMatrix();
    glTranslatef(120,195,0);
    treemodel();
    glPopMatrix();
}

void tree4(){
    glPushMatrix();
    glTranslatef(-80,195,0);
    treemodel();
    glPopMatrix();
}
void tree5(){
    glPushMatrix();
    glTranslatef(-60,195,0);
    treemodel();
    glPopMatrix();
}
void tree6(){
    glPushMatrix();
    glTranslatef(300,195,0);
    treemodel();
    glPopMatrix();
}
void tree7(){
    glPushMatrix();
    glTranslatef(320,195,0);
    treemodel();
    glPopMatrix();
}
void tree8(){
    glPushMatrix();
    glTranslatef(340,195,0);
    treemodel();
    glPopMatrix();
}
void tree9(){
    glPushMatrix();
    glTranslatef(360,195,0);
    treemodel();
    glPopMatrix();
}
void tree10(){
    glPushMatrix();
    glTranslatef(380,195,0);
    treemodel();
    glPopMatrix();
}

void tree11(){
    glPushMatrix();
    glTranslatef(540,195,0);
    treemodel();
    glPopMatrix();
}
 void tree12(){
    glPushMatrix();
    glTranslatef(560,195,0);
    treemodel();
    glPopMatrix();
}
 void tree13(){
    glPushMatrix();
    glTranslatef(580,195,0);
    treemodel();
    glPopMatrix();
}

void tree14(){
    glPushMatrix();
    glTranslatef(620,195,0);
    treemodel();
    glPopMatrix();
}
void tree15(){
    glPushMatrix();
    glTranslatef(640,195,0);
    treemodel();
    glPopMatrix();
}
void tree16(){
    glPushMatrix();
    glTranslatef(680,195,0);
    treemodel();
    glPopMatrix();
}
void tree17(){
    glPushMatrix();
    glTranslatef(700,195,0);
    treemodel();
    glPopMatrix();
}
void tree18(){
    glPushMatrix();
    glTranslatef(720,195,0);
    treemodel();
    glPopMatrix();
}
void tree19(){
    glPushMatrix();
    glTranslatef(800,195,0);
    treemodel();
    glPopMatrix();
}
void tree20(){
    glPushMatrix();
    glTranslatef(820,195,0);
    treemodel();
    glPopMatrix();
}

void Hill()
{
    glPushMatrix();
        //glTranslatef(0,0,0);
        //glMatrixMode(GL_MODELVIEW);
        glBegin(GL_POLYGON);


        glColor3ub(0,0,0);          //hill-1

        glVertex2i(0,550);
        glVertex2i(350,550);
        glVertex2i(320,615);
        glVertex2i(290,625);
        glVertex2i(260,595);
        glVertex2i(210,615);
        glVertex2i(170,595);
        glVertex2i(140,625);
        glVertex2i(110,635);
        glVertex2i(90,555);
        glVertex2i(40,595);
        glVertex2i(10,555);
        glEnd();
    glPopMatrix();
}

void Jeep()
{

    glPushMatrix();

    glTranslatef(0.0, 0.0, 0.0);
    if (day)
    glColor3ub(210,180,140);    //Jeep
    //glColor4f(0, 7, 18, 29);
    if(!day)
        glColor3ub(73,64,49);

    glBegin(GL_TRIANGLES);      //Jeep

    glVertex2i(290,170);
    glVertex2i(270,220);
    glVertex2i(270,175);

    glEnd();

    glBegin(GL_QUADS);



    glVertex2i(100,130);
    glVertex2i(130,130);
    glVertex2i(130,220);
    glVertex2i(100,220);

    glVertex2i(130,130);        //Tire Cut 1
    glVertex2i(150,150);
    glVertex2i(150,220);
    glVertex2i(130,220);

    glVertex2i(150,150);
    glVertex2i(180,150);
    glVertex2i(180,220);
    glVertex2i(150,220);

    glVertex2i(180,150);
    glVertex2i(200,130);       //Tire Cut 1
    glVertex2i(200,220);
    glVertex2i(180,220);


    glVertex2i(200,130);
    glVertex2i(270,130);
    glVertex2i(270,220);
    glVertex2i(200,220);

    glVertex2i(270,130);       //Tire Cut 2
    glVertex2i(290,150);
    glVertex2i(290,185);
    glVertex2i(270,190);

    glVertex2i(290,150);
    glVertex2i(320,150);
    glVertex2i(320,180);
    glVertex2i(290,185);

    glVertex2i(320,150);       //Tire Cut 2
    glVertex2i(340,130);
    glVertex2i(340,175);
    glVertex2i(320,180);


    glVertex2i(340,130);
    glVertex2i(360,130);
    glVertex2i(360,170);
    glVertex2i(340,175);

    if(day)
    glColor3ub(229,203,144);
    if(!day)
        glColor3ub(67,59,46);

    glVertex2i(210,135);           // Door
    glVertex2i(265,135);
    glVertex2i(265,215);
    glVertex2i(210,215);

    glColor3ub(8, 69, 112);
    glVertex2i(215,180);           // Door Window
    glVertex2i(260,180);
    glVertex2i(260,210);
    glVertex2i(215,210);




    glVertex2i(140,180);
    glVertex2i(190,180);
    glVertex2i(190,210);
    glVertex2i(140,210);

    glEnd();
    glPopMatrix();


    glPushMatrix();

    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);            //back tire wheel
    glColor3ub(104, 110, 105);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*30,135+sin(angle)*25);
    }

    glEnd();

    glPopMatrix();


    glPushMatrix();

    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);        //back tire inner
    glColor3ub(31, 36, 32);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*19,135+sin(angle)*17);
    }

    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);        //back tire middle
    glColor3ub(153, 144, 95);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(165+cos(angle)*9,135+sin(angle)*9);
    }

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0.0);

    glBegin(GL_POLYGON);        //front wheel out
    glColor3ub(104, 110, 105);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*30,135+sin(angle)*25);
    }

    glEnd();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,0,0.0);


    glBegin(GL_POLYGON);
    glColor3ub(31, 36, 32);         //front tire in
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*19,135+sin(angle)*17);
    }

    glEnd();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,0);      //front tire middle

    glBegin(GL_POLYGON);
    glColor3ub(153, 144, 95);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(305+cos(angle)*9,135+sin(angle)*9);
    }

    glEnd();

    glPopMatrix();


    glBegin(GL_QUADS);

    glVertex2i(205,170);
    glVertex2i(220,170);
    glVertex2i(220,175);
    glVertex2i(205,175);

    glEnd();


    glBegin(GL_QUADS);

    glVertex2i(100,175);
    glVertex2i(110,175);
    glVertex2i(110,220);
    glVertex2i(100,220);

    glEnd();



    glBegin(GL_QUADS);

    glVertex2i(122,155);
    glVertex2i(132,155);
    glVertex2i(132,165);
    glVertex2i(122,165);


    glEnd();



}
void ScaledJeep()
{
    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glScalef(0.6,0.6,0);
    glTranslatef(1500,130,0);
    glTranslatef(jpos,0,0);

  glScalef(-0.9,1.0,0.0);
    Jeep();
    glPopMatrix();

//    glPushMatrix();
//    glTranslatef(jpos,0,0);
//    //glTranslatef(200,122,0);
//    //glScalef(0.9,0.4,0);
//    //rocket();
//    glPopMatrix();

    glPopMatrix();

}

void tank()
{
    //tank-start

    //tankbody1

   glBegin(GL_POLYGON);
    glColor3ub(50,56,6);
    glVertex2i(525,325);
    glVertex2i(535,325);
    glVertex2i(715,325);
    glVertex2i(725,325);
    glVertex2i(715,360);
    glVertex2i(535,360);

    glEnd();

    //tankbody2

    glBegin(GL_QUADS);
    glVertex2i(565,350);
    glVertex2i(675,350);
    glVertex2i(675,390);
    glVertex2i(565,390);
    //tankhead

    glColor3ub(34,36,34);
    glVertex2i(600,390);
    glVertex2i(640,390);
    glVertex2i(640,400);
    glVertex2i(600,400);

     //tankgun
     glColor3ub(34, 36, 34);
    glVertex2i(675,365);
    glVertex2i(755,370);
    glVertex2i(755,380);
    glVertex2i(675,385);

    glEnd();



    //tankbase

    glBegin(GL_POLYGON);
  glColor3ub(79,68,31);
  for(int i=180;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(625+cos(angle)*90,325+sin(angle)*35);
    }
    glEnd();

    //wheel-1

      glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(555+cos(angle)*10,315+sin(angle)*10);
    }
    glEnd();


//wheel-2
  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;
    glVertex2f(690+cos(angle)*10,315+sin(angle)*10);

    }
    glEnd();

//whell3
      glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(583+cos(angle)*10,310+sin(angle)*10);

    }
    glEnd();


//wheel-4
  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(611+cos(angle)*10,305+sin(angle)*10);

    }

    glEnd();

    //wheel-5

  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(639+cos(angle)*10,305+sin(angle)*10);

    }

    glEnd();
    //whell-6

  glBegin(GL_POLYGON);
      glColor3ub(22, 23, 22);
     for(int i=0;i<=360;i++)
    {
        float angle= i*3.1416/180;

    glVertex2f(667+cos(angle)*10,306+sin(angle)*10);
    }

    glEnd();               //tank-end
    glPopMatrix();

}
void ScaledTank()
{
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glTranslatef(1600,100,0);
    glScalef(-0.7,0.7,0);
    glTranslatef(tankpos,-150,0);
    tank();
    glPopMatrix();
    glPopMatrix();

}

void tank2()
{
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    glTranslatef(1600,100,0);
    glScalef(-0.8,0.8,0);
    glTranslatef(tankpos,-250,0);
    tank();
    glPopMatrix();
    glPopMatrix();
}



void TruckTire(int xx, int yy, float r)//C029//H103
{
    glMatrixMode(GL_MODELVIEW);
 glPushMatrix();
glTranslatef(0.0f,0.0f,0.0f);
glRotatef(TruckTireRotateAngle, 0.0f, 0.0f,1.0f);
glTranslatef(-0.0f,-0.0f,0.0f);
glBegin(GL_POLYGON); // Draw a Red 1x1 Square centered at origin
    for (int i = 0; i < 200; i++)
    {

        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;

        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xx, y + yy);
    }
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,0,0);//black-rim
    glVertex2f(-0.075,0);
    glVertex2f(0.075,0);

    glVertex2f(-0.05,-0.075);
    glVertex2f(0.05,0.075);

    glVertex2f(0.05,-0.075);
    glVertex2f(-0.05,0.075);

    glVertex2f(0,-0.1);
    glVertex2f(0,0.1);

    glEnd();

    glPopMatrix();

}
void TruckScaledTire()
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(140.1,95,0);
    glScalef(90,90,0);
    glColor3ub(0,0,0);//black-tire
    TruckTire(0, 0, 0.2);
    glColor3ub(192,192,192);//silver-tire-rim
    TruckTire(0,0,0.13);
    glColor3ub(211,211,255);//grey-tire-rim
    TruckTire(0,0,0.09);
    glPopMatrix();
}

void TruckBody()
{

    glColor3ub(128,128,0);//blue-body

    //glPushMatrix();

    //glTranslatef(tpos, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(240, 127);
    glVertex2f(240, 92);
    glVertex2f(150,92);
    glEnd();

    glBegin(GL_POLYGON);//trolly
    glVertex2f(150, 129);
    glVertex2f(60,129);
    glVertex2f(60,92);
    glVertex2f(150,92);
    glEnd();
     glBegin(GL_POLYGON);//trolly-cargo
     glColor3ub(169, 120, 53);//brown
    glVertex2f(70,129);
    glVertex2f(100,129);
    glVertex2f(100, 152);
    glVertex2f(70,152);
    glEnd();

    glColor3ub(9, 12, 53);//black
     //text(90.0,130.0,text3);
    glBegin(GL_POLYGON); //back-light
    glColor3ub(255, 0, 0);
    glVertex2f(110-50, 92);
    glVertex2f(115-50, 92);
    glVertex2f(115-50, 117);
    glVertex2f(110-50, 117);
    glEnd();

    glBegin(GL_POLYGON); //window
    glColor3ub(0, 0, 0);//black-window-in-day
    if(!day)
    glColor3ub(163, 228, 215);//gray-window-in-night
    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(150, 127);
    glVertex2f(130, 127);
    glEnd();





    glBegin(GL_POLYGON); //window-Divider
    glColor3ub(192, 192, 192);
    glVertex2f(170, 152);
    glVertex2f(165, 152);
    glVertex2f(165, 127);
    glVertex2f(170, 127);
    glEnd();



    glBegin(GL_POLYGON); //roof-plate
    glColor3ub(168, 169, 173);

    glVertex2f(150, 152);
    glVertex2f(190, 152);
    glVertex2f(185, 157);
    glVertex2f(150, 157);
    glEnd();

    glBegin(GL_POLYGON); //window-holder-front
    glColor3ub(168, 169, 173);
    glVertex2f(190, 152);
    glVertex2f(215, 127);
    glVertex2f(210, 127);
    glVertex2f(185, 152);
    glEnd();

    glBegin(GL_POLYGON); //window-holder-back
    glColor3ub(168, 169, 173);
    glVertex2f(140+20-10, 157);
    glVertex2f(115+20, 127);
    glVertex2f(125+20, 127);
    glVertex2f(140+20-10, 152);
    glEnd();

    glBegin(GL_POLYGON); //foot-holder
    glColor3ub(168, 169, 173);
    glVertex2f(242, 92);
    glVertex2f(60, 92);
    glVertex2f(60, 97);
    glVertex2f(242, 97);

    glEnd();

    glBegin(GL_POLYGON);      //mirror
    glColor3f(0, 0, 0.1373);
    glVertex2f(211.5, 134.5);
    glVertex2f(204.5, 135.5);
    glVertex2f(203.5, 129);
    glVertex2f(210.5, 127);
    glEnd();

    glBegin(GL_POLYGON);      //Yellow-headlight
    glColor3f(1.0, 1.0, 0.0); //body
    glVertex2f(210.5+28, 134.5-10);
    glVertex2f(203.5+28, 135.5-10);
    glVertex2f(203.5+28, 129-10);
    glVertex2f(210.5+28, 127-10);
    glEnd();
    if(!day)
    {
        glBegin(GL_POLYGON);      //Yellow-headlight
        glColor3f(1.0, 1.0, 1.0); //body
        glVertex2f(210.5+28+90, 134.5-10-0);
        glVertex2f(205.5+28, 134.5-10);
        glColor3f(0.8, 0.9, 0.0);
        glVertex2f(205.5+28, 127-10);
        glVertex2f(210.5+28+90, 127-10-30);
        glEnd();

    }

    glBegin(GL_POLYGON); //window-opener-1
    glColor3ub(192, 192, 192);
    glVertex2f(150-15-5+20, 127-5-3);
    glVertex2f(155-5-5+20, 127-5-3);
    glVertex2f(155-5-5+20, 129-5);
    glVertex2f(150-15-5+20, 129-5);
    glEnd();
    glBegin(GL_POLYGON); //window-opener-2
    glColor3ub(192, 192, 192);
    glVertex2f(150-15+40, 127-5-3);
    glVertex2f(155-5+40, 127-5-3);
    glVertex2f(155-5+40, 129-5);
    glVertex2f(150-15+40, 129-5);
    glEnd();

    //glPopMatrix();
}
void TruckThrust()
{
    if(day)
    {
        glBegin(GL_POLYGON);
        glColor3ub(168, 169, 173);
        glVertex2f(110-50, 92);
        glColor3ub(255, 255, 255);
        glVertex2f(00-50, 80);
        glVertex2f(00-50, 110);
        glColor3ub(0, 0, 0);
        glVertex2f(110-50, 97);
        glEnd();
    }


}
void fullTruck()
{
    glPushMatrix();
    glTranslatef(0,0,0);
    TruckBody();
    glTranslatef(65,0,0);
    TruckScaledTire();
    glTranslatef(-85,0,0);
    TruckScaledTire();
    glPopMatrix();

}
void TruckReverse()
{
    glLineWidth(1);

    glTranslatef(-100.5, 0, 0);

    fullTruck();


}


void rocket(){

        glBegin(GL_POLYGON);

        glColor3ub(85,126,24);//body

        glVertex2f(250, 200);
        glVertex2f(300, 200);
        glVertex2f(300, 220);
        glVertex2f(250, 220);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(20,54,54);//head

        glVertex2f(250, 200);
        glVertex2f(250, 220);
        glVertex2f(230, 210);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(20,54,54);//leg

        glVertex2f(300, 200);
        glVertex2f(300, 220);
        glVertex2f(305, 225);
        glVertex2f(305, 195);

        glEnd();


        glPushMatrix();
    if(fire)glTranslatef(bul,0,0);
        glBegin(GL_POLYGON);
        glColor3ub(105,105,105);//bullet

        glVertex2f(230, 208);
        glVertex2f(230, 212);
        glVertex2f(220, 212);
        glVertex2f(220, 208);

        glEnd();
        glPopMatrix();





}

WatchTower()
{
    glPushMatrix;
glBegin(GL_QUADS);

glColor3ub(133,120,101);        //WatchTower 1

glVertex2i(340,570);
glVertex2i(340,565);      //base
glVertex2i(420,565);
glVertex2i(420,570);

glColor3ub(58,65,4);

glVertex2i(365,585);
glVertex2i(365,570);        //big quad
glVertex2i(395,570);
glVertex2i(395,585);

glColor3ub(58,65,4);     //border Right

glVertex2i(395,585);
glVertex2i(395,584);
glVertex2i(420,584);
glVertex2i(420,585);

glVertex2i(419,584);
glVertex2i(419,565);
glVertex2i(420,565);
glVertex2i(420,584);

glVertex2i(395,576);
glVertex2i(395,577);
glVertex2i(420,577);
glVertex2i(420,576);

glVertex2i(414,585);
glVertex2i(414,570);
glVertex2i(415,570);
glVertex2i(414,585);

glVertex2i(414,585);
glVertex2i(414,577);
glVertex2i(415,577);
glVertex2i(415,585);

glColor3ub(58,65,4);

glVertex2i(403,595);     //Big border
glVertex2i(403,570);
glVertex2i(406,570);
glVertex2i(406,595);

glVertex2i(392,595);
glVertex2i(392,585);
glVertex2i(395,585);
glVertex2i(395,595);

glColor3ub(58,65,4);     //border Left

glVertex2i(340,585);
glVertex2i(340,584);
glVertex2i(365,584);
glVertex2i(365,585);

glVertex2i(339,584);
glVertex2i(339,565);
glVertex2i(340,565);
glVertex2i(340,584);

glVertex2i(340,576);
glVertex2i(340,577);
glVertex2i(365,577);
glVertex2i(365,576);

glVertex2i(345,585);
glVertex2i(345,570);
glVertex2i(346,570);
glVertex2i(346,585);

glVertex2i(414,585);
glVertex2i(414,577);
glVertex2i(415,577);
glVertex2i(415,585);  //useless border

glColor3ub(58,65,4);

glVertex2i(354,595);
glVertex2i(354,570);   //big border
glVertex2i(357,570);
glVertex2i(357,595);

glVertex2i(365,595);
glVertex2i(365,585);
glVertex2i(369,585);
glVertex2i(369,595);
glEnd();

glBegin(GL_TRIANGLES);

glColor3ub(125,88,42);

glVertex2i(344,595);       //Triangle
glVertex2i(416,595);
glVertex2i(380,620);
glEnd();

glBegin(GL_QUADS);

glVertex2i(354,565);
glVertex2i(354,500);
glVertex2i(359,500);    //pillar
glVertex2i(359,565);

glVertex2i(401,565);
glVertex2i(401,500);
glVertex2i(406,500);
glVertex2i(406,565);
glEnd();

glBegin(GL_QUADS);      //Ladder

glColor3ub(0,0,0);

glVertex2i(375,565);
glVertex2i(375,500);
glVertex2i(377,500);
glVertex2i(377,565);

glVertex2i(385,565);
glVertex2i(385,500);
glVertex2i(387,500);
glVertex2i(387,565);

glVertex2i(377,562);
glVertex2i(377,561);
glVertex2i(385,561);
glVertex2i(385,562);

glVertex2i(377,557);
glVertex2i(377,556);
glVertex2i(385,556);
glVertex2i(385,557);

glVertex2i(377,552);
glVertex2i(377,551);
glVertex2i(385,551);
glVertex2i(385,552);

glVertex2i(377,547);
glVertex2i(377,546);
glVertex2i(385,546);
glVertex2i(385,547);

glVertex2i(377,542);
glVertex2i(377,541);
glVertex2i(385,541);
glVertex2i(385,542);

glVertex2i(377,537);
glVertex2i(377,536);
glVertex2i(385,536);
glVertex2i(385,537);

glVertex2i(377,532);
glVertex2i(377,531);
glVertex2i(385,532);
glVertex2i(385,531);

glVertex2i(377,527);
glVertex2i(377,526);
glVertex2i(385,526);
glVertex2i(385,527);

glVertex2i(377,522);
glVertex2i(377,521);
glVertex2i(385,521);
glVertex2i(385,522);

glVertex2i(377,517);
glVertex2i(377,516);
glVertex2i(385,516);
glVertex2i(385,517);

glVertex2i(377,512);
glVertex2i(377,511);
glVertex2i(385,511);
glVertex2i(385,512);

glVertex2i(377,507);
glVertex2i(377,506);
glVertex2i(385,506);
glVertex2i(385,507);

glVertex2i(377,502);
glVertex2i(377,501);
glVertex2i(385,501);
glVertex2i(385,502);
glEnd();

glPopMatrix();
}

void ScaledWatchTower()
{
    glPushMatrix();
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    //glTranslatef(0,0,0);
    glTranslatef(-250,-800,0);
    glScalef(1.8,2.0,0);

    WatchTower();
    glPopMatrix();

}


void frontWindow()
{
    glPushMatrix();
     glScalef(0.3,0.3,0);
     glTranslatef(0,0,0);
  // glScalef(0.3,0.3,0);
        glColor3ub(0,0,0);
        glBegin(GL_QUADS),
        glVertex2f(0, 60);
        glVertex2f(200,  56);
        glVertex2f(200, 216);
        glVertex2f(0, 220);
        glEnd();
    glPopMatrix();


}

void sideWindow()
{
    glPushMatrix();
     glScalef(0.3,0.3,0);
     glTranslatef(0,0,0);
  // glScalef(0.3,0.3,0);
        glColor3ub(0,0,0);
        glBegin(GL_QUADS),
        glVertex2f(0, 60);
        glVertex2f(130,  100);
        glVertex2f(130, 260);
        glVertex2f(0, 220);
        glEnd();
    glPopMatrix();


}

void topGrill()
{
        glPushMatrix();

        //horizontal
        glPushMatrix();
        glColor3ub(0,0,0);
        glTranslatef(0,300,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(300, 220);
        glVertex2f(0, 225);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,315,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(300, 220);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0,330,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(300, 220);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(90,300,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(0, 325);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        //vertical
        glPushMatrix();
        glTranslatef(45,300,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(0, 325);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(5,300,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(0, 325);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(15,300,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(0, 325);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(30,300,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(0, 325);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(60,300,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(0, 325);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(75,300,0);
        glScalef(0.3,0.3,0.0);
        glBegin(GL_LINES);

        glVertex2f(0, 325);
        glVertex2f(0, 225);

        glEnd();
        glPopMatrix();

        glPopMatrix();
}

void defenseTower()
{
    glPushMatrix();
    glTranslatef(-100,60,0);
    glScalef(1.1,1.1,0);

        glBegin(GL_POLYGON);

        ///front side
        glColor3ub(110,110,110);//front colour

        glVertex2f(0, 60);
        glVertex2f(300,  49);
        glVertex2f(300, 220);
        glVertex2f(0, 225);
        glEnd();

        glBegin(GL_POLYGON);

        ///right side
        glColor3ub(100,100,100);//right colour

        glVertex2f(300,  49);
        glVertex2f(400,  80);
        glVertex2f(400, 250);
        glVertex2f(300, 220);
        glEnd();

        glBegin(GL_POLYGON);

        ///lower top side
        glColor3ub(110,110,110);//top colour

        glVertex2f(0, 225);
        glVertex2f(300, 220);
        glVertex2f(400, 250);
        glVertex2f(0, 260);
        glEnd();


        glBegin(GL_POLYGON);
        ///top railing rear side
        glColor3ub(38,38,38);//rear color
        glVertex2f(393, 255);
        glVertex2f(393, 285);
        glVertex2f(0, 301);
        glVertex2f(0, 260);
        glEnd();

        glPushMatrix();
        glLineWidth(2);
        glColor3ub(48,48,48);
        glBegin(GL_LINES);
        glVertex2f(393, 285);
        glVertex2f(0, 301);
        glEnd();

        glPopMatrix();


        ///2nd level
        glPushMatrix();
        glTranslatef(0,195,0);
        glScalef(0.6,0.6,0);

        glBegin(GL_POLYGON);

        ///front side
        glColor3ub(110,110,110);//front colour

        glVertex2f(0, 60);
        glVertex2f(300,  49);
        glVertex2f(300, 220);
        glVertex2f(0, 225);
        glEnd();

        glBegin(GL_POLYGON);

        ///right side
        glColor3ub(100,100,100);//right colour

        glVertex2f(300,  49);
        glVertex2f(400,  80);
        glVertex2f(400, 250);
        glVertex2f(300, 220);
        glEnd();





        glBegin(GL_POLYGON);

        ///Upper top side
        glColor3ub(128,128,128);//top colour

        glVertex2f(0, 225);
        glVertex2f(300, 220);
        glVertex2f(400, 250);
        glVertex2f(0, 260);
        glEnd();
        glPopMatrix();



        glBegin(GL_POLYGON);

        ///top railing front side
        glColor3ub(38,38,38);//front colour
        glVertex2f(0, 227);
        glVertex2f(300,  222);
        glVertex2f(300, 260);
        glVertex2f(0, 270);
        glEnd();


        ///top railing right side
        glBegin(GL_POLYGON);
        glColor3ub(35,35,35);//front colour
        glVertex2f(300,  222);
        glVertex2f(300, 260);
        glVertex2f(393, 285);
        glVertex2f(393, 249);
        glEnd();

        glPushMatrix();
        glLineWidth(5);
        glBegin(GL_LINES);

        glColor3ub(48,48,48);//front railing
        glVertex2f(300, 260);
        glVertex2f(0, 270);

        //glLineWidth(10);
        glColor3ub(48,48,48 );//right railing
        glVertex2f(300, 260);
        glVertex2f(393, 285);

        glEnd();
        glPopMatrix();

//        glBegin(GL_POLYGON);
//        ///top railing rear side
//        glColor3ub(45, 84, 44);//rear color
//        glVertex2f(393, 285);
//        glVertex2f(393, 249);
//        glVertex2f(0, 260);
//        glVertex2f(0, 290);
//        glEnd();


        glPopMatrix();

        //front left window
        glPushMatrix();
        glTranslatef(0,230,0);
        frontWindow();
        glPopMatrix();
        //front middle window
        glPushMatrix();
        glTranslatef(80,228,0);
        frontWindow();
        glPopMatrix();
        //front right window
        glPushMatrix();
        glTranslatef(160,226,0);
        frontWindow();
        glPopMatrix();

        //right first window
        glPushMatrix();
        glTranslatef(240,226,0);
        sideWindow();
        glPopMatrix();
        //right second window
        glPushMatrix();
        glTranslatef(290,241,0);
        sideWindow();
        glPopMatrix();

        topGrill();




}

void ScaledTruckReverse()
{
    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(tpos,0,0);
    glTranslatef(500,140,0);
    glScalef(-0.6,0.55,0.0);
    TruckReverse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tpos,0,0);
    glTranslatef(200,122,0);
    glScalef(0.9,0.4,0);
    rocket();
    glPopMatrix();

    glPopMatrix();

}

void Truck2()
{
    glPushMatrix();

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(tpos,0,0);
    glTranslatef(550,200,0);
    glScalef(-0.5,0.45,0.0);
    //glColor3ub(0,0,0);
    TruckReverse();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(tpos,0,0);
    glTranslatef(285,122+70,0);
    glScalef(0.8,0.3,0);
    rocket();
    glPopMatrix();

    glPopMatrix();

}

void tent()
{

        glPushMatrix();
//        glScalef(0.8,0.8,0);
//        glTranslatef(-130,-220,0);
        glBegin(GL_QUADS);      //Tent 1

        if(day)
        glColor3ub(45,89,67);
        if(!day)
        glColor3ub(17,37,26);


        glVertex2i(700,490);
        glVertex2i(700,540);
        glVertex2i(620,540);
        glVertex2i(620,490);

        glEnd();

        glBegin(GL_TRIANGLES);

        glVertex2i(710,540);
        glVertex2i(660,565);
        glVertex2i(610,540);
        glEnd();

        glBegin(GL_LINES);
        glVertex2i(610,540);
        glVertex2i(620,520);

        glVertex2i(610,540);
        glVertex2i(600,480);

        glVertex2i(710,540);
        glVertex2i(690,500);

        glVertex2i(710,540);
        glVertex2i(720,480);
        glEnd();


        glBegin(GL_QUADS);      //Tent 1 Door
        glColor3ub(0,0,0);
        glVertex2i(675,490);
        glVertex2i(675,525);
        glVertex2i(645,525);
        glVertex2i(645,490);
        glEnd();

        glPopMatrix();
}


void tent1()
{
    glPushMatrix();
     glScalef(0.8,0.8,0);
        glTranslatef(-130,-220,0);
        tent();

    glPopMatrix();
}

void tent2()
{
    glPushMatrix();
    glScalef(1.2,1.2,0);
    glTranslatef(-400,-400, 0);
    tent();

    glPopMatrix();
}

void siren()
{
    glPushMatrix();
    glTranslatef(400,400,0);
    glColor3ub(12,43,1);
    glRotatef(rpos, 0,1,0);
    circle(0,0,50);
    glPopMatrix();
}



///Main
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0,0.0,1.0);

//	sky();
//
//	star();
//	sun();
//    moon();
//    cloud1();
//    cloud2();
//    cloud3();
//    cloud4();
//    cloud5();
//    airPlane();
//    tilla1();
//    tilla2();
//    tilla3();
//    tilla4();
//    Hill();
//    field();
//    tree1();
//    tree2();
//    tree3();
//    tree4();
//    tree5();
//    tree6();
//    tree7();
//    tree8();
//    tree9();
//    tree10();
//    tree11();
//    tree12();
//    tree13();
//    tree14();
//    tree15();
//    tree16();
//    tree17();
//    tree18();
//    tree19();
//    tree20();
//    tent1();
//    Truck2();
//    ScaledTank();
//    ScaledTruckReverse();
//    ScaledJeep();
//
//
//
//
//
//    ScaledWatchTower();
//    defenseTower();
//    tent2();
//    tank2();

//Hill();

    siren();


    timeCheck();



	glFlush();
}
void init(void){
	glClearColor(0.8,0.93,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}

void update(int value){

    ///Cloud Control
    if(cpos1>750)cpos1=-320;
    if(cpos2<-350)cpos2=650;
    if(cpos3>750)cpos3=-320;
    if(cpos4>750)cpos4=-320;
    if(cpos5<-350)cpos5=650;
    cpos1+=sp1;
    cpos2-=sp1;
    cpos3+=sp1;
    cpos4+=sp1;
    cpos5-=sp1;
    ///Sun Control
    if(day)
    {
        if(sun_y<300)
            {
                sun_x=450;
                sun_y=480;
                day=0;
            }
        sun_x+=sp_x;
        sun_y-=sp_y;
    }

    ///AirPlane Control
    if(plane_x>1000){
        plane_x=-100;
    }
    plane_x+=plane_speed;

    glutTimerFunc(1000/30, update, 0);
    glutPostRedisplay();

    ///Bullet Control
    bul -= 10;
	if (bul <-410)
    {
        bul = 0;
    }
    ///Truck control
    if(tpos<200)tpos=550;
    tpos-=truckSpeed;

    ///jeep control
    if (jpos<-100) jpos = 550;
    jpos -= jeepSpeed;

    ///tank control
    if(tankpos>700) tankpos = 0;
    tankpos += tankSpeed;

    rpos += 1.0f;

}

void Rain(int value){

if(rainday){

    _rain += 0.01f;

    glBegin(GL_POINTS);
    for(int i=1;i<=1000;i++)
    {
        int x=rand(),y=rand();
        x%=1000; y%=1000;
        glBegin(GL_LINES);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(x,y);
        glVertex2d(x+5,y+5);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();

}
}



void handleKeypress(unsigned char key, int x, int y){
	switch (key){
        case 'd':
            day=1;
            night = 0;
            break;
        case 'n':
            night = 1;
            day = 0;
            break;
        case 'r':
        rainday = true;
        Rain(_rain);
        //sndPlaySound("River.wav",SND_ASYNC|SND_LOOP);
        //sndPlaySound("River.wav",SND_MEMORY|SND_ASYNC);
        break;

    case 's':
        rainday = false;
		//sndPlaySound(NULL,SND_ASYNC);
        break;

        case 'f':
        fire = true;
		//sndPlaySound(NULL,SND_ASYNC);
        break;

        case 'o':
        fire = false;
		//sndPlaySound(NULL,SND_ASYNC);
        break;

        glutPostRedisplay();
	}
}
void credit(){

    cout<<"------------------------------------------------------"<<endl;
    cout<<"Press d for Day "<<endl;
    cout<<"Press n for Night "<<endl;
    cout<<"Press r for Rain "<<endl;
    cout<<"Press s for Stop Rain "<<endl;
    cout<<"Press f for Fire "<<endl;
    cout<<"Press o for Stop Fire "<<endl;

    cout<<"------------------------------------------------------"<<endl;

}
int main(int argc, char** argv){
    credit();
    ///Music Background
    //PlaySound(TEXT("sound.wav"), NULL, SND_ASYNC);
    ///system("pause");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("CG Project- War Zone");
	init();
	glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);

    glutTimerFunc(1000, update, 0);
    glutMainLoop();
}

