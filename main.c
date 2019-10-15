#include "tp.h"

int main (int argc, char *argv[]) {
    int opt;
    int algoritmo_escolhido;

    while((opt = getopt(argc, argv, "a:")) > 0) {
        switch (opt) {
            case 'a':
                if (strcmp(optarg, "FB")) { //algoritmo forca bruta
                    algoritmo_escolhido = 1;
                }
                else if (strcmp(optarg, "AG")) { //algoritmo guloso
                    algoritmo_escolhido = 2;
                }
                else if (strcmp(optarg, "PD")) { //algoritmo programacao dinamica
                    algoritmo_escolhido = 3;
                }
                else{
                    fprintf(stderr, "Opcao invalida\n");
                    return -1;   
                }
                break;
            default:
                fprintf(stderr, "Opcao invalida ou faltando argumento: `-a'\n") ;
                return -1;
        }
    }

    int **matriz_instancias = abri_arq("entrada.txt");


    return 0;
}