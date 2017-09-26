#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int j = 0, inicio_next = 0;

void inicializa_tab(int vet_first[],int vet_next[], int vet_best[], int vet_fim_best[], int vet_ini_best[], int vet_tam_best[],
					int vet_worst[], int vet_fim_worst[], int vet_ini_worst[], int vet_tam_worst[], int tam){
	//#1
	for (int i = 0; i < tam; i++){

		vet_first[i] = 0;
	}//#2
	for (int i = 0; i < tam; i++){

		vet_next[i] = 0;
	}//#3
	for (int i = 0; i < tam; i++){

		vet_best[i] = 0;
	}//#4
	for (int i = 0; i < tam; i++){

		vet_ini_best[i] = 0;
	}//#5
	for (int i = 0; i < tam; i++){

		vet_fim_best[i] = 0;
	}//#6
	for (int i = 0; i < tam; i++){

		vet_tam_best[i] = 0;
	}//#7

	for (int i = 0; i < tam; i++){

		vet_worst[i] = 0;
	}//#8
	for (int i = 0; i < tam; i++){

		vet_ini_worst[i] = 0;
	}//#9
	for (int i = 0; i < tam; i++){

		vet_fim_worst[i] = 0;
	}//#10
	for (int i = 0; i < tam; i++){

		vet_tam_worst[i] = 0;
	}

}

void first_fit(int vet_first[], int tam , int PID, int proc){

int inicio =0 , tam_b =0, espaco=0;
//verifica quantidade de espaço livre na memoria
for ( int i =0; i < tam ; i++){
	if(vet_first[i]==0){
		espaco++;
	}

}
//verifica se o tamanho do processo eh maior que o espaço livre
if(espaco < proc){
	printf("MEMORIA CHEIA, PROCESSO NAO ALOCADO\n");
	return;
}
//verifica se a posiçao de inicio eh buraco ou processo
while(vet_first[inicio] != 0){
	inicio++;
}
int k =inicio;
//conta o tamanho do buraco
while(vet_first[k] == 0){
	tam_b++;
	k++;	
}

//atualiza o inicio
if(tam_b < proc ){
	inicio = inicio+tam_b;
}

while(vet_first[inicio] != 0){
	inicio++;
}
if (inicio+proc > tam)
{
	inicio = -1;
}

if (inicio == -1)
{
	printf("FF - PROCESSO NAO ALOCADO - SEM ESPAÇO\n");
	return;
}


int final;
final = inicio+proc;

		//aloca o processo
	   	for (int i = inicio; i < final ; i++)
		{
			vet_first[i] = PID;
			inicio++;
		
		}
		printf("PROCESSO ALOCADO - FF !!!\n");
		PID++;



}
void next_fit(int vet_next[], int tam , int PID, int proc){

int tam_b =0, volta = 0, espaco =0;

for ( int i =0; i < tam ; i++){
	if(vet_next[i]==0){
		espaco++;
	}

}

if(espaco < proc){
	printf("FF - MEMORIA CHEIA, PROCESSO NAO ALOCADO\n");
	return;
}

int maior =0;
for (int i = 0; i < tam; i++)
{
	if (vet_next[i]<vet_next[i+1])
	{
		maior= vet_next[i+1];
	}
}
for (int i = 0; i < tam; i++)
{
	if (vet_next[i]==maior)
	{
		inicio_next = i;
		break;
	}
}
while(vet_next[inicio_next]!=0)
{
	inicio_next++;
}


int k =inicio_next;
while(vet_next[k] == 0 && k < tam){
	tam_b++;
	k++;	
}


if((tam_b) < proc){
	inicio_next = inicio_next+(tam_b);
}
if (tam_b < proc)
{
	inicio_next = 0;
}

while(vet_next[inicio_next] != 0){
	inicio_next++;
}

int final;
final = inicio_next+proc;


	   	for (int i = inicio_next; i < final ; i++)
		{
			vet_next[i] = PID;
			inicio_next++;
		
		}
		PID++;
		printf("PROCESSO ALOCADO - NF !!!\n");

}

