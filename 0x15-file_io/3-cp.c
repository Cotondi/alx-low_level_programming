#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"

#define BUFFER_SIZE 1024

/**
* _putchar - Writes a character to stdout.
* @c: The character to write.
*
* Return: On success, the character written.
*         On error, -1 is returned.
*/
int _putchar(char c)
{
return (write(STDOUT_FILENO, &c, 1));
}

/**
* error_exit - Prints an error message and exits with the specified code.
* @code: The exit code.
* @msg: The error message.
* @arg: The additional argument for the error message.
*/
void error_exit(int code, const char *msg, const char *arg)
{
const char *ptr;

ptr = arg;

while (*ptr)
_putchar(*ptr++);

write(STDERR_FILENO, msg, sizeof(msg) - 1);
exit(code);
}

/**
* main - Copies the content of a file to another file.
* @argc: The number of arguments.
* @argv: The arguments.
*
* Return: 0 on success, or the corresponding exit code on failure.
*/
int main(int argc, char **argv)
{
int fd_from, fd_to, bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

if (argc != 3)
error_exit(97, "Usage: cp file_from file_to\n", "");

fd_from = open(argv[1], O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);

fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
error_exit(99, "Error: Can't write to %s\n", argv[2]);

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1)
error_exit(99, "Error: Can't write to %s\n", argv[2]);
}

if (bytes_read == -1)
error_exit(98, "Error: Can't read from file %s\n", argv[1]);

if (close(fd_from) == -1)
error_exit(100, "Error: Can't close fd ", argv[1]);

if (close(fd_to) == -1)
error_exit(100, "Error: Can't close fd ", argv[2]);

return (0);
}
