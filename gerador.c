#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(void)
{
	//declaramos a variável c do tipo char, delimitando que ela contém 256 locais e cada lugar é preenchido com a letra a
char c[256] = "batatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabatatabata";
// definimos a variável out, onde chamamos a syscal e definimos o nome e o tipo do arquivo
int out = open("file1GB.in", O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
// no for, definimos a quantidade de vezes que o laço irá ser executado
	for(int i = 0; i< 4194304; i++){
		//mandamos o for escrever a variavel c 256 vezes
		write(out, &c, 256);
	} 
}
 