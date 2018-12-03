#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WIDTH  1000
#define HEIGHT 1000

/* run this program for both the original input and the input in reverse */
/* The answer is output1 ∩ output 2 */

int main(int argc, char *argv[])
{
    int id, x, y, w, h;
    int i, j;
    int count = 0;

    static int grid[WIDTH][HEIGHT];

    memset(grid, 0, sizeof(int) * WIDTH * HEIGHT);

    while(scanf("#%d @ %d,%d: %dx%d\n", &id, &x, &y, &w, &h) != -1) {
        /*printf("ID: %d\t%d, %d; %dx%d\n", id, x, y, w, h);*/
        bool overlap = false;
        for(i = x; i < x + w; i++)
            for(j = y; j < y + h; j++) {
                if(grid[i][j] != 0)
                    overlap = true;
                grid[i][j]++;
            }
        if(!overlap)
            printf("ID %d is non-overlapping!\n", id);
    }

    for(i = 0; i < WIDTH; i++)
        for(j = 0; j < HEIGHT; j++)
            if(grid[i][j] >= 2)
                count++;

    printf("Total number of overlapping sq inches = %d\n", count);

    return 0;
}
