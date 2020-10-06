#include<stdio.h>
#include<stdlib.h>

int main() {

    puts("Enter your birthday separated by spaces (eg: 1997 07 20)");
    int y, m, d;
    char pattern[7];
    scanf("%d %d %d", &y, &m, &d);
    y = y % 100;
    if (m < 10) y *= 10;
    if (d < 10) m *= 10;
    sprintf(pattern, "%d%d%d", y, m, d);

    int patternLength = (int) sizeof(pattern) / sizeof(pattern[0]) - 1;
    printf("Your birthday string is : %s\n", pattern);
    printf("The pattern length is %d\n", patternLength);
    printf("Searching for a matching string..\r");

    FILE *fptr;
    char *input;
    input = (char *) malloc(100000001);
    int c, state = 0, sequence = 0, i = -1;

    fptr = fopen("pi.txt", "r");

    if (fptr == NULL) perror("Error opening file");
    else {
        do {
            c = fgetc(fptr);
            if (state) {

                if (c >= 48 && c <= 57) {
                    ++i;
                    *(input + i) = c;
                    sequence = 1;
                } else if (c != 32) {
                    sequence = 0;
                }
            }
            if (c == '\n') {
                state = 1;
                continue;
            }

            if (!sequence) {
                state = 0;
            }

        } while (c != EOF);
        ++i;
        *(input + i) = '\n';
    }
    
    fclose(fptr);

    int stamp = -1, j = 0, index = -1;
    i = -1;
    while (input[++i]) {
        if (input[i] == pattern[j]) {
            if (j == 0) stamp = i;
            if (j == patternLength - 1) {
                index = stamp;
                printf("Pattern found at index : %d       \n", index);
                index = -1;
            }
            j++;
            continue;
        }
        j = 0;
        if (stamp > -1) {
            i = stamp;
            stamp = -1;
        }
    }

    if (index > -1) {
        printf("Pattern found at index : %d       ", index);
    }

    return 0;
}
