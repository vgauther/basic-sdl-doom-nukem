#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void putc(char c)
{
	write(1, &c, 1);
}

void puts(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		putc(s[i]);
		i++;
	}
}

int main(void)
{
	int fd;
	int ok;
	char buff[6000];

	fd = open("draw", O_RDONLY);
	ok = read(fd, buff, 6001);
	buff[ok] = 0;
	puts(buff);
	return (0);
}
