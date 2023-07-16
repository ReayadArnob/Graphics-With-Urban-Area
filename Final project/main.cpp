#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI 3.14159265358979323846
GLfloat twicePi = 2.0f * PI;
float i;
GLfloat position = 0.0f; GLfloat speed = 0.01f;
GLfloat position1 = 0.0f; GLfloat speed1 = 0.02f;
GLfloat position2 = 0.0f; GLfloat speed2 = 0.02f;
GLfloat position3 = 0.0f; GLfloat speed3 = 0.02f;
GLfloat position4 = 0.0f; GLfloat speed4 = 0.02f;
GLfloat position5 = 0.0f; GLfloat speed5 = 0.02f;
GLfloat position6 = 0.0f; GLfloat speed6 = 0.01f;
GLfloat position7 = 0.0f; GLfloat speed7 = 0.05f;
GLfloat position8 = 0.0f; GLfloat speed8 = 0.05f;

void update(int value) {
    if(position <-1.77){ //floating light
        position = 0.0f;}
    if(position1 <-1.25){ //cloud 1
        position1 = 1.2f;}
    if(position2 <-0.7){ //cloud 2
        position2 = 1.5f;}
    if(position3 <-1.6){ //cloud 3
        position3 = 0.8f;}
    if(position4 <-1.95){ //cloud 4
        position4 = 0.2f;}
    if(position5 <-2.0){ //snow fall
        position5 = 0.0f;}
    if(position6 > 0.75){ //mountain smokes
        position6 = 0.0f;}
     if(position7 > 1.4){
        position7 = -0.8f;}
    if(position8 <-2.0){
        position8 = 0.5f;}

    position -= speed;
    position1 -= speed1;
    position2 -= speed2;
    position3 -= speed3;
    position4 -= speed4;
    position5 -= speed5;
    position6 += speed6;
    position7 += speed7;
    position8 -= speed8;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}


void evening() { //day}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

//Back ground....................................................................
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(251, 159, 148);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,-1.0);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(214, 131, 131);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,0.2);
    glVertex2f(1.0,0.2);
    glVertex2f(1.0,-1.0);
	glEnd();

	float jl = 0;

//sun==================================================================================
    for (int j = 0; j < 4; j++){
	glBegin(GL_TRIANGLE_FAN);
	   if (j == 0){
        glColor3ub(250, 172, 150); //SUN effect 2.............
        jl = .22;
	   }
	   else if (j == 1){
        glColor3ub(253, 183, 157); //SUN effect 1.............
         jl = .17;
	   }
	   else if (j == 2){
        glColor3ub(255, 201, 165); //SUN effect 1.............
         jl = .12;
	   }
	   else{
        glColor3ub(255, 251, 222); //SUN.............
        jl = .06;
	   }

		for(i = 0; i <= 21;i++) {
			glVertex2f(
			    -0.7 + (jl * cos(i *  twicePi / 21)), //x
			    .8 + (jl* sin(i * twicePi / 21)) //y
			);
		}
	glEnd();}

//smokes from mountain+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    float posx = 0.0, posy =0.0; //cloud 3++++++++++++++++++++++++
    glTranslatef(0,-0.4 + position6,0);
    for(int r=0; r<7; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.04f + posx,0.65f + posy);
        glVertex2f(-0.04f + posx,0.665f + posy);
        glVertex2f(0.04f - posx,0.665f + posy);
        glVertex2f(0.04f - posx,0.65f + posy);
        glEnd();
        posx += 0.01f; posy += 0.09f;
        if (r == 2){ posx =0.0;}
        else{ }
    }
    glLoadIdentity();

//clouds+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    posx = 0.0, posy =0.0; //cloud 3++++++++++++++++++++++++
    glTranslatef(0.4f + position3,0,0);
    glScalef(1.3,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();
//main mountain+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glBegin(GL_TRIANGLE_FAN);//main mountain base
    glColor3ub(146, 114, 163);
    glVertex2f(-0.5,0.51);
    glVertex2f(-1.1,0.2);
    glVertex2f(1.1,0.2);
    glVertex2f(0.5,0.51);
    glVertex2f(0.05,0.83);
    glVertex2f(-0.05,0.83);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//top ice part
    glColor3ub(219, 141, 181);
    glVertex2f(-0.05,0.83);
    glVertex2f(-0.3,0.6);
    glVertex2f(-0.2,0.5);
    glVertex2f(-0.05,0.66);
    glVertex2f(0.05,0.57);
    glVertex2f(0.05,0.83);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);//top ice part
    glColor3ub(219, 141, 181);
    glVertex2f(0.15,0.63);
    glVertex2f(0.05,0.57);
    glVertex2f(0.05,0.83);
    glVertex2f(0.5,0.51);
	glEnd();

    glBegin(GL_TRIANGLE_FAN); //light hitting top
    glColor3ub(255, 201, 165);
    glVertex2f(-0.5,0.51);
    glVertex2f(-0.28,0.57);
    glVertex2f(-0.2,0.65);
    glVertex2f(-0.29,0.6);
    glVertex2f(-0.05,0.83);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //light hitting down
    glColor3ub(206, 133, 124);
    glVertex2f(-1.1,0.2);
    glVertex2f(-0.8,0.2);
    glVertex2f(-0.6,0.35);
    glVertex2f(-0.75,0.3);
    glVertex2f(-0.28,0.57);
    glVertex2f(-0.5,0.51);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //Mountain shading
    glColor3ub(125, 94, 145);
    glVertex2f(-0.1,0.2);
    glVertex2f(-0.12,0.45);
    glVertex2f(-0.3,0.2);
    glEnd();
    glBegin(GL_TRIANGLE_FAN); //1
    glColor3ub(125, 94, 145);
    glVertex2f(0.1,0.2);
    glVertex2f(0.12,0.56);
    glVertex2f(0.3,0.2);
    glEnd();
    glBegin(GL_TRIANGLE_FAN); //2
    glColor3ub(125, 94, 145);
    glVertex2f(0.47,0.2);
    glVertex2f(0.4,0.3);
    glVertex2f(0.6,0.2);
    glEnd();

//mountain shade on water++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(0,0.06,0);
    glScalef(1,0.7,1);
    glBegin(GL_TRIANGLE_FAN);//main mountain base shadow
    glColor3ub(129, 90, 132);
    glVertex2f(-1.1,0.2);
    glVertex2f(1.1,0.2);
    glVertex2f(0.05,-0.63);
    glVertex2f(-0.05,-0.63);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//shadow ice part on water
    glColor3ub(155, 151, 158);
    glVertex2f(-0.05,-0.63);
    glVertex2f(-0.3,-0.4);
    glVertex2f(-0.2,-0.3);
    glVertex2f(-0.05,-0.46);
    glVertex2f(0.05,-0.37);
    glVertex2f(0.05,-0.63);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);//1
    glColor3ub(155, 151, 158);
    glVertex2f(0.15,-0.43);
    glVertex2f(0.05,-0.37);
    glVertex2f(0.05,-0.63);
    glVertex2f(0.451,-0.31);
	glEnd();
    glBegin(GL_TRIANGLE_FAN); //2
    glColor3ub(155, 151, 158);
    glVertex2f(-0.451,-0.31);
    glVertex2f(-0.28,-0.37);
    glVertex2f(-0.2,-0.45);
    glVertex2f(-0.29,-0.4);
    glVertex2f(-0.05,-0.63);
    glEnd();
    glLoadIdentity();

//Clouds+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    posx = 0.0, posy =0.0; //cloud 1+++++++++++++++++
    glTranslatef(position1,0,0);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();


    posx = 0.0, posy =0.0; //cloud 2+++++++++++++++++++++++
    glTranslatef(-0.4f + position2,0,0);
    glScalef(0.8,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();

    posx = 0.0, posy =0.0; //cloud 4++++++++++++++++++++++++
    glTranslatef(0.85f + position4,0,0);
    glScalef(0.8,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();

//floating lights++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    float pos = 0;  posy = 0;
    for(int y =0; y<22; y++){
    if(y == 6){pos = -0.3; posy = 0.1;}
    else if(y == 14){pos = -0.3; posy = -0.1;}
    glTranslatef(position, 0, 0);
    glBegin(GL_QUADS);
    glColor3ub(255,201,165);
    glVertex2f(-0.6f + pos,0.0f + posy);
    glVertex2f(-0.57f + pos,0.0f + posy);
    glVertex2f(-0.57f + pos,0.05f + posy);
    glVertex2f(-0.6f + pos,0.05f + posy);
    glEnd();
    glLoadIdentity();

    pos += 0.6;
    }

//Background houses +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//3RD

glScalef(1.3,1.3,1);
glTranslatef(1.15,-.4,0);
glBegin(GL_TRIANGLE_FAN);//3T
glColor3ub(108,141,160);
glVertex2f(-0.94,-0.1);
glVertex2f(-0.74,-0.1);
glVertex2f(-0.74,-0.02);
glVertex2f(-.94,-0.02);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3R
glColor3ub(108,141,160);
glVertex2f(-1,-0.02);
glVertex2f(-0.68,-0.02);
glVertex2f(-0.78,0.04);
glVertex2f(-.9,0.04);
glEnd();

//TOP
glBegin(GL_TRIANGLE_FAN);//TT
glColor3ub(108,141,160);
glVertex2f(-0.9,0.04);
glVertex2f(-0.78,0.04);
glVertex2f(-0.78,0.1);
glVertex2f(-.9,0.1);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TR
glColor3ub(108,141,160);
glVertex2f(-.96,0.1);
glVertex2f(-0.72,0.1);
glVertex2f(-0.82,0.16);
glVertex2f(-.86,0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRT
glColor3ub(108,141,160);
glVertex2f(-.86,0.16);
glVertex2f(-0.82,0.16);
glVertex2f(-0.82,0.18);
glVertex2f(-.86,0.18);
glEnd();
glLoadIdentity();

//circle++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


glBegin(GL_TRIANGLE_FAN);
glColor3ub(49,113,125); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.6 + (.15 * cos(i * twicePi / 21)), //x
 -0.15 + (.15* sin(i * twicePi / 21)) //y
);
}
glEnd();



glBegin(GL_TRIANGLE_FAN);
glColor3ub(49,113,125); //left big circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-.5 + (.4 * cos(i * twicePi / 21)), //x
-0.56 + (.4* sin(i * twicePi / 21)) //y
);
}
glEnd();



glBegin(GL_TRIANGLE_FAN);
glColor3ub(49,113,125); //middle circle
for(i = 0; i <= 21;i++) {
glVertex2f(
 .1 + (.4* cos(i * twicePi / 21)), //x0
-0.75 + (.4* sin(i * twicePi / 21)) //y
);
}
glEnd();


glScalef(1.3,1.35,1);
glTranslatef(0.2,0.1,0);
//LEFT BUILDING+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//GROUND
glBegin(GL_TRIANGLE_FAN);//GT
glColor3ub(145,96,84);
glVertex2f(-1,-0.52);
glVertex2f(-0.6,-0.52);
glVertex2f(-0.6,-0.44);
glVertex2f(-1,-0.44);
glEnd();

glBegin(GL_TRIANGLE_FAN);//GR
glColor3ub(79,39,89);
glVertex2f(-1,-0.44);
glVertex2f(-0.54,-0.44);
glVertex2f(-0.66,-0.38);
glVertex2f(-1,-0.38);
glEnd();

glBegin(GL_TRIANGLE_FAN);//GL
glColor3ub(91, 29, 54);
glVertex2f(-1,-0.47);
glVertex2f(-0.6,-0.47);
glVertex2f(-0.6,-0.46);
glVertex2f(-1,-0.46);
glEnd();

glBegin(GL_TRIANGLE_FAN);//GLP
glColor3ub(91, 29, 54);
glVertex2f(-.98,-0.52);
glVertex2f(-0.97,-0.52);
glVertex2f(-0.97,-0.47);
glVertex2f(-.98,-0.47);
glEnd();

glBegin(GL_TRIANGLE_FAN);//GRP
glColor3ub(91, 29, 54);
glVertex2f(-.64,-0.52);
glVertex2f(-0.63,-0.52);
glVertex2f(-0.63,-0.47);
glVertex2f(-.64,-0.47);
glEnd();

//light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.56,-0.44);
    glVertex2f(-.56,-0.46);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.56 + (.02 * cos(i * twicePi / 21)), //x
-0.48 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();



//1ST
glBegin(GL_TRIANGLE_FAN);//1T
glColor3ub(145,96,84);
glVertex2f(-1,-0.38);
glVertex2f(-0.66,-0.38);
glVertex2f(-0.66,-0.3);
glVertex2f(-1,-0.3);
glEnd();


glBegin(GL_TRIANGLE_FAN);//GR
glColor3ub(79,39,89);
glVertex2f(-1,-0.3);
glVertex2f(-0.6,-0.3);
glVertex2f(-0.7,-0.24);
glVertex2f(-1,-0.24);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1L
glColor3ub(91, 29, 54);
glVertex2f(-1,-0.32);
glVertex2f(-0.66,-0.32);
glVertex2f(-0.66,-0.31);
glVertex2f(-1,-0.31);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1LP
glColor3ub(91, 29, 54);
glVertex2f(-.98,-0.38);
glVertex2f(-0.97,-0.38);
glVertex2f(-0.97,-0.32);
glVertex2f(-.98,-0.32);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1ST RIGHT P
glColor3ub(91, 29, 54);
glVertex2f(-.69,-0.38);
glVertex2f(-0.68,-0.38);
glVertex2f(-0.68,-0.32);
glVertex2f(-.69,-0.32);
glEnd();

