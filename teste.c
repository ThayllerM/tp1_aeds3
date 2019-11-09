#include <stdio.h>
#define MAX 50

int main()
{
	// exemplo de um número em decimal
	int num = 40000;
	// vetor de MAX posições para guardar o número em binário
	int vet_bin[MAX];
	// variáveis de controle de loop
	int i = 0, j;
	// aux_num serve para guardar num para mostrar posteriormente
	int aux_num = num;

	/*
		Para converter um número decimal em binário basta dividir
		sucessivamente o número decimal por 2 guardando o resto
		da divisão.
		Exemplo: 8
		resto de 8 por 2 = 0
		8 / 2 = 4
		resto de 4 por 2 = 0
		4 / 2 = 2
		resto de 2 por 2 = 0
		2 / 2 = 1
		resto de 1 por 2 = 1
		1 / 2 = 0
		FIM
		Por último é só pegar do último resto pro primeiro
		8 em binário é 1000
	*/

	// enquanto "num" for maior que 0
	while(num > 0)
	{
		// obtém o resto da divisão de num por 2
		vet_bin[i] = num % 2;
		i++;
		num = num / 2;
	}

	printf("%d em binario: ", aux_num);

	// percorre o vetor para mostrar o número em binário
	for(j = i - 1; j >= 0; j--)
		printf("%d", vet_bin[j]);
	printf("\n");

	return 0;
}
