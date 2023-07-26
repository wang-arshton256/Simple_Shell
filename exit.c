#include "main.h"

/**
 * exit_shell - Exits the current process through sending a (SIGTERM) signal.
 *
 * Return: Nothing.
 */
void exit_shell(void)
{
	signal(SIGTERM, &exit_handler);
	kill(getpid(), SIGTERM);
}

/**
 * exit_handler - Handles the signal sent by the exit_shell function (SIGTERM)
 * signal by printing a newline character.
 *
 * @sig_num: Integer value, represents the signal given to the function.
 *
 * Return: Nothing.
 */
void exit_handler(int sig_num)
{
	if (sig_num == SIGTERM)
	{
		exit(0);
	}
}
