#include <stdbool.h>
#include <stdlib.h>

#define TABLE_SIZE 1000

typedef struct Node{
	int data; struct Node* next; int index;
} Node;

int hash(int value){
	int h = value % TABLE_SIZE;
	if(h < 0) h += TABLE_SIZE;
	return h;
}

void insertFront(Node** head, int data, int index){
	Node* newNode = (Node*)malloc(sizeof(Node));

	if(!newNode) return;

	newNode -> data = data;
	newNode -> index = index;
	newNode -> next = *head;

	*head = newNode;
}

bool searchList(Node* head, int target, int* result_index){
	Node* curr = head;
	while(curr) { if(curr -> data == target) {*result_index = curr -> index; return 1;} curr = curr -> next;}
	return 0;
}

void tableInsert(Node* table[], int value, int index){
	int h = hash(value);

	insertFront(&table[h], value, index);
}
bool tableSearch(Node* table[], int value, int* result_index){
	int h = hash(value);

	Node* head = table[h];
	return searchList(head, value, result_index);
}

void freeList(Node** head){
	Node* curr = *head;

	while (curr) {
		Node* next = curr -> next;
		free(curr);
		curr = next;
	}
	*head = NULL;
}

void freeTable(Node* table[]){
	for(int i = 0; i < TABLE_SIZE; i ++){
		freeList(&table[i]);
	}
}

bool twoSum(int arr[], int n, int k, int* idx1, int* idx2){
	Node* table[TABLE_SIZE] = {NULL};
	int x;
	for(int i = 0; i < n; i ++){
		int complement = k - arr[i];
		if(tableSearch(table, complement, &x) == 1){
			*idx1 = i;
			*idx2 = x;
			freeTable(table);
			return 1;
		}
		tableInsert(table, arr[i], i);
	}
	freeTable(table);
	return 0;
}

int main(void){
	return 0;
}
