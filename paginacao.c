#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>

void ordena(int  numero[]){

int i, j, aux;

          for( i=0; i<3; i++ ){
                  for( j=i+1; j<4; j++ ){
                       if( numero[i] > numero[j] ){
                           aux = numero[i];
                           numero[i] = numero[j];
                           numero[j] = aux;
                       }
                  }
           }        
}

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

void tabela(){
	// TABELA DE PAGINA
int tam_pag = 8;
int vet_flag[tam_pag], vet_indice[tam_pag], vet_ini_pag[tam_pag], vet_fim_pag[tam_pag];
vet_ini_pag[0]= 0;
for (int i = 0; i < tam_pag; i++)
{
	vet_flag[i]= -1 ;	
}
for (int i = 0; i < tam_pag; i++)
{
	vet_indice[i]= i;
}
for (int i = 1; i < tam_pag; i++)
{
	vet_ini_pag[i]= vet_ini_pag[i-1]+4096;
}
for (int i = 0; i < tam_pag; i++)
{
	vet_fim_pag[i]=vet_ini_pag[i]+4095;
}
printf("\nflag ------- indice--------Inicio Pag.-------Fim Pag\n\n");
for (int i = 0; i < tam_pag; i++)
{
	printf("%d           %d               %d                  %d\n", vet_flag[i], vet_indice[i], vet_ini_pag[i], vet_fim_pag[i]);
}
//--------------------------------------------------------------

int tam_frame = 4;
int vet_indice_frame[tam_frame], vet_flag_frame[tam_frame];

for (int i = 0; i < tam_frame; i++)
{
	vet_indice_frame[i]= i;
}

for (int i = 0; i < tam_frame; i++)
{
	vet_flag_frame[i]= -1;
}



printf("tabela de frames\n");
printf("\nflag ------- indice\n\n");
for (int i = 0; i < tam_frame; i++)
{
	printf("%d            %d\n",vet_flag_frame[i], vet_indice_frame[i]);
}

int pagina_rand, frame_rand,  aux ;



for (int i = 0; i < tam_frame; i++)
{	
	
	srand(time(NULL));  
	pagina_rand = rand()%8;
	vet_flag_frame[i] = pagina_rand;	


	for(int j=0; j<i; j++)
		{
			if(vet_flag_frame[j] == vet_flag_frame[i])
			{
				vet_flag_frame[i] = (rand()%8)+1;
			
				j=0;
			}
		}
}
for (int i = 0; i < tam_frame; i++)
{
	aux = vet_flag_frame[i];
	vet_flag[aux] = i;
}


printf("\nIndice-------------- Flag---------------Inicio Pag.-------------Fim Pag\n\n");
for (int i = 0; i < tam_pag; i++)
{
	printf("[   %d   ]         [   %d  ]              [   %d  ]             [   %d  ]\n", vet_indice[i], vet_flag[i],  vet_ini_pag[i], vet_fim_pag[i]);
}


printf("tabela de frames\n");
printf("\nflag ------- indice\n\n");
for (int i = 0; i < tam_frame; i++)
{
	printf("%d            %d\n",vet_flag_frame[i], vet_indice_frame[i]);
}



int vet_alea[4], vet_desloc[4];
for (int i = 0; i < 4;i++)
{
		srand(time(NULL));  
	vet_alea[i] = rand()%32767;
		


	for(int j=0; j<i; j++)
		{
			if(vet_alea[j] == vet_alea[i])
			{
				vet_alea[i] = (rand()%32767)+1;
			
				j=0;
			}
		}
}
printf("\n\n");

int deslocamento, k=0;

ordena(vet_alea);

for (int i = 0; i < 4; i++)
{
	printf("%d\n",vet_alea[i]);
}


for (int i = 0; i < 8; i++)
{
	if (k == 4)
	{
		break;
	}
	while( k < 4){
		if (vet_alea[k]<vet_fim_pag[i])
		{	
			deslocamento = vet_alea[k]-vet_ini_pag[i];
			//printf("%d      %d       %d \n", vet_fim_pag[i],vet_ini_pag[i],vet_alea[k] );			

				vet_desloc[k]= deslocamento;
			printf("\n\nPagina = %d\n",vet_indice[i] );
			if (vet_flag[i] != -1)
			{
				printf("Moldura = %d\n\n", vet_flag[i] );
			}else{
				printf("PAGE FAULT\n\n");
			}
			
			k++;
		}else{
			break;
		}
	}
}







printf("\ndeslocamento \n");

for (int i = 0; i < 4; i++)
{
	printf("%d\n",vet_desloc[i] );
}

//---------------------------------
printf("\nIndice-------------- Flag---------------Inicio Pag.-------------Fim Pag\n\n");
for (int i = 0; i < tam_pag; i++)
{	if (vet_flag[vet_indice[i]] != -1)
{	 
	//printf(" DECIMAL            DECIMAL                 DECIMAL              DECIMAL\n");
	printf("[   %d   ]         [   %d  ]              [   %d  ]             [   %d  ]\n", vet_indice[i], vet_flag[i],  vet_ini_pag[i], vet_fim_pag[i]);
}
	
}


//--------------------------------------------imprime pf







}





void main(void){
	int n;
	tabela();
	//printf("informe um numero decimal para converter para binario\n");
	//scanf("%d",&n);
	//converteBinario(n);
}
