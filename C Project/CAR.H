#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include "mouse.h"
void car();
union REGS in, out;
void print()
{
	int gd,gm,f;
	gd=DETECT;
	initgraph(&gd,&gm,"");

	f=mouse1("Game over");
	if(f==0)
		car();
	if(f==1)
		exit(0);
}
void print1()
{
	int gd,gm,f;
	gd=DETECT;
	initgraph(&gd,&gm,"");


	f=mouse1("You won");
	if(f==0)
		car();
	if(f==1)
		exit(0);

}

void car()
{
	int x=50,y=50; 				     //game
	int a=x,b=y;
	int gd,gm;
	char cn;
	clrscr();

	gd=DETECT;
	initgraph(&gd,&gm,"");


	while(1)
	{
		rectangle(12,b-10,30,b+50);
	       //	setcolor(RED);
		settextstyle(TRIPLEX_FONT, VERT_DIR,1);
		outtextxy(10,45," Start");


		rectangle(a-20,b-10,a+100,b+50);     //for 1 rectangle
		rectangle(a+100,b-10,a+170,b+100);   //for 2 rectangle
		rectangle(a+170,b+45,a+370,b+100);   //for 3 rectangle
		rectangle(a+370,b+45,a+430,b+200);   //for 4 rectangle

		rectangle(a+370,b+200,a+430,b+220);
		settextstyle(TRIPLEX_FONT, HORIZ_DIR,1);
		outtextxy(435,250,"End");


		gotoxy(60,2);
		printf("Press P for pause");
		gotoxy(1,1);
		rectangle(x,y,x+50,y+30);            //for car
		setfillstyle(SOLID_FILL,BLUE);
		floodfill(x+1,y+1,getmaxcolor());
		setfillstyle(SOLID_FILL,BLUE);
		floodfill(x+49,y+29,getmaxcolor());
		circle(x+8,y+32,5);
		circle(x+42,y+32,5);
		cn=getch();
		cleardevice();


		if(cn=='a')
		{
			if(x<35)        	     //for 1 rectangle
			{
				print();
				getch();
				exit(0);
			}
			if(x<160&&y>60)      	     //for 2 and 3 rectangle
			{
				print();
				getch();
				exit(0);
			}
			if(x<430&&y>110)
			{
				print();
				getch();
				exit(0);
			}
			x=x-10;
		}


		if(cn=='d')
		{
			if(x>160&&y<100)             //for 1 and 2 rectangle
			{
				print();
				getch();
				exit(0);
			}
			if(x>420)                    //for 3 rectangle
			{
				print();
				getch();
				exit(0);
			}
			x=x+10;
		}


		if(y>10 && cn=='w')
		{
			if(y<41)           	     // for 1 and 2 rectangle
			{
				print();
				getch();
				exit(0);
			}
			if(x>170&&y<110)    	     //for 3 rectangle
			{
				print();
				getch();
				exit(0);
			}

			y=y-10;
		}


		if(y<400&&cn=='s')
		{
			if(x<150&&y<100&&y>50)       //for 1 rectangle
			{
				print();
				getch();
				exit(0);
			}
			if(x>140&&y>100&&x<420)             //for 2 and 3 rectangle
			{
				print();
				getch();
				exit(0);
			}
			if(x>410&&y==210)
			{
				print1();
				getch();
				exit(0);
			}
			y=y+10;
		}

		if(cn=='p'||cn=='P')
		{
			getch();
		}

	}
getch();
closegraph();
}


