#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int instancias;

int** abri_arq(char *nome);
void forca_bruta(int n, int k, int *linha_instancia);
int guloso(int inicio, int fim, int k, int *linha_instancia, int *vet_bin);
void Prog_Dinamica();
