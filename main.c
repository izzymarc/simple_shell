#include "shell.h"

/**
 * main - entry point
 * @ac: arg count
 * @argumentVector: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int ac, char **argumentVector)
{
	info_t infoStruct[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(argumentVector[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argumentVector[0]);
				_eputs(": 0: Can't open ");
				_eputs(argumentVector[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		infoStruct->readfd = fd;
	}
	populate_env_list(infoStruct);
	read_history(infoStruct);
	hsh(infoStruct, argumentVector);
	return (EXIT_SUCCESS);
}
