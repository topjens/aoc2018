#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int find_number_of_differences(char *s1, char *s2)
{
	int count = 0;

	/* this is not save if s1 > s2! */
	for(int i = 0; i < strlen(s1); i++)
		if(s1[i] != s2[i])
			count++;

	return count;
}

int main(int argc, char *argv[])
{
	size_t lines_size = 10;
	int number_of_lines = 0;
	char **lines = malloc(lines_size * sizeof *lines);

	char *l = NULL;
	size_t n = 0;

	int i, j;
	char *p;
	
	while(getline(&l, &n, stdin) != -1) {
		if(number_of_lines > lines_size) {
			lines_size *= 2;
			lines = realloc(lines, lines_size * sizeof *lines);
		}

		lines[number_of_lines++] = strdup(l);
		
		free(l);
		l = NULL;
		n = 0;
	}

	for(i = 0; i < number_of_lines; i++)
		for(j = i + 1; j < number_of_lines; j++)
		    if(find_number_of_differences(lines[i], lines[j]) == 1) {
				printf("%d:%s%d:%s\n", i, lines[i], j, lines[j]);
				goto cleanup;
			}

cleanup:
    for(i = 0; i < number_of_lines; i++)
		free(lines[i]);

	free(lines);
	
	return 0;
}
