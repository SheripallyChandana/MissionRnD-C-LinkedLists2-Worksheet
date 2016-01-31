/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int round(int nodeCount){
	if (nodeCount % 2 == 0)
		return nodeCount / 2;
	else
		return (nodeCount / 2) + 1;
}

int linkedListMedian(struct node *head) {

	struct node* median = head;
	int currentCount = 0;
	int nodeCount = 0;

	if(head == NULL)
		return -1;
	
	if (head){
		++nodeCount;
		++currentCount;
	}
	head = head->next;
	while (head){
		++nodeCount;
		int r = round(nodeCount);
		while (currentCount != r){
			median = median->next;
			++currentCount;
		}
		head = head->next;
	}	
	if (nodeCount % 2 == 0)
		return (median->num + median->next->num) / 2;
	else
		return median->num;

}
