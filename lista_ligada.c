#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>



void inicializa_tab(int vet[], int tam, int vet_aux[]){

	for (int i = 0; i < tam; i++){

		vet[i] = 0;
	}

}
void criar_proc(int vet[], int vet_aux[],int tam , int pid){


int flag, proc, aux =0;
do{

printf("Informe o tamanho do processo :\n");
scanf("%d",&proc);


int j = proc + (aux);

if(j > tam){

	printf("\nEsse processo excede o tamanho livre da memoria, o processo nao foi criado\n");
	return;
}

for(int i= (aux); i< j;i++){

	vet[i] = pid;
	aux++;
}
pid++;

printf("\nPROCESSO INSERIDO NO MAPA DE BITS \n");
printf("-----------------------------------\n");
printf("deseja inserir outro ?(sim = 1, nao = 0 )\n");

       scanf("%d",&flag);

    
}while ( flag == 1);
}
void matar_proc( int vet[], int tam){
int id, flag = 0, inicio, contador =0;
printf("Qual o id do processo que voce deseja matar?\n");
scanf("%d",&id);

do{
	for (int i = 0; i< tam; i++){
		//printf("entrou no FOR, valor de i = %d |\n",i);
		if(vet[i] == id){
			//printf("entrou no if de busca 01 |\n");
			contador++;
		}		
	}
	for (int i = 0; i< tam; i++){
	 if(vet[i] == id){
	 		//printf("entrou no if de busca 02 |\n");
			inicio = i;	
			break;		
		}
	}


//printf("valor de inicio = %d \n", inicio );
//printf("valor de contador = %d \n", contador );

int j= inicio + contador;
for(int i= inicio; i< j;i++){

	vet[i]=0;
}
printf("PROCESSO ELIMINADO!!!\n");
printf("deseja matar outro ?(sim = 1, nao = 0 )\n");

       scanf("%d",&flag);

}while(flag == 1);

}
void imprime_tab(int vet[], int tam, int vet_aux[]){
	printf("-----------------------\n");
	printf("\nMAPA DE BITS DA MEMORIA\n");
	printf("-----------------------\n");
	for (int i = 0; i < tam; i++){

		printf("%d", vet[i]);
	}
	printf("\n-----------------------\n");

	/*for (int i = 0; i < cont; i++){

		printf("%d ", vet_aux[i]);
	}*/
	//printf("\n----------\n");
}

void main(void){
	int opcao, tam, proc, contador;

printf("-------------------------------\n");
printf("Informe o tamanho da memoria :\n");
scanf("%d",&tam);
int vet[tam], vet_aux[tam], pid=1;
inicializa_tab(vet,tam,vet_aux);
do{
printf("-------------------------------\n");
printf("O que voce deseja fazer?\n");
printf("-------------------------------\n");
printf("1- Criar processo \n");
printf("-------------------------------\n");
printf("2- Matar um processo \n");
printf("-------------------------------\n");
printf("3- Imprimir o mapa de bits memoria \n");
printf("-------------------------------\n");
printf("4- Sair \n");

scanf("%d",&opcao);

switch (opcao)
{
   case 1:
   		
       criar_proc(vet,vet_aux, tam,pid);   
       imprime_tab(vet,tam,vet_aux);       
   break;

   case 2:
     matar_proc(vet,tam);
     imprime_tab(vet,tam,vet_aux);
   break;

   case 3:
     imprime_tab(vet,tam , vet_aux);
  
   break;

   case 4:
      
      exit(0);

   break;

   default:

     printf("OPcAO INVALIDA");
}
printf("Voltar ao menu principal?(sim = 1, nao = 0 )\n");

       scanf("%d",&contador);
}while(contador == 1);






}







