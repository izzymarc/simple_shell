#include "shell.h"

/**
 * stark_prompt - Displays the shell prompt and reads input from the user
 * Return: Pointer to the input string
 */
char *stark_prompt(void)
{
    char *input = NULL;
    ssize_t read;
    size_t len = 0;

    /* Display prompt */
    write(STDOUT_FILENO, "$ ", 2);

    /* Read input from user */
    read = getline(&input, &len, stdin);

    /* Check for EOF or read error */
    if (read == -1)
    {
        free(input);
        return (NULL);
    }

    return (input);
}
