#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>

char* filename1 = "D://result.bin";
char* filename2 = "D://result.txt";
char buf[10000];
int counter;

float foo(float x)
{
	return sin(x) * cos(x);
}


void wFile()
{
	FILE* file1= fopen(filename1, "a");
	FILE* file2= fopen(filename2, "a");
	char* buffer;
	unsigned sizelem, n;
	sizelem = 1;


	fwrite(buf, sizelem, counter, file1);
	fprintf(file2, "%s", buf);
	fclose(file1);
	fclose(file2);
}

void wBuf(char a)
{	
	buf[counter] = a;
	if (counter == 10000)
	{
		wFile();
		counter = 0;
	}
	counter++;
}


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

void divisionNumber(float s)
{
	char a;
	int n;
	if(s<0)
		wBuf('-');
	if(s<1)
		wBuf('0');
	s = fabs(s);

	int m = checkLenght(s);
	s /= pow(10, m);
	for (n = 0; m > n; n++)
	{
		s *= 10;
		a = (int)s % 10 + '0';
		wBuf(a);
	}
	wBuf('.');
	for (n = 0; 3>n; n++)
	{
		s *= 10;
		a = (int)s%10 + '0';
		wBuf(a);
	}

}

void divisionIntNumber(float s)
{
	char a,b;
	int n;

	int m = checkLenght(s);
	s /= pow(10, m);
	for (n = 0; m > n; n++)
	{
		s *= 10;
		a = (int)s % 10 + '0';
		wBuf(a);

	}
	

}

void paint(int size)
{
	wBuf('+');
	for (int i = 0; i < size; i++)
	{
		wBuf('-');
	}

}

void paintTable(float x1, float x2, float delta, unsigned int n)
{
	int iLenght, XLenght, fooLenght, sizePoint, sizeX, sizeFX;
	int i = 1;
	float X = x1;
	sizePoint = 10;
	sizeX = 10;
	sizeFX = 10;

	for (int i = 0; i < sizePoint + sizeX + sizeFX + 4; i++)
		wBuf('*');
	
	wBuf('\n');
	wBuf('*');
	for (int i = 0; i < sizePoint - 2; i++)
	{
		if ((sizePoint / 2) - 1 == i)
			wBuf('N');
		wBuf(' ');
		
	}
	wBuf(' ');
	wBuf('*');
	for (int i = 0; i < sizeX - 2; i++)
	{
		if ((sizeX / 2) - 1 == i)
			wBuf('X');
		wBuf(' ');
	}
	wBuf(' ');
	wBuf('*');
	for (int i = 0; i < sizeFX - 4; i++)
	{
		if ((sizeFX / 2) - 1 == i)
		{
			
			wBuf('F');
			wBuf('(');
			wBuf('X');
			wBuf(')');
		}
		wBuf(' ');
	}
	wBuf('*');
	wBuf('\n');
	for (int i = 0; i < sizePoint + sizeX + sizeFX + 4; i++)
	{
		wBuf('*');
	}
	wBuf('\n');

	for (; i < n; i++)
	{
		iLenght = checkLenght(i);
		XLenght = checkLenght(X);
		fooLenght = checkLenght(foo(X));

		paint(sizePoint);
		paint(sizeX);
		paint(sizeFX);

		wBuf('+');
		wBuf('\n');
		wBuf('|');
		for (int j = 0; j < sizePoint - iLenght; j++)
			wBuf(' ');
		divisionIntNumber(i);
		wBuf('|');
	

		for (int j = 0; j < sizeX - XLenght - 4; j++)
			wBuf(' ');

		divisionNumber(X);
		wBuf('|');
		
		for (int j = 0; j < sizeFX - fooLenght - 5; j++)
			wBuf(' ');

		divisionNumber(foo(X));
		wBuf('|');
		wBuf('\n');
		X += delta;
	}
	paint(sizePoint);
	paint(sizeX);
	paint(sizeFX);

	wBuf('+');
	wBuf('\n');
}

void main()
{
	FILE* file = fopen("D://input.txt", "r");
	unsigned int choice = 1, n;
	float x1, x2, delta, temp;
	char array[100];
	int a1[5];
	int cou = 0;
	int temp1[6];
	int arr[3];

	fopen(filename1, "w");
	fopen(filename2, "w");

	while (fscanf(file, "%79[^\n]\n", array) == 1)
	{

		int m = 0;
		for (int n = 0; n < 5; n++)
		{
			temp1[n] = 0;
			a1[cou] = 0;
		}

		for (int n = 0;; n++, m++)
			if (array[n] == '\0')
				break;
		for (int n = 0; n < m; n++)
			temp1[n] = array[n] - '0';

		for (int n = 0; n <= m; n++)
			a1[cou] += temp1[n] * pow(10, m - n - 1);			
		cou++;
	}
	fclose(file);
	x1 = a1[1];
	x2 = a1[2];
	n = a1[3]+1;
	delta = (x2 - x1) / (n - 1);

	paintTable(x1, x2, delta, n);

	wFile();

	file = fopen(filename1, "r");
	while (fscanf(file, "%79[^\n]\n", array) == 1)
	{

		printf("%s\n", array); 
	}
	fclose(file);
	
	return 0;

}