void best_fit(int vet_best[], int tam , int PID, int proc, int vet_fim_best[], int vet_ini_best[], int vet_tam_best[]){
int i=0, k =0 ,cont=0, espaco =0; 

for ( int m =0; m < tam ; m++){
	if(vet_best[m]==0){
		espaco++;
	}

}


if(espaco < proc){
	printf("NF - MEMORIA CHEIA, PROCESSO NAO ALOCADO\n");
	return;
}

do{
if(vet_best[i] == 0){
	
	vet_ini_best[k] = i; //armazena valor do inicio do buraco no vetor de inicio
	
	while(vet_best[i]== 0 && i< tam){		
		i++;		
	}
	
	vet_fim_best[k] = i; //armazena valor do final do buraco no vetor de final	
	vet_tam_best[k] = (vet_fim_best[k] - vet_ini_best[k]  ); //armazena no vetor de tamanho do buraco a diferença entre o fim e o começo do buraco
	k++;

}else{

	while(vet_best[i] != 0){
		i++;
	}
}

}while(i < tam);


//----------------------------------------------------	
int  diferenca, diferencaAux = 0, menor_d =0;

while(vet_tam_best[cont]!= 0){

	cont++;
}
int  vet_dif[tam], h=0;

for(int l = 0; l < cont+1; l++){	


	vet_dif[l] = vet_tam_best[l]-proc;	
	
}
/*printf("vetor de inicio \n");

for (int i = 0; i < cont; i++){

		printf("%d - ", vet_ini_best[i]);
	}
printf("\nvetor de tamanho \n");

for (int i = 0; i < cont; i++){

		printf("%d - ", vet_tam_best[i]);
	}
printf("\nvetor de diferenca \n");

for (int i = 0; i < cont; i++){

		printf("%d - ", vet_dif[i]);
	}
	*/
int q =0;

if (vet_dif[q] >= 0){
	menor_d = vet_dif [q];
		
}else{
	menor_d = vet_dif [q+1];
		
}


int menor_indice=0, p=0;

while( p <= cont){
	if (vet_dif[p] <= menor_d  && vet_dif[p] >= 0 )
	{
		menor_d = vet_dif[p];
		menor_indice = p;
	}
	p++;
}

if (vet_tam_best[menor_indice] < proc )
{
	printf("BF - SEM ESPAÇO, PROCESSO NAO ALOCADO\n");
	return;
}
for (int k = vet_ini_best[menor_indice]; k < (vet_ini_best[menor_indice] + proc) ; k++)
{	
	
	if (vet_best[k] == 0)
	{
		vet_best[k] = PID;
	}
	
}
printf("PROCESSO ALOCADO - BF !!!\n");
}
void worst_fit(int vet_worst[], int tam , int PID, int proc, int vet_fim_worst[], int vet_ini_worst[], int vet_tam_worst[]){

int i=0, k =0 ,cont=0, espaco =0; 

for ( int m =0; m < tam ; m++){
	if(vet_worst[m]==0){
		espaco++;
	}

}


if(espaco < proc){
	printf("WF - MEMORIA CHEIA, PROCESSO NAO ALOCADO\n");
	return;
}

do{
if(vet_worst[i] == 0){
	
	vet_ini_worst[k] = i; //armazena valor do inicio do buraco no vetor de inicio
	
	while(vet_worst[i]== 0 && i< tam){
		
		i++;
		//printf("valor de i : %d\n", i );
	}
	
	vet_fim_worst[k] = i; //armazena valor do final do buraco no vetor de final


	
	vet_tam_worst[k] = (vet_fim_worst[k] - vet_ini_worst[k]  ); //armazena no vetor de tamanho do buraco a diferença entre o fim e o começo do buraco
	k++;	

}else{

	while(vet_worst[i] != 0){
		i++;
	}
}

}while(i < tam);

int  diferenca, diferencaAux = 0, maior_d =0;

while(vet_tam_worst[cont]!= 0){

	cont++;
}
int  vet_dif[tam], h=0;


for(int l = 0; l < cont+1; l++){	


	vet_dif[l] = vet_tam_worst[l]-proc;	
	
}

maior_d = vet_dif [0];
int maior_indice=0, p=1;
while( p < cont){

	if (vet_dif[p] >= maior_d && vet_dif[p] >= 0 )
	{
		maior_d = vet_dif[p];
		maior_indice = p;
	}
	p++;
}


if (vet_tam_worst[maior_indice] < proc )
{
	printf("WF - SEM ESPAÇO, PROCESSO NAO ALOCADO\n");
	return;
}
for (int k = vet_ini_worst[maior_indice]; k < (vet_ini_worst[maior_indice] + proc) ; k++)
{	
	
	if (vet_worst[k] == 0)
	{
		vet_worst[k] = PID;

	}
	
}
printf("PROCESSO ALOCADO - WF !!!\n");


}

