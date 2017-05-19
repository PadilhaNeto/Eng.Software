#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


//Função para fazer as iterações 
double calculaPi(int itera){

	double pi = 2.0;
	double numerador = 2;
	double denominador = 1;


	for (int i = 1; i <= itera ;i++){
    	//printf ("entrou no for\n ");
    
    		if( i % 2==0){
    		//printf ("entrou no if par \n");    
    		numerador = numerador + 2;
       		pi = pi * (numerador/denominador);    
        	//printf(" pi do par %f\n",pi);
    		}else{
        	//printf ("entrou no else \n");
        	denominador = denominador + 2;
        	pi = pi * (numerador/denominador);
           // printf(" pi do IMpar %f\n",pi);
    		}
      for (int k = 0; k < 600 ; k++){
  //printf(" oi ");
  } 
	}

//printf("-----------------------------------------\n");
//printf("| VALOR DE PI | = %f \n",pi*2);

return (pi*2);   

}
//Fim da função

void main(void){

	struct timeval tempo1,tempo2;
	struct timezone tzp;
	double tempo, tempoMedio, soma =0;
	int cont = 1; 
  int i, itera = 300000;    
 
 
  gettimeofday(&tempo1,&tzp);   
 
  //for( i = 1; i <=10 ; i++){
    
    calculaPi(itera);   
   // printf("\n| %d EXECUÇÃO PARA APROXIMAÇÃO DO PI | \n",cont);
    //cont++;
   // }
 
  gettimeofday(&tempo2,&tzp);
  tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);
  //soma=soma+tempo;
  //tempoMedio = soma / 5;
  
  printf("\n\n----------------------------------------------------\n");
  printf("| TEMPO MÉDIO DECORRIDO PARA APROXIMAÇÃO DO PI EXECUTADO 10 VEZES| = %f\n",tempo);
  printf("----------------------------------------------------\n");
  printf("| NUMERO DE ITERAÇÕES NECESSARIAS | = %d\n",itera);
}





