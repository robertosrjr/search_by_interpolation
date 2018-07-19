/*
 ============================================================================
 Name        : BuscaSequencial.c
 Author      : Roberto S. Ramos Jr
 Version     : 1.0
 Copyright   : robertosrjr@gmail.com
 Description : Algoritmo de Busca por Interpolação in C, Ansi-style
 	 	 	 : Obs.:
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int vec[] = {2, 8, 12, 28, 31, 33, 37, 41, 42, 47};

int main(void) {

	int resp_busca_binaria = -1;
	int num_a_ser_pesquisado = 28;

	resp_busca_binaria = buscaInterpolacao(vec, num_a_ser_pesquisado, 10);
	if (resp_busca_binaria == -1) {

		printf("\nO número %d não foi encontrado.", num_a_ser_pesquisado);
	} else {

		printf("\nO número %d foi encontrado na posição %d.", num_a_ser_pesquisado, resp_busca_binaria);
	}

	return EXIT_SUCCESS;
}

int buscaInterpolacao(int vec[], int arg, int tam) {

	int menor = 0;
	int maior = tam-1;
	int meio = 0;
	int achou = -1;

	while ((menor <= maior) && (achou == -1)) {

		meio = menor + (maior - menor) * ((arg - vec[menor]) / vec[maior] - vec[menor]);
		printf(" %d + (%d - %d) * ( (%d - %d) / %d - %d) = %d\n", menor, maior, menor, arg, vec[menor], vec[maior], vec[menor], meio);
		if (arg == vec[meio]) {

			achou = meio;
		}

		if (arg < vec[meio]) {

			maior = meio - 1;
		} else {

			menor = meio + 1;
		}
	}
	return(achou);
}
