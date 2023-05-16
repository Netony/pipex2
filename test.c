#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
 
int main(int argc, char **argv, char **envp)
{
	int	pid;

	dup2(open("./infile", O_RDONLY), 0);
	pid = fork();
	if (pid == 0)
	{
		
	}
	else
}

