#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void randArray(float** array, int n, int m);
void printArray(float** array, int n, int m);
void maxMinArray(float** array, int n, int m);
void transposedArray(float** array, int n, int m);
void multiplicationArray(float** array, float** array2, int n, int m);
void sortArray(float** array, int n, int m);
void sumArray(float** array, float** array2, int n, int m);

int main()
{
	srand(time(NULL));
	int N, M,check=0,choice;
	printf("Enter size array\n");
	scanf_s("%i%i", &N, &M);
	printf("Enter the array manually(1-yes 0-no)\n");
	scanf_s("%i",&check);

	float** Square = (float**) malloc(N * sizeof(float*));
	for (int i = 0; i < N; i++)
		Square[i] = (float*)malloc(N * sizeof(float));
	

	float** Rectangle = (float**)malloc(N * sizeof(float*));
	for (int i = 0; i < N; i++)
		Rectangle[i] = (float*)malloc(M * sizeof(float));
	
	if (check)
	{
		float temp=0;
		printf("Enter the array square\n");
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
			{
				scanf_s("%f",&temp);
				Square[i][j] = temp;
			}
		printf("Enter the array Rectangle\n");
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
			{
				scanf_s("%f",&temp);
				Rectangle[i][j] = temp;
			}
	}
	else
	{
		randArray(Square, N, N);
		randArray(Rectangle, N, M); 
	}

	printArray(Square, N, N);
	printf("\n");
	printArray(Rectangle, N, M);
	printf("\n");

	

	check = 1;
	while (check)
	{

		printf("Choice variant(1-maxMinArray 2-transposedArray 3-multiplicationArray 4-sortArray 5-sumArray 6-End)\n\n");
		scanf_s("%i", &choice);
		switch (choice)
		{
		case 1:
			maxMinArray(Square, N, N);
			break;
		case 2:
			transposedArray(Rectangle, N, M);
			break;
		case 3:
			multiplicationArray(Square, Rectangle, N, M);
			break;
		case 4:
			sortArray(Square, N, N);
			break;
		case 5:

			sumArray(Square, Rectangle, N, M);
			break;
		case 6:
			printf("End");
			check = 0;
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		free(Square[i]);
		free(Rectangle[i]);
	}
	free(Square);
	free(Rectangle);

}

void randArray(float** array, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			array[i][j] = (float)rand() / 1000;
		}
	}
}

void printArray(float** array, int n, int m)
{
	printf("Print Array\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%0.1f ", array[i][j]);
		}
		printf("\n");
	}
}

void maxMinArray(float** array, int n, int m) 
{
	printf("Max Min Array\n");
	float max = array[0][1];
	float min = array[1][0];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (array[i][j] > max && i != j && i < j)
			{
				max = array[i][j];
			}
			if (array[i][j] < min && i != j && i > j)
			{
				min = array[i][j];
			}
		}
	}
	printf("max = %0.1f \nmin = %0.1f ", max, min);
	printf("\n\n");

}

void transposedArray(float** array, int n, int m)
{
	printf("Transposed Array \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%0.1f ", array[j][i]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void multiplicationArray(float** array, float** array2, int n, int m)
{
	printf("Multiplication Array \n");
	float temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp = 0;
			for (int k = 0; k < n; k++)
				temp += array[i][k] * array2[k][j];
			printf("%0.1f ", temp);
		}
		printf("\n");
	}
	printf("\n\n");
}

void sortArray(float** array, int n, int m)
{ 
	printf("Sort Array\n");
	int k = 1; 
	do
	{
		printf("Enter table number\n");
		scanf_s("%i", &k);
	} while (k>n-1);
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (array[k][j] > array[k][j + 1])
			{
				float tmp = array[k][j];
				array[k][j] = array[k][j + 1];
				array[k][j + 1] = tmp;
			}
		}
	}

	printArray(array, n, n);
}

void sumArray(float** array, float** array2, int n, int m) 
{
	printf("Sum Array\n");

	float temp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			temp += array[i][j];
		}
		for (int k = 0; k < n; k++)
		{
			temp += array2[k][i];
		}
		printf("\n%0.1f\n", temp);
	}
}