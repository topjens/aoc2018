#include <stdlib.h>
#include <stdio.h>

int *list;
int total = 0, capacity = 4000;
FILE *fp;
int change = 0;
int done = 0;
int final = 0;

int *init_list(void)
{
	int *list = malloc(sizeof(int)*capacity);
	if(!list)
		exit(EXIT_FAILURE);

	return list;
}

void add_item(int *list, int item)
{
	if(total == capacity) {
		capacity *= 2;
		int *l = realloc(list, sizeof(int)*capacity);
		if(l) {
			list = l;
		}
		else {
			free(list);
			exit(EXIT_FAILURE);
		}
	}

	list[total] = item;
	total++;
}

void free_list(int *list)
{
	free(list);
}

int check_and_append(int *list, int num)
{
	int i;

	for(i = 0; i < total; i++) {
		if(list[i] == num) {
			printf("Answer is %d\n", num);
			return 1;
		}
	}

	add_item(list, num);

	return 0;
}

int main(int argc, char *argv[])
{
	if(argc > 2) {
		fprintf(stderr, "Please provide input file as argument");
		exit(EXIT_FAILURE);
	}
	
	fp = fopen(argv[1], "r");
	
	if(!fp) {
		fprintf(stderr, "Could not open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	list = init_list();

	int final = 0;

	while(!done)
	{
		if(fscanf(fp, "%d", &change) == 1) {
			final += change;
			if(check_and_append(list, final))
			    done = 1;
		}
		if(feof(fp))
			rewind(fp);
	}

	printf("Total size = %d, capacity = %d\n", total, capacity);

	free_list(list);

	fclose(fp);
	
	return 0;
}
