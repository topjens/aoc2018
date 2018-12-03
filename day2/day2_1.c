#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
	char *l = NULL;
	char *p;
	size_t n = 0;
    int count[256];
	int i, num_d = 0, num_t = 0;
	bool have_d = false, have_t = false;
	
	while(getline(&l, &n, stdin) != -1) {
		memset(count, 0, 256*sizeof(int));
		
		for(p = l; *p; p++) {
			count[*p]++;
		}

		for(i = 0; i < 256; i++) {
			if(count[i] == 2)
			    have_d = true;
			else if(count[i] == 3)
				have_t = true;
		}

		if(have_d)
			num_d++;
		if(have_t)
			num_t++;

		have_d = have_t = false;
		
		free(l);
		l = NULL;
		n = 0;
	}

	printf("Double = %d\tTriple = %d\n", num_d, num_t);
	printf("Checksum = %d\n", num_d * num_t);

	return 0;
}
