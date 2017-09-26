#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

double copiaByte(){
struct timeval tempo1,tempo2;
struct timezone tzp;
double tempo;	

char c;
int in, out;
in = open("file1Byte.in", O_RDONLY);
out = open("file1Byte.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

gettimeofday(&tempo1,&tzp); 
while(read(in,&c,1) == 1)
write(out,&c,1);
gettimeofday(&tempo2,&tzp);
tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);
return tempo;

}

double copiaBloco(){
struct timeval tempo1,tempo2;
struct timezone tzp;
double tempo;	
char block[4096];
int in, out;
int nread;
in = open("file1Byte.in", O_RDONLY);
out = open("file1Byte.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);

gettimeofday(&tempo1,&tzp); 
while((nread = read(in,block,sizeof(block))) > 0)
write(out,block,nread);
gettimeofday(&tempo2,&tzp);
tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);
return tempo;
}

double copiaBiblioteca(){

struct timeval tempo1,tempo2;
struct timezone tzp;
double tempo;
int c;
FILE *in, *out;
in = fopen("file1Byte.in","r");
out = fopen("file1Byte.out","w");
gettimeofday(&tempo1,&tzp);
while((c = fgetc(in)) != EOF)
fputc(c,out);
gettimeofday(&tempo2,&tzp);
tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);
return tempo;



}

int main(void)
{

printf("TEMPO PARA COPIAR ARQUIVO DE 1BYTE BYTE A BYTE = %f\n", copiaByte());
// printf("TEMPO PARA COPIAR ARQUIVO BLOCO DE 1BYTE BLOCO = %f\n", copiaBloco());
// printf("TEMPO PARA COPIAR ARQUIVO BIBLIOTECA DE 1BYTE BYE A BYTE = %f\n", copiaBiblioteca());



return(0);
}