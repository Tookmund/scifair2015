#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main (int argc, char* argv[]) {
	int fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0) return 0;
	int tot = atoi(argv[1]);
	char buf[tot];
	int rd = read(fd,buf,tot);
	write(STDOUT_FILENO,buf,rd);
	return 0;
}
