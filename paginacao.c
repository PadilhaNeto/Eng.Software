#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
float cont_Pf = 0.0, cont_Ok = 0.0;
float percPF , percOK ;
void ordena(int  numero[], int cont_alea){

int i, j, aux;

          for( i=0; i<cont_alea-1; i++ ){
                  for( j=i+1; j<cont_alea; j++ ){
                       if( numero[i] > numero[j] ){
                           aux = numero[i];
                           numero[i] = numero[j];
                           numero[j] = aux;
                       }
                  }
           }        
}

//funçao para converter decimal para binario
void converteBinario(int n, int bits){
	int resto, divisao, vetBin[bits];
//inicia o vetor de bit com -1
	for (int j = 0; j < bits; j++){

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
	//printf("numero em decimal: %d\n",n );
	printf(" ");
//completa o vetor com 0 ate chegar no numero de bits proposto
	for (int j = 0; j < bits; j++){
	
		if (vetBin[j] == -1)
		{
			vetBin[j] = 0;
		}
	}

// imprime o vetor da ultima posiçao ate a primeira
	for (int j = bits-1; j >= 0 ; j--){
	printf("%d",vetBin[j]);
	}

}

void tabela(int n){
	// TABELA DE PAGINA
int tam_pag = 1024;
int vet_flag[tam_pag], vet_indice[tam_pag], vet_ini_pag[tam_pag], vet_fim_pag[tam_pag];
vet_ini_pag[0]= 0;
//inicia o vetor de paginaçao de frame com -1
for (int i = 0; i < tam_pag; i++)
{
	vet_flag[i]= -1 ;	
}
//inicia os valores de indeces de pagina
for (int i = 0; i < tam_pag; i++)
{
	vet_indice[i]= i;
}
//inicia os valores de inicio das paginas
for (int i = 1; i < tam_pag; i++)
{
	vet_ini_pag[i]= vet_ini_pag[i-1]+4096;
}
//inicia os valores de final das paginas
for (int i = 0; i < tam_pag; i++)
{
	vet_fim_pag[i]=vet_ini_pag[i]+4095;
}
//imprime a tabela de endereços de pagina sem mapeamento
printf("\nIndice__________Indice Moldura__________Inicio Pag.__________Fim Pag\n\n");
for (int i = 0; i < tam_pag; i++)
{
	printf("%d", vet_indice[i] );
	if (vet_indice[i] < 10)
	{
		printf("                    ");
	}else if (vet_indice[i] >= 10 && vet_indice[i]< 100){
		printf("                   ");
	}else if (vet_indice[i] >= 100 && vet_indice[i]< 1000 ){
		printf("                  ");
	}else if (vet_indice[i] >= 1000 && vet_indice[i]< 10000 ){
		printf("                 ");
	}
	
	printf("%d", vet_flag[i]);
	if (vet_indice[i] < 10)
	{
		printf("                    ");
	}else if (vet_indice[i] >= 10 && vet_indice[i]< 100){
		printf("                   ");
	}else if (vet_indice[i] >= 100 && vet_indice[i]< 1000 ){
		printf("                  ");
	}else if (vet_indice[i] >= 1000 && vet_indice[i]< 10000 ){
		printf("                 ");
	}
	
	printf("%d", vet_ini_pag[i]);
	if (vet_indice[i] < 10)
	{
		printf("                    ");
	}else if (vet_indice[i] >= 10 && vet_indice[i]< 100){
		printf("                   ");
	}else if (vet_indice[i] >= 100 && vet_indice[i]< 1000 ){
		printf("                  ");
	}else if (vet_indice[i] >= 1000 && vet_indice[i]< 10000 ){
		printf("                 ");
	}

	printf("%d", vet_fim_pag[i]);
	printf("\n");

}
//--------------------------------------------------------------

int tam_frame = tam_pag/2;
int vet_indice_frame[tam_frame], vet_flag_frame[tam_frame];
//inicializa os indices de cada frame
for (int i = 0; i < tam_frame; i++)
{
	vet_indice_frame[i]= i;
}
//inicia os indices das paginas em frames
for (int i = 0; i < tam_frame; i++)
{
	vet_flag_frame[i]= -1;
}

//gera paginas aleatorias e associa as frames
int pagina_rand, frame_rand,  aux , randon;

randon = tam_pag - 1 ;

srand(time(NULL));
for (int i = 0; i < tam_frame; i++)
{		  

	vet_flag_frame[i] = rand()%randon;	

	
	for(int j=0; j<i; j++)
		{
			
			if(vet_flag_frame[i] == vet_flag_frame[j])
			{
			
					
				vet_flag_frame[i] = rand()%randon;
				j=0;
				
				
			}
		}	

}
/**/
for (int i = 0; i < tam_frame; i++)
{
	aux = vet_flag_frame[i];
	vet_flag[aux] = i;
}
//imprime tabela mapeada

printf("\nIndice___________Indice Moldura.___________Inicio Pag.______________Fim Pag\n\n");
for (int i = 0; i < tam_pag; i++)
{
	printf("%d", vet_indice[i] );
	if (vet_indice[i] < 10)
	{
		printf("                    ");
	}else if (vet_indice[i] >= 10 && vet_indice[i]< 100){
		printf("                   ");
	}else if (vet_indice[i] >= 100 && vet_indice[i]< 1000 ){
		printf("                  ");
	}else if (vet_indice[i] >= 1000 && vet_indice[i]< 10000 ){
		printf("                 ");
	}
	
	printf("%d", vet_flag[i]);
	if (vet_indice[i] < 10)
	{
		printf("                    ");
	}else if (vet_indice[i] >= 10 && vet_indice[i]< 100){
		printf("                   ");
	}else if (vet_indice[i] >= 100 && vet_indice[i]< 1000 ){
		printf("                  ");
	}else if (vet_indice[i] >= 1000 && vet_indice[i]< 10000 ){
		printf("                 ");
	}
	
	printf("%d", vet_ini_pag[i]);
	if (vet_indice[i] < 10)
	{
		printf("                    ");
	}else if (vet_indice[i] >= 10 && vet_indice[i]< 100){
		printf("                   ");
	}else if (vet_indice[i] >= 100 && vet_indice[i]< 1000 ){
		printf("                  ");
	}else if (vet_indice[i] >= 1000 && vet_indice[i]< 10000 ){
		printf("                 ");
	}

	printf("%d", vet_fim_pag[i]);
	printf("\n");
}
printf("_________________________________________________________________________\n");
//imprime a tabela de frames mapeada
printf("\nTabela de frames\n");
printf("\nIndice da Pagina _______ Indice da Moldura\n\n");
for (int i = 0; i < tam_frame; i++)
{
	printf("|     %d                       %d       |\n",vet_flag_frame[i], vet_indice_frame[i]);
}
printf("________________________________________________\n");

//gera quantidade de numeros aleatoriamente (fornecido elo usuario)
int vet_alea[n], vet_desloc[n];
srand(time(NULL)); 
for (int i = 0; i < n;i++)
{
		 
	vet_alea[i] = rand()% 4194302;	


	for(int j=0; j<i; j++)
		{
			if(vet_alea[j] == vet_alea[i])
			{
				vet_alea[i] = (rand()% 4194302)+1;
			
				j=0;
			}
		}
}
printf("\n");

int deslocamento, k=0;

ordena(vet_alea, n);
printf("%d VALORES GERADOS ALEATORIAMENTE PARA CONSULTA\n\n",n);
for (int i = 0; i < n; i++)
{
	printf("%d   ",vet_alea[i]);
}
printf("\n________________________________________________\n");
//imprime tabela dos elementos randomicos consultados em decimal------------------------
printf("\nTABELA DE PAGINAÇAO EM DECIMAL\n");
	printf("\n\n________[ Endereço_Virtual ]_____________________________________[Endereço_Real ]______________\n\n");
for (int i = 0; i < tam_pag; i++)
{
	if (k == n)
	{
		break;
	}

	while( k < n){
	//	printf("vetor aleatorio %d\n",vet_alea[k]);
	//	printf("vetor fim de pagina %d\n",vet_fim_pag[i]);


		if (vet_alea[k]<vet_fim_pag[i])
		{	
			deslocamento = vet_alea[k]-vet_ini_pag[i];
						

				vet_desloc[k]= deslocamento;
			printf("\n%d        ",vet_indice[i] );
			printf("                  %d        ",vet_desloc[k]);
			if (vet_flag[i] != -1)
			{
				printf("                   %d      ", vet_flag[i] );
				printf("                  %d        ",vet_desloc[k]);

			}else{   
				printf("                   PAGE FAULT  ");
				printf("                ---  ");
			} 
			printf("\n");
			k++;
		}else{
			break;
		}
	}
}
printf("________________________________________________________________________________________________\n");
//imprime tabela dos elementos randomicos consultados em binario------------------------
printf("\n\nTABELA DE PAGINAÇAO EM BINARIO\n");
	printf("\n\n________End.Virtual_________________________End.Real______________\n\n");
k = 0;
for (int i = 0; i < tam_pag; i++)
{
	if (k == n)
	{
		break;
	}

	while( k < n){
		if (vet_alea[k]<vet_fim_pag[i])
		{	
			deslocamento = vet_alea[k]-vet_ini_pag[i];
						

				vet_desloc[k]= deslocamento;
			
			converteBinario(vet_indice[i],10);	
			converteBinario(vet_desloc[k],12);		
			printf("                  ");

			if (vet_flag[i] != -1)
			{
				converteBinario(vet_flag[i],8);
				converteBinario(vet_desloc[k],12);	
				cont_Ok = cont_Ok + 1.0;
			}else{

				printf(" PAGE FAULT  ");
				cont_Pf = cont_Pf + 1.0;

			} 
			printf("\n");
			k++;
		}else{
			break;
		}
	}
}
printf("__________________________________________________________________\n\n");
percPF = ( cont_Pf*100)/n;
percOK = ( cont_Ok*100)/n;
printf("TOTAL DE ENDEREÇOS BUSCADOS : %d\n\n",n );
printf("NUMERO DE ACERTOS: [ %.f ]  EQUIVALENTE A %.3f %%\n",cont_Ok, percOK);
printf("NUMERO DE PAGE FAULTS: [ %.f ]  EQUIVALENTE A %.3f %%\n\n",cont_Pf,  percPF);






}





void main(void){
printf("|-----------------------------------|\n");
printf("| Jose Padilha Neto - Breno Teodoro |\n");
printf("|-----------------------------------|\n");
printf("|             Paginaçao             |\n");
printf("|---------------------------------------------------------------------------------------------|\n");
printf("| Descriçao: O usuario devera informar a quantidade de numeros que desejar,                   |\n");
printf("| o programa ira gerar aleatoriamente a quantidade de numeros informada em um                 |\n");
printf("| intervalo entre 0 e 4194302 que correspondem ao endereços virtuais das paginas.             |\n");
printf("| No final o programa exibe a tabela desses numeros gerados, mostrando se estao mapeados ou ! |\n");
printf("| com Page Fault.                                                                             |\n");






	int n;
	printf("\nInforme um numero de endereços que deseja consultar\n");
	scanf("%d",&n);
	tabela(n);
	
	
	//converteBinario(n);
}
