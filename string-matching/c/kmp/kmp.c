#include<stdio.h>
#include<stdlib.h>

#define LEN(arr) ((int) sizeof(arr) / sizeof(arr[0]) - 1)

int main() {

    puts("Enter your birthday separated by spaces (eg: 1997 07 20)");
    int y, m, d;
    char pattern[7];
    scanf("%d %d %d", &y, &m, &d);
    y = y % 100;
    if (m < 10) y *= 10;
    if (d < 10) m *= 10;
    sprintf(pattern, "%d%d%d", y, m, d);

    int patternLength = LEN(pattern);
    char patternLast[patternLength][2];

    int i, j, toggle;
    for (i = 0; i < patternLength; i++) {
        patternLast[i][0] = pattern[i];
    }

    for (i = 0; i < patternLength; i++) { // create LPS function
        toggle = 0;
        for (j = 0; j < i; j++) {
            if (pattern[i] == pattern[j]) {
                patternLast[i][1] = j + 1;
                toggle = 1;
            }
        }

        if (toggle) continue;
        patternLast[i][1] = 0;
    }

    printf("Your birthday string is : %s\n", pattern);
    printf("The pattern length is %d\n", patternLength);
    printf("Searching for a matching string..\r");

    FILE *fptr;
    char *input;
    input = (char *) malloc(100000001);
    int c, state = 0, sequence = 0;
    i = -1;

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

    i = 0, j = -1;
    int index = -1, characterCount = 0, matchingCount = 0;

    while (input[i]) {

        if (matchingCount == patternLength) {
            printf("Matching string found at index : %d\n", index);
            matchingCount = 0;
        }

        if (input[i] == patternLast[j + 1][0]) { // checks for string's character is equal with pattern's character
            ++matchingCount; // if there is a match,  matching count increases
            if (j == -1) {
                index = i;
            } else if (characterCount > 0) {
                index = i - characterCount;
            }
            characterCount = 0;
            i++;
            j++;
            continue;
        }

        if (j > -1) {
            int temp = j;
            j = patternLast[j][1] - 1;
            if (j > -1) {
                characterCount = temp - j;
                matchingCount -= characterCount;
            } else {
                matchingCount = 0;
            }
            continue;
        }

        i++;
        index = -1;
        matchingCount = 0;
    }

    if (matchingCount == patternLength) {
        printf("Matching string found at index : %d\n", index);
    }

//    for (i = 0; i < patternLength; i++) {
//        printf("%d ", patternLast[i][1]);
//    }

    return 0;
}
