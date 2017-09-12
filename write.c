#include <unistd.h>
#include <stdlib.h>
int main(void)
{
	if ((write(1, "Isto é um teste\n", 16)) != 16)
	write (2, "Erro de escrita no DA 1\n",24);
	return (0);
}