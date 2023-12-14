#include "shell.h"

/**
 * getShellEnvironment - returns the string array copy of our environ
 * @shellEnvInfo: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **getShellEnvironment(info_t *shellEnvInfo)
{
	if (!shellEnvInfo->environ || shellEnvInfo->env_changed)
	{
		shellEnvInfo->environ = list_to_strings(shellEnvInfo->env);
		shellEnvInfo->env_changed = 0;
	}

	return (shellEnvInfo->environ);
}

/**
 * removeEnvironmentVar - Remove an environment variable
 * @shellEnvInfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int removeEnvironmentVar(info_t *shellEnvInfo, char *var)
{
	list_t *node = shellEnvInfo->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			shellEnvInfo->env_changed = delete_node_at_index(&(shellEnvInfo->env), i);
			i = 0;
			node = shellEnvInfo->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (shellEnvInfo->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @shellEnvInfo: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *shellEnvInfo, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = shellEnvInfo->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			shellEnvInfo->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(shellEnvInfo->env), buf, 0);
	free(buf);
	shellEnvInfo->env_changed = 1;
	return (0);
}
