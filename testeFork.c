#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
	void main(void)
	{
	int fPid;
		printf("Ainda existe apenas um processo (%i)\n",getpid());
		fPid = fork();
		printf("Agora somos dois (%i)\n",getpid());
	if(fPid)
	{
	printf("eu sou o pai(%i), o meu filho :%i\n",getpid(),fPid);
	sleep(1);
	}
	else{
	printf(" eu sou o filho(%i), o meu pai: %i\n", getpid(),getppid());
	}
}
