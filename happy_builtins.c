#include "shell.h"

/**
 * exitShell - exits the shell
 * @cmdDetails: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if cmdDetails.argv[0] != "exit"
 */
int exitShell(info_t *cmdDetails)
{
	int exitCode;

	if (cmdDetails->argv[1])  /* If there is an exit arguement */
	{
		exitCode = _erratoi(cmdDetails->argv[1]);
		if (exitCode == -1)
		{
			cmdDetails->status = 2;
			print_error(cmdDetails, "Illegal number: ");
			_eputs(cmdDetails->argv[1]);
			_eputchar('\n');
			return (1);
		}
		cmdDetails->err_num = _erratoi(cmdDetails->argv[1]);
		return (-2);
	}
	cmdDetails->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @cmdDetails: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(info_t *cmdDetails)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!cmdDetails->argv[1])
	{
		dir = _getenv(cmdDetails, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(cmdDetails, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(cmdDetails->argv[1], "-") == 0)
	{
		if (!_getenv(cmdDetails, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(cmdDetails, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(cmdDetails, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(cmdDetails->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(cmdDetails, "can't cd to ");
		_eputs(cmdDetails->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(cmdDetails, "OLDPWD", _getenv(cmdDetails, "PWD="));
		_setenv(cmdDetails, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @cmdDetails: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(info_t *cmdDetails)
{
	char **arg_array;

	arg_array = cmdDetails->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
