#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1000

typedef struct Node{
	int data; struct Node* next;
}Node;

void displayList(Node* head){
	Node* curr = head;
	while(curr) { printf("%d-> ", curr -> data); curr = curr -> next; }
	printf("NULL\n");
}

void insertFront(Node** head, int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	if(!newNode) return;
	newNode -> data = data;
	newNode -> next = *head;
	*head = newNode;
}

bool searchList(Node* head, int target){
	Node* curr = head;
	while(curr){ if(curr -> data == target) return 1; curr = curr -> next; }

	return 0;
}

void deletefromList(Node** head, int target){
	if(!(*head)) return;

	if((*head) -> data == target) { Node* temp = *head; *head = (*head) -> next; free(temp); return; }
	
	Node* curr = *head;
	while(curr -> next) {
		if(curr -> next -> data == target){
			Node* temp = curr -> next; curr -> next = temp -> next; free(temp);
			return;
		}
	curr = curr -> next;}
}

int hash(int value){
	int h = value % TABLE_SIZE;
	if( h < 0 ) h += TABLE_SIZE;
	return h;
}

void table_insert(Node* table[], int value){
	int h = hash(value);

	insertFront(&table[h], value);
}

bool table_search(Node* table[], int value){
	int h = hash(value);

	Node* head = table[h];
	return searchList(head, value);
}

int main(void){

	Node* table[TABLE_SIZE] = {NULL};

	table_insert(table, 1);
	table_insert(table, 1001);
	displayList(table[1]);
	table_insert(table, 500);
	displayList(table[500]);
	table_insert(table, -47);
	displayList(table[953]);

	bool val = table_search(table, 1001);
	bool val2 = table_search(table, 100);
	bool val3 = table_search(table, 500);

	printf("does 1001 exist: %d\ndoes 100 exist: %d\ndoes 500 exist: %d\n", val, val2, val3);

	return 0;
}
