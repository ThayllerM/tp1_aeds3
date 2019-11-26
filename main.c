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
    algoritmo_escolhido = 3;
    int vet_bin[500] = {0};

    switch (algoritmo_escolhido) {
        case 1:
            for (i = 0; i < instancias; i++) {
              printf("Instancia FB: %d\n", i);
              forca_bruta(matriz_instancias[i][0], matriz_instancias[i][1], matriz_instancias[i]);
            }
            break;
        case 2:
            for (i = 0; i < instancias; i++) {
              printf("Instancia PG: %d\n", i);
              guloso(2, matriz_instancias[i][0] + 2, matriz_instancias[i][1], matriz_instancias[i], vet_bin);
            }
            break;
        case 3:
            for (i = 0; i < instancias; i++) {
              printf("Instancia PD: %d\n", i);
              Prog_Dinamica(2, matriz_instancias[i][0] + 2, matriz_instancias[i][1], matriz_instancias[i], vet_bin);
            }
            break;
    }

    return 0;
}
