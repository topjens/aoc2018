#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	int change, final = 0;
	
	if(argc > 2) {
		fprintf(stderr, "Please profide input file as argument");
		exit(EXIT_FAILURE);
	}
	
	if(!(fp = fopen(argv[1], "r"))) {
		fprintf(stderr, "Could not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while(!feof(fp)) {
		if(fscanf(fp, "%d", &change) == 1)
			final += change;
	}

	printf("%d\n", final);

	fclose(fp);

	return 0;
}
