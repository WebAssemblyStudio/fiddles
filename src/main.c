#define WASM_EXPORT __attribute__((visibility("default")))
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

#define MAX 200
#define START 1

static char seats[MAX][MAX], copy[MAX][MAX];

char *mygetline(FILE *f)
{
    size_t len = 0;
    int c, i;
    char *res;

    while (c = fgetc(f), c != '\n' && c != EOF) len++;
    if (len == 0 && c == EOF)
        return NULL;
    fseek(f, -len-1, SEEK_CUR);
    res = malloc(sizeof(char)*(len+1));
    for (i = 0; i <= len; i++)
        res[i] = fgetc(f);
    res[i-1] = '\0';
    return res;
}

int same(char seats[MAX][MAX], char seats2[MAX][MAX])
{
    for (size_t i = 0; i < MAX; i++)
        for (size_t j = 0; j < MAX; j++)
            if (seats[i][j] != seats2[i][j])
                return 0;
    return 1;
}

int check(char s[MAX][MAX], size_t y, size_t x)
{
    char a = s[y-1][x-1]; char b = s[y-1][x  ]; char c = s[y-1][x+1];
    char d = s[y  ][x-1]; char f = s[y  ][x+1];
    char g = s[y+1][x-1]; char h = s[y+1][x  ]; char i = s[y+1][x+1];
    return (a == '#') + (b == '#') + (c == '#') + (d == '#') +
           (f == '#') + (g == '#') + (h == '#') + (i == '#');
}

int find_seat(char s[MAX][MAX], size_t y, size_t x, int yinc, int xinc)
{
    int i = 0, j = 0;
    int i_max = (MAX + (MAX * yinc))/2 - y;
    int j_max = (MAX + (MAX * xinc))/2 - x;
    while (i += yinc, j += xinc, i != i_max && j != j_max && s[y+i][x+j] == '.')
        ;
    return s[y+i][x+j] == '#';
}

int check2(char s[MAX][MAX], size_t y, size_t x)
{
    return find_seat(s, y, x,  1,  0) + find_seat(s, y, x, -1,  0) + find_seat(s, y, x,  0,  1) + find_seat(s, y, x,  0, -1) +
           find_seat(s, y, x,  1,  1) + find_seat(s, y, x, -1,  1) + find_seat(s, y, x,  1, -1) + find_seat(s, y, x, -1, -1);
}

void step(char src[MAX][MAX], char next[MAX][MAX], int n_occ_if_occ, int (*check_seats)(char (*)[MAX], size_t, size_t))
{
    for (size_t y = 1; y < MAX-1; y++)
        for (size_t x = 1; x < MAX-1; x++) {
            switch (src[y][x]) {
            case 'L': next[y][x] = (check_seats(src, y, x) == 0            ? '#' : 'L'); break;
            case '#': next[y][x] = (check_seats(src, y, x) >= n_occ_if_occ ? 'L' : '#'); break;
            case '.': case '\0': next[y][x] = '.'; break;
            }
        }
}

void print(char s[MAX][MAX], size_t start, size_t len)
{
    for (size_t x = start; x < len; x++) {
        for (size_t y = start; y < len; y++) {
            char c = s[x][y];
            putchar( c == '\0' ? '.' : c );
        }
        putchar('\n');
    }
}

size_t count(char s[MAX][MAX])
{
    size_t sum = 0;
    for (size_t x = 0; x < MAX; x++)
        for (size_t y = 0; y < MAX; y++)
            sum += (s[x][y] == '#');
    return sum;
}

WASM_EXPORT
int main()
{
    FILE *infile = fopen("input11.txt", "r");
    if (!infile) return 1;
    char *line;
    size_t i = START;
    while (line = mygetline(infile), line != NULL) {
        strcpy(seats[i] + START, line);
        free(line);
        i++;
    }
    char (*s1)[MAX] = seats, (*s2)[MAX] = copy;
    size_t len = START + strlen(seats[START] + START);
    size_t steps = 0;
    do {
        // part 1:
        // step(s1, s2, 4, check);
        // part 2:
        step(s1, s2, 5, check2);
        steps++;
        char (*tmp)[MAX] = s1;
        s1 = s2;
        s2 = tmp;
    } while(!same(s1, s2));
    printf("%lu\n", count(s1));
    return 0;
}
