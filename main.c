#include "shell.h"

/**
 * main - shell function
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success,while 1 on error
 */
int main(int ac, char **argv)
{
	char *line =NULL;
	char **command=NULL;
	int status  = 0, idx =0;
	(void) ac;
	/*(void) argv;*/


	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDOUT_FILENO))
			   write(STDOUT_FILENO, "\n", 1);
		        return (status);
		}
		/*printf("%s\n", line);
		free(line)*/
		idx++;
		command = tokenizer(line);
		if (!command)
			continue;
		/*for (i = 0; command[i]; i++)
		{
			printf("%s\n", command[i]);
			free(command[i]), command[i] = NULL;*/
			if (is_builtin(command[0]))
				handle_builtin(command, argv, &status, idx);

		}
		else
		    status = _execute(command, argv, idx);
		
	}
}

