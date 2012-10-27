
#include <stdio.h>
#include <stdlib.h>
#include "test.h"
int main(){
	struct list* newList=malloc(sizeof(struct list));
	newList->head=NULL;
	struct node* tmp;
	int a[]={1,2,3,4,5,6};
	int i=0;
	for (;i<6;i++){
		printf("%d\n", a[i]);
		// addData(&tmp,a[i]);
		// addFirst(&newList,tmp);
	}
	convertArraytoList(&newList,a,6);
	printList(newList);
	freeList(&newList);
	return 0;
}
