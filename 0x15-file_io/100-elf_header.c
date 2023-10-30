#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
* print_error - outputs an error message and exits with status 98
* @msg: The error message to output
*/
void print_error(char *msg)
{
while (*msg != '\0')
{
write(STDERR_FILENO, msg, 1);
msg++;
}
exit(98);
}

/**
* read_elf_header - reads the ELF header from a file
* @fd: The file descriptor
* @header: The ELF header structure to read into
*/
void read_elf_header(int fd, Elf64_Ehdr *header)
{
if (read(fd, header, sizeof(*header)) != sizeof(*header))
{
print_error("Error: Unable to read ELF header\n");
}
}

/**
* print_elf_header_info - prints information from the ELF header
* @header: The ELF header structure to extract data from
*/
void print_elf_header_info(Elf64_Ehdr *header)
{
char hex[17] = "0123456789abcdef";
int i;

for (i = 0; i < EI_NIDENT; i++)
{
write(STDOUT_FILENO, &hex[header->e_ident[i] / 16], 1);
write(STDOUT_FILENO, &hex[header->e_ident[i] % 16], 1);
}
}

/**
* main - entry point
* @argc: Count of arguments
* @argv: The argument vector
*
* Return: 0 on success, 98 on failure
*/
int main(int argc, char **argv)
{
int fd;
Elf64_Ehdr header;

if (argc != 2)
{
print_error("Usage: elf_header elf_filename\n");
}

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
print_error("Error: Could not open file\n");
}

read_elf_header(fd, &header);

if (header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
{
print_error("Error: Not an ELF file\n");
}

print_elf_header_info(&header);

close(fd);
return (0);
}
