#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


//Função para fazer as iterações 
  double calculaPi(int itera){
	double pi = 2.0;
	double numerador = 2;
	double denominador = 1;


	for (int i = 1; i <= itera ;i++){   
    
    		if( i % 2==0){
    		    
    		  numerador = numerador + 2;
       		pi = pi * (numerador/denominador);    
     
    		}else{
        	
        	denominador = denominador + 2;
        	pi = pi * (numerador/denominador);
           
    		}
        for (int k = 0; k < 1000 ; k++){
  
  } 
	}
printf("| VALOR DE PI | = %f \n",pi*2);
return (pi*2); 
}
//Fim da função

double calculaTempo(){

  struct timeval tempo1,tempo2;
  struct timezone tzp;
  double tempo, tempoMedio, soma =0;
  int cont = 1;
 
  int i, status, itera = 300000;    
  pid_t fPid;
 
gettimeofday(&tempo1,&tzp); //começa a contagem do tempo  

fPid = fork(); // cria o processo filho
 
if(fPid == 0){ //verifica se é o filho

  calculaPi(itera); //chama a função iterativa  
  _exit(0); //libera para o pai executar

}else{

  wait(&status); //espera o filho executar para poder executar seu código 
  calculaPi(itera);

}

 
 
gettimeofday(&tempo2,&tzp);
tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);
return tempo;
}


void main(void){
  printf("\n ----------------------------------------------------------------------------\n");  
  printf("| TRABALHO APLICANDO CONCEITOS DA SYSCALL FORK() UTILIZANDO SÉRIE ITERATIVA |\n");
  printf("| -------------------DISCIPLINA SISTEMAS OPERACIONAIS ----------------------|\n\n");
  printf("| ______Alunos______|\n\n");
  printf("| José Padilha Neto |\n");
  printf("| Breno Teodoro     |");
  printf("\n\n----------------------------------------------------\n");
  printf("| TEMPO MÉDIO DECORRIDO PARA APROXIMAÇÃO DO PI EXECUTADO 1 VEZ| = %f\n",calculaTempo());
  printf("----------------------------------------------------\n"); 
}





