#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int j = 0;

void inicializa_tab(int vet[], int tam){

	for (int i = 0; i < tam; i++){

		vet[i] = 0;
	}

}


void best_fit(int vet[], int tam , int pid, int aux){


   int flag =0, proc, inicio ,fim =0,tamanho_buraco = 0;
   printf("Informe o tamanho do processo :\n");
   scanf("%d",&proc);

   system("clear");
   //verifica se ta cheia

    for(int i = 0; i< tam; i++){
   
           	if( vet[i]== 0){
           		flag =0;
           	}
           	else{
           		flag = 1;
           	}
           }   
           if(flag == 1 || ((proc+inicio) > tam)){
           	printf("MEMORIA CHEIA\n");
           	return;
           }


   //verifica o começo do buraco
   for (int i= 0 ; i< tam; i++){
   	    if(vet[i] == 0){
   	 	inicio = i;
   	 	printf("valor de inicio %d\n",inicio);
   	 	break;
   	    }

    }
       //verifica o tamanho do buraco
    for (int i= inicio ; i< tam; i++){
   	   if(vet[i] == 0){
   	 	
   	   tamanho_buraco++;
   	   }else{
   	 	
   	 	break;
   	   }

    }


  
//printf("buraco de tamanho = %d\n",tamanho_buraco);


    int j = inicio+proc;     
    for(int i = inicio; i < j ; i++){

    //se o tamanho do  buraco for menor que o tamanho do processo
        if(tamanho_buraco >= proc){  
 
    	 

    		vet[i] = pid;
    		
   
        }else{
          
            while(vet[inicio]==0){
                inicio++;
            }
            while(vet[inicio]!=0){
                inicio++;
            }
            return;

        }
   

    }  
	printf("NOVO VALOR INICIO %d\n",inicio);
fim= inicio + tamanho_buraco;
//printf("buraco de fim = %d\n",fim);
printf("\nPROCESSO INSERIDO NO MAPA DE BITS \n");

}


void matar_proc( int vet[], int tam){
int id, flag = 0, inicio, tamanho_buraco =0;
printf("Qual o id do processo que voce deseja matar?\n");
scanf("%d",&id);
system("clear");
do{
	for (int i = 0; i< tam; i++){
		
		if(vet[i] == id){
			
			tamanho_buraco++;
		}		
	}
	for (int i = 0; i< tam; i++){
	 if(vet[i] == id){
	
			inicio = i;	
			break;		
		}
	}


int j= inicio + tamanho_buraco;
    for(int i= inicio; i< j;i++){

	vet[i]=0;
    }

printf("PROCESSO ELIMINADO!!!\n");
printf("deseja matar outro ?(sim = 1, nao = 0 )\n");
scanf("%d",&flag);

  }while(flag == 1);
}

void imprime_tab(int vet[], int tam){
	
	printf("-----------------------\n");
	printf("MAPA DE BITS DA MEMORIA\n");
	printf("-----------------------\n");
	for (int i = 0; i < tam; i++){

		printf("%d", vet[i]);
	}
	printf("\n-----------------------\n");

	
}

void main(void){
	int opcao, tam, proc, aux = 0;

printf("-------------------------------\n");
printf("Informe o tamanho da memoria :\n");
scanf("%d",&tam);
system("clear");
int vet[tam], pid=1;
inicializa_tab(vet,tam);
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

system("clear");

switch (opcao)
{
   case 1:
   		
       best_fit(vet, tam,pid,aux);   
       imprime_tab(vet,tam);       
       pid++;  
      // system("clear");     
   break;

   case 2:
     matar_proc(vet,tam);
     imprime_tab(vet,tam);
   break;

   case 3:
     imprime_tab(vet,tam);
  
   break;

   case 4:
      
      exit(0);

   break;

   default:

     printf("OPcAO INVALIDA");
}
}while(1 == 1);

}







