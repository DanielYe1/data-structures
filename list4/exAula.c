#include <stdio.h>
#include <stdlib.h>

void misc(int **mat, int l, int c, int *teste);

int main(){

	int col = 2;
	int row = 2;

	int **mat= malloc(sizeof(int*)*col);
	for (int i = 0; i < row; ++i){
		mat[i] = malloc(sizeof(int)*row);
	}

	mat[0][0] = 2;
	mat[0][1] = 0;
	mat[1][0] = 1;
	mat[1][1] = 2;

	int teste;
	misc(mat,row,col, &teste);

	return 0;
}



void misc(int **mat, int l, int c, int *teste){
	*teste=1;
	if(c!=l) *teste=0;
	int i,j;
	for (i = 0; i < l; i++){
		for (j = 0; j < c; j++){
			if(i!=j){
				if(mat[i][j] != mat[j][i])*teste=0;
			}
		}
	}

	printf("%d\n",*teste);
}