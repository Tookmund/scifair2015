#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main (int argc, char** argv) {
	int i;
	struct stat statbuf;
	struct stat *st = &statbuf;
	char* buf;
	int ret;
	int fd;
	int rd;
	int wr;
	for (i = 1; i < argc; i++) {
		ret = stat(argv[i],st);
		if (ret < 0) {
			printf("Stat ");
			perror(argv[i]);
			printf("\n");
			return 1;
		}
		buf = (char*)malloc(st->st_size);
		if (buf == NULL) {
			printf("Malloc %ld",st->st_size);
			perror(argv[i]);
			return 1;
		}
		fd = open(argv[i],O_RDONLY);
		if (fd < 0) {
			printf("Open ");
			perror(argv[i]);
		}
		rd = read(fd,buf,st->st_size);
		if (rd < 0) {
			printf("Read ");
			perror(argv[i]);
			return 1;
		}
		wr = write(STDOUT_FILENO,buf,st->st_size);
		if (wr < 0) {
			printf("Write ");
			perror(argv[i]);
			return 1;
		}
	}
	return 0;
}
