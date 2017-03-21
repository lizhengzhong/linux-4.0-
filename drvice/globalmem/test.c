#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, const char *argv[])
{

	int fd;
	char buf[128] = "This is rw test.";
	char buff[128] = {0};
	int ret;

	if ((fd = open("/dev/globalmem", O_RDWR)) < 0) {
		perror("fail to open\n");
		return -1;
	}

	printf("fd = %d\n", fd);

	ret = write(fd, buf, strlen(buf)+1);
	printf("ret = %d\n", ret);
	close(fd);

	getchar();

	if ((fd = open("/dev/globalmem", O_RDWR)) < 0) {
		perror("fail to open\n");
		return -1;
	}

	printf("fd = %d\n", fd);
	ret = read(fd, buff, 128);
	printf("%s, ret = %d\n", buff, ret);


	close(fd);

	return 0;
}
