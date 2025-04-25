#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define tam 10

void copymatrix(int msource[tam][tam], int mdest[tam][tam]){
    for(int i =0; i < tam; i++){
        for (int j=0; j<tam; j++){
            mdest[i][j] = msource[i][j];
        }
    }
}


void printmatrix(int matriz[tam][tam]){
    for(int i =0; i < tam; i++){
            for (int j=0; j<tam; j++){
                if(matriz[i][j]== 0){
                    printf("- ");
                }
                if(matriz[i][j]== 1){
                    printf("V ");
                }
            }
            printf("\n");
        }
}

int count(int matrizA[tam][tam], int matrizB[tam][tam]){
    int vivo;
    for(int i=0; i<tam;i++){
            for(int j=0;j<tam;j++){
                vivo =0;

                for(int a=(i-1); a<(i+1);a++){
                    for(int b=(j-1);b<(j+1);b++){
                        if(a == b){
                            continue;
                        }
                        if (a > 0 && a < tam && b > 0 && b < tam){
                            vivo += matrizA[a][b];
                        }
                        //printf("%i", matrizA[i-a][j-b]);
                    }
                }

                if(matrizA[i][j] == 1){
                    if(vivo < 2 || vivo > 3){
                        matrizB[i][j] = 0;
                    }else{
                        matrizB[i][j] = 1;
                    }
                }else{
                    if(vivo == 3){
                        matrizB[i][j] = 1;
                    }else{
                        matrizB[i][j] = 0;
                    }
                }
            }
        }
}
int main(){

    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));


    //Define as duas matrizes, uma tabuleiro e outra de apoio.
    int A[tam][tam], B[tam][tam];

    // Realiza a primeira geração
    for(int i =0; i < tam; i++){
        for (int j=0; j<tam; j++){
            A[i][j]= rand() %2;
        }
    }

    printf("\nSeed: \n");
    printmatrix(A);

    // Copia matriz A para B
    copymatrix(A,B);


    for(int k = 0; k < 4; k++){
        // Copia Matriz B para A
        copymatrix(B,A);

        printf("\n%d° Geração: \n", k+1);
        count(A,B);

        printmatrix(B);
    }

    return 0;
}

