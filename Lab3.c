#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>


float methodChord(float x1, float x2, float e, int count,bool checkDisplayResult);
float foo(float x);
float findHalfDivision(float x1, float x2, float e, int count, bool checkDisplayResult);

int main()
{
    float tStop,tStart;

    bool check,checkDisplayResult=1;
    int count,choiceMethod=1;

    float x1,x2,e,xMethodChord, xFindHalfDivision;

    while (1)
    {
        printf("Choice method(1 method Chord, 2 method half division\n");
        scanf_s("%d", &choiceMethod);

        if (choiceMethod == 1 || choiceMethod == 2)
            break;
        else
           printf("Incorrect data, try again\n");
    }
    while (1)
    {
        printf("Display the result on each iteration(1-yes 0-no)\n");
        scanf_s("%d", &checkDisplayResult);
        if (checkDisplayResult == 1 || checkDisplayResult == 0)
            break;
        else
            printf("Incorrect data, try again\n");
    }
    do {
        printf("Enter initial value of the root, calculation error, maximum number of iterations (through the enter).\n");
        scanf_s("%f", &x1);
        scanf_s("%f", &x2);
        scanf_s("%f", &e);
        scanf_s("%d", &count);
        check = false;
        if (foo(x1) * foo(x2) > 0)
        {
            printf("Wrong point, try again\n");
            printf("foo(x1) = %f", foo(x1));
            printf("\nfoo(x2) = %f", foo(x2));
            printf("\nfoo(x1)*foo(x2) must be < 0\n");
            check = true;
        }
    } while (check);



  
    tStart = clock();

    switch (choiceMethod)
    {
    case 1:
        xMethodChord = methodChord(x1, x2, e, count, checkDisplayResult);
        float tempPrint = foo(xMethodChord);
        printf("the value of the root = %f \nthe value of the function at the found point =  %f", xMethodChord, tempPrint);
        break;
    case 2:
        xFindHalfDivision = findHalfDivision(x1, x2, e, count, checkDisplayResult);
        float tempPrint2 = foo(xFindHalfDivision);
        printf_s("the value of the root = %f \nthe value of the function at the found point =  %f",xFindHalfDivision,tempPrint2);
        break;
    }

    tStop = clock();
    float t = CLOCKS_PER_SEC;
    float time = (tStop - tStart) / CLOCKS_PER_SEC;

    printf("\nLoop required %f seconds",time);
  
    _getch();
    return 0;
}

float methodChord(float x1, float x2, float e,int count,bool checkDisplayResult)
{

    float X = 1;
    float tmp;
    int countFoo = 0;
    bool checkEnd = 1;

    do
    {
        if ((count <= countFoo && checkEnd))
        {

            printf("The number of iterations exceeded the specified number, what to do?(0-continue,1-complete calculations)\n");
            scanf_s("%d", &checkEnd);
            if (checkEnd)
            {
                break;
            }
        }
        tmp = X;
        X = x2 - foo(x2) * (x1 - x2) / (foo(x1) - foo(x2));
        x1 = x2;
        x2 = tmp;
        countFoo++;
        if (checkDisplayResult)
            printf("X = %f\n",X);
    } while (abs(X - x2) > e);
  

    return X;
}

float foo(float x)
{
    return pow(x, 3) - 18 * x - 83;
}

float findHalfDivision(float x1, float x2, float e, int count, bool checkDisplayResult)
{
    float X;
    int countFoo = 0;
    bool checkEnd = 1;

    while ((x2 - x1) / 2 > e) 
    {
        if ((count <= countFoo && checkEnd))
        {
           
            printf("The number of iterations exceeded the specified number, what to do?(0-continue,1-complete calculations)\n");
            scanf_s("%d", &checkEnd);
            if (checkEnd)
                break;
        }
        X = (x1 + x2) / 2;
        if ((foo(x1) * foo(X)) > 0)
            x1 = X;
        else
            x2 = X;
        if (checkDisplayResult)
            printf("X = %f\n", X);
        countFoo++;
    }
    printf("\nIterations = %i\n", countFoo);
    return X;
}



