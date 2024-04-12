#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/history.h>
#include <readline/readline.h>

//  // esempio EXECVE
// int main()
// {
// 	char *args[3];
 
// 	args[0] = "ls";
// 	args[1] = "-l";
// 	args[2] = NULL;
// 	execve("/bin/ls", args, NULL);
// 	printf("This line will not be executed.\n");
 
// 	return (0);
// }

// // esempio ACCESS
// int main()
// {
// 	if (access("example.txt", R_OK) != -1) //R_OK W_OK X_OK
// 		printf("I have permission\n");
// 	else
// 		printf("I don't have permission\n");
 
// 	return (0);
// }


// // esempio DUP(2)
// int main()
// {
// 	int fd;
 
// 	fd = open("example.txt", O_WRONLY | O_CREAT, 0644);
// 	dup2(fd, STDOUT_FILENO);
// 	close(fd);
// 	printf("This is printed in example.txt!\n");
 
// 	return (0);
// }

// // esempio FORK
// int main()
// {
// 	pid_t pid;
 
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
 
// 	if (pid == 0)
// 		printf("This is the child process. (pid: %d)\n", getpid());
// 	else
// 		printf("This is the parent process. (pid: %d)\n", getpid());
 
// 	return (0);
// }


// // esempio PIPE
// int main()
// {
// 	int fd[2];
// 	pid_t pid;
// 	char buffer[13];
 
// 	if (pipe(fd) == -1)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
 
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
 
// 	if (pid == 0)
// 	{
// 		close(fd[0]); // close the read end of the pipe
// 		write(fd[1], "Hello parent!", 13);
// 		close(fd[1]); // close the write end of the pipe
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		close(fd[1]); // close the write end of the pipe
// 		read(fd[0], buffer, 13);
// 		close(fd[0]); // close the read end of the pipe
// 		printf("Message from child: '%s'\n", buffer);
// 		exit(EXIT_SUCCESS);
// 	}
// }


// // esempio WAIT
// int main(int argc, char *argv[])
// {
// 	pid_t pid;
 
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	else if (pid == 0)
// 	{
// 		printf("I am the child process.\n");
// 		sleep(2);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		printf("I am the parent process.\n");
// 		wait(NULL);
// 		printf("Child process terminated after a 2s delay.\n");
// 	}
 
// 	return (EXIT_SUCCESS);
// }


// esempio READLINE
int main ()
{
    char *line;
    while (1)
        {
                line = readline("[minishell][:)]~> ");
                if (line)
                {
                    printf("%s", line);
                    exit(1);
                }
                // if (strcmp(*line, "") == EQUAL || ft_strisspace(line))
                //     return (1);
                // if (strlen(line) > 0)
                //     add_history(line);
        }
}