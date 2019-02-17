#include<dos.h>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>

union REGS in,out;
int  ch,xc,yc,button,flag;

int mouse1(char ch[])
{
	int gd,gm,f,z;
	gd=DETECT;
	initgraph(&gd,&gm,"");

	setcolor(RED);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR,4);
	outtextxy(220,80,ch);

	in.x.ax=1;
	int86(0x33,&in,&out);
	setcolor(CYAN);
	gotoxy(19,11);
	printf("Restart");
	rectangle(120,145,225,190);
	gotoxy(50,11);
	printf("Exit");
	rectangle(350,145,465,190);


	while(1)
	{

		in.x.ax=3;
		int86(0x33,&in,&out);
		button=out.x.bx;
		xc= out.x.cx;
		yc= out.x.dx;

		if(button==1)
		{
			if(xc>110&&xc<225&&yc>145&&yc<190) //restart
			{
				flag=0;
				goto start;

			}
			if(xc>350&&xc<465&&yc>145&&yc<190) //exit
			{
				flag=1;
				goto start;
			}
		}
	}
	 start:
	 return(flag);
}
