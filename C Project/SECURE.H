#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
int bb=0;
void permit();
int secure()
{
	int gd=DETECT,gm,i=0,maxx,maxy;
	int ch=3,flag=1,b;
	char a[30],pas[20];
	char user[30]="Admin",pass[20]="root123";
	initgraph(&gd,&gm,"");
	do
	{       system("cls");
		gotoxy(45,22);
		printf("remaining attempts=%d",ch);
		gotoxy(30,12);
		printf("enter user name=");
		scanf("%[^\n]%*c",a);
		gotoxy(30,14);
		printf("enter password= ");
		i=0;
		do
		{
			pas[i]=getch();

			if(pas[i]=='\b'&&bb!=0)
			{
				i=i-2;
				printf("\b");
				printf(" ");
				printf("\b");
				bb--;

			}
			else if(pas[i]=='\b')
			{
			       i--;
			}
			else if(pas[i]!='\r')
			{
				printf("*");
				bb++;

			}
			i++;
		}while(pas[i-1]!='\r');
		pas[i-1]='\0';
		ch--;
		bb=0;
		if((strcmp(a,user)==0)&&(strcmp(pas,pass)==0))
		{
			permit();
			ch=0;
			flag=0;
		 }
		 else
		 {
			gotoxy(30,16);
			printf("Try Again!");
			getch();

		 }
	}while(ch>0);
	closegraph();
	return flag;
}
void permit()
{       system("cls");
	gotoxy(30,14);
	printf("Access Granted!!");
	delay(2000);
}
