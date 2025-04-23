#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define tam 5

void copymatrix(int msource[tam][tam], int mdest[tam][tam]){
    for(int j =0; j < tam; j++){
        for (int i=0; i<tam; i++){
            mdest[j][i] = msource[j][i];
        }
    }
}


void printmatrix(int matriz[tam][tam]){
    for(int j =0; j < tam; j++){
            for (int i=0; i<tam; i++){
                if(matriz[j][i]== 0){
                    printf("- ");
                }
                else{
                    printf("V ");
                }
            }
            printf("\n");
        }
}


int main(){

    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));


    //Define as duas matrizes, uma tabuleiro e outra de apoio.
    int A[tam][tam], B[tam][tam],qtd;

    // Realiza a primeira geração
    for(int j =0; j < tam; j++){
        for (int i=0; i<tam; i++){
            A[j][i]= rand() %2;
        }
    }

    printf("\n1° Geração: \n");
    printmatrix(A);

    // Copia matriz A para B
    copymatrix(A,B);


    for(int k = 0; k < 2; k++){

        // Copia Matriz B para A
        copymatrix(B,A);

        printf("\n%d° Geração: \n", k+2);
        for(int j=0; j<tam;j++){
            for(int i=0;i<tam;i++){
                qtd =0;
                if(j == 0 || i == 0 || j == tam-1 || i == tam -1){
                    if(j ==0 && i == 0){
                        qtd = A[1][0] + A[0][1] + A[1][1];
                    }
                    if(j == tam-1 && i == 0){
                        qtd = A[j][i+1] + A[j+1][i+1] + A[j][i+1];
                    }
                    if(j == tam-1 && i == tam -1){
                        qtd = A[j-1][i] + A[j-1][i-1] + A[j][i-1];
                    }
                    if(j == tam-1 && i == tam -1){
                        qtd = A[j-1][i] + A[j-1][i-1] + A[j][i-1];
                    }

                    if(qtd > 3 || qtd <2){
                        B[j][i] = 0;
                        }
                    else{
                        B[j][i] = 1;
                    }

                }
                else{
                    qtd = A[j-1][i-1] + A[j][i-1] + A[j+1][i-1] + A[j-1][i] + A[j+1][i] + A[j-1][i+1] + A[j][i+1] + A[j+1][i+1];
                    if(qtd > 3 || qtd <2){
                        B[j][i] = 0;
                    } else{
                        B[j][i] = 1;
                    }
                }
            }
        }

        printmatrix(B);
    }

    return 0;
}

