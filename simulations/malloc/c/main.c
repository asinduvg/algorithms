#include "mymalloc.h"

int main() {
	int *x = (int*)myMalloc(sizeof(int));
	*x = 67;
	printf("%d", *x);
	return 0;
}
