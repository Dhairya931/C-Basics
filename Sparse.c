#include<stdio.h>
#include<stdlib.h>
int main()
{
int row,col,i,j,k,Matrix[10][10],count=0,nonzero_count;
int sparseMatrix[50][3];
printf("Enter row\n");
scanf("%d",&row);
printf("Enter Column\n");
scanf("%d",&col);
printf("Enter Element of Matrix1\n");
for(i = 0; i < row; i++){
for(j = 0; j < col; j++){
scanf("%d",&Matrix[i][j]);
}
}
printf("Elements are:\n");
for(i = 0; i < row; i++)
{
for(j = 0; j < col; j++)
{
printf("%d\t",Matrix[i][j]);
}
printf("\n");
}
/*checking sparse of matrix*/
for(i = 0; i < row; i++)
{
for(j = 0; j < col; j++)
{
if(Matrix[i][j] == 0)
count=count+1;
}
}
if(count > ((row * col)/2))
{
nonzero_count=(row * col)-count;
printf("Matrix is a sparse matrix with %d number of Elements \n",nonzero_count);
printf("Making of new matrix \n");
k=0;
sparseMatrix[k][0] = row;
sparseMatrix[k][1] = col;

sparseMatrix[k][2] = nonzero_count;
k=k+1;
for (int i = 0; i < row; i++)
for (int j = 0; j < col; j++)
if (Matrix[i][j] != 0)
{
sparseMatrix[k][0] = i;
sparseMatrix[k][1] = j;
sparseMatrix[k][2] = Matrix[i][j];
k++;
}
for (int i=0; i<nonzero_count+1; i++)//Misleading indentation: statement is indented too deeply clang-tidy (readability-misleading-indentation) [55, 1]
{
for (int j=0; j<3; j++)
printf("%d ",sparseMatrix[i][j]);
printf("\n");//Misleading indentation: statement is indented too deeply clang-tidy (readability-misleading-indentation) [59, 1]
}
}
else
printf("Matrix is not sparse matrix\n");
}
