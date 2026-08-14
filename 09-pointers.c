#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data; struct node* next;
} Node;

int main(void){

	Node *head = (Node*)malloc(sizeof(Node)); 
	Node *second = (Node*)malloc(sizeof(Node));
	Node *third = (Node*)malloc(sizeof(Node));

	head -> data = 5;
	second -> data = 6;
	third -> data = 7;
	
	head -> next = second;
	second -> next = third;
	third-> next = NULL;
	
	Node* curr = head;
	while(curr){
		printf("%d-> ", curr -> data); curr = curr -> next;
	}
	printf("NULL\n");



//	int a = 5;
//	int *ptr = &a;
//
//	printf("\nptr pointing to a: %p\n", ptr);
//	printf("address of a: %p\n", &a);
//	printf("accessing a's value through dereferenced pointer: %d\n", *ptr);	
//	*ptr = 1000;
//	printf("a's value after changing the value at the address of a: %d\n\n", a);

	return 0;
}
