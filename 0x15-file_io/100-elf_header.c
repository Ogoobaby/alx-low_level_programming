#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - prints address
 * @ptr: magic.
 * Return: no return.
 */
void print_addr(char *p)
{
int s;
int begin;
char syp;

printf("  Entry point address:               0x");

syp = p[4] + '0';
if (syp == '1')
{
begin = 26;
printf("80");
for (s = begin; s >= 22; s--)
{
if (p[s] > 0)
printf("%x", p[s]);
else if (p[s] < 0)
printf("%x", 256 + p[s]);
}
if (p[7] == 6)
printf("00");
}

if (syp == '2')
{
begin = 26;
for (s = begin; s > 23; s--)
{
if (p[s] >= 0)
printf("%02x", p[s]);

else if (p[s] < 0)
printf("%02x", 256 + p[s]);
}
}
printf("\n");
}

/**
 * print_type - prints type
 * @p: magic.
 * Return: no return.
 */
void print_type(char *p)
{
char type = p[16];

if (p[5] == 1)
type = p[16];
else
type = p[17];

printf("  Type:                              ");
if (type == 0)
printf("NONE (No file type)\n");
else if (type == 1)
printf("REL (Relocatable file)\n");
else if (type == 2)
printf("EXEC (Executable file)\n");
else if (type == 3)
printf("DYN (Shared object file)\n");
else if (type == 4)
printf("CORE (Core file)\n");
else
printf("<unknown: %x>\n", type);
}

/**
 * print_osabi - prints osabi
 * @p: magic.
 * Return: no return.
 */
void print_osabi(char *p)
{
char osabi = p[7];

printf("  OS/ABI:                            ");
if (osabi == 0)
printf("UNIX - System V\n");
else if (osabi == 2)
printf("UNIX - NetBSD\n");
else if (osabi == 6)
printf("UNIX - Solaris\n");
else
printf("<unknown: %x>\n", osabi);

printf("  ABI Version:                       %d\n", p[8]);
}

/**
 * print_version - prints version
 * @p: magic.
 * Return: no return.
 */
void print_version(char *p)
{
int version = p[6];

printf("  Version:                           %d", version);

if (version == EV_CURRENT)
printf(" (current)");

printf("\n");
}
/**
 * print_data - prints data
 * @p: magic.
 * Return: no return.
 */
void print_data(char *p)
{
char data = p[5];

printf("  Data:                              2's complement");
if (data == 1)
printf(", little endian\n");

if (data == 2)
printf(", big endian\n");
}
/**
 * print_magic - prints magic info.
 * @p: magic.
 * Return: no return.
 */
void print_magic(char *p)
{
int bytes;

printf("  Magic:  ");

for (bytes = 0; bytes < 16; bytes++)
printf(" %02x", p[bytes]);

printf("\n");
}

/**
 * check_sys - check the version system.
 * @p: magic.
 * Return: no return.
 */
void check_sys(char *p)
{
char syp = p[4] + '0';

if (syp == '0')
exit(98);

printf("ELF Header:\n");
print_magic(p);

if (syp == '1')
printf("  Class:                             ELF32\n");

if (syp == '2')
printf("  Class:                             ELF64\n");

print_data(p);
print_version(p);
print_osabi(p);
print_type(p);
print_addr(p);
}

/**
 * check_elf - check if it is an elf file.
 * @p: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
int check_elf(char *p)
{
int addr = (int)p[0];
char E = p[1];
char L = p[2];
char F = p[3];

if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
return (1);

return (0);
}

/**
 * main - check the code for Holberton School students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
int fd, ret_read;
char p[27];

if (argc != 2)
{
dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
exit(98);
}

fd = open(argv[1], O_RDONLY);

if (fd < 0)
{
dprintf(STDERR_FILENO, "Err: file can not be open\n");
exit(98);
}

lseek(fd, 0, SEEK_SET);
ret_read = read(fd, p, 27);

if (ret_read == -1)
{
dprintf(STDERR_FILENO, "Err: The file can not be read\n");
exit(98);
}

if (!check_elf(p))
{
dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
exit(98);
}

check_sys(p);
close(fd);

return (0);
}
