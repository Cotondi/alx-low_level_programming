#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
* error_exit - Handles errors and terminates program with specified exit code.
* @code: Error code.
* @msg: Prints the error message.
* @arg: Specifies the argument for the error message.
*/
void error_exit(int code, char *msg, char *arg)
{
dprintf(STDERR_FILENO, msg, arg);
exit(code);
}

/**
* copy_file - Duplicates the contents of a file to another file.
* @file_from: The source file.
* @file_to: The destination file.
*/
void copy_file(char *file_from, char *file_to)
{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

fd_from = open(file_from, O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file %s\n", file_from);

fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (fd_to == -1)
error_exit(99, "Error: Can't write to %s\n", file_to);

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written != bytes_read)
error_exit(99, "Error: Can't write to %s\n", file_to);
}

if (bytes_read == -1)
error_exit(98, "Error: Can't read from file %s\n", file_from);

if (close(fd_from) == -1)
error_exit(100, "Error: Can't close fd %d\n", (char *)(intptr_t)fd_from);

if (close(fd_to) == -1)
error_exit(100, "Error: Can't close fd %d\n", (char *)(intptr_t)fd_to);
}

/**
* main - Entry point, copies the content of one file to another.
* @ac: Number of arguments.
* @av: Array of arguments.
*
* Return: Always 0.
*/
int main(int ac, char **av)
{
if (ac != 3)
error_exit(97, "Usage: cp file_from file_to\n", "");

copy_file(av[1], av[2]);

return (0);
}
