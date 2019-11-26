#include "tp.h"

int main (int argc, char *argv[]) {
    int opt;
    int algoritmo_escolhido, i;

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
    algoritmo_escolhido = 2;

    switch (algoritmo_escolhido) {
        case 1:
            for (i = 0; i < instancias; i++) {
              printf("Instancia: %d\n", i);
              forca_bruta(matriz_instancias[i][0], matriz_instancias[i][1], matriz_instancias[i]);
            }
            break;
        case 2:

            break;
        case 3:

            break;
    }

    return 0;
}