void matar_proc( int vet_first[],int vet_next[],int vet_best[],int vet_worst[], int tam, int id){
int flag = 0, inicio, tamanho_buraco = 0, status =0;
int flag_next =0, inicio_next, tamanho_buraco_next = 0, status_next =0;
int flag_best =0, inicio_best, tamanho_buraco_best = 0, status_best =0;
int flag_worst =0, inicio_worst, tamanho_buraco_worst = 0, status_worst =0;
system("clear");
//elimina do first fit
	for (int i = 0; i< tam; i++){
		
		if(vet_first[i] == id){
			
			tamanho_buraco++;
			status = 1;
		}		
	}
	for (int i = 0; i< tam; i++){
		if(vet_first[i] == id){
			status = 1;
			inicio = i;	
			break;		
		}
	}
	if (status == 0)
	{
		printf("FF - Processo de PID %d nao existe\n", id);
	}else{

		printf("FF - PROCESSO ELIMINADO!!!\n");	
	}

int j= inicio + tamanho_buraco;

for(int i= inicio; i< j;i++){

	vet_first[i]=0;

}
// elimina next
for (int i = 0; i< tam; i++){
		
		if(vet_next[i] == id){
			
			tamanho_buraco_next++;
			status_next = 1;
		}		
	}
	for (int i = 0; i< tam; i++){
		if(vet_next[i] == id){
			status_next = 1;
			inicio_next = i;	
			break;		
		}
	}
	if (status_next == 0)
	{
		printf("NF - Processo de PID %d nao existe\n", id);
	}else{

		printf("NF - PROCESSO ELIMINADO!!!\n");	
	}

int j_next = inicio_next + tamanho_buraco_next;

for(int i= inicio_next; i< j_next;i++){

	vet_next[i]=0;

}
//elimina best
for (int i = 0; i< tam; i++){
		
		if(vet_best[i] == id){
			
			tamanho_buraco_best++;
			status_best = 1;
		}		
	}
	for (int i = 0; i< tam; i++){
		if(vet_best[i] == id){
			status_best = 1;
			inicio_best = i;	
			break;		
		}
	}
	if (status_best == 0)
	{
		printf("BF - Processo de PID %d nao existe\n", id);
	}else{

		printf("BF - PROCESSO ELIMINADO!!!\n");	
	}

int j_best = inicio_best + tamanho_buraco_best;

for(int i= inicio_best; i< j_best;i++){

	vet_best[i]=0;

}
//elimina wf
  for (int i = 0; i< tam; i++){
		
		if(vet_worst[i] == id){
			
			tamanho_buraco_worst++;
			status_worst = 1;
		}		
	}
	for (int i = 0; i< tam; i++){
		if(vet_worst[i] == id){
			status_worst = 1;
			inicio_worst = i;	
			break;		
		}
	}
	if (status_worst == 0)
	{
		printf("WF - Processo de PID %d nao existe\n", id);
	}else{

		printf("WF - PROCESSO ELIMINADO!!!\n");	
	}

int j_worst = inicio_worst + tamanho_buraco_worst;

for(int i= inicio_worst; i< j_worst;i++){

	vet_worst[i]=0;

}

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
int opcao, tam, proc, id;
printf("|----------------------------------------------------------------------------------------|\n");
printf("|                           Jose Padilha Neto -  Breno Teodoro                           |\n");                 
printf("|----------------------------------------------------------------------------------------|\n");
printf("|                        Gerência com Listas Ligadas - Mapa de bits                      |\n");
printf("|----------------------------------------------------------------------------------------|\n");
printf("| Descriçao: O usuario devera informar o tamanho da memoria em MB, ele podera inserir    |\n");
printf("| processos, eliminar processos, e mostrar o mapa de bits da memoria, cada bloco tera    |\n");
printf("| tamanho de 1KB.                                                                        |\n");
printf("| Objetivo: Aprendizado na pratica dos metodos de alocaçao e suas vantagens/desvantagens.|\n");
printf("|----------------------------------------------------------------------------------------|\n\n");
printf("Informe o tamanho da memoria em MB :\n");
scanf("%d",&tam);

if(tam > 1023 || tam < 1){
	printf("Por favor, Informe um valor em MB entre 1 e 1024\n");
	printf("Informe o tamanho da memoria em MB :\n");
	scanf("%d",&tam);
	
}
tam = tam * 1024;
system("clear");
int vet_first[tam], vet_next[tam], vet_best[tam], vet_worst[tam], pid=1;
int vet_fim_best[tam], vet_ini_best[tam], vet_tam_best[tam];
int vet_fim_worst[tam], vet_ini_worst[tam], vet_tam_worst[tam];

inicializa_tab(vet_first, vet_next, vet_best, vet_ini_best, vet_fim_best, vet_tam_best,vet_worst, vet_ini_worst, vet_fim_worst, vet_tam_worst ,tam);

do{
printf("\n\n|----------------------------------|\n");
printf("|     O que voce deseja fazer?     |\n");
printf("|----------------------------------|\n");
printf("|1- Criar processo                 |\n");
printf("|----------------------------------|\n");
printf("|2- Eliminar um processo           | \n");
printf("|----------------------------------|\n");
printf("|3- Mostrar o mapa de bits memoria | \n");
printf("|----------------------------------|\n");
printf("|4- Sair                           |\n");
printf("|----------------------------------|\n");

scanf("%d",&opcao);

system("clear");

switch (opcao)
{
   case 1:
   		printf("informe o tamanho do processo em KB\n");
		scanf("%d",&proc);
		//printf("\n\n|      First fit      |\n");
       	first_fit(vet_first, tam,pid, proc); 
      	//imprime_tab(vet_first,tam); 
       	//printf("\n\n|      Next fit       |\n");  
        next_fit(vet_next,tam,pid,proc);
       	//imprime_tab(vet_next,tam);    
       	//printf("\n\n|      Best fit       |\n");   
       	best_fit(vet_best,tam,pid,proc, vet_ini_best, vet_fim_best, vet_tam_best);
       	//imprime_tab(vet_best,tam); 
       	//printf("\n\n|      Worst fit      |\n");   
       	worst_fit(vet_worst,tam,pid,proc, vet_ini_worst, vet_fim_worst, vet_tam_worst);
       	//imprime_tab(vet_worst,tam); 
       	pid++;  
      // system("clear");     
   break;

   case 2:
     printf("Qual o PID do processo que voce deseja matar?\n");
	 scanf("%d",&id);
     matar_proc(vet_first,vet_next, vet_best,vet_worst, tam, id);     
     
   break;

   case 3:
   printf("\n\n|      First fit      |\n");
   imprime_tab(vet_first,tam);
   printf("\n\n|      Next fit       |\n");  
   imprime_tab(vet_next,tam);
   printf("\n\n|      Best fit       |\n");  
   imprime_tab(vet_best,tam);
   printf("\n\n|      Worst fit      |\n"); 
   imprime_tab(vet_worst,tam);
   break;
 
   case 4:
      
      exit(0);

   break;

   default:

     printf("OPcAO INVALIDA");
}
}while(1 == 1);

}







