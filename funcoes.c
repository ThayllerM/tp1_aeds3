#include "tp.h"

int** abri_arq(char *nome){
    int n, k;
    FILE *arq;
    arq = fopen(nome, "r");

        if(!arq){
            fprintf(stderr, "Erro ao abrir o arquivo.\n");
            exit(1);
        }
        
        fscanf(arq, "%d", &instancias);
        int **matriz_instancias = (int**) malloc(sizeof(int*)*instancias);
        for(int i = 0; i < instancias; i++){
            fscanf(arq, "%d %d", &n, &k);
            matriz_instancias[i] = (int*) calloc(n+4, sizeof(int));
            matriz_instancias[i][0] = n;
            matriz_instancias[i][1] = k;

            for(int j = 0; j < n+1; j++){
                fscanf(arq, "%d", &matriz_instancias[i][j+2]);
            }
        }

    fclose(arq);    

     /*   for(int i = 0; i < instancias; i++){
            for(int j = 0; j < matriz_instancias[i][0] + 4; j++){
                printf("%d ", matriz_instancias[i][j]);
            }
            printf("\n");
        }*/
    return matriz_instancias;
}

void forca_bruta(int n, int k){


}

void guloso(){


}

void Prog_Dinamica(){

    
}