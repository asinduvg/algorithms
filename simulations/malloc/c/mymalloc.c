#include "mymalloc.h"

static char mem[25000] = {'\0'};
static void* global = mem; //points to newly created meta blocks
struct meta* base = (struct meta*)mem;
static int isCreatable = 1;
static struct meta* previous = (struct meta*)mem; //points to previous meta block

struct meta {
	int freeSpace;
	char flag;
	struct meta* next;
	int size;
};


//static struct meta* base; //points to first meta block 

//void* myMalloc(size_t size);
//int createMetaBlock();
//void* myFree();


//void init() {
////	base = (struct meta*)global;
//	previous = base;
//}

//int main() {

//	global = mem;
	
//	base = (struct meta*)global;
//	previous = base;
	
	/*if(*(int*)global == NULL) { //checks whether the array is empty and 
		base->flag = 'f';       //initializing first meata block
		base->freeSpace = 120 - sizeof(struct meta);
		base->next = NULL;
		base->size = 0;
	}*/

//	char* p = (char*)myMalloc(sizeof(char));
//	*p = 'd';
//	
//	int* ptrr = (int*)myMalloc(sizeof(int));
//	*ptrr = 99;
//	
//	myFree((void*)ptrr);
//
//	char* pls = (char*)myMalloc(sizeof(char));
//	*pls = 'e';
	
//	myFree((void*)ptr2);

//	int i;
//	for(i = 0; i < 120; i++) {
//		printf("%d ", mem[i]);
//	}

//	printf("\n%c\n", *p);
//	printf("%d\n", *ptrr);
//	printf("%c\n", *pls);

//	return 0;
//}

void* myMalloc(size_t size) {
	
	if(size <= 0) {
		return NULL;
	}
	
//	if(!isCreatable) {
//		printf("Memory Full!!\n");
//		return;
//	}
	
	if(*(int*)global == '\0') { //checks whether the array is empty and 
		base->flag = 'f';       //initializing first meata block
		base->freeSpace = 25000 - sizeof(struct meta);
		base->next = NULL;
		base->size = 0;
	}
	
	struct meta* trav = base;
//	int isNotEnd = 1;
	
	while(1) {
		if(trav->flag == 'f' && trav->freeSpace == size) {
			trav->flag = 'a';
			trav->freeSpace = trav->freeSpace - size;
			trav->size = size;
			
			return (void*)trav + sizeof(struct meta);
		} else {
			if(trav->flag == 'f' && trav->freeSpace > size) {
				trav->flag = 'a';
				trav->freeSpace = trav->freeSpace - size;
				trav->size = size;
				
				if(trav == global) {
					global = global + sizeof(struct meta) + size;
//					isNotEnd = 0;
					isCreatable = createMetaBlock();
					trav->freeSpace = 0;
				}
				return (void*)trav + sizeof(struct meta);
			}	
		}
		trav = trav->next;
	}
}

int createMetaBlock() {
	int spaceAvail = previous->freeSpace - sizeof(struct meta); //checks whether it has enough space to assign metablock
	if(spaceAvail < sizeof(struct meta)) {
		printf("Meta block could not be initialized\n");
		return 0;
	} else {
		struct meta* block = (struct meta*)global;
		block->flag = 'f';
		block->freeSpace = spaceAvail;
		block->next = NULL;
		previous->next = block;
		previous = block;	
		return 1;
	}
}

void* myFree(void* point) {
	struct meta* startBlock = (struct meta*)(point - sizeof(struct meta));
	startBlock->flag = 'f';
	startBlock->freeSpace = startBlock->size;
	startBlock->size = 0;
}















