#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>

struct rusage r_usage;
struct timeval start, end;
struct timeval user_start, user_end;
struct timeval sys_start, sys_end;
int instancias;

void imprimir_usuario (struct timeval start, struct timeval tend);
void imprimir_sistema (struct timeval start, struct timeval tend);
void fim_do_programa ();
int** abri_arq(char *nome);
void forca_bruta(int n, int k, int *linha_instancia);
int guloso(int inicio, int fim, int k, int *linha_instancia, int *vet_bin);
void Prog_Dinamica();
