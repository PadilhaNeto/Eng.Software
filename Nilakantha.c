//série de TNilakantha
// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

double calculaPi(int itera){

float pi;
int numerador = 4;
int denominador1 = 2;
int denominador2 = 3;
int denominador3 = 4;

for (int i =0; i < itera ;i++){
    printf ("entrou no for\n ");
    if( i % 2==0){
    printf ("entrou no if par \n");    

    //    pi+=(numerador/(denominador1*denominador2*denominador3));
    double aux = 4*24;
        pi = (float) aux;
        printf(" pi do par %f\n",pi);
    }
    else{
        printf ("entrou no else \n");
        pi = pi - (numerador/(denominador1*denominador2*denominador3));
            printf(" pi do IMpar %f\n",pi);
    }
    denominador1 = denominador1 + 2;
    denominador2 = denominador2 + 2;
    denominador3 = denominador3 + 2;
}
printf("pi = %f \n",pi+3);
return pi + 3;    
}

int main(){
struct timeval tempo1,tempo2;
struct timezone tzp;
double tempo, tempoMedio, soma =0;
char mensagem;
int cont = 1;

int itera;


printf(" Insira o numero de iteracoes \n");
scanf("%d",&itera);   

for ( int j =0; j<itera ; j++){
    gettimeofday(&tempo1,&tzp);     
    calculaPi(itera);
    gettimeofday(&tempo2,&tzp);
    tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);
    soma=soma+tempo;
    mensagem = printf("------------------------------------------\n| TEMPO DECORRIDO DE %d EXECUÇÃO PARA APROXIMAÇÃO DO PI | = %f\n------------------------------------------\n",cont,tempo);
    cont++;
}
printf(" valor de PI = %f \n", calculaPi(itera)); 
mensagem;

return 0;
}