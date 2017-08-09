#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
//funçao para converter decimal para binario
void converteBinario(int n){
	int resto, divisao, vetBin[10];
//inicia o vetor de bit com -1
	for (int j = 0; j < 10; j++){

		vetBin[j] = -1;
	}

	int i =0;
	divisao = n;
	resto = n;
//rotina para dividir o n/2 e guardar os restos no vetor para formar o binario
	do{

	resto = divisao % 2;
	divisao = divisao / 2;
	vetBin[i] = resto;
	i++;

	}
	while ( divisao >= 2);
//armazena o ultimo resultado no vetor
	vetBin[i]= divisao;
	printf("numero em decimal: %d\n",n );
	printf("valor em binario: \n");
//completa o vetor com 0 ate chegar no numero de bits proposto
	for (int j = 0; j < 10; j++){
	
		if (vetBin[j] == -1)
		{
			vetBin[j] = 0;
		}
	}

// imprime o vetor da ultima posiçao ate a primeira
	for (int j = 9; j >= 0 ; j--){
	printf("%d",vetBin[j]);
	}

}

void main(void){
	int n;
	printf("informe um numero decimal para converter para binario\n");
	scanf("%d",&n);
	converteBinario(n);
}