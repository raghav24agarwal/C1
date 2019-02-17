#include "secure.h"
#include "progress.h"
#include "car.h"
void main()
{
	int a;

	a=secure();
	if(a==0)
	{
		progress();

		car();

	}
	getch();
}

