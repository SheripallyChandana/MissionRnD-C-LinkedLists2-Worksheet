/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node *next;
};


struct node * reverseLinkedList(struct node *head) {

	struct node* newHead = NULL;
	struct node* newNode;

	if (head == NULL)
		return NULL;
	
	if(head->next == NULL)
		return head;
	
	while (head){

		newNode = (struct node*)malloc(sizeof(struct node));
		if (newHead == NULL){
			newNode->num = head->num;
			newNode->next = NULL;
			newHead = newNode;
		}
		else{
			newNode->num = head->num;
			newNode->next = newHead;
			newHead = newNode;
		}
		head = head->next;
	}
	return newHead;	
}
