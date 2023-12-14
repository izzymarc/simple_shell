#include "shell.h"

/**
 * fetchCommandHistory - gets the history file
 * @info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *fetchCommandHistory(info_t *info)
{
	char *historyPathBuffer, *homeDirectory;

	homeDirectory = _getenv(info, "HOME=");
	if (!homeDirectory)
		return (NULL);
	historyPathBuffer = malloc(sizeof(char) * (_strlen(homeDirectory) + _strlen(SHELL_HISTORY_FILE) + 2));
	if (!historyPathBuffer)
		return (NULL);
	historyPathBuffer[0] = 0;
	_strcpy(historyPathBuffer, homeDirectory);
	_strcat(historyPathBuffer, "/");
	_strcat(historyPathBuffer, SHELL_HISTORY_FILE);
	return (historyPathBuffer);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = fetchCommandHistory(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *historyPathBuffer = NULL, *filename = fetchCommandHistory(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	historyPathBuffer = malloc(sizeof(char) * (fsize + 1));
	if (!historyPathBuffer)
		return (0);
	rdlen = read(fd, historyPathBuffer, fsize);
	historyPathBuffer[fsize] = 0;
	if (rdlen <= 0)
		return (free(historyPathBuffer), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (historyPathBuffer[i] == '\n')
		{
			historyPathBuffer[i] = 0;
			build_history_list(info, historyPathBuffer + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, historyPathBuffer + last, linecount++);
	free(historyPathBuffer);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @historyPathBuffer: historyPathBufferfer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *historyPathBuffer, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, historyPathBuffer, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}