glBegin(GL_TRIANGLE_FAN);//left window
glColor3ub(255,201,165);
glVertex2f(-.92,-0.36);
glVertex2f(-0.88,-0.36);
glVertex2f(-0.88,-0.34);
glVertex2f(-.92,-0.34);
glEnd();

glBegin(GL_TRIANGLE_FAN);//left window
glColor3ub(255,201,165);
glVertex2f(-.78,-0.36);
glVertex2f(-0.74,-0.36);
glVertex2f(-0.74,-0.34);
glVertex2f(-.78,-0.34);
glEnd();

//light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.62,-0.3);
    glVertex2f(-.62,-0.32);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.62 + (.02 * cos(i * twicePi / 21)), //x
-0.34 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

//2ND
glBegin(GL_TRIANGLE_FAN);//2T
glColor3ub(145,96,84);
glVertex2f(-0.98,-0.24);
glVertex2f(-0.7,-0.24);
glVertex2f(-0.7,-0.16);
glVertex2f(-.98,-0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2R
glColor3ub(79,39,89);
glVertex2f(-1,-0.16);
glVertex2f(-0.64,-0.16);
glVertex2f(-0.74,-0.1);
glVertex2f(-.94,-0.1);

glEnd();

glBegin(GL_TRIANGLE_FAN);//2L
glColor3ub(91,29,54);
glVertex2f(-.98,-0.18);
glVertex2f(-0.7,-0.18);
glVertex2f(-0.7,-0.17);
glVertex2f(-0.98,-0.17);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2LP
glColor3ub(91,29,54);
glVertex2f(-.95,-0.24);
glVertex2f(-0.96,-0.24);
glVertex2f(-0.96,-0.18);
glVertex2f(-.95,-0.18);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2RP
glColor3ub(91,29,54);
glVertex2f(-.73,-0.24);
glVertex2f(-0.72,-0.24);
glVertex2f(-0.72,-0.18);
glVertex2f(-.73,-0.18);
glEnd();
//windows
glBegin(GL_TRIANGLE_FAN);//left
glColor3ub(255,201,165);
glVertex2f(-.92,-0.22);
glVertex2f(-0.88,-0.22);
glVertex2f(-0.88,-0.2);
glVertex2f(-.92,-0.2);
glEnd();

glBegin(GL_TRIANGLE_FAN);//right
glColor3ub(255,201,165);
glVertex2f(-.8,-0.22);
glVertex2f(-0.76,-0.22);
glVertex2f(-0.76,-0.2);
glVertex2f(-.8,-0.2);
glEnd();

//light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.66,-0.16);
    glVertex2f(-.66,-0.18);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.66 + (.02 * cos(i * twicePi / 21)), //x
-0.2 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

//3RD
glBegin(GL_TRIANGLE_FAN);//3T
glColor3ub(145,96,84);
glVertex2f(-0.94,-0.1);
glVertex2f(-0.74,-0.1);
glVertex2f(-0.74,-0.02);
glVertex2f(-.94,-0.02);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3R
glColor3ub(79,39,89);
glVertex2f(-1,-0.02);
glVertex2f(-0.68,-0.02);
glVertex2f(-0.78,0.04);
glVertex2f(-.9,0.04);

glEnd();

glBegin(GL_TRIANGLE_FAN);//3L
glColor3ub(91,29,54);
glVertex2f(-.94,-0.04);
glVertex2f(-0.74,-0.04);
glVertex2f(-0.74,-0.03);
glVertex2f(-0.94,-0.03);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3LP
glColor3ub(91,29,54);
glVertex2f(-.92,-0.1);
glVertex2f(-0.91,-0.1);
glVertex2f(-0.91,-0.04);
glVertex2f(-.92,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3RP
glColor3ub(91,29,54);
glVertex2f(-.77,-0.1);
glVertex2f(-0.76,-0.1);
glVertex2f(-0.76,-0.04);
glVertex2f(-.77,-0.04);
glEnd();

// right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.7,-0.02);
    glVertex2f(-.7,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.7 + (.02 * cos(i * twicePi / 21)), //x
-0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();
// Right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.98,-0.02);
    glVertex2f(-.98,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.98 + (.02 * cos(i * twicePi / 21)), //x
-0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

//TOP
glBegin(GL_TRIANGLE_FAN);//TT
glColor3ub(145,96,84);
glVertex2f(-0.9,0.04);
glVertex2f(-0.78,0.04);
glVertex2f(-0.78,0.1);
glVertex2f(-.9,0.1);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TR
glColor3ub(79,39,89);
glVertex2f(-.96,0.1);
glVertex2f(-0.72,0.1);
glVertex2f(-0.82,0.16);
glVertex2f(-.86,0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRT
glColor3ub(0,0,0);
glVertex2f(-.86,0.16);
glVertex2f(-0.82,0.16);
glVertex2f(-0.82,0.18);
glVertex2f(-.86,0.18);
glEnd();

glBegin(GL_TRIANGLE_FAN);//window
glColor3ub(255,201,165);
glVertex2f(-.86,-0.08);
glVertex2f(-0.82,-0.08);
glVertex2f(-0.82,-0.06);
glVertex2f(-.86,-0.06);
glEnd();

//TOWER
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0,0,0);
glVertex2f(-.85,0.18);
glVertex2f(-0.83,0.18);
glVertex2f(-0.83,0.4);
glVertex2f(-.85,0.4);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1
glColor3ub(0,0,0);
glVertex2f(-.88,0.36);
glVertex2f(-0.8,0.36);
glVertex2f(-0.8,0.38);
glVertex2f(-.88,0.38);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2
glColor3ub(0,0,0);
glVertex2f(-.88,0.32);
glVertex2f(-0.8,0.32);
glVertex2f(-0.8,0.34);
glVertex2f(-.88,0.34);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3
glColor3ub(0,0,0);
glVertex2f(-.88,0.28);
glVertex2f(-0.8,0.28);
glVertex2f(-0.8,0.3);
glVertex2f(-.88,0.3);
glEnd();


glBegin(GL_TRIANGLE_FAN);//TL
glColor3ub(91,29,54);
glVertex2f(-.9,0.08);
glVertex2f(-0.78,0.08);
glVertex2f(-0.78,0.09);
glVertex2f(-0.9,0.09);
glEnd();



glBegin(GL_TRIANGLE_FAN);//TLP
glColor3ub(91,29,54);
glVertex2f(-.88,0.04);
glVertex2f(-0.87,0.04);
glVertex2f(-0.87,0.08);
glVertex2f(-.88,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRP
glColor3ub(91,29,54);
glVertex2f(-.80,0.04);
glVertex2f(-0.81,0.04);
glVertex2f(-0.81,0.08);
glVertex2f(-.8,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRP
glColor3ub(255,201,165);
glVertex2f(-.82,0.05);
glVertex2f(-0.86,0.05);
glVertex2f(-0.86,0.07);
glVertex2f(-.82,0.07);
glEnd();

//left light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.74,0.1);
    glVertex2f(-.74,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.74 + (.02 * cos(i * twicePi / 21)), //x
0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

// right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.94,0.1);
    glVertex2f(-.94,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.94 + (.02 * cos(i * twicePi / 21)), //x
0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

glLoadIdentity();

//right side building+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
glTranslatef(1.7,-.05,0);
glScalef(1,1.2,1);

//right BUILDING
//GROUND
glBegin(GL_TRIANGLE_FAN);//GR
glColor3ub(108,141,160);
glVertex2f(-1.09,-0.44);
glVertex2f(-0.54,-0.44);
glVertex2f(-0.66,-0.38);
glVertex2f(-1,-0.38);
glEnd();

//1ST
glBegin(GL_TRIANGLE_FAN);//1T
glColor3ub(108,141,160);
glVertex2f(-1,-0.38);
glVertex2f(-0.66,-0.38);
glVertex2f(-0.66,-0.3);
glVertex2f(-1,-0.3);
glEnd();


glBegin(GL_TRIANGLE_FAN);//1R
glColor3ub(108,141,160);
glVertex2f(-1.07,-0.3);
glVertex2f(-0.6,-0.3);
glVertex2f(-0.7,-0.24);
glVertex2f(-0.98,-0.24);
glEnd();


//2ND
glBegin(GL_TRIANGLE_FAN);//2T
glColor3ub(108,141,160);
glVertex2f(-0.98,-0.24);
glVertex2f(-0.7,-0.24);
glVertex2f(-0.7,-0.16);
glVertex2f(-.98,-0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2R
glColor3ub(108,141,160);
glVertex2f(-1.04,-0.16);
glVertex2f(-0.64,-0.16);
glVertex2f(-0.74,-0.1);
glVertex2f(-.94,-0.1);
glEnd();

//3RD
glBegin(GL_TRIANGLE_FAN);//3T
glColor3ub(108,141,160);
glVertex2f(-0.94,-0.1);
glVertex2f(-0.74,-0.1);
glVertex2f(-0.74,-0.02);
glVertex2f(-.94,-0.02);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3R
glColor3ub(108,141,160);
glVertex2f(-1,-0.02);
glVertex2f(-0.68,-0.02);
glVertex2f(-0.78,0.04);
glVertex2f(-.9,0.04);
glEnd();

//TOP
glBegin(GL_TRIANGLE_FAN);//TT
glColor3ub(108,141,160);
glVertex2f(-0.9,0.04);
glVertex2f(-0.78,0.04);
glVertex2f(-0.78,0.1);
glVertex2f(-.9,0.1);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TR
glColor3ub(108,141,160);
glVertex2f(-.96,0.1);
glVertex2f(-0.72,0.1);
glVertex2f(-0.82,0.16);
glVertex2f(-.86,0.16);
glEnd();

//TOWER
glBegin(GL_TRIANGLE_FAN);
glColor3ub(108,141,160);
glVertex2f(-.85,0.18);
glVertex2f(-0.83,0.18);
glVertex2f(-0.83,0.4);
glVertex2f(-.85,0.4);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1
glColor3ub(108,141,160);
glVertex2f(-.88,0.36);
glVertex2f(-0.8,0.36);
glVertex2f(-0.8,0.38);
glVertex2f(-.88,0.38);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2
glColor3ub(108,141,160);
glVertex2f(-.88,0.32);
glVertex2f(-0.8,0.32);
glVertex2f(-0.8,0.34);
glVertex2f(-.88,0.34);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3
glColor3ub(108,141,160);
glVertex2f(-.88,0.28);
glVertex2f(-0.8,0.28);
glVertex2f(-0.8,0.3);
glVertex2f(-.88,0.3);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRT
glColor3ub(108,141,160);
glVertex2f(-.86,0.16);
glVertex2f(-0.82,0.16);
glVertex2f(-0.82,0.18);
glVertex2f(-.86,0.18);
glEnd();
glLoadIdentity();

//middle building*************************************************+++++++++++++++++
//3RD
glScalef(1.7,1.5,1);
glTranslatef(0.9,-.29,0);
glBegin(GL_TRIANGLE_FAN);//3T
glColor3ub(145,96,84);
glVertex2f(-0.94,-0.1);
glVertex2f(-0.74,-0.1);
glVertex2f(-0.74,-0.02);
glVertex2f(-.94,-0.02);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3R
glColor3ub(79,39,89);
glVertex2f(-1,-0.02);
glVertex2f(-0.68,-0.02);
glVertex2f(-0.78,0.04);
glVertex2f(-.9,0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3L
glColor3ub(91,29,54);
glVertex2f(-.94,-0.04);
glVertex2f(-0.74,-0.04);
glVertex2f(-0.74,-0.03);
glVertex2f(-0.94,-0.03);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3LP
glColor3ub(91,29,54);
glVertex2f(-.92,-0.1);
glVertex2f(-0.91,-0.1);
glVertex2f(-0.91,-0.04);
glVertex2f(-.92,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3RP
glColor3ub(91,29,54);
glVertex2f(-.77,-0.1);
glVertex2f(-0.76,-0.1);
glVertex2f(-0.76,-0.04);
glVertex2f(-.77,-0.04);
glEnd();

// right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.7,-0.02);
    glVertex2f(-.7,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.7 + (.02 * cos(i * twicePi / 21)), //x
-0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

// Right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.98,-0.02);
    glVertex2f(-.98,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.98 + (.02 * cos(i * twicePi / 21)), //x
-0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

//TOP
glBegin(GL_TRIANGLE_FAN);//TT
glColor3ub(145,96,84);
glVertex2f(-0.9,0.04);
glVertex2f(-0.78,0.04);
glVertex2f(-0.78,0.1);
glVertex2f(-.9,0.1);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TR
glColor3ub(79,39,89);
glVertex2f(-.96,0.1);
glVertex2f(-0.72,0.1);
glVertex2f(-0.82,0.16);
glVertex2f(-.86,0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRT
glColor3ub(0,0,0);
glVertex2f(-.86,0.16);
glVertex2f(-0.82,0.16);
glVertex2f(-0.82,0.18);
glVertex2f(-.86,0.18);
glEnd();

glBegin(GL_TRIANGLE_FAN);//window
glColor3ub(255,201,165);
glVertex2f(-.86,-0.08);
glVertex2f(-0.82,-0.08);
glVertex2f(-0.82,-0.06);
glVertex2f(-.86,-0.06);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRP
glColor3ub(255,201,165);
glVertex2f(-.82,0.05);
glVertex2f(-0.86,0.05);
glVertex2f(-0.86,0.07);
glVertex2f(-.82,0.07);
glEnd();

//left light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.74,0.1);
    glVertex2f(-.74,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.74 + (.02 * cos(i * twicePi / 21)), //x
0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

// right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.94,0.1);
    glVertex2f(-.94,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.94 + (.02 * cos(i * twicePi / 21)), //x
0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();
glBegin(GL_TRIANGLE_FAN);//TL
glColor3ub(91,29,54);
glVertex2f(-.9,0.08);
glVertex2f(-0.78,0.08);
glVertex2f(-0.78,0.09);
glVertex2f(-0.9,0.09);
glEnd();



glBegin(GL_TRIANGLE_FAN);//TLP
glColor3ub(91,29,54);
glVertex2f(-.88,0.04);
glVertex2f(-0.87,0.04);
glVertex2f(-0.87,0.08);
glVertex2f(-.88,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRP
glColor3ub(91,29,54);
glVertex2f(-.80,0.04);
glVertex2f(-0.81,0.04);
glVertex2f(-0.81,0.08);
glVertex2f(-.8,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRP
glColor3ub(255,201,165);
glVertex2f(-.82,0.05);
glVertex2f(-0.86,0.05);
glVertex2f(-0.86,0.07);
glVertex2f(-.82,0.07);
glEnd();
glLoadIdentity();

//tree++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 pos = 0.0; posy = 0.0;
 for(i = 0; i< 3; i++){
    glTranslatef(pos, posy,0);
    glBegin(GL_TRIANGLE_FAN);  //big branches
    glColor3ub(89,69,69);
    glVertex2f(1.0, -0.4);
    glVertex2f(0.86, -0.35);
    glVertex2f(0.66, -0.35);
    glVertex2f(0.46, -0.36);
    glVertex2f(0.66, -0.37);
    glVertex2f(0.86, -0.38);
    glVertex2f(1.0, -0.44);
    glEnd();
    posy += 0.08;
    pos += 0.07;
    glLoadIdentity();
    }
    glBegin(GL_TRIANGLE_FAN);  //small branches
    glColor3ub(89,69,69);
    glVertex2f(0.66, -0.37);
    glVertex2f(0.63, -0.37);
    glVertex2f(0.6, -0.43);
    glEnd();

//tree leaves++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    posx = 0,posy = 0;
    float hold = 0;
    for(int t=0; t<4; t++){
        if(t==0){posx=1.4,posy=-0.78,hold=0;}
        else if(t==1){posx=1.8,posy=-0.55;}
        else if(t==2){posx=2.3,posy=-0.35;}
        else if(t==3){posx=2.4,posy=-0.8;}
        hold = posx;
        for(int i= 1; i<=3; i++){
          for(int j=0; j<(i+3); j++){
            glScalef(0.35,0.45,1);
            glTranslatef(posx, posy, 0);
            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(209, 67, 152);
            glVertex2f(0.0,0.04);
            glVertex2f(0.06,0.0);
            glVertex2f(0.0,-0.04);
            glVertex2f(-0.06,0.0);
            glEnd();
            glLoadIdentity();
            posx += 0.14;
          }
            hold += -0.07;
            posx = hold; posy += -0.07;
        }
    }



//Road++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glBegin(GL_TRIANGLE_FAN); //main road base
    glColor3ub(49, 14, 38);
    glVertex2f(-1.0,-0.52);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,-0.52);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //road bar+++++++++++++
    glColor3ub(33, 12, 31);
    glVertex2f(-1.0,-0.45);
    glVertex2f(-1.0,-0.47);
    glVertex2f(1.0,-0.47);
    glVertex2f(1.0,-0.45);
    glEnd();
    float dif = 0.0;
    for(int p= 0; p<29; p++ ){ //road bar small stripes
    glTranslatef(dif,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(33, 12, 31);
    glVertex2f(-0.98,-0.45);
    glVertex2f(-0.98,-0.52);
    glVertex2f(-0.96,-0.52);
    glVertex2f(-0.96,-0.45);
    glEnd();
    glLoadIdentity();
    dif += 0.07;
    }

    dif = 0.0;
    for(int p =0; p<4; p++){ //road middle yellow stripe
    glTranslatef(dif,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(178, 154, 116);
    glVertex2f(-0.98,-0.75);
    glVertex2f(-0.98,-0.77);
    glVertex2f(-0.68,-0.77);
    glVertex2f(-0.68,-0.75);
    glEnd();
    glLoadIdentity();
    dif += 0.5;
    }


//cherry blossom++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(position5, position5, 0);
    posy = 0.0;
    for(int j = 0; j < 5; j++){
        posx = 0.0;
        for(int i = 0; i < 10; i++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(209, 67, 152);
        glVertex2f( -1.0f + posx, 0.985f - posy);
        glVertex2f(-0.985f + posx, 0.97f - posy);
        glVertex2f(-0.97f + posx, 0.985f - posy);
        glEnd();
        posx = posx + 0.4;
        }
        posy = posy + 0.4;
        }
    glLoadIdentity();

    glTranslatef(position5, position5, 0);
    posy = 0.0;
    for(int j = 0; j < 5; j++){
        posx = 0.0;
        for(int i = 0; i < 10; i++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(209, 67, 152);
        glVertex2f( -1.0f + posx, 2.935f - posy);
        glVertex2f(-0.985f + posx, 2.92f - posy);
        glVertex2f(-0.97f + posx, 2.935f - posy);
        glEnd();
        posx = posx + 0.4;
        }
        posy = posy + 0.4;
        }
    glLoadIdentity();


    //car 1+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glScalef(1.2,1.2,1);
    glTranslatef(position7,0.1,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(77, 34, 124);
    glVertex2f(-.42,-0.78);
    glVertex2f(-.4,-.8);
    glVertex2f(-.2,-.8);
    glVertex2f(-0.18,-0.78);
    glVertex2f(-0.18,-0.7);
    glVertex2f(-0.2,-0.68);
    glVertex2f(-0.4,-0.68);
    glVertex2f(-0.42,-0.7);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car
    glColor3ub(47, 17, 86);
    glVertex2f(-.38,-0.8);
    glVertex2f(-.36,-0.8);
    glVertex2f(-.36,-0.68);
    glVertex2f(-.38,-0.68);
    glEnd();

    //strip
    pos = 0.0;
    for(i = 0; i<5; i++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(47, 17, 86);
        glVertex2f(-.35f +pos,-0.8);
        glVertex2f(-.33f +pos,-0.8);
        glVertex2f(-.33f +pos,-0.68);
        glVertex2f(-.35f +pos,-0.68);
        glEnd();
        pos += 0.03;
    }

    glBegin(GL_TRIANGLE_FAN); //head
    glColor3ub(166,134,168);
    glVertex2f(-.17,-0.77);
    glVertex2f(-.2,-0.8);
    glVertex2f(-.06,-0.8);
    glVertex2f(-.06,-0.76);
    glVertex2f(-.1,-0.71);
    glVertex2f(-.17,-0.71);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car 1 window
    glColor3ub(77,34,124);
    glVertex2f(-.15,-0.76);
    glVertex2f(-.08,-0.76);
    glVertex2f(-.11,-0.72);
    glVertex2f(-.15,-0.72);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //left wheel circle
    for(i = 0; i <= 21;i++) {
        glVertex2f(
         -0.3 + (.03 * cos(i * twicePi / 21)), //x
         -0.81 + (.03* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(77,34,124); //left small wheel
    for(i = 0; i <= 21;i++) {
        glVertex2f(
         -0.3 + (.01 * cos(i * twicePi / 21)), //x
         -0.81 + (.01* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
     glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //right wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
         -0.12 + (.03 * cos(i * twicePi / 21)), //x
         -0.81 + (.03* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
     glBegin(GL_TRIANGLE_FAN);
    glColor3ub(77,34,124); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.12 + (.01 * cos(i * twicePi / 21)), //x
     -0.81 + (.01* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();
    glLoadIdentity();

    //car 2++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(position8,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32, 47, 80);
    glVertex2f(.68,-0.58);
    glVertex2f (.7,-0.6);
    glVertex2f(.96,-0.6);
    glVertex2f(.98,-0.58);
    glVertex2f(.98,-0.46);
    glVertex2f(.96,-0.44);
    glVertex2f(.7,-0.44);
    glVertex2f(.68,-0.46);
    glEnd();

    pos = 0.0;
    for(i = 0; i<8; i++){
        glBegin(GL_TRIANGLE_FAN); //stripes
        glColor3ub(27, 39, 61);

        glVertex2f(.72f + pos,-0.6);
        glVertex2f (.74f + pos,-0.6);
        glVertex2f(.74f + pos,-0.44);
        glVertex2f(.72f + pos,-0.44);
        glEnd();
        pos += 0.03;
    }

    glBegin(GL_TRIANGLE_FAN); //car front part
    glColor3ub(111,151,161);
    glVertex2f(.52,-0.6);
    glVertex2f (.7,-0.6);
    glVertex2f(.675,-0.57);
    glVertex2f(.675,-0.48);
    glVertex2f(.56,-0.48);
    glVertex2f(.52,-0.56);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car window
    glColor3ub(32,47,80);
    glVertex2f(.56,-0.56);
    glVertex2f (.64,-0.56);
    glVertex2f(.64,-0.5);
    glVertex2f(.59,-0.5);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //left wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
        0.6 + (.04 * cos(i * twicePi / 21)), //x
         -0.61 + (.04* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,47,80); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
         0.6 + (.02 * cos(i * twicePi / 21)), //x
         -0.61 + (.02* sin(i * twicePi / 21)) //y
     );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //right wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
          0.9 + (.04 * cos(i * twicePi / 21)), //x
         -0.61 + (.04* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,47,80); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
          0.9 + (.02 * cos(i * twicePi / 21)), //x
         -0.61 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();
    glLoadIdentity();


	glFlush();
}

void morning() { //day}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

//Back ground....................................................................
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(138, 186, 253);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,-1.0);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(92, 147, 229);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,0.2);
    glVertex2f(1.0,0.2);
    glVertex2f(1.0,-1.0);
	glEnd();

	float jl = 0;

//sun==================================================================================
    for (int j = 0; j < 4; j++){
	glBegin(GL_TRIANGLE_FAN);
	   if (j == 0){
        glColor3ub(160, 196, 239); //SUN effect 2.............
        jl = .22;
	   }
	   else if (j == 1){
        glColor3ub(193, 213, 232); //SUN effect 1.............
         jl = .17;
	   }
	   else if (j == 2){
        glColor3ub(228, 234, 211); //SUN effect 1.............
         jl = .12;
	   }
	   else{
        glColor3ub(255, 255, 255); //SUN.............
        jl = .06;
	   }

		for(i = 0; i <= 21;i++) {
			glVertex2f(
			    -0.7 + (jl * cos(i *  twicePi / 21)), //x
			    .8 + (jl* sin(i * twicePi / 21)) //y
			);
		}
	glEnd();}

//smokes from mountain+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    float posx = 0.0, posy =0.0; //cloud 3++++++++++++++++++++++++
    glTranslatef(0,-0.4 + position6,0);
    for(int r=0; r<7; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.04f + posx,0.65f + posy);
        glVertex2f(-0.04f + posx,0.665f + posy);
        glVertex2f(0.04f - posx,0.665f + posy);
        glVertex2f(0.04f - posx,0.65f + posy);
        glEnd();
        posx += 0.01f; posy += 0.09f;
        if (r == 2){ posx =0.0;}
        else{ }
    }
    glLoadIdentity();

//clouds+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    posx = 0.0, posy =0.0; //cloud 3++++++++++++++++++++++++
    glTranslatef(0.4f + position3,0,0);
    glScalef(1.3,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();
//main mountain+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glBegin(GL_TRIANGLE_FAN);//main mountain base
    glColor3ub(138,134,199);
    glVertex2f(-0.5,0.51);
    glVertex2f(-1.1,0.2);
    glVertex2f(1.1,0.2);
    glVertex2f(0.5,0.51);
    glVertex2f(0.05,0.83);
    glVertex2f(-0.05,0.83);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//top ice part
    glColor3ub(220,218,230);
    glVertex2f(-0.05,0.83);
    glVertex2f(-0.3,0.6);
    glVertex2f(-0.2,0.5);
    glVertex2f(-0.05,0.66);
    glVertex2f(0.05,0.57);
    glVertex2f(0.05,0.83);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);//top ice part
    glColor3ub(220,218,230);
    glVertex2f(0.15,0.63);
    glVertex2f(0.05,0.57);
    glVertex2f(0.05,0.83);
    glVertex2f(0.5,0.51);
	glEnd();

    glBegin(GL_TRIANGLE_FAN); //light hitting top
    glColor3ub(253,255,230);
    glVertex2f(-0.5,0.51);
    glVertex2f(-0.28,0.57);
    glVertex2f(-0.2,0.65);
    glVertex2f(-0.29,0.6);
    glVertex2f(-0.05,0.83);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //light hitting down
    glColor3ub(216,214,180);
    glVertex2f(-1.1,0.2);
    glVertex2f(-0.8,0.2);
    glVertex2f(-0.6,0.35);
    glVertex2f(-0.75,0.3);
    glVertex2f(-0.28,0.57);
    glVertex2f(-0.5,0.51);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //Mountain shading
    glColor3ub(109,119,181);
    glVertex2f(-0.1,0.2);
    glVertex2f(-0.12,0.45);
    glVertex2f(-0.3,0.2);
    glEnd();
    glBegin(GL_TRIANGLE_FAN); //1
    glColor3ub(109,119,181);
    glVertex2f(0.1,0.2);
    glVertex2f(0.12,0.56);
    glVertex2f(0.3,0.2);
    glEnd();
    glBegin(GL_TRIANGLE_FAN); //2
    glColor3ub(109,119,181);
    glVertex2f(0.47,0.2);
    glVertex2f(0.4,0.3);
    glVertex2f(0.6,0.2);
    glEnd();

//mountain shade on water++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(0,0.06,0);
    glScalef(1,0.7,1);
    glBegin(GL_TRIANGLE_FAN);//main mountain base shadow
    glColor3ub(106,100,175);
    glVertex2f(-1.1,0.2);
    glVertex2f(1.1,0.2);
    glVertex2f(0.05,-0.63);
    glVertex2f(-0.05,-0.63);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//shadow ice part on water
    glColor3ub(159,181,214);
    glVertex2f(-0.05,-0.63);
    glVertex2f(-0.3,-0.4);
    glVertex2f(-0.2,-0.3);
    glVertex2f(-0.05,-0.46);
    glVertex2f(0.05,-0.37);
    glVertex2f(0.05,-0.63);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);//1
    glColor3ub(159,181,214);
    glVertex2f(0.15,-0.43);
    glVertex2f(0.05,-0.37);
    glVertex2f(0.05,-0.63);
    glVertex2f(0.451,-0.31);
	glEnd();
    glBegin(GL_TRIANGLE_FAN); //2
    glColor3ub(159,181,214);
    glVertex2f(-0.451,-0.31);
    glVertex2f(-0.28,-0.37);
    glVertex2f(-0.2,-0.45);
    glVertex2f(-0.29,-0.4);
    glVertex2f(-0.05,-0.63);
    glEnd();
    glLoadIdentity();

//Clouds+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    posx = 0.0, posy =0.0; //cloud 1+++++++++++++++++
    glTranslatef(position1,0,0);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();


    posx = 0.0, posy =0.0; //cloud 2+++++++++++++++++++++++
    glTranslatef(-0.4f + position2,0,0);
    glScalef(0.8,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();

    posx = 0.0, posy =0.0; //cloud 4++++++++++++++++++++++++
    glTranslatef(0.85f + position4,0,0);
    glScalef(0.8,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 250, 250);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();

//Ducks++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    float pos = 0;  posy = 0;
    for(int y =0; y<22; y++){
    if(y == 6){pos = -0.3; posy = 0.1;}
    else if(y == 14){pos = -0.3; posy = -0.1;}
    glTranslatef(position + pos, 0.0f + posy, 0.0f);
    glBegin(GL_TRIANGLE_FAN); //main body
    glColor3ub(255,255,255);
    glVertex2f(-0.6f ,0.0f );
    glVertex2f(-0.55f ,0.0f );
    glVertex2f(-0.56f ,0.02f );
    glVertex2f(-0.6f ,0.01f );
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //throat
    glVertex2f(-0.6f ,0.0f );
    glVertex2f(-0.59f ,0.0f );
    glVertex2f(-0.59f ,0.05f );
    glVertex2f(-0.6f ,0.05f );
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //beak
    glColor3ub(200,0,0);
    glVertex2f(-0.6f ,0.04f );
    glVertex2f(-0.6f ,0.05f );
    glVertex2f(-0.62f ,0.045f );
    glEnd();
    glLoadIdentity();

    pos += 0.6;
    }

//Background houses +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//3RD

glScalef(1.3,1.3,1);
glTranslatef(1.15,-.4,0);
glBegin(GL_TRIANGLE_FAN);//3T
glColor3ub(78,173,128);
glVertex2f(-0.94,-0.1);
glVertex2f(-0.74,-0.1);
glVertex2f(-0.74,-0.02);
glVertex2f(-.94,-0.02);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3R
glColor3ub(78,173,128);
glVertex2f(-1,-0.02);
glVertex2f(-0.68,-0.02);
glVertex2f(-0.78,0.04);
glVertex2f(-.9,0.04);
glEnd();

//TOP
glBegin(GL_TRIANGLE_FAN);//TT
glColor3ub(78,173,128);
glVertex2f(-0.9,0.04);
glVertex2f(-0.78,0.04);
glVertex2f(-0.78,0.1);
glVertex2f(-.9,0.1);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TR
glColor3ub(78,173,128);
glVertex2f(-.96,0.1);
glVertex2f(-0.72,0.1);
glVertex2f(-0.82,0.16);
glVertex2f(-.86,0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRT
glColor3ub(78,173,128);
glVertex2f(-.86,0.16);
glVertex2f(-0.82,0.16);
glVertex2f(-0.82,0.18);
glVertex2f(-.86,0.18);
glEnd();
glLoadIdentity();

//circle++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


glBegin(GL_TRIANGLE_FAN);
glColor3ub(57,145,105); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.6 + (.15 * cos(i * twicePi / 21)), //x
 -0.15 + (.15* sin(i * twicePi / 21)) //y
);
}
glEnd();



glBegin(GL_TRIANGLE_FAN);
glColor3ub(57,145,105); //left big circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-.5 + (.4 * cos(i * twicePi / 21)), //x
-0.56 + (.4* sin(i * twicePi / 21)) //y
);
}
glEnd();



glBegin(GL_TRIANGLE_FAN);
glColor3ub(57,145,105); //middle circle
for(i = 0; i <= 21;i++) {
glVertex2f(
 .1 + (.4* cos(i * twicePi / 21)), //x0
-0.75 + (.4* sin(i * twicePi / 21)) //y
);
}
glEnd();


glScalef(1.3,1.35,1);
glTranslatef(0.2,0.1,0);
//LEFT BUILDING+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//GROUND
glBegin(GL_TRIANGLE_FAN);//GT
glColor3ub(183,107,92);
glVertex2f(-1,-0.52);
glVertex2f(-0.6,-0.52);
glVertex2f(-0.6,-0.44);
glVertex2f(-1,-0.44);
glEnd();

glBegin(GL_TRIANGLE_FAN);//GR
glColor3ub(178,80,169);
glVertex2f(-1,-0.44);
glVertex2f(-0.54,-0.44);
glVertex2f(-0.66,-0.38);
glVertex2f(-1,-0.38);
glEnd();

glBegin(GL_TRIANGLE_FAN);//GL
glColor3ub(91, 29, 54);
glVertex2f(-1,-0.47);
glVertex2f(-0.6,-0.47);
glVertex2f(-0.6,-0.46);
glVertex2f(-1,-0.46);
glEnd();

glBegin(GL_TRIANGLE_FAN);//GLP
glColor3ub(91, 29, 54);
glVertex2f(-.98,-0.52);
glVertex2f(-0.97,-0.52);
glVertex2f(-0.97,-0.47);
glVertex2f(-.98,-0.47);
glEnd();

glBegin(GL_TRIANGLE_FAN);//GRP
glColor3ub(91, 29, 54);
glVertex2f(-.64,-0.52);
glVertex2f(-0.63,-0.52);
glVertex2f(-0.63,-0.47);
glVertex2f(-.64,-0.47);
glEnd();

//light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.56,-0.44);
    glVertex2f(-.56,-0.46);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.56 + (.02 * cos(i * twicePi / 21)), //x
-0.48 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();



//1ST
glBegin(GL_TRIANGLE_FAN);//1T
glColor3ub(183,107,92);
glVertex2f(-1,-0.38);
glVertex2f(-0.66,-0.38);
glVertex2f(-0.66,-0.3);
glVertex2f(-1,-0.3);
glEnd();


glBegin(GL_TRIANGLE_FAN);//1R
glColor3ub(178,80,169);
glVertex2f(-1,-0.3);
glVertex2f(-0.6,-0.3);
glVertex2f(-0.7,-0.24);
glVertex2f(-1,-0.24);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1L
glColor3ub(91, 29, 54);
glVertex2f(-1,-0.32);
glVertex2f(-0.66,-0.32);
glVertex2f(-0.66,-0.31);
glVertex2f(-1,-0.31);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1LP
glColor3ub(91, 29, 54);
glVertex2f(-.98,-0.38);
glVertex2f(-0.97,-0.38);
glVertex2f(-0.97,-0.32);
glVertex2f(-.98,-0.32);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1ST RIGHT P
glColor3ub(91, 29, 54);
glVertex2f(-.69,-0.38);
glVertex2f(-0.68,-0.38);
glVertex2f(-0.68,-0.32);
glVertex2f(-.69,-0.32);
glEnd();

glBegin(GL_TRIANGLE_FAN);//left window
glColor3ub(244,222,208);
glVertex2f(-.92,-0.36);
glVertex2f(-0.88,-0.36);
glVertex2f(-0.88,-0.34);
glVertex2f(-.92,-0.34);
glEnd();

glBegin(GL_TRIANGLE_FAN);//left window
glColor3ub(244,222,208);
glVertex2f(-.78,-0.36);
glVertex2f(-0.74,-0.36);
glVertex2f(-0.74,-0.34);
glVertex2f(-.78,-0.34);
glEnd();

//light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.62,-0.3);
    glVertex2f(-.62,-0.32);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.62 + (.02 * cos(i * twicePi / 21)), //x
-0.34 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

//2ND
glBegin(GL_TRIANGLE_FAN);//2T
glColor3ub(183,107,92);
glVertex2f(-0.98,-0.24);
glVertex2f(-0.7,-0.24);
glVertex2f(-0.7,-0.16);
glVertex2f(-.98,-0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2R
glColor3ub(178,80,169);
glVertex2f(-1,-0.16);
glVertex2f(-0.64,-0.16);
glVertex2f(-0.74,-0.1);
glVertex2f(-.94,-0.1);

glEnd();

glBegin(GL_TRIANGLE_FAN);//2L
glColor3ub(91,29,54);
glVertex2f(-.98,-0.18);
glVertex2f(-0.7,-0.18);
glVertex2f(-0.7,-0.17);
glVertex2f(-0.98,-0.17);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2LP
glColor3ub(91,29,54);
glVertex2f(-.95,-0.24);
glVertex2f(-0.96,-0.24);
glVertex2f(-0.96,-0.18);
glVertex2f(-.95,-0.18);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2RP
glColor3ub(91,29,54);
glVertex2f(-.73,-0.24);
glVertex2f(-0.72,-0.24);
glVertex2f(-0.72,-0.18);
glVertex2f(-.73,-0.18);
glEnd();
//windows
glBegin(GL_TRIANGLE_FAN);//left
glColor3ub(244,222,208);
glVertex2f(-.92,-0.22);
glVertex2f(-0.88,-0.22);
glVertex2f(-0.88,-0.2);
glVertex2f(-.92,-0.2);
glEnd();

glBegin(GL_TRIANGLE_FAN);//right
glColor3ub(244,222,208);
glVertex2f(-.8,-0.22);
glVertex2f(-0.76,-0.22);
glVertex2f(-0.76,-0.2);
glVertex2f(-.8,-0.2);
glEnd();

//light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.66,-0.16);
    glVertex2f(-.66,-0.18);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.66 + (.02 * cos(i * twicePi / 21)), //x
-0.2 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

//3RD
glBegin(GL_TRIANGLE_FAN);//3T
glColor3ub(183,107,92);
glVertex2f(-0.94,-0.1);
glVertex2f(-0.74,-0.1);
glVertex2f(-0.74,-0.02);
glVertex2f(-.94,-0.02);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3R
glColor3ub(178,80,169);
glVertex2f(-1,-0.02);
glVertex2f(-0.68,-0.02);
glVertex2f(-0.78,0.04);
glVertex2f(-.9,0.04);

glEnd();

glBegin(GL_TRIANGLE_FAN);//3L
glColor3ub(91,29,54);
glVertex2f(-.94,-0.04);
glVertex2f(-0.74,-0.04);
glVertex2f(-0.74,-0.03);
glVertex2f(-0.94,-0.03);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3LP
glColor3ub(91,29,54);
glVertex2f(-.92,-0.1);
glVertex2f(-0.91,-0.1);
glVertex2f(-0.91,-0.04);
glVertex2f(-.92,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3RP
glColor3ub(91,29,54);
glVertex2f(-.77,-0.1);
glVertex2f(-0.76,-0.1);
glVertex2f(-0.76,-0.04);
glVertex2f(-.77,-0.04);
glEnd();

// right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.7,-0.02);
    glVertex2f(-.7,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.7 + (.02 * cos(i * twicePi / 21)), //x
-0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();
// Right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.98,-0.02);
    glVertex2f(-.98,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.98 + (.02 * cos(i * twicePi / 21)), //x
-0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

//TOP
glBegin(GL_TRIANGLE_FAN);//TT
glColor3ub(183,107,92);
glVertex2f(-0.9,0.04);
glVertex2f(-0.78,0.04);
glVertex2f(-0.78,0.1);
glVertex2f(-.9,0.1);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TR
glColor3ub(178,80,169);
glVertex2f(-.96,0.1);
glVertex2f(-0.72,0.1);
glVertex2f(-0.82,0.16);
glVertex2f(-.86,0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRT
glColor3ub(0,0,0);
glVertex2f(-.86,0.16);
glVertex2f(-0.82,0.16);
glVertex2f(-0.82,0.18);
glVertex2f(-.86,0.18);
glEnd();

glBegin(GL_TRIANGLE_FAN);//window
glColor3ub(244,222,208);
glVertex2f(-.86,-0.08);
glVertex2f(-0.82,-0.08);
glVertex2f(-0.82,-0.06);
glVertex2f(-.86,-0.06);
glEnd();

//TOWER
glBegin(GL_TRIANGLE_FAN);
glColor3ub(0,0,0);
glVertex2f(-.85,0.18);
glVertex2f(-0.83,0.18);
glVertex2f(-0.83,0.4);
glVertex2f(-.85,0.4);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1
glColor3ub(0,0,0);
glVertex2f(-.88,0.36);
glVertex2f(-0.8,0.36);
glVertex2f(-0.8,0.38);
glVertex2f(-.88,0.38);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2
glColor3ub(0,0,0);
glVertex2f(-.88,0.32);
glVertex2f(-0.8,0.32);
glVertex2f(-0.8,0.34);
glVertex2f(-.88,0.34);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3
glColor3ub(0,0,0);
glVertex2f(-.88,0.28);
glVertex2f(-0.8,0.28);
glVertex2f(-0.8,0.3);
glVertex2f(-.88,0.3);
glEnd();


glBegin(GL_TRIANGLE_FAN);//TL
glColor3ub(91,29,54);
glVertex2f(-.9,0.08);
glVertex2f(-0.78,0.08);
glVertex2f(-0.78,0.09);
glVertex2f(-0.9,0.09);
glEnd();



glBegin(GL_TRIANGLE_FAN);//TLP
glColor3ub(91,29,54);
glVertex2f(-.88,0.04);
glVertex2f(-0.87,0.04);
glVertex2f(-0.87,0.08);
glVertex2f(-.88,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRP
glColor3ub(91,29,54);
glVertex2f(-.80,0.04);
glVertex2f(-0.81,0.04);
glVertex2f(-0.81,0.08);
glVertex2f(-.8,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);//window of top
glColor3ub(244,222,208);
glVertex2f(-.82,0.05);
glVertex2f(-0.86,0.05);
glVertex2f(-0.86,0.07);
glVertex2f(-.82,0.07);
glEnd();

//left light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.74,0.1);
    glVertex2f(-.74,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.74 + (.02 * cos(i * twicePi / 21)), //x
0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

// right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.94,0.1);
    glVertex2f(-.94,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.94 + (.02 * cos(i * twicePi / 21)), //x
0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

glLoadIdentity();

//right side building+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
glTranslatef(1.7,-.05,0);
glScalef(1,1.2,1);

//right BUILDING
//GROUND
glBegin(GL_TRIANGLE_FAN);//GR
glColor3ub(78,173,128);
glVertex2f(-1.09,-0.44);
glVertex2f(-0.54,-0.44);
glVertex2f(-0.66,-0.38);
glVertex2f(-1,-0.38);
glEnd();

//1ST
glBegin(GL_TRIANGLE_FAN);//1T
glColor3ub(78,173,128);
glVertex2f(-1,-0.38);
glVertex2f(-0.66,-0.38);
glVertex2f(-0.66,-0.3);
glVertex2f(-1,-0.3);
glEnd();


glBegin(GL_TRIANGLE_FAN);//1R
glColor3ub(78,173,128);
glVertex2f(-1.07,-0.3);
glVertex2f(-0.6,-0.3);
glVertex2f(-0.7,-0.24);
glVertex2f(-0.98,-0.24);
glEnd();


//2ND
glBegin(GL_TRIANGLE_FAN);//2T
glColor3ub(78,173,128);
glVertex2f(-0.98,-0.24);
glVertex2f(-0.7,-0.24);
glVertex2f(-0.7,-0.16);
glVertex2f(-.98,-0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2R
glColor3ub(78,173,128);
glVertex2f(-1.04,-0.16);
glVertex2f(-0.64,-0.16);
glVertex2f(-0.74,-0.1);
glVertex2f(-.94,-0.1);
glEnd();

//3RD
glBegin(GL_TRIANGLE_FAN);//3T
glColor3ub(78,173,128);
glVertex2f(-0.94,-0.1);
glVertex2f(-0.74,-0.1);
glVertex2f(-0.74,-0.02);
glVertex2f(-.94,-0.02);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3R
glColor3ub(78,173,128);
glVertex2f(-1,-0.02);
glVertex2f(-0.68,-0.02);
glVertex2f(-0.78,0.04);
glVertex2f(-.9,0.04);
glEnd();

//TOP
glBegin(GL_TRIANGLE_FAN);//TT
glColor3ub(78,173,128);
glVertex2f(-0.9,0.04);
glVertex2f(-0.78,0.04);
glVertex2f(-0.78,0.1);
glVertex2f(-.9,0.1);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TR
glColor3ub(78,173,128);
glVertex2f(-.96,0.1);
glVertex2f(-0.72,0.1);
glVertex2f(-0.82,0.16);
glVertex2f(-.86,0.16);
glEnd();

//TOWER
glBegin(GL_TRIANGLE_FAN);
glColor3ub(78,173,128);
glVertex2f(-.85,0.18);
glVertex2f(-0.83,0.18);
glVertex2f(-0.83,0.4);
glVertex2f(-.85,0.4);
glEnd();

glBegin(GL_TRIANGLE_FAN);//1
glColor3ub(78,173,128);
glVertex2f(-.88,0.36);
glVertex2f(-0.8,0.36);
glVertex2f(-0.8,0.38);
glVertex2f(-.88,0.38);
glEnd();

glBegin(GL_TRIANGLE_FAN);//2
glColor3ub(78,173,128);
glVertex2f(-.88,0.32);
glVertex2f(-0.8,0.32);
glVertex2f(-0.8,0.34);
glVertex2f(-.88,0.34);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3
glColor3ub(78,173,128);
glVertex2f(-.88,0.28);
glVertex2f(-0.8,0.28);
glVertex2f(-0.8,0.3);
glVertex2f(-.88,0.3);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRT
glColor3ub(78,173,128);
glVertex2f(-.86,0.16);
glVertex2f(-0.82,0.16);
glVertex2f(-0.82,0.18);
glVertex2f(-.86,0.18);
glEnd();
glLoadIdentity();

//middle building*************************************************+++++++++++++++++
//3RD
glScalef(1.7,1.5,1);
glTranslatef(0.9,-.29,0);
glBegin(GL_TRIANGLE_FAN);//3T
glColor3ub(183,107,92);
glVertex2f(-0.94,-0.1);
glVertex2f(-0.74,-0.1);
glVertex2f(-0.74,-0.02);
glVertex2f(-.94,-0.02);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3R
glColor3ub(178,80,169);
glVertex2f(-1,-0.02);
glVertex2f(-0.68,-0.02);
glVertex2f(-0.78,0.04);
glVertex2f(-.9,0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3L
glColor3ub(91,29,54);
glVertex2f(-.94,-0.04);
glVertex2f(-0.74,-0.04);
glVertex2f(-0.74,-0.03);
glVertex2f(-0.94,-0.03);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3LP
glColor3ub(91,29,54);
glVertex2f(-.92,-0.1);
glVertex2f(-0.91,-0.1);
glVertex2f(-0.91,-0.04);
glVertex2f(-.92,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);//3RP
glColor3ub(91,29,54);
glVertex2f(-.77,-0.1);
glVertex2f(-0.76,-0.1);
glVertex2f(-0.76,-0.04);
glVertex2f(-.77,-0.04);
glEnd();

// right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.7,-0.02);
    glVertex2f(-.7,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.7 + (.02 * cos(i * twicePi / 21)), //x
-0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

// Right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.98,-0.02);
    glVertex2f(-.98,-0.04);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.98 + (.02 * cos(i * twicePi / 21)), //x
-0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

//TOP
glBegin(GL_TRIANGLE_FAN);//TT
glColor3ub(183,107,92);
glVertex2f(-0.9,0.04);
glVertex2f(-0.78,0.04);
glVertex2f(-0.78,0.1);
glVertex2f(-.9,0.1);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TR
glColor3ub(178,80,169);
glVertex2f(-.96,0.1);
glVertex2f(-0.72,0.1);
glVertex2f(-0.82,0.16);
glVertex2f(-.86,0.16);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRT
glColor3ub(0,0,0);
glVertex2f(-.86,0.16);
glVertex2f(-0.82,0.16);
glVertex2f(-0.82,0.18);
glVertex2f(-.86,0.18);
glEnd();

glBegin(GL_TRIANGLE_FAN);//window
glColor3ub(244,222,208);
glVertex2f(-.86,-0.08);
glVertex2f(-0.82,-0.08);
glVertex2f(-0.82,-0.06);
glVertex2f(-.86,-0.06);
glEnd();

glBegin(GL_TRIANGLE_FAN);//
glColor3ub(244,222,208);
glVertex2f(-.82,0.05);
glVertex2f(-0.86,0.05);
glVertex2f(-0.86,0.07);
glVertex2f(-.82,0.07);
glEnd();

//left light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.74,0.1);
    glVertex2f(-.74,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.74 + (.02 * cos(i * twicePi / 21)), //x
0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();

// right light
glBegin(GL_LINES);
glColor3ub(0,0,0);
    glVertex2f(-.94,0.1);
    glVertex2f(-.94,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);
glColor3ub(255,255,255); //left small circle
for(i = 0; i <= 21;i++) {
glVertex2f(
-0.94 + (.02 * cos(i * twicePi / 21)), //x
0.06 + (.02* sin(i * twicePi / 21)) //y
);
}
glEnd();
glBegin(GL_TRIANGLE_FAN);//TL
glColor3ub(91,29,54);
glVertex2f(-.9,0.08);
glVertex2f(-0.78,0.08);
glVertex2f(-0.78,0.09);
glVertex2f(-0.9,0.09);
glEnd();



glBegin(GL_TRIANGLE_FAN);//TLP
glColor3ub(91,29,54);
glVertex2f(-.88,0.04);
glVertex2f(-0.87,0.04);
glVertex2f(-0.87,0.08);
glVertex2f(-.88,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRP
glColor3ub(91,29,54);
glVertex2f(-.80,0.04);
glVertex2f(-0.81,0.04);
glVertex2f(-0.81,0.08);
glVertex2f(-.8,0.08);
glEnd();

glBegin(GL_TRIANGLE_FAN);//TRP
glColor3ub(244,222,208);
glVertex2f(-.82,0.05);
glVertex2f(-0.86,0.05);
glVertex2f(-0.86,0.07);
glVertex2f(-.82,0.07);
glEnd();
glLoadIdentity();

//tree++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 pos = 0.0; posy = 0.0;
 for(i = 0; i< 3; i++){
    glTranslatef(pos, posy,0);
    glBegin(GL_TRIANGLE_FAN);  //big branches
    glColor3ub(155,95,95);
    glVertex2f(1.0, -0.4);
    glVertex2f(0.86, -0.35);
    glVertex2f(0.66, -0.35);
    glVertex2f(0.46, -0.36);
    glVertex2f(0.66, -0.37);
    glVertex2f(0.86, -0.38);
    glVertex2f(1.0, -0.44);
    glEnd();
    posy += 0.08;
    pos += 0.07;
    glLoadIdentity();
    }
    glBegin(GL_TRIANGLE_FAN);  //small branches
    glColor3ub(155,95,95);
    glVertex2f(0.66, -0.37);
    glVertex2f(0.63, -0.37);
    glVertex2f(0.6, -0.43);
    glEnd();

//tree leaves++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    posx = 0,posy = 0;
    float hold = 0;
    for(int t=0; t<4; t++){
        if(t==0){posx=1.4,posy=-0.78,hold=0;}
        else if(t==1){posx=1.7,posy=-0.56;}
        else if(t==2){posx=2.3,posy=-0.35;}
        else if(t==3){posx=2.4,posy=-0.8;}
        hold = posx;
        for(int i= 1; i<=3; i++){
          for(int j=0; j<(i+3); j++){
            glScalef(0.35,0.45,1);
            glTranslatef(posx, posy, 0);
            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(250, 227, 252);
            glVertex2f(0.0,0.04);
            glVertex2f(0.06,0.0);
            glVertex2f(0.0,-0.04);
            glVertex2f(-0.06,0.0);
            glEnd();
            glLoadIdentity();
            posx += 0.14;
          }
            hold += -0.07;
            posx = hold; posy += -0.07;
        }
    }

//Road++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glBegin(GL_TRIANGLE_FAN); //main road base
    glColor3ub(52, 55, 58);
    glVertex2f(-1.0,-0.52);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,-0.52);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //road bar+++++++++++++
    glColor3ub(33, 12, 31);
    glVertex2f(-1.0,-0.45);
    glVertex2f(-1.0,-0.47);
    glVertex2f(1.0,-0.47);
    glVertex2f(1.0,-0.45);
    glEnd();
    float dif = 0.0;
    for(int p= 0; p<29; p++ ){ //road bar small stripes
    glTranslatef(dif,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(33, 12, 31);
    glVertex2f(-0.98,-0.45);
    glVertex2f(-0.98,-0.52);
    glVertex2f(-0.96,-0.52);
    glVertex2f(-0.96,-0.45);
    glEnd();
    glLoadIdentity();
    dif += 0.07;
    }

    dif = 0.0;
    for(int p =0; p<4; p++){ //road middle yellow stripe
    glTranslatef(dif,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(221, 171, 104);
    glVertex2f(-0.98,-0.75);
    glVertex2f(-0.98,-0.77);
    glVertex2f(-0.68,-0.77);
    glVertex2f(-0.68,-0.75);
    glEnd();
    glLoadIdentity();
    dif += 0.5;
    }

//car 1++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glScalef(1.2,1.2,1);
    glTranslatef(position7,0.1,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(78, 115, 160);
    glVertex2f(-.42,-0.78);
    glVertex2f(-.4,-.8);
    glVertex2f(-.2,-.8);
    glVertex2f(-0.18,-0.78);
    glVertex2f(-0.18,-0.7);
    glVertex2f(-0.2,-0.68);
    glVertex2f(-0.4,-0.68);
    glVertex2f(-0.42,-0.7);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car
    glColor3ub(41, 66, 104);
    glVertex2f(-.38,-0.8);
    glVertex2f(-.36,-0.8);
    glVertex2f(-.36,-0.68);
    glVertex2f(-.38,-0.68);
    glEnd();

    //strip
    pos = 0.0;
    for(i = 0; i<5; i++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(41, 66, 104);
        glVertex2f(-.35f +pos,-0.8);
        glVertex2f(-.33f +pos,-0.8);
        glVertex2f(-.33f +pos,-0.68);
        glVertex2f(-.35f +pos,-0.68);
        glEnd();
        pos += 0.03;
    }

    glBegin(GL_TRIANGLE_FAN); //head
    glColor3ub(126,172,183);
    glVertex2f(-.17,-0.77);
    glVertex2f(-.2,-0.8);
    glVertex2f(-.06,-0.8);
    glVertex2f(-.06,-0.76);
    glVertex2f(-.1,-0.71);
    glVertex2f(-.17,-0.71);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car 1 window
    glColor3ub(78, 115, 160);
    glVertex2f(-.15,-0.76);
    glVertex2f(-.08,-0.76);
    glVertex2f(-.11,-0.72);
    glVertex2f(-.15,-0.72);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //left wheel circle
    for(i = 0; i <= 21;i++) {
        glVertex2f(
         -0.3 + (.03 * cos(i * twicePi / 21)), //x
         -0.81 + (.03* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(41, 66, 104); //left small wheel
    for(i = 0; i <= 21;i++) {
        glVertex2f(
         -0.3 + (.01 * cos(i * twicePi / 21)), //x
         -0.81 + (.01* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
     glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //right wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
         -0.12 + (.03 * cos(i * twicePi / 21)), //x
         -0.81 + (.03* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
     glBegin(GL_TRIANGLE_FAN);
    glColor3ub(41, 66, 104); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.12 + (.01 * cos(i * twicePi / 21)), //x
     -0.81 + (.01* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();
    glLoadIdentity();

    //car 2++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(position8,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(128, 94, 181);
    glVertex2f(.68,-0.58);
    glVertex2f (.7,-0.6);
    glVertex2f(.96,-0.6);
    glVertex2f(.98,-0.58);
    glVertex2f(.98,-0.46);
    glVertex2f(.96,-0.44);
    glVertex2f(.7,-0.44);
    glVertex2f(.68,-0.46);
    glEnd();

    pos = 0.0;
    for(i = 0; i<8; i++){
        glBegin(GL_TRIANGLE_FAN); //stripes
        glColor3ub(59, 34, 107);

        glVertex2f(.72f + pos,-0.6);
        glVertex2f (.74f + pos,-0.6);
        glVertex2f(.74f + pos,-0.44);
        glVertex2f(.72f + pos,-0.44);
        glEnd();
        pos += 0.03;
    }

    glBegin(GL_TRIANGLE_FAN); //car front part
    glColor3ub(209,167,196);
    glVertex2f(.52,-0.6);
    glVertex2f (.7,-0.6);
    glVertex2f(.675,-0.57);
    glVertex2f(.675,-0.48);
    glVertex2f(.56,-0.48);
    glVertex2f(.52,-0.56);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car window
    glColor3ub(128, 94, 181);
    glVertex2f(.56,-0.56);
    glVertex2f (.64,-0.56);
    glVertex2f(.64,-0.5);
    glVertex2f(.59,-0.5);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //left wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
        0.6 + (.04 * cos(i * twicePi / 21)), //x
         -0.61 + (.04* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(59, 34, 107); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
         0.6 + (.02 * cos(i * twicePi / 21)), //x
         -0.61 + (.02* sin(i * twicePi / 21)) //y
     );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //right wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
          0.9 + (.04 * cos(i * twicePi / 21)), //x
         -0.61 + (.04* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(59, 34, 107); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
          0.9 + (.02 * cos(i * twicePi / 21)), //x
         -0.61 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();
    glLoadIdentity();



//Snow++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(position5, position5, 0);
    posy = 0.0;
    for(int j = 0; j < 10; j++){
        posx = 0.0;
        for(int i = 0; i < 20; i++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255, 255, 255);
        glVertex2f( -1.0f + posx, 0.985f - posy);
        glVertex2f(-0.985f + posx, 0.97f - posy);
        glVertex2f(-0.97f + posx, 0.985f - posy);
        glEnd();
        posx = posx + 0.2;
        }
        posy = posy + 0.2;
        }
    glLoadIdentity();

    glTranslatef(position5, position5, 0);
    posy = 0.0;
    for(int j = 0; j < 10; j++){
        posx = 0.0;
        for(int i = 0; i < 20; i++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(255, 255, 255);
        glVertex2f( -1.0f + posx, 2.935f - posy);
        glVertex2f(-0.985f + posx, 2.92f - posy);
        glVertex2f(-0.97f + posx, 2.935f - posy);
        glEnd();
        posx = posx + 0.2;
        }
        posy = posy + 0.2;
        }
    glLoadIdentity();


	glFlush();
}



void night() { //night}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

//Back ground....................................................................
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 38, 115);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(1.0,1.0);
    glVertex2f(1.0,-1.0);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(2, 39, 91);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,0.2);
    glVertex2f(1.0,0.2);
    glVertex2f(1.0,-1.0);
	glEnd();

	float jl = 0;

//sun==================================================================================
    for (int j = 0; j < 4; j++){
	glBegin(GL_TRIANGLE_FAN);
	   if (j == 0){
        glColor3ub(27, 68, 135); //SUN effect 2.............
        jl = .22;
	   }
	   else if (j == 1){
        glColor3ub(59, 105, 165); //SUN effect 1.............
         jl = .17;
	   }
	   else if (j == 2){
        glColor3ub(118, 157, 193); //SUN effect 1.............
         jl = .12;
	   }
	   else{
        glColor3ub(255, 255, 255); //SUN.............
        jl = .06;
	   }

		for(i = 0; i <= 21;i++) {
			glVertex2f(
			    -0.7 + (jl * cos(i *  twicePi / 21)), //x
			    .8 + (jl* sin(i * twicePi / 21)) //y
			);
		}
	glEnd();}

//smokes from mountain+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    float posx = 0.0, posy =0.0; //cloud 3++++++++++++++++++++++++
    glTranslatef(0,-0.4 + position6,0);
    for(int r=0; r<7; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(193, 206, 224);
        glVertex2f(-0.04f + posx,0.65f + posy);
        glVertex2f(-0.04f + posx,0.665f + posy);
        glVertex2f(0.04f - posx,0.665f + posy);
        glVertex2f(0.04f - posx,0.65f + posy);
        glEnd();
        posx += 0.01f; posy += 0.09f;
        if (r == 2){ posx =0.0;}
        else{ }
    }
    glLoadIdentity();

//clouds+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    posx = 0.0, posy =0.0; //cloud 3++++++++++++++++++++++++
    glTranslatef(0.4f + position3,0,0);
    glScalef(1.3,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(193, 206, 224);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();

//main mountain+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glBegin(GL_TRIANGLE_FAN);//main mountain base
    glColor3ub(27,64,119);
    glVertex2f(-0.5,0.51);
    glVertex2f(-1.1,0.2);
    glVertex2f(1.1,0.2);
    glVertex2f(0.5,0.51);
    glVertex2f(0.05,0.83);
    glVertex2f(-0.05,0.83);
	glEnd();

    glBegin(GL_TRIANGLE_FAN);//top ice part
    glColor3ub(96,104,172);
    glVertex2f(-0.05,0.83);
    glVertex2f(-0.3,0.6);
    glVertex2f(-0.2,0.5);
    glVertex2f(-0.05,0.66);
    glVertex2f(0.05,0.57);
    glVertex2f(0.05,0.83);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);//top ice part
    glColor3ub(96,104,172);
    glVertex2f(0.15,0.63);
    glVertex2f(0.05,0.57);
    glVertex2f(0.05,0.83);
    glVertex2f(0.5,0.51);
	glEnd();

    glBegin(GL_TRIANGLE_FAN); //light hitting top
    glColor3ub(226,226,222);
    glVertex2f(-0.5,0.51);
    glVertex2f(-0.28,0.57);
    glVertex2f(-0.2,0.65);
    glVertex2f(-0.29,0.6);
    glVertex2f(-0.05,0.83);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //light hitting down
    glColor3ub(114,134,155);
    glVertex2f(-1.1,0.2);
    glVertex2f(-0.8,0.2);
    glVertex2f(-0.6,0.35);
    glVertex2f(-0.75,0.3);
    glVertex2f(-0.28,0.57);
    glVertex2f(-0.5,0.51);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //Mountain shading
    glColor3ub(0,27,69);
    glVertex2f(-0.1,0.2);
    glVertex2f(-0.12,0.45);
    glVertex2f(-0.3,0.2);
    glEnd();
    glBegin(GL_TRIANGLE_FAN); //1
    glColor3ub(0,27,69);
    glVertex2f(0.1,0.2);
    glVertex2f(0.12,0.56);
    glVertex2f(0.3,0.2);
    glEnd();
    glBegin(GL_TRIANGLE_FAN); //2
    glColor3ub(0,27,69);
    glVertex2f(0.47,0.2);
    glVertex2f(0.4,0.3);
    glVertex2f(0.6,0.2);
    glEnd();

//mountain shade on water++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(0,0.06,0);
    glScalef(1,0.7,1);

    glBegin(GL_TRIANGLE_FAN);//shadow ice part on water
    glColor3ub(61,72,119);
    glVertex2f(-0.05,-0.63);
    glVertex2f(-0.3,-0.4);
    glVertex2f(-0.2,-0.3);
    glVertex2f(-0.05,-0.46);
    glVertex2f(0.05,-0.37);
    glVertex2f(0.05,-0.63);
	glEnd();
	glBegin(GL_TRIANGLE_FAN);//1
    glColor3ub(61,72,119);
    glVertex2f(0.15,-0.43);
    glVertex2f(0.05,-0.37);
    glVertex2f(0.05,-0.63);
    glVertex2f(0.451,-0.31);
	glEnd();
    glBegin(GL_TRIANGLE_FAN); //2
    glColor3ub(61,72,119);
    glVertex2f(-0.451,-0.31);
    glVertex2f(-0.28,-0.37);
    glVertex2f(-0.2,-0.45);
    glVertex2f(-0.29,-0.4);
    glVertex2f(-0.05,-0.63);
    glEnd();
    glLoadIdentity();

//Clouds+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    posx = 0.0, posy =0.0; //cloud 1+++++++++++++++++
    glTranslatef(position1,0,0);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(193, 206, 224);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();


    posx = 0.0, posy =0.0; //cloud 2+++++++++++++++++++++++
    glTranslatef(-0.4f + position2,0,0);
    glScalef(0.8,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(193, 206, 224);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();

    posx = 0.0, posy =0.0; //cloud 4++++++++++++++++++++++++
    glTranslatef(0.85f + position4,0,0);
    glScalef(0.8,1,1);
    for(int r=0; r<6; r++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(193, 206, 224);
        glVertex2f(-0.15f + posx,0.65f + posy);
        glVertex2f(-0.15f + posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.66f + posy);
        glVertex2f(0.15f - posx,0.65f + posy);
        glEnd();
        if (r<4){ posx += 0.03f; posy += 0.01f; }
        else{ posx =0.0; posy = 0.0; posx += 0.03f; posy -= 0.01f; }
    }
    glLoadIdentity();

//floating lights++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    float pos = 0;  posy = 0;
    for(int y =0; y<22; y++){
    if(y == 6){pos = -0.3; posy = 0.1;}
    else if(y == 14){pos = -0.3; posy = -0.1;}
    glTranslatef(position, 0, 0);
    glBegin(GL_QUADS);
    glColor3ub(255,201,165);
    glVertex2f(-0.6f + pos,0.0f + posy);
    glVertex2f(-0.57f + pos,0.0f + posy);
    glVertex2f(-0.57f + pos,0.05f + posy);
    glVertex2f(-0.6f + pos,0.05f + posy);
    glEnd();
    glLoadIdentity();

    pos += 0.6;
    }

//Background houses +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//3RD

    glScalef(1.3,1.3,1);
    glTranslatef(1.15,-.4,0);
    glBegin(GL_TRIANGLE_FAN);//3T
    glColor3ub(15,79,140);
    glVertex2f(-0.94,-0.1);
    glVertex2f(-0.74,-0.1);
    glVertex2f(-0.74,-0.02);
    glVertex2f(-.94,-0.02);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3R
    glColor3ub(15,79,140);
    glVertex2f(-1,-0.02);
    glVertex2f(-0.68,-0.02);
    glVertex2f(-0.78,0.04);
    glVertex2f(-.9,0.04);
    glEnd();

    //TOP
    glBegin(GL_TRIANGLE_FAN);//TT
    glColor3ub(15,79,140);
    glVertex2f(-0.9,0.04);
    glVertex2f(-0.78,0.04);
    glVertex2f(-0.78,0.1);
    glVertex2f(-.9,0.1);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TR
    glColor3ub(15,79,140);
    glVertex2f(-.96,0.1);
    glVertex2f(-0.72,0.1);
    glVertex2f(-0.82,0.16);
    glVertex2f(-.86,0.16);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRT
    glColor3ub(15,79,140);
    glVertex2f(-.86,0.16);
    glVertex2f(-0.82,0.16);
    glVertex2f(-0.82,0.18);
    glVertex2f(-.86,0.18);
    glEnd();
    glLoadIdentity();

    //circle++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40,105,127); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.6 + (.15 * cos(i * twicePi / 21)), //x
     -0.15 + (.15* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();



    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40,105,127); //left big circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -.5 + (.4 * cos(i * twicePi / 21)), //x
    -0.56 + (.4* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();



    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(40,105,127); //middle circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
     .1 + (.4* cos(i * twicePi / 21)), //x0
    -0.75 + (.4* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();


    glScalef(1.3,1.35,1);
    glTranslatef(0.2,0.1,0);
    //LEFT BUILDING+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //GROUND
    glBegin(GL_TRIANGLE_FAN);//GT
    glColor3ub(112,54,43);
    glVertex2f(-1,-0.52);
    glVertex2f(-0.6,-0.52);
    glVertex2f(-0.6,-0.44);
    glVertex2f(-1,-0.44);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//GR
    glColor3ub(62,44,91);
    glVertex2f(-1,-0.44);
    glVertex2f(-0.54,-0.44);
    glVertex2f(-0.66,-0.38);
    glVertex2f(-1,-0.38);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//GL
    glColor3ub(45,11,28);
    glVertex2f(-1,-0.47);
    glVertex2f(-0.6,-0.47);
    glVertex2f(-0.6,-0.46);
    glVertex2f(-1,-0.46);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//GLP
    glColor3ub(45,11,28);
    glVertex2f(-.98,-0.52);
    glVertex2f(-0.97,-0.52);
    glVertex2f(-0.97,-0.47);
    glVertex2f(-.98,-0.47);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//GRP
    glColor3ub(45,11,28);
    glVertex2f(-.64,-0.52);
    glVertex2f(-0.63,-0.52);
    glVertex2f(-0.63,-0.47);
    glVertex2f(-.64,-0.47);
    glEnd();

    //light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.56,-0.44);
        glVertex2f(-.56,-0.46);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.56 + (.02 * cos(i * twicePi / 21)), //x
    -0.48 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();



    //1ST
    glBegin(GL_TRIANGLE_FAN);//1T
    glColor3ub(112,54,43);
    glVertex2f(-1,-0.38);
    glVertex2f(-0.66,-0.38);
    glVertex2f(-0.66,-0.3);
    glVertex2f(-1,-0.3);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);//GR
    glColor3ub(62,44,91);
    glVertex2f(-1,-0.3);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-0.7,-0.24);
    glVertex2f(-1,-0.24);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//1L
    glColor3ub(45,11,28);
    glVertex2f(-1,-0.32);
    glVertex2f(-0.66,-0.32);
    glVertex2f(-0.66,-0.31);
    glVertex2f(-1,-0.31);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//1LP
    glColor3ub(45,11,28);
    glVertex2f(-.98,-0.38);
    glVertex2f(-0.97,-0.38);
    glVertex2f(-0.97,-0.32);
    glVertex2f(-.98,-0.32);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//1ST RIGHT P
    glColor3ub(45,11,28);
    glVertex2f(-.69,-0.38);
    glVertex2f(-0.68,-0.38);
    glVertex2f(-0.68,-0.32);
    glVertex2f(-.69,-0.32);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//left window
    glColor3ub(255,201,165);
    glVertex2f(-.92,-0.36);
    glVertex2f(-0.88,-0.36);
    glVertex2f(-0.88,-0.34);
    glVertex2f(-.92,-0.34);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//left window
    glColor3ub(255,201,165);
    glVertex2f(-.78,-0.36);
    glVertex2f(-0.74,-0.36);
    glVertex2f(-0.74,-0.34);
    glVertex2f(-.78,-0.34);
    glEnd();

    //light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.62,-0.3);
        glVertex2f(-.62,-0.32);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.62 + (.02 * cos(i * twicePi / 21)), //x
    -0.34 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    //2ND
    glBegin(GL_TRIANGLE_FAN);//2T
    glColor3ub(112,54,43);
    glVertex2f(-0.98,-0.24);
    glVertex2f(-0.7,-0.24);
    glVertex2f(-0.7,-0.16);
    glVertex2f(-.98,-0.16);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//2R
    glColor3ub(62,44,91);
    glVertex2f(-1,-0.16);
    glVertex2f(-0.64,-0.16);
    glVertex2f(-0.74,-0.1);
    glVertex2f(-.94,-0.1);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);//2L
    glColor3ub(45,11,28);
    glVertex2f(-.98,-0.18);
    glVertex2f(-0.7,-0.18);
    glVertex2f(-0.7,-0.17);
    glVertex2f(-0.98,-0.17);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//2LP
    glColor3ub(45,11,28);
    glVertex2f(-.95,-0.24);
    glVertex2f(-0.96,-0.24);
    glVertex2f(-0.96,-0.18);
    glVertex2f(-.95,-0.18);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//2RP
    glColor3ub(45,11,28);
    glVertex2f(-.73,-0.24);
    glVertex2f(-0.72,-0.24);
    glVertex2f(-0.72,-0.18);
    glVertex2f(-.73,-0.18);
    glEnd();
    //windows
    glBegin(GL_TRIANGLE_FAN);//left
    glColor3ub(255,201,165);
    glVertex2f(-.92,-0.22);
    glVertex2f(-0.88,-0.22);
    glVertex2f(-0.88,-0.2);
    glVertex2f(-.92,-0.2);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//right
    glColor3ub(255,201,165);
    glVertex2f(-.8,-0.22);
    glVertex2f(-0.76,-0.22);
    glVertex2f(-0.76,-0.2);
    glVertex2f(-.8,-0.2);
    glEnd();

    //light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.66,-0.16);
        glVertex2f(-.66,-0.18);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.66 + (.02 * cos(i * twicePi / 21)), //x
    -0.2 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    //3RD
    glBegin(GL_TRIANGLE_FAN);//3T
    glColor3ub(112,54,43);
    glVertex2f(-0.94,-0.1);
    glVertex2f(-0.74,-0.1);
    glVertex2f(-0.74,-0.02);
    glVertex2f(-.94,-0.02);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3R
    glColor3ub(62,44,91);
    glVertex2f(-1,-0.02);
    glVertex2f(-0.68,-0.02);
    glVertex2f(-0.78,0.04);
    glVertex2f(-.9,0.04);

    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3L
    glColor3ub(45,11,28);
    glVertex2f(-.94,-0.04);
    glVertex2f(-0.74,-0.04);
    glVertex2f(-0.74,-0.03);
    glVertex2f(-0.94,-0.03);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3LP
    glColor3ub(45,11,28);
    glVertex2f(-.92,-0.1);
    glVertex2f(-0.91,-0.1);
    glVertex2f(-0.91,-0.04);
    glVertex2f(-.92,-0.04);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3RP
    glColor3ub(45,11,28);
    glVertex2f(-.77,-0.1);
    glVertex2f(-0.76,-0.1);
    glVertex2f(-0.76,-0.04);
    glVertex2f(-.77,-0.04);
    glEnd();

    // right light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.7,-0.02);
        glVertex2f(-.7,-0.04);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.7 + (.02 * cos(i * twicePi / 21)), //x
    -0.06 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();
    // Right light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.98,-0.02);
        glVertex2f(-.98,-0.04);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.98 + (.02 * cos(i * twicePi / 21)), //x
    -0.06 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    //TOP
    glBegin(GL_TRIANGLE_FAN);//TT
    glColor3ub(112,54,43);
    glVertex2f(-0.9,0.04);
    glVertex2f(-0.78,0.04);
    glVertex2f(-0.78,0.1);
    glVertex2f(-.9,0.1);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TR
    glColor3ub(62,44,91);
    glVertex2f(-.96,0.1);
    glVertex2f(-0.72,0.1);
    glVertex2f(-0.82,0.16);
    glVertex2f(-.86,0.16);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRT
    glColor3ub(0,0,0);
    glVertex2f(-.86,0.16);
    glVertex2f(-0.82,0.16);
    glVertex2f(-0.82,0.18);
    glVertex2f(-.86,0.18);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//window
    glColor3ub(255,201,165);
    glVertex2f(-.86,-0.08);
    glVertex2f(-0.82,-0.08);
    glVertex2f(-0.82,-0.06);
    glVertex2f(-.86,-0.06);
    glEnd();

    //TOWER
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0);
    glVertex2f(-.85,0.18);
    glVertex2f(-0.83,0.18);
    glVertex2f(-0.83,0.4);
    glVertex2f(-.85,0.4);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//1
    glColor3ub(0,0,0);
    glVertex2f(-.88,0.36);
    glVertex2f(-0.8,0.36);
    glVertex2f(-0.8,0.38);
    glVertex2f(-.88,0.38);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//2
    glColor3ub(0,0,0);
    glVertex2f(-.88,0.32);
    glVertex2f(-0.8,0.32);
    glVertex2f(-0.8,0.34);
    glVertex2f(-.88,0.34);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3
    glColor3ub(0,0,0);
    glVertex2f(-.88,0.28);
    glVertex2f(-0.8,0.28);
    glVertex2f(-0.8,0.3);
    glVertex2f(-.88,0.3);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);//TL
    glColor3ub(45,11,28);
    glVertex2f(-.9,0.08);
    glVertex2f(-0.78,0.08);
    glVertex2f(-0.78,0.09);
    glVertex2f(-0.9,0.09);
    glEnd();



    glBegin(GL_TRIANGLE_FAN);//TLP
    glColor3ub(45,11,28);
    glVertex2f(-.88,0.04);
    glVertex2f(-0.87,0.04);
    glVertex2f(-0.87,0.08);
    glVertex2f(-.88,0.08);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRP
    glColor3ub(45,11,28);
    glVertex2f(-.80,0.04);
    glVertex2f(-0.81,0.04);
    glVertex2f(-0.81,0.08);
    glVertex2f(-.8,0.08);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRP
    glColor3ub(255,201,165);
    glVertex2f(-.82,0.05);
    glVertex2f(-0.86,0.05);
    glVertex2f(-0.86,0.07);
    glVertex2f(-.82,0.07);
    glEnd();

    //left light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.74,0.1);
        glVertex2f(-.74,0.08);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.74 + (.02 * cos(i * twicePi / 21)), //x
    0.06 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    // right light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.94,0.1);
        glVertex2f(-.94,0.08);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.94 + (.02 * cos(i * twicePi / 21)), //x
    0.06 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    glLoadIdentity();

    //right side building+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(1.7,-.05,0);
    glScalef(1,1.2,1);

    //right BUILDING
    //GROUND
    glBegin(GL_TRIANGLE_FAN);//GR
    glColor3ub(15,79,114);
    glVertex2f(-1.09,-0.44);
    glVertex2f(-0.54,-0.44);
    glVertex2f(-0.66,-0.38);
    glVertex2f(-1,-0.38);
    glEnd();

    //1ST
    glBegin(GL_TRIANGLE_FAN);//1T
    glColor3ub(15,79,114);
    glVertex2f(-1,-0.38);
    glVertex2f(-0.66,-0.38);
    glVertex2f(-0.66,-0.3);
    glVertex2f(-1,-0.3);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);//1R
    glColor3ub(15,79,114);
    glVertex2f(-1.07,-0.3);
    glVertex2f(-0.6,-0.3);
    glVertex2f(-0.7,-0.24);
    glVertex2f(-0.98,-0.24);
    glEnd();


    //2ND
    glBegin(GL_TRIANGLE_FAN);//2T
    glColor3ub(15,79,114);
    glVertex2f(-0.98,-0.24);
    glVertex2f(-0.7,-0.24);
    glVertex2f(-0.7,-0.16);
    glVertex2f(-.98,-0.16);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//2R
    glColor3ub(15,79,114);
    glVertex2f(-1.04,-0.16);
    glVertex2f(-0.64,-0.16);
    glVertex2f(-0.74,-0.1);
    glVertex2f(-.94,-0.1);
    glEnd();

    //3RD
    glBegin(GL_TRIANGLE_FAN);//3T
    glColor3ub(15,79,114);
    glVertex2f(-0.94,-0.1);
    glVertex2f(-0.74,-0.1);
    glVertex2f(-0.74,-0.02);
    glVertex2f(-.94,-0.02);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3R
    glColor3ub(15,79,114);
    glVertex2f(-1,-0.02);
    glVertex2f(-0.68,-0.02);
    glVertex2f(-0.78,0.04);
    glVertex2f(-.9,0.04);
    glEnd();

    //TOP
    glBegin(GL_TRIANGLE_FAN);//TT
    glColor3ub(15,79,114);
    glVertex2f(-0.9,0.04);
    glVertex2f(-0.78,0.04);
    glVertex2f(-0.78,0.1);
    glVertex2f(-.9,0.1);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TR
    glColor3ub(15,79,114);
    glVertex2f(-.96,0.1);
    glVertex2f(-0.72,0.1);
    glVertex2f(-0.82,0.16);
    glVertex2f(-.86,0.16);
    glEnd();

    //TOWER
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(15,79,114);
    glVertex2f(-.85,0.18);
    glVertex2f(-0.83,0.18);
    glVertex2f(-0.83,0.4);
    glVertex2f(-.85,0.4);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//1
    glColor3ub(15,79,114);
    glVertex2f(-.88,0.36);
    glVertex2f(-0.8,0.36);
    glVertex2f(-0.8,0.38);
    glVertex2f(-.88,0.38);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//2
    glColor3ub(15,79,114);
    glVertex2f(-.88,0.32);
    glVertex2f(-0.8,0.32);
    glVertex2f(-0.8,0.34);
    glVertex2f(-.88,0.34);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3
    glColor3ub(15,79,114);
    glVertex2f(-.88,0.28);
    glVertex2f(-0.8,0.28);
    glVertex2f(-0.8,0.3);
    glVertex2f(-.88,0.3);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRT
    glColor3ub(15,79,114);
    glVertex2f(-.86,0.16);
    glVertex2f(-0.82,0.16);
    glVertex2f(-0.82,0.18);
    glVertex2f(-.86,0.18);
    glEnd();
    glLoadIdentity();

    //middle building*************************************************+++++++++++++++++
    //3RD
    glScalef(1.7,1.5,1);
    glTranslatef(0.9,-.29,0);
    glBegin(GL_TRIANGLE_FAN);//3T
    glColor3ub(112,54,43);
    glVertex2f(-0.94,-0.1);
    glVertex2f(-0.74,-0.1);
    glVertex2f(-0.74,-0.02);
    glVertex2f(-.94,-0.02);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3R
    glColor3ub(62,44,91);
    glVertex2f(-1,-0.02);
    glVertex2f(-0.68,-0.02);
    glVertex2f(-0.78,0.04);
    glVertex2f(-.9,0.04);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3L
    glColor3ub(45,11,28);
    glVertex2f(-.94,-0.04);
    glVertex2f(-0.74,-0.04);
    glVertex2f(-0.74,-0.03);
    glVertex2f(-0.94,-0.03);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3LP
    glColor3ub(45,11,28);
    glVertex2f(-.92,-0.1);
    glVertex2f(-0.91,-0.1);
    glVertex2f(-0.91,-0.04);
    glVertex2f(-.92,-0.04);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//3RP
    glColor3ub(45,11,28);
    glVertex2f(-.77,-0.1);
    glVertex2f(-0.76,-0.1);
    glVertex2f(-0.76,-0.04);
    glVertex2f(-.77,-0.04);
    glEnd();

    // right light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.7,-0.02);
        glVertex2f(-.7,-0.04);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.7 + (.02 * cos(i * twicePi / 21)), //x
    -0.06 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    // Right light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.98,-0.02);
        glVertex2f(-.98,-0.04);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.98 + (.02 * cos(i * twicePi / 21)), //x
    -0.06 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    //TOP
    glBegin(GL_TRIANGLE_FAN);//TT
    glColor3ub(112,54,43);
    glVertex2f(-0.9,0.04);
    glVertex2f(-0.78,0.04);
    glVertex2f(-0.78,0.1);
    glVertex2f(-.9,0.1);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TR
    glColor3ub(62,44,91);
    glVertex2f(-.96,0.1);
    glVertex2f(-0.72,0.1);
    glVertex2f(-0.82,0.16);
    glVertex2f(-.86,0.16);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRT
    glColor3ub(0,0,0);
    glVertex2f(-.86,0.16);
    glVertex2f(-0.82,0.16);
    glVertex2f(-0.82,0.18);
    glVertex2f(-.86,0.18);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//window
    glColor3ub(255,201,165);
    glVertex2f(-.86,-0.08);
    glVertex2f(-0.82,-0.08);
    glVertex2f(-0.82,-0.06);
    glVertex2f(-.86,-0.06);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRP
    glColor3ub(255,201,165);
    glVertex2f(-.82,0.05);
    glVertex2f(-0.86,0.05);
    glVertex2f(-0.86,0.07);
    glVertex2f(-.82,0.07);
    glEnd();

    //left light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.74,0.1);
        glVertex2f(-.74,0.08);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.74 + (.02 * cos(i * twicePi / 21)), //x
    0.06 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    // right light
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
        glVertex2f(-.94,0.1);
        glVertex2f(-.94,0.08);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255,255,255); //left small circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.94 + (.02 * cos(i * twicePi / 21)), //x
    0.06 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);//TL
    glColor3ub(45,11,28);
    glVertex2f(-.9,0.08);
    glVertex2f(-0.78,0.08);
    glVertex2f(-0.78,0.09);
    glVertex2f(-0.9,0.09);
    glEnd();



    glBegin(GL_TRIANGLE_FAN);//TLP
    glColor3ub(45,11,28);
    glVertex2f(-.88,0.04);
    glVertex2f(-0.87,0.04);
    glVertex2f(-0.87,0.08);
    glVertex2f(-.88,0.08);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRP
    glColor3ub(45,11,28);
    glVertex2f(-.80,0.04);
    glVertex2f(-0.81,0.04);
    glVertex2f(-0.81,0.08);
    glVertex2f(-.8,0.08);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);//TRP
    glColor3ub(255,201,165);
    glVertex2f(-.82,0.05);
    glVertex2f(-0.86,0.05);
    glVertex2f(-0.86,0.07);
    glVertex2f(-.82,0.07);
    glEnd();
    glLoadIdentity();


//tree++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 pos = 0.0; posy = 0.0;
 for(i = 0; i< 3; i++){
    glTranslatef(pos, posy,0);
    glBegin(GL_TRIANGLE_FAN);  //big branches
    glColor3ub(99,59,66);
    glVertex2f(1.0, -0.4);
    glVertex2f(0.86, -0.35);
    glVertex2f(0.66, -0.35);
    glVertex2f(0.46, -0.36);
    glVertex2f(0.66, -0.37);
    glVertex2f(0.86, -0.38);
    glVertex2f(1.0, -0.44);
    glEnd();
    posy += 0.08;
    pos += 0.07;
    glLoadIdentity();
    }
    glBegin(GL_TRIANGLE_FAN);  //small branches
    glColor3ub(99,59,66);
    glVertex2f(0.66, -0.37);
    glVertex2f(0.63, -0.37);
    glVertex2f(0.6, -0.43);
    glEnd();

//tree leaves++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    posx = 0,posy = 0;
    float hold = 0;
    for(int t=0; t<4; t++){
        if(t==0){posx=1.4,posy=-0.78,hold=0;}
        else if(t==1){posx=1.7,posy=-0.56;}
        else if(t==2){posx=2.3,posy=-0.35;}
        else if(t==3){posx=2.4,posy=-0.8;}
        hold = posx;
        for(int i= 1; i<=3; i++){
          for(int j=0; j<(i+3); j++){
            glScalef(0.35,0.45,1);
            glTranslatef(posx, posy, 0);
            glBegin(GL_TRIANGLE_FAN);
            glColor3ub(172, 141, 198);
            glVertex2f(0.0,0.04);
            glVertex2f(0.06,0.0);
            glVertex2f(0.0,-0.04);
            glVertex2f(-0.06,0.0);
            glEnd();
            glLoadIdentity();
            posx += 0.14;
          }
            hold += -0.07;
            posx = hold; posy += -0.07;
        }
    }



//Road++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glBegin(GL_TRIANGLE_FAN); //main road base
    glColor3ub(30, 38, 45);
    glVertex2f(-1.0,-0.52);
    glVertex2f(-1.0,-1.0);
    glVertex2f(1.0,-1.0);
    glVertex2f(1.0,-0.52);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //road bar+++++++++++++
    glColor3ub(33, 12, 31);
    glVertex2f(-1.0,-0.45);
    glVertex2f(-1.0,-0.47);
    glVertex2f(1.0,-0.47);
    glVertex2f(1.0,-0.45);
    glEnd();
    float dif = 0.0;
    for(int p= 0; p<29; p++ ){ //road bar small stripes
    glTranslatef(dif,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(33, 12, 31);
    glVertex2f(-0.98,-0.45);
    glVertex2f(-0.98,-0.52);
    glVertex2f(-0.96,-0.52);
    glVertex2f(-0.96,-0.45);
    glEnd();
    glLoadIdentity();
    dif += 0.07;
    }

    dif = 0.0;
    for(int p =0; p<4; p++){ //road middle yellow stripe
    glTranslatef(dif,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(127, 96, 75);
    glVertex2f(-0.98,-0.75);
    glVertex2f(-0.98,-0.77);
    glVertex2f(-0.68,-0.77);
    glVertex2f(-0.68,-0.75);
    glEnd();
    glLoadIdentity();
    dif += 0.5;
    }

//car 1++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glScalef(1.2,1.2,1);
    glTranslatef(position7,0.1,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(77, 34, 124);
    glVertex2f(-.42,-0.78);
    glVertex2f(-.4,-.8);
    glVertex2f(-.2,-.8);
    glVertex2f(-0.18,-0.78);
    glVertex2f(-0.18,-0.7);
    glVertex2f(-0.2,-0.68);
    glVertex2f(-0.4,-0.68);
    glVertex2f(-0.42,-0.7);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car
    glColor3ub(47, 17, 86);
    glVertex2f(-.38,-0.8);
    glVertex2f(-.36,-0.8);
    glVertex2f(-.36,-0.68);
    glVertex2f(-.38,-0.68);
    glEnd();

    //strip
    pos = 0.0;
    for(i = 0; i<5; i++){
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(47, 17, 86);
        glVertex2f(-.35f +pos,-0.8);
        glVertex2f(-.33f +pos,-0.8);
        glVertex2f(-.33f +pos,-0.68);
        glVertex2f(-.35f +pos,-0.68);
        glEnd();
        pos += 0.03;
    }

    glBegin(GL_TRIANGLE_FAN); //head
    glColor3ub(166,134,168);
    glVertex2f(-.17,-0.77);
    glVertex2f(-.2,-0.8);
    glVertex2f(-.06,-0.8);
    glVertex2f(-.06,-0.76);
    glVertex2f(-.1,-0.71);
    glVertex2f(-.17,-0.71);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car 1 window
    glColor3ub(77,34,124);
    glVertex2f(-.15,-0.76);
    glVertex2f(-.08,-0.76);
    glVertex2f(-.11,-0.72);
    glVertex2f(-.15,-0.72);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //left wheel circle
    for(i = 0; i <= 21;i++) {
        glVertex2f(
         -0.3 + (.03 * cos(i * twicePi / 21)), //x
         -0.81 + (.03* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(77,34,124); //left small wheel
    for(i = 0; i <= 21;i++) {
        glVertex2f(
         -0.3 + (.01 * cos(i * twicePi / 21)), //x
         -0.81 + (.01* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
     glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //right wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
         -0.12 + (.03 * cos(i * twicePi / 21)), //x
         -0.81 + (.03* sin(i * twicePi / 21)) //y
        );
    }
    glEnd();
     glBegin(GL_TRIANGLE_FAN);
    glColor3ub(77,34,124); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
    -0.12 + (.01 * cos(i * twicePi / 21)), //x
     -0.81 + (.01* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();
    glLoadIdentity();

    //car 2++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    glTranslatef(position8,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32, 47, 80);
    glVertex2f(.68,-0.58);
    glVertex2f (.7,-0.6);
    glVertex2f(.96,-0.6);
    glVertex2f(.98,-0.58);
    glVertex2f(.98,-0.46);
    glVertex2f(.96,-0.44);
    glVertex2f(.7,-0.44);
    glVertex2f(.68,-0.46);
    glEnd();

    pos = 0.0;
    for(i = 0; i<8; i++){
        glBegin(GL_TRIANGLE_FAN); //stripes
        glColor3ub(27, 39, 61);

        glVertex2f(.72f + pos,-0.6);
        glVertex2f (.74f + pos,-0.6);
        glVertex2f(.74f + pos,-0.44);
        glVertex2f(.72f + pos,-0.44);
        glEnd();
        pos += 0.03;
    }

    glBegin(GL_TRIANGLE_FAN); //car front part
    glColor3ub(111,151,161);
    glVertex2f(.52,-0.6);
    glVertex2f (.7,-0.6);
    glVertex2f(.675,-0.57);
    glVertex2f(.675,-0.48);
    glVertex2f(.56,-0.48);
    glVertex2f(.52,-0.56);
    glEnd();

    glBegin(GL_TRIANGLE_FAN); //car window
    glColor3ub(32,47,80);
    glVertex2f(.56,-0.56);
    glVertex2f (.64,-0.56);
    glVertex2f(.64,-0.5);
    glVertex2f(.59,-0.5);
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //left wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
        0.6 + (.04 * cos(i * twicePi / 21)), //x
         -0.61 + (.04* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,47,80); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
         0.6 + (.02 * cos(i * twicePi / 21)), //x
         -0.61 + (.02* sin(i * twicePi / 21)) //y
     );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0,0,0); //right wheel circle
    for(i = 0; i <= 21;i++) {
    glVertex2f(
          0.9 + (.04 * cos(i * twicePi / 21)), //x
         -0.61 + (.04* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(32,47,80); //left small wheel
    for(i = 0; i <= 21;i++) {
    glVertex2f(
          0.9 + (.02 * cos(i * twicePi / 21)), //x
         -0.61 + (.02* sin(i * twicePi / 21)) //y
    );
    }
    glEnd();
    glLoadIdentity();

	glFlush();
}



void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
case 'a':
    glutDisplayFunc(morning);
    break;
case 's':
    glutDisplayFunc(night);
    break;
case 'd':
    glutDisplayFunc(evening);
    break;
glutPostRedisplay();
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(600,200);
	glutInitWindowSize(900, 900);
	glutCreateWindow("Test");
	glutDisplayFunc(evening);
	glutTimerFunc(100, update, 0);
	glutKeyboardFunc(handleKeypress);
	glutMainLoop();
	return 0;
}

