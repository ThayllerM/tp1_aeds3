#include "tp.h"

int main (int argc, char *argv[]) {
    int opt = getopt(argc, argv, "a:");
    int algoritmo_escolhido, i;

    switch (opt) {
        case 'a':
            if (optarg[0] == 'F' && optarg[1] == 'B') { //algoritmo forca bruta
                algoritmo_escolhido = 1;
            }
            else if (optarg[0] == 'A' && optarg[1] == 'G') { //algoritmo guloso
                algoritmo_escolhido = 2;
            }
            else if (optarg[0] == 'P' && optarg[1] == 'D') { //algoritmo programacao dinamica
                algoritmo_escolhido = 3;
            }
            else{
                fprintf(stderr, "Opcao invalida\n");
                return -1;
            }
            break;
        default:
            fprintf(stderr, "Opcao invalida ou faltando argumento: '-a'\n") ;
            return -1;
    }

    int **matriz_instancias = abri_arq("entrada.txt");
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
