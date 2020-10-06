#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int createHash(const char *arr, int length);

static unsigned int inputHash;

int main() {
	
	puts("Enter your birthday sperated by spaces (eg: 1997 07 20)");
	int y, m, d;
	char pattern[7];
	scanf("%d %d %d", &y, &m, &d);
	y = y % 100;
	if(m < 10) y *= 10;
	if(d < 10) m *= 10;
	sprintf(pattern, "%d%d%d", y, m, d);
    
    int patternLength = (int) sizeof(pattern) / sizeof(pattern[0]) - 1;
    unsigned int patternHash = createHash(pattern, patternLength);
//    printf("The pattern hash is %d\n", patternHash);
    printf("Your birthday string is : %s\n", pattern);
    printf("The pattern length is %d\n", patternLength);
//    puts("\rSearching for a matching string..");
	printf("Searching for a matching string..\r");

    FILE *fptr;
    char *input;
    input = (char *) malloc(100000001);
    int c, state = 0, sequence = 0, i = -1;

    fptr = fopen("pi.txt file/pi.txt", "r");
    
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
	
    int inputLength = -1, index = -1;

    inputHash = createHash(input, patternLength);

    while (input[++inputLength] && input[inputLength + patternLength - 1]) {
        if (inputLength > 0) {
            inputHash = (int) (inputHash - (input[inputLength - 1] * pow(10, patternLength))) * 10;
            inputHash += input[inputLength + patternLength - 1] * 10;
        }

        if (patternHash == inputHash) {
            for (i = 0; i < patternLength; i++) {
                if (pattern[i] != input[inputLength + i]) {
                    break;
                }
            }
            index = inputLength;
       		printf("Matching string found at index : %d\n", index);
        }
    }
    
    if(index == -1) {
    	printf("No matching found!!");
	}

    free(input);

    return 0;
}

unsigned int createHash(const char *arr, int length) { // hash initiating function
    int i, total = 0;
    for (i = 0; i < length; i++) {
        int result = (int) (arr[length - 1 - i] * pow(10, i + 1));
        total += result;
    }
    return total;
}

/*
 *  // DOCUMENTATION //
 *
 *  -- LOGIC --
 *
 *  when there is a newline, state turns up to 1
 *  every (newline) iteration, compiler checks whether it starts from a number or not
 *  if it starts from a number, sequence turns up to 1 and state still on 1
 *  sequence still remains 1 if the characters are numbers or character is a space
 *  if a character is a number we store it in an array
 *  if a character is not a number and also not a space sequence turns down to 0
 *  if sequence is 0, state turns down to 0
 *
 *  -- TERMINOLOGY --
 *
 *  createHash() :
 *      createHash function is to create a hash number
 *      it executes only twice
 *          i.  when we first enter a pattern
 *          ii. when compiler reads the array for the first time
 *
 */


