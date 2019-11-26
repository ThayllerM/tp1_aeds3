#include "tp.h"

int** abri_arq(char *nome){
    int n, k;
    FILE *arq;
    arq = fopen(nome, "r");

        if(!arq){ //caso o arquivo nao abra, para mostrar o erro
            fprintf(stderr, "Erro ao abrir o arquivo.\n");
            exit(1);
        }

        fscanf(arq, "%d", &instancias); //pega a primeira posicao como o numeros de instancias.
        int **matriz_instancias = (int**) malloc(sizeof(int*)*instancias);
        for(int i = 0; i < instancias; i++){
            fscanf(arq, "%d %d", &n, &k);
            matriz_instancias[i] = (int*) calloc(n+4, sizeof(int)); //N+4 por causa do valor de N,K, Inicio e Final.
            matriz_instancias[i][0] = n; //n - numero de planetas na primeira coluna da matriz
            matriz_instancias[i][1] = k; //k - numero de planetas a serem conquistados na segunda coluna da matriz ao lado da qtd de planetas.

            for(int j = 0; j < n+1; j++){
                fscanf(arq, "%d", &matriz_instancias[i][j+2]); //looping para pegar as distancias dos caminhos
            }
        }

    fclose(arq);

        /*for(int i = 0; i < instancias; i++){
            for(int j = 0; j < matriz_instancias[i][0] + 4; j++){
                printf("%d ", matriz_instancias[i][j]);
            }
            printf("\n");
        }*/
    return matriz_instancias;
}

void converte_bin (int num, int *vet_bin) {

	int i = 0, j;
	int aux_num = num;

	while(num > 0) {
		vet_bin[i] = num % 2;
		i++;
		num = num / 2;
	}
}

int testa (int vet_bin[], int *linha_instancia) { // retornar o maior subcaminho da permutacao recebida
  int n = linha_instancia[0]; // total de planetas da instancia
  int k = linha_instancia[1]; // planetas a conquistar
  int max = 0, aux = linha_instancia[2];

  for (int i = 0; i < n; i++) {
    if (vet_bin[i] == 0) {
      aux += linha_instancia[i + 3];
    }
    else if (vet_bin[i] == 1) {
      if (max < aux) {
        max = aux;
      }
      aux = linha_instancia[i + 3];
    }
  }
  if (max < aux) {
    max = aux;
  }
  return max;
}

void forca_bruta(int n, int k, int *linha_instancia){
  int cont, i, j, trigger;
  int vet_bin[500] = {0};
  int max = pow(2, n);
  int min_max = INFINITY; // guardar o menor maior subcaminho das permutacoes geradas
  int aux;

  //gerar permutacoes

  for (i = 0; i < max; i++) {
    converte_bin(i, vet_bin);
    cont = 0;
    for (j = 0, trigger = 0; j < 500 && trigger == 0; j++) {
      if (vet_bin[j] == 1) {
        cont++;
      }
      if (cont > k) {
        trigger = 1;
      }
    }

    if (cont == k) {
      aux = testa(vet_bin, linha_instancia);
      if (aux < min_max) {
        min_max = aux;
      }
    }
  }
  printf("Menor maior subcaminho possivel: %d\n", min_max);
}

int guloso(int inicio, int fim, int k, int *linha_instancia, int *vet_bin){
  if (k == 0) { // se ja conquistou os planetas necessarios
    printf("Menor maior subcaminho possivel: %d\n", testa(vet_bin, linha_instancia));
    return 2;
  }
  else if (inicio < fim) { // se os planetas nao sao nem o primeiro nem o ultimo
    int i, max = 0, indice;
    int soma1 = 0, soma2 = 0;
    int retorno;

    //achar um pivo inicial, que vai buscar o maior caminho da instancia atual

    for (i = inicio; i < fim; i++) {
      if (linha_instancia[i] > max) {
        max = linha_instancia[i];
        indice = i;
      }
    }

    vet_bin[indice - 2] = 1;

    //descobrir se o subcaminho a esquerda do pivo e maior que o da direita

    for (i = inicio; i < indice; i++) {
      soma1 += linha_instancia[i];
    }

    for (i = indice + 1; i < fim; i++) {
      soma2 += linha_instancia[i];
    }

    if (soma1 > soma2) { // se a parcela a esquerda conter a maior soma de caminhos
      retorno = guloso(inicio, indice - 1, --k, linha_instancia, vet_bin);
      if (retorno == 2) { // caso ja tenha conquistado os planetas necessaios
        return 2;
      }
      else if (retorno == 1) { // caso o algoritmo precise conquistar mais planetas na parcela da direita
        retorno = guloso(indice + 1, fim, --k, linha_instancia, vet_bin);
        if (retorno == 2) { // caso ja tenha conquistado os planetas necessaios
          return 2;
        }
      }
    }
    else { // se a parcela a direita conter a maior soma de caminhos
      retorno = guloso(indice + 1, fim, --k, linha_instancia, vet_bin);
      if (retorno == 2) { // caso ja tenha conquistado os planetas necessaios
        return 2;
      }
      else if (retorno == 1) {  // caso o algoritmo precise conquistar mais planetas na parcela da esquerda
        retorno = guloso(inicio, indice - 1, --k, linha_instancia, vet_bin);
        if (retorno == 2) { // caso ja tenha conquistado os planetas necessaios
          return 2;
        }
      }
    }
    return 0;
  }
  else { // caso o conjunto de planetas analizados tenha apenas o primeiro ou o ultimo planeta
    vet_bin[inicio - 2] = 1;
    return 1;
  }
}

void Prog_Dinamica(){

}
