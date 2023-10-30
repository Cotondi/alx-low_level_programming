#include <unistd.h>
#include "main.h"
#include <fcntl.h>
/**
* append_text_to_file - Appends text to the end of a file.
* @filename: Name of the file.
* @text_content: Text to append.
*
* Return: 1 on success, -1 on failure.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, bytes_written, text_size = 0;

if (filename == NULL)
return (-1);
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);
if (text_content != NULL)
{
while (text_content[text_size] != '\0')
text_size++;
bytes_written = write(fd, text_content, text_size);
if (bytes_written == -1)
{
close(fd);
return (-1);
}
}
close(fd);
return (1);
}
