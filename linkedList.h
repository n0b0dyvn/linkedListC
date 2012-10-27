#ifndef _LINKEDLIST_
#define _LINKEDLIST_

struct node
{
	/* data */
	int data;
	struct node *next;
};
struct list{
	int count;
	struct node* head;
};
void addFirst(struct list** newList,struct node* newNode){
	printf("addFirst Running\n");
	if ((*newList)->head==NULL){
		printf("Head is NULL, add %d to Head\n",newNode->data );
		(*newList)->head=newNode;
		newNode->next=NULL;
		printf("Head is NULL, add %d to Head\n",newNode->data );
	}
	else{
		struct node* tmp=newNode;
		tmp->next=(*newList)->head;
		(*newList)->head=tmp;
		printf("add %d to first\n",newNode->data );
	}
	(*newList)->count++;
}

void addData(struct node** newNode,int data){
	printf("addData Running\n");
	struct node* tmp = malloc(sizeof(struct node));
	tmp->data=data;
	tmp->next=NULL;
	*newNode=tmp;
	printf("%d add to node success\n",data);
}

void convertArraytoList(struct list** newList,int* a,int size){
	printf("convertArraytoList Running\n");
	//struct list *tmpList;//=malloc(sizeof(struct list));
	int i;
	for (i=0;i<size;i++){
		struct node *newNode;
		printf("add %d to List\n",a[i]);
		addData(&newNode,a[i]);
		addFirst(newList,newNode);
	}
}

void freeList(struct list** newList){
	printf("freeList Running\n");
	while((*newList)->head!=NULL){

		struct node *tmp=(*newList)->head;
		printf("free %d\n", tmp->data);
		(*newList)->head=(*newList)->head->next;
		free(tmp);
		(*newList)->count--;
	}
	free(*newList);
}

void printList(struct list* newList){
	printf("printList Running\n");
	struct node* tmp=newList->head;
	while (tmp!=NULL && tmp->next!=NULL){
		printf("Data=%d\n",tmp->data );
		tmp=tmp->next;
	}
}

// int addFirst(struct DList*,struct List*);
// extern int addLast(struct DList*,struct List*);
// extern int freeAll(struct Dlist*);
#endif