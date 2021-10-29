#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

int checkLenght(float a)
{
	int n = 0;
	int temp;
	if (a < 0)
		n++;
	for (;;)
	{
		temp = a;
		if (temp == 0)
			return n;
		a /= 10;
		n++;
	}
}

void paint(int size)
{
	printf("+");
	for (int i = 0; i < size; i++)
	{
		printf("-");
	}
	
}

float foo(float x)
{
	return sin(x) * cos(x);
}

void paintTable(float x1, float x2, float delta, unsigned int n )
{
	int iLenght, XLenght, fooLenght,sizePoint,sizeX,sizeFX;
	int i = 1;
	float X = x1;

	printf("Enter the size\n");
	scanf_s("%i",&sizePoint);
	scanf_s("%i",&sizeX);
	scanf_s("%i",&sizeFX);


	for (int i = 0; i < sizePoint + sizeX + sizeFX+4; i++)
		printf("*");
	printf("\n*");
	for (int i = 0; i < sizePoint-2; i++)
	{
		if ((sizePoint/2)-1==i)
		{
			printf("N");
		}
		printf(" ");
	}
	printf(" *");
	for (int i = 0; i < sizeX-2; i++)
	{
		if ((sizePoint / 2)-1 == i)
		{
			printf("X");
		}
		printf(" ");
	}
	printf(" *");
	for (int i = 0; i < sizeFX-4; i++)
	{
		if ((sizePoint / 2)-1 == i)
		{
			printf("F(X)");
		}
		printf(" ");
	}
	printf("*\n");
	for (int i = 0; i < sizePoint + sizeX + sizeFX + 4; i++)
		printf("*");
	printf("\n");

	for (; i < n; i++)
	{
		iLenght = checkLenght(i);
		XLenght = checkLenght(X);
		fooLenght = checkLenght(foo(X));
	
		paint(sizePoint);
		paint(sizeX);
		paint(sizeFX);

		printf("+\n");

		printf("|");
		for (int j = 0;j< sizePoint -iLenght;j++)
		{
			printf(" ");
		}
		printf("%d|", i);

		for (int j = 0; j < sizeX - XLenght-3; j++)
		{
			printf(" ");
		}
		printf("%.2f|", X);
		for (int j = 0; j < sizeFX - fooLenght-5; j++)
		{
			printf(" ");
		}
		printf("%.3f|", foo(X));
		printf("\n");
		X += delta;
		if (i % 10 == 0 ) 
		{
			printf("Press any key to continue\r");
			_getch();
		}
	}
	paint(sizePoint);
	paint(sizeX);
	paint(sizeFX);
	printf("+\n");
}

int main()
{
	unsigned int choice=1,n;
	float x1, x2, delta,temp;
	
	printf("Enter varint 1 or 2\n");
	scanf_s("%d", &choice);
	system("cls");

	switch (choice)
	{
	case 1:
		printf("Enter initial and final value of arguments number of table points\n");
		scanf_s("%f", &x1);
		scanf_s("%f", &x2);
		scanf_s("%d", &n);

		delta = (x2 - x1) / (n - 1);
		
		printf("x1=%.3f  x2=%.3f number points=%d\n", x1, x2, n);
		n++;
		break;
	case 2:
		printf("Enter the initial and final value of the arguments step of changing the argument\n");
		scanf_s("%f", &x1);
		scanf_s("%f", &x2);
		scanf_s("%f", &delta);
		n = 2;
		temp = x1;
		for (;;)
		{
			temp += delta;
			if (temp >= x2)
				break;
			n++;
			
		}
		printf("x1=%.3f  x2=%.3f delta=%.3f\n", x1, x2, delta);
		break;
	}
	
	paintTable(x1, x2, delta, n);
	return 0;
}