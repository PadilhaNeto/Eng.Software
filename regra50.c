#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int moeda(){
	int random;
	random = rand() % 2;
	return  random;
}


void matar_proc( int n, int vet_processos[]){
	srand(time(NULL));
	for(int i = 0; i< n; i++){
	int flag = moeda();
		if(flag == 0){
		vet_processos[i]= 0;
		}

	}
}
void contar_buraco( int vet_processos[], int n){
int cont_p =0, cont_b=0;
  for(int i=0; i< n; i++){  
	  while(vet_processos[i]==0 ){		
		cont_b++;		  
		if(vet_processos[i] == vet_processos[i+1] ){
	    cont_b--;	  
        }	
		break;	  
	  }
	  while(vet_processos[i]!=0 ){	
		cont_p++;
		break;
	 }
	}

printf("\n\n|------------------------------|\n");
printf("     Numero de buracos: %d      \n", cont_b);
printf("    Numero de processos: %d     \n", cont_p );
printf("|------------------------------|\n");
}
void main(void){
int n;
printf("|-----------------------------------|\n");
printf("| Jose Padilha Neto - Breno Teodoro |\n");
printf("|-----------------------------------|\n");
printf("|          Regra dos 50%%            |\n");
printf("|------------------------------------------------------------------------------------|\n");
printf("| Descriçao: O usuario devera informar o numero de processos que desejar,            |\n");
printf("| o programa ira jogar uma 'moeda' para decidir se o processo sera eliminado,        |\n");
printf("| mantendo assim 50%% de chance de ser eliminado e 50%% de nao ser eliminado.          |\n");
printf("| No final o programa exibe o numero de buracos e o numero de processos na memoria ! |\n");




printf("|-----------------------------------|\n");
printf("[   Informe o numero de processos : ]\n");
scanf("%d",&n);
int vet_processos[n];
for (int i = 0; i < n; i++)
{
	vet_processos[i] = i+1;
}
printf("\n");	
matar_proc(n, vet_processos);
	for(int i =0 ;i< n;i++){
	printf(" %d", vet_processos[i] );
	}
	printf("\n");
	contar_buraco(vet_processos,n);

}