#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#define iteracoes 10
void main(void){
int fPid,i,j;
fPid = fork();
if(fPid){
for (i=0; i<iteracoes;i++){
printf("PAI\n");
for(j=0;j<500000;j++);
}}else{
for (i=0; i<iteracoes;i++){
printf("FILHO\n");
for(j=0;j<500000;j++);
}
}
}
