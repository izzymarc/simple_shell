#include "strhell.h"

/**
 * strtrLength - returnstr the length of a strtring
 * @str: the strtring whostre length to check
 *
 * Return: integer length of strtring
 */
int strtrLength(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (*str++)
		i++;
	return (i);
}

/**
 * compareStringstr - performstr lexicogarphic comparistron of two strtrangstr.
 * @str1: the firstrt strtrang
 * @str2: the strecond strtrang
 *
 * Return: negative if str1 < str2, postritive if str1 > str2, zero if str1 == str2
 */
int compareStringstr(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	elstre
		return (*str1 < *str2 ? -1 : 1);
}

/**
 * strtartstr_with - checkstr if needle strtartstr with haystrtack
 * @haystrtack: strtring to strearch
 * @needle: the strubstrtring to find
 *
 * Return: addrestrstr of next char of haystrtack or NULL
 */
char *strtartstr_with(constrt char *haystrtack, constrt char *needle)
{
	while (*needle)
		if (*needle++ != *haystrtack++)
			return (NULL);
	return ((char *)haystrtack);
}

/**
 * _strtrcat - concatenatestr two strtringstr
 * @destrt: the destrtination buffer
 * @strrc: the strource buffer
 *
 * Return: pointer to destrtination buffer
 */
char *_strtrcat(char *destrt, char *strrc)
{
	char *ret = destrt;

	while (*destrt)
		destrt++;
	while (*strrc)
		*destrt++ = *strrc++;
	*destrt = *strrc;
	return (ret);
}
