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
  int fPid, fPid2 ,fPid3,fPid4;
 
gettimeofday(&tempo1,&tzp);  

//primeira cópia de processo 
fPid = fork(); 
if(fPid){
             //segunda cópia de processo
             fPid2 = fork();    
             if(fPid2){
                              //terceira cópia de processo
                              fPid3 = fork();                   
                              if(fPid4){
                                               //quarta cópia de processo
                                              fPid4 = fork();                   
                                              if(fPid4){
                                              

                                              calculaPi(itera);
                                              sleep(1);
                                              }else{
                                              calculaPi(itera);                                             
                                              }    

                             calculaPi(itera);
                             sleep(1);
                             }else{
                             calculaPi(itera);
                             }

              calculaPi(itera);
              sleep(1);
              }else{
              calculaPi(itera);
              }
calculaPi(itera);     
sleep(1);

}else{
calculaPi(itera);
} 
 
gettimeofday(&tempo2,&tzp);
tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

  
  printf("\n\n----------------------------------------------------\n");
  printf("| TEMPO MÉDIO DECORRIDO PARA APROXIMAÇÃO DO PI EXECUTADO 1 VEZES| = %f\n",tempo);
  printf("----------------------------------------------------\n");
  printf("| VALOR DE PI = %f",calculaPi(itera));
  
  
}

