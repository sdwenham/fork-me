// C program that uses RAM in smallish chunks
// For testing OOM killer tweaks
// Use with caution as it will make a
// system un-responsive. 
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main() 
{
    int i;
    long page_size = sysconf(_SC_PAGESIZE);
    long ram_size = page_size * 1000;
    for (i=0;i<10;i++) {
        long j;
        //printf("Round %d Using %ld bytes of memory\n", i, ram_size);
        char* tmp = (char*) malloc(ram_size);
          if (tmp)
            // Fill the meory to force the kernel to map it into RAM.
            memset(tmp, 0xa5, ram_size);

        //sleep(5);
        fork();
    }
    return 0;
}
