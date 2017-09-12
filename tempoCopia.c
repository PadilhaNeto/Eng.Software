#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>


void copiaSyscall (){

char c;
int in, out;
in = open("fileSyscall.in", O_RDONLY);
out = open("fileSyscall.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);

while(read(in,&c,1) == 1)
write(out,&c,1);


}
void copiaBiblioteca (){

int c;
FILE *in, *out;
in = fopen("fileBiblioteca.in","r");
out = fopen("fileBiblioteca.out","w");
while((c = fgetc(in)) != EOF)
fputc(c,out);


}



int main()
{
struct timeval tempo1,tempo2;
struct timezone tzp;
double tempo;	



gettimeofday(&tempo1,&tzp);   
 
copiaSyscall();
 
gettimeofday(&tempo2,&tzp);
tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

printf(" | TEMPO DE COPIA USANDO SYSCALL = %f |\n", tempo );




gettimeofday(&tempo1,&tzp);   
 
copiaBiblioteca();
 
gettimeofday(&tempo2,&tzp);

tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

printf(" | TEMPO DE COPIA USANDO BIBLIOTECA STDIO = %f |\n", tempo );






 return 0;
}