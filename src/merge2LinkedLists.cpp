/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {

	struct node* head3 = NULL;
	struct node* tail = NULL;
	struct node* smallest = NULL;

	while (head1 && head2){
		if (head1->num <= head2->num){
			smallest = head1;
			head1 = head1->next;
		}
		else{
			smallest = head2;
			head2 = head2->next;
		}
		if (head3 == NULL){
			head3 = smallest;
			tail = smallest;
		}
		else{
			tail->next = smallest;
			tail = smallest;
		}
	}
	while (head1){
		if (head3 == NULL){
			head3 = head1;
			tail = head1;
		}
		else{
			tail->next = head1;
			tail = head1;
		}
		head1 = head1->next;
	}
	while (head2){
		if (head3 == NULL){
			head3 = head2;
			tail = head2;
		}
		else{
			tail->next = head2;
			tail = head2;
		}
		head2 = head2->next;
	}

	return head3;
}	