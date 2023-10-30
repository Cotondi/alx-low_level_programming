#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"
/**
 * read_textfile - Processes text and outputs its content to the POSIX stdout.
 * @filename: Name of the file to read.
 * @letters: Count of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
int fd;
char buffer;
ssize_t bytes_read, bytes_written, total_written;
if (filename == NULL)
return (0);
fd = open(filename, O_RDONLY);
if (fd == -1)
return (0);
total_written = 0;
while ((bytes_read = read(fd, &buffer, 1)) > 0 && letters > 0)
{
bytes_written = write(STDOUT_FILENO, &buffer, 1);
if (bytes_written != 1)
{
close(fd);
return (0);
}
total_written++;
letters--;
}
close(fd);
return (total_written);
}
