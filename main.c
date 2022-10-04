#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int* dimensionaMatriz(int i, int j){

    int* mat = malloc(i*j* sizeof (int));
    return mat;

}

void zeraMatriz(int* mat){
    memset(mat,0, sizeof mat);
}

int calcK(int i, int j, int c){
    return ((i-1)*c)+(j-1);
}

int buscarElemento(int* mat, int i, int j, int c){
    return mat[calcK(i,j,c)];
}

void imprimirMatriz(int* mat,int i, int j){
    for(int x = 1; x <= i; x++){
        printf("[");
        for(int y=1; y <= j; y++){
            if(y==j){
                printf("%d", buscarElemento(mat, x,y,j));
            }else{
                printf("%d,", buscarElemento(mat, x,y,j));
            }
        }
        printf("]\n");
    }
}


void adicionaElemento(int* mat, int value, int i, int j, int c){
    const int k = calcK(i,j,c);
    mat[k] = value;
}


int* somarMatrizes(int* m1, int* m2, int i, int j){

    int* sum = malloc(i*j*sizeof (int));

    for(int x = 0; x < i*j; x++){
        sum[x] = m1[x] + m2[x];
    }

    return sum;

}


int main(){

    setbuf(stdout, 0);
    const int i = 3;
    const int j = 3;


    int* mat = dimensionaMatriz(i,j);
    zeraMatriz(mat);
    imprimirMatriz(mat, i, j);
    adicionaElemento(mat,15,1,1,j);
    adicionaElemento(mat,25,2,2,j);
    adicionaElemento(mat,35,3,3,j);
    imprimirMatriz(mat, i, j);

    printf("O elemento na posição linha 2 e coluna 2 é: %d\n", buscarElemento(mat,2,2,j));

    int* mat2 = dimensionaMatriz(i,j);
    zeraMatriz(mat2);
    adicionaElemento(mat2,10,1,1,j);
    adicionaElemento(mat2,20,3,3,j);

    printf("Soma\n");

    imprimirMatriz(somarMatrizes(mat,mat2,i,j),i,j);


    return 0;
}
