#include "pch.h"
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void insert(int new_data, struct Node **head) {

	while (*head != NULL) {
		head = &((*head)->next);
	}
	if (*head == NULL) {
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		new_node->data = new_data;
		new_node->next = NULL;
		*head = new_node;
	}
}


void insert_maintain_order(int new_data, struct Node **head) {
	struct Node * rest_of_linked_list = *head;
	bool loop = true;
	while (*head != NULL && loop) {
		if ((*head)->data > new_data) {
			loop = false;
			*head = NULL;
		}
		else {
			head = &((*head)->next);
			rest_of_linked_list = *head;
		}

	}
	if (*head == NULL) {
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		new_node->data = new_data;
		new_node->next = rest_of_linked_list;
		*head = new_node;
	}
}


void print(struct Node * head) {
	cout << "\n";
	while (head != NULL) {
		cout << head->data << "  ";
		head = (head->next);
	}
	cout << "\n\n";
}


int main() {

	struct Node* head = NULL;

	insert_maintain_order(31, &head);
	insert_maintain_order(4, &head);
	insert_maintain_order(7, &head);
	insert_maintain_order(3, &head);
	insert_maintain_order(34, &head);
	insert_maintain_order(2, &head);
	insert_maintain_order(44, &head);
	insert_maintain_order(1, &head);
	insert_maintain_order(27, &head);
	insert_maintain_order(14, &head);
	insert_maintain_order(0, &head);

	cout << "Print ordered list\n";
	print(head);



	cout << "\n\n";

	struct Node* head2 = NULL;

	insert(31, &head2);
	insert(4, &head2);
	insert(7, &head2);
	insert(3, &head2);
	insert(34, &head2);
	insert(2, &head2);
	insert(44, &head2);
	insert(1, &head2);
	insert(27, &head2);
	insert(14, &head2);
	insert(0, &head2);

	cout << "Print list\n";


	print(head2);

	return 0;
}