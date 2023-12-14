#include "shell.h"

/**
 * initShellInfo - initializes info_t struct
 * @shellInfo: struct address
 */
void initShellInfo(info_t *shellInfo)
{
	shellInfo->arg = NULL;
	shellInfo->argv = NULL;
	shellInfo->path = NULL;
	shellInfo->argc = 0;
}

/**
 * configureShellInfo - initializes info_t struct
 * @shellInfo: struct address
 * @cmdArguments: argument vector
 */
void configureShellInfo(info_t *shellInfo, char **cmdArguments)
{
	int i = 0;

	shellInfo->fname = cmdArguments[0];
	if (shellInfo->arg)
	{
		shellInfo->argv = strtow(shellInfo->arg, " \t");
		if (!shellInfo->argv)
		{

			shellInfo->argv = malloc(sizeof(char *) * 2);
			if (shellInfo->argv)
			{
				shellInfo->argv[0] = _strdup(shellInfo->arg);
				shellInfo->argv[1] = NULL;
			}
		}
		for (i = 0; shellInfo->argv && shellInfo->argv[i]; i++)
			;
		shellInfo->argc = i;

		replace_alias(shellInfo);
		replace_vars(shellInfo);
	}
}

/**
 * free_info - frees info_t struct fields
 * @shellInfo: struct address
 * @all: true if freeing all fields
 */
void free_info(info_t *shellInfo, int all)
{
	ffree(shellInfo->argv);
	shellInfo->argv = NULL;
	shellInfo->path = NULL;
	if (all)
	{
		if (!shellInfo->cmd_buf)
			free(shellInfo->arg);
		if (shellInfo->env)
			free_list(&(shellInfo->env));
		if (shellInfo->history)
			free_list(&(shellInfo->history));
		if (shellInfo->alias)
			free_list(&(shellInfo->alias));
		ffree(shellInfo->environ);
			shellInfo->environ = NULL;
		bfree((void **)shellInfo->cmd_buf);
		if (shellInfo->readfd > 2)
			close(shellInfo->readfd);
		_putchar(BUF_FLUSH);
	}
}
