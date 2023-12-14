#include "shell.h"
char *_getenv(char *variable)
{
	char *tmp, *key,  *value;
	int i;

	fpr (i = 0; environ[i]; itt)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if c(_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
/*int main()
{
	char *env = _getenv("path");
	printf(%s\n, env);
	free(env);
	return (0);
}*/
