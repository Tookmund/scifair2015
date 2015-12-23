#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

#define MAXBUF 1000

void lsdir(char* path) {
	char pf[MAXBUF];
	DIR* dir = opendir(path);
	if (dir == NULL) {
		snprintf(pf,MAXBUF,"Open %s",path);
		perror(pf);
		return;
	}
	struct dirent* ent = readdir(dir);
	while (ent != NULL) {
		printf("%s\n",ent->d_name);
		ent = readdir(dir);
	}
}

int main (int argc, char *argv[]) {
	if (argc == 1) {
		lsdir(".");
	}
	else {
		int i;
		for (i = 0; i < argc; i++) {
			lsdir(argv[i]);
		}
	}
}

