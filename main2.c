#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int l;
    int c;
    int* vet;
} Matriz;

Matriz dimensionaMatriz(int i, int j){

    Matriz mt;
    mt.l = i;
    mt.c = j;
    mt.vet = malloc(i*j*sizeof (int));

    return mt;

}

void zeraMatriz(Matriz mat){
    memset(mat.vet,0, sizeof &mat.vet);
}

int calcK(Matriz mat,int i, int j){
    return ((i-1)*mat.c)+(j-1);
}

void imprimirMatriz(Matriz mat){
    for(int x = 1; x <= mat.l; x++){
        printf("[");
        for(int y=1; y <= mat.c; y++){
            if(y==mat.c){
                printf("%d", mat.vet[calcK(mat,x,y)]);
            }else{
                printf("%d,", mat.vet[calcK(mat,x,y)]);
            }
        }
        printf("]\n");
    }
}


void adicionaElemento(Matriz mat, int value, int i, int j){
    const int k = calcK(mat,i,j);
    mat.vet[k] = value;
}

int buscarElemento(Matriz mat, int i, int j){
    return mat.vet[calcK(mat,i,j)];
}

Matriz somarMatrizes(Matriz m1, Matriz m2){

    Matriz sum;
    sum = dimensionaMatriz(m1.l,m1.c);

    for(int x = 0; x < m1.l*m1.c; x++){
        sum.vet[x] = m1.vet[x] + m2.vet[x];
    }

    return sum;

}


int main(){

    setbuf(stdout, 0);
    const int i = 3;
    const int j = 3;


    Matriz mat = dimensionaMatriz(i,j);
    zeraMatriz(mat);
    imprimirMatriz(mat);
    adicionaElemento(mat,5,1,1);
    adicionaElemento(mat,25,2,2);
    adicionaElemento(mat,35,3,3);
    imprimirMatriz(mat);

    printf("O elemento na posição linha 2 e coluna 2 é: %d\n", buscarElemento(mat,2,2));

    Matriz mat2 = dimensionaMatriz(i,j);
    zeraMatriz(mat2);
    adicionaElemento(mat2,10,1,1);
    adicionaElemento(mat2,20,3,3);

    printf("Soma\n");

    imprimirMatriz(mat);
    printf("+\n");
    imprimirMatriz(mat2);
    printf("\n");
    imprimirMatriz(somarMatrizes(mat,mat2));


    return 0;
}
