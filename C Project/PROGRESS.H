#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
void progress()
{
	char ch=177,ce=178;
	int i,j;
	clrscr();
	textcolor(RED);
	gotoxy(11,21);
	cprintf("loading!!");
	textcolor(GREEN);
	gotoxy(11,22);
	for(i=0;i<60;i++)
	{
		cprintf("%c",ch);
	}
	 gotoxy(11,22);
	for(i=0;i<60;i++)
	{
		sound(i+40);
		delay(40);
		cprintf("%c",ce);
	}
	nosound();
//	getch();
}
