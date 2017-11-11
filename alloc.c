#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char **argv) {
  int max = atoi(argv[1]);

  for(int i = 0; i < max; i++) {
    int *ptr = mmap(NULL, 1048576, PROT_READ | PROT_WRITE,
		    MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    for(int j = 0; j < 1048576 / sizeof(int); j++)
      ptr[j] = 0;

    write(1, ".", 1);
  }

  pause();
}
