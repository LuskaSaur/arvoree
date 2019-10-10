#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define LINHAS 1000
#define COLUNAS 1000
int rseed = 0;
clock_t start, end;
double cpu_time_used;

void multMat(int **a, int **b){
  int **c,i,j,k;

	c = (int**)malloc(LINHAS * sizeof(int*));


	for(i = 0; i < LINHAS; i++){
    c[i] = (int*)malloc(COLUNAS * sizeof(int));
  }
  for (i=0;i<LINHAS; i++) {
    for (j=0; j<LINHAS; j++) {
      for (k=0; k<COLUNAS; k++) {
        c[i][j] = c[i][j] + (a[i][k] * b[k][j]);

      }
    }
  }

}
int main()
{

	int **mat,**mat2;

	mat = (int**)malloc(LINHAS * sizeof(int*));
  mat2 = (int**)malloc(LINHAS * sizeof(int*));

	int i;
	for(i = 0; i < LINHAS; i++){
    mat[i] = (int*)malloc(COLUNAS * sizeof(int));
    mat2[i] = (int*)malloc(COLUNAS * sizeof(int));
  }


	int j;


	for(i = 0; i < LINHAS; i++)
	{
		for(j = 0; j < COLUNAS; j++){
      mat[i][j] = i + j;
      mat2[i][j] = i * j;
    }

	}
  multMat(mat,mat2);

/*
	for(i = 0; i < LINHAS; i++)
	{
		for(j = 0; j < COLUNAS; j++){
      printf("%d\t", mat[i][j]);
      printf("%d\t", mat2[i][j]);
    }

		printf("\n");
	}

	for(i = 0; i < LINHAS; i++){
    free(mat[i]);
    free(mat2[i]);
  }


	free(mat);
  free(mat2);
*/
  end = clock();
  cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
  printf(" time (sec) = %f\n",cpu_time_used );
  for(i = 0; i < LINHAS; i++){
    free(mat[i]);
    free(mat2[i]);
  }


	free(mat);
  free(mat2);
  }
