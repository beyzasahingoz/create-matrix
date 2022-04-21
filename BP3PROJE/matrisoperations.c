#include <stdio.h>
#include <stdlib.h>
#include "matrisoperations.h"
//operasyon1 function
int **operasyon1(int **matris1, int **matris2, int islemTipi, int arr1Size, int arr2Size)
{
    //defined integer values.
    int i, j, sum, k = 0, m = 0;
    //calculated new matrix size.
    int out = (arr1Size - arr2Size + (2 * islemTipi)) / 1 + 1;
    //defined temp matrix with malloc.
    int **temp = (int **)malloc(out * sizeof(int *));
    for (i = 0; i < out; i++)
    {
        temp[i] = (int *)malloc(out * sizeof(int));
    }
    //until temp matrix sizes, matrix 1 values multiply with matrix2 values.
    for (k = 0; k < out; k++)
    {
        for (m = 0; m < out; m++)
        {
            sum = 0;
            for (i = 0; i < arr2Size; i++)
            {

                for (j = 0; j < arr2Size; j++)
                {
                    sum += matris1[i + k][j + m] * matris2[i][j];
                }
            }
            //sum of every step adding temp matrix.
            temp[k][m] = sum;
        }
    }
    printf("\n");
    return temp;
}
//if 'islemTipi !=0' this method called.
int **operasyon2(int **matris1, int **matris2, int islemTipi, int arr1Size, int arr2Size)
{
    //defined integer values.
    int i, j, sum, k = 0, m = 0;
    //calculated new matrix size.
    int out = (arr1Size - arr2Size + (2 * islemTipi)) / 1 + 1;
    //defined temp matrix with malloc.
    int **temp = (int **)malloc(out * sizeof(int *));
    for (i = 0; i < out; i++)
    {
        temp[i] = (int *)malloc(out * sizeof(int));
    }
    //new matrix size is determined.
    int dimension = arr1Size + (2 * islemTipi);
    int c[dimension][dimension];
    //every elements of c matrix done 0.
    for (int k = 0; k < dimension; ++k)
    {
        for (int m = 0; m < dimension; ++m)
        {
            c[k][m] = 0;
        }
    }
    //matrix 1 adding c matrix.
    for (int i = 0; i < arr1Size; ++i)
    {
        for (int j = 0; j < arr1Size; ++j)
        {
            c[islemTipi + i][islemTipi + j] = matris1[i][j];
        }
    }
    printf("\n");
    printf("*********NEW MATRIX 1*********");
    //printed updated c matrix.
    for (i = 0; i < dimension; i++)
    {
        printf("\n");
        for (int j = 0; j < dimension; ++j)
        {
            printf("%d\t", c[i][j]);
        }
    }
    printf("\n");
    printf("*********MATRIX2*********");
    //printed matrix2.
    for (i = 0; i < arr2Size; i++)
    {
        printf("\n");
        for (int j = 0; j < arr2Size; ++j)
        {
            printf("%d\t", matris2[i][j]);
        }
    }
    printf("\n");
    //until temp matrix sizes, matrix 1 values multiply with matrix2 values.
    for (k = 0; k < out; k++)
    {
        for (m = 0; m < out; m++)
        {
            sum = 0;
            for (i = 0; i < arr2Size; i++)
            {

                for (j = 0; j < arr2Size; j++)
                {
                    sum += c[i + k][j + m] * matris2[i][j];
                }
            }
            //sum of every step adding temp matrix.
            temp[k][m] = sum;
        }
    }
    printf("\n");
    return temp;
}
