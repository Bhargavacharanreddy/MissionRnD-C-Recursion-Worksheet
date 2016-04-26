/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void  spiralOrder(int **A, int m, int n,int *result)
{
	int x = 0;
	int i, k = 0, l = 0;
	while (k < m && l < n)
	{
		/* Printing the first row  */
		for (i = l; i < n; ++i)
		{
			result[x++]=A[k][i];
		}
		k++;

		/* Printing the last column */
		for (i = k; i < m; ++i)
		{
			result[x++] = A[i][n - 1];
		}
		n--;

		/* Printing the last row */
		if (k < m)
		{
			for (i = n - 1; i >= l; --i)
			{
				result[x++] = A[m - 1][i];
			}
			m--;
		}

		/* Printing the first column*/
		if (l < n)
		{
			for (i = m - 1; i >= k; --i)
			{
				result[x++] = A[i][l];
			}
			l++;
		}
	}
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array==NULL || rows<=0 || columns<=0)
	return NULL;
	int *result;
	result = (int *)malloc((rows*columns)*sizeof(int));
	spiralOrder(input_array, rows, columns, result);
	return result;

}
