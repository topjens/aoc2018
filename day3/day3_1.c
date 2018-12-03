#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH  1000
#define HEIGHT 1000

/*void die(char *s)
{
    fprintf(stderr, "%s", s);
    exit(EXIT_FAILURE);
    }*/

int main(int argc, char *argv[])
{
    int id, x, y, w, h;
    int i, j;
    int count = 0;

    static int grid[WIDTH][HEIGHT];

    memset(grid, 0, sizeof(int) * WIDTH * HEIGHT);

    while(scanf("#%d @ %d,%d: %dx%d\n", &id, &x, &y, &w, &h) != -1) {
        /*printf("ID: %d\t%d, %d; %dx%d\n", id, x, y, w, h);*/
        for(i = x; i < x + w; i++)
            for(j = y; j < y + h; j++)
                grid[i][j]++;
    }

    for(i = 0; i < WIDTH; i++)
        for(j = 0; j < HEIGHT; j++)
            if(grid[i][j] >= 2)
                count++;

    printf("Total number of overlapping sq inches = %d\n", count);

    return 0;
}
