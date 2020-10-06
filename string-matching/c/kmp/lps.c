#include<stdio.h>

#define LEN(arr) ((int) sizeof(arr) / sizeof(arr[0]) - 1) 

int main() {
	
	char pattern[] = {"97121299"};
	int patternLength = LEN(pattern);
	char patternLast[patternLength][2];
	
	int j,i, toggle;
	
	for(i = 0; i < patternLength; i++) { // create LPS function
		toggle = 0;
		for(j = 0; j < i; j++) {
			if(pattern[i] == pattern[j]) {
				patternLast[i][1] = j + 1;
				toggle = 1;
			} 	
		}
		
		if(toggle) continue;
		patternLast[i][1] = 0;
	}

	for(i = 0; i < patternLength; i++) {
		printf("%c", pattern[i]);
	}
	
	printf("\n");
	
	for(i = 0; i < patternLength; i++) {
		printf("%d ", patternLast[i][1]);
	}
	
	return 0;
}
