#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	size_t changes_size = 10;
	int *changes = malloc(changes_size * sizeof *changes);
	int num_changes = 0;
	
	int last_freq = 0;
	char *l = NULL;
	size_t n = 0;
	while (getline(&l, &n, stdin) != -1) {
		int change = atoi(l);
		free(l);
		l = NULL;
		n = 0;
		if (num_changes == changes_size) {
			changes_size *= 10;
			changes = realloc(changes, changes_size * sizeof *changes);
		}
		changes[num_changes++] = change;
		last_freq += change;
	}
	printf("Problem 1: %d\n", last_freq);

	size_t freqs_size = 1000;
	char *freqs = malloc(freqs_size);
	memset(freqs, 0, freqs_size);
	int freq = 0;
	for (int i = 0;; i = i + 1 < num_changes ? i + 1 : 0) {
		freq += changes[i];
		size_t idx = freq > 0 ? 2 * freq - 1 : freq < 0 ? freq * -2 : 0;
		if (idx / 8 >= freqs_size) {
			size_t old_size = freqs_size;
			freqs_size = (idx / 8) * 2;
			realloc(freqs, freqs_size);
			memset(freqs + old_size, 0, freqs_size - old_size);
		}
		if (freqs[idx / 8] & (1 << (idx % 8))) {
			printf("Problem 2: %d\n", freq);
			return 0;
		}
		freqs[idx / 8] |= 1 << (idx % 8);
	}
}
