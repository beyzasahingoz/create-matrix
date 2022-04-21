#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrisoperations.h"

int main(int argc, char *argv[])
{
    //controlled argument number
    if (argc < 5)
    {
        printf("The missing argument has been entered");
        exit(1);
    }
    else if (argc > 5)
    {
        printf("Too many arguments have been entered");
        exit(1);
    }
    else
    {
        //defined integers.
        int size1 = atoi(argv[1]);
        int size2 = atoi(argv[2]);
        int opNum = atoi(argv[3]);
        int seedValue = atoi(argv[4]);

        //defined srand method for random numbers.
        srand(seedValue);
        //controlled integer values.
        if (size2 != 3 && size2 != 5)
        {
            printf("Try again. Size 2 must be 3 or 5.\n");
            exit(1);
        } 
        if (size1 % 2 == 0)
        {
            printf("Try again. Size 1 must be odd number.\n");
            exit(1);
        }
        if (size1 <= size2)
        {
            printf("Try again. Size 1 must be greater than size 2.\n");
            exit(1);
        }
        if (opNum != 0 && opNum != 1)
        {
            printf("Try again. Operation number must be 0 or 1.\n");
            exit(1);
        }

        //defined random1 matrix using malloc.
        int **random1 = (int **)malloc(size1 * sizeof(int *));
        for (int i = 0; i < size1; i++)
        {
            random1[i] = (int *)malloc(size1 * sizeof(int));
        }

        for (int i = 0; i < size1; i++)
        {
            for (int j = 0; j < size1; j++)
            {
                random1[i][j] = (rand() % 10) + 1;
            }
        }
        printf("\n");
        
        printf("*********RANDOM1 MATRIX*********");
        //printed random1 matrix.
        for (int i = 0; i < size1; i++)
        {
            printf("\n");
            for (int j = 0; j < size1; j++)
            {
                printf("%d\t", random1[i][j]);
            }
        }

        printf("\n");
        //defined random2 matrix using malloc.
        int **random2 = (int **)malloc(size2 * sizeof(int *));

        for (int i = 0; i < size2; i++)
        {
            random2[i] = (int *)malloc(size2 * sizeof(int));
        }

        //created random2 matrix with random numbers.
        for (int i = 0; i < size2; i++)
        {
            for (int j = 0; j < size2; j++)
            {
                random2[i][j] = (rand() % 10) + 1;
            }
        }
        printf("\n");
        printf("*********RANDOM2 MATRIX*********");
        //printed random2 matrix.
        for (int i = 0; i < size2; i++)
        {
            printf("\t\n");
            for (int j = 0; j < size2; j++)
            {
                printf("%d\t", random2[i][j]);
            }
        }
        //calculated new matrix size and defined new matris with malloc.
        int out = (size1 - size2 + (2 * opNum)) / 1 + 1;
        int **new = (int **)malloc(out * sizeof(int *));
        for (int i = 0; i < out; i++)
        {
            new[i] = (int *)malloc(out * sizeof(int));
        }
        //according to opNum calling functions.
        if (opNum == 0)
        {
            new = operasyon1(random1, random2, opNum, size1, size2);
        }
        else
        {
            new = operasyon2(random1, random2, opNum, size1, size2);
        }
        printf("\n");
        printf("*********NEW MATRIX*********");
        //printed new matrix.
        for (int i = 0; i < out; i++)
        {
            printf("\n");
            for (int j = 0; j < out; j++)
            {
                printf("%d\t", new[i][j]);
            }
        }
        //cleaned matrices.
        for (int i = 0; i < size1; i++)
        {
            free(random1[i]);
        }
        free(random1);

        for (int i = 0; i < size2; i++)
        {
            free(random2[i]);
        }
        free(random2);
        for (int i = 0; i < out; i++)
        {
            free(new[i]);
        }
        free(new);
        exit(1);

        return 0;
    }
}