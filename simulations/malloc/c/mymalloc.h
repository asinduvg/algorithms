#include<stdio.h>

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

void* myMalloc(size_t size);
void* myFree(void* point);
int createMetaBlock();

void* myMalloc(size_t size) {
	
	if(size <= 0) {
		return NULL;
	}
	
//	if(!isCreatable) {
//		printf("Memory Full!!\n");
//		return NULL;
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
//		global = global + spaceAvail;
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

