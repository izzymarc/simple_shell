#include "shell.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *input;

    while (1)
    {
        /* Get input from user */
        input = stark_prompt();

        /* Handle end-of-file (EOF) or read error */
        if (input == NULL)
        {
            if (feof(stdin))
            {
                /* Handle EOF gracefully */
                putchar('\n');
                break;
            }
            else
            {
                /* Handle read error */
                perror("stark_prompt");
                continue;
            }
        }

        /* Process input here */

        free(input);
    }

    return (0);
}
