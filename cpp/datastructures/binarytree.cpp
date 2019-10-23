#include "pch.h"
#include <iostream>
using namespace std;


struct Node {
	int data;
	struct Node *a;
	struct Node *b;
};
struct Node* head = NULL;


void insert(int new_data, struct Node **parent) {
	if (*parent == NULL) {
		struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
		new_node->data = new_data;
		new_node->a = NULL;
		new_node->b = NULL;
		*parent = new_node;
	}
	else {

		if ((*parent)->data < new_data) {
			insert(new_data, &((*parent)->a));
		}
		else {
			insert(new_data, &((*parent)->b));
		}
	}
}


void displayRecursive(struct Node *parent) {
	if (parent != NULL) {
		displayRecursive(((parent)->a));

		cout << (parent)->data << '\n';
		displayRecursive(((parent)->b));

	}
}

bool find(int data, struct Node *parent, int *level) {
	if (parent == NULL) {
		return false;
	}
	if (parent->data == data) {
		return true;
	}
	else {
		(*level) = (*level) + 1;
		if (parent->data < data) {
			return find(data, parent->a, level);
		}
		else {
			return find(data, parent->b, level);
		}
	}
	return false;
}

void display() {
	struct Node* ptr;
	ptr = head;
	while (ptr != NULL) {
		cout << ptr->data << " ";
		ptr = ptr->a;
	}
}


int main() {
	insert(3, &head);
	insert(4, &head);
	insert(8, &head);
	insert(7, &head);
	insert(27, &head);
	insert(17, &head);
	insert(2, &head);
	insert(1, &head);
	insert(12, &head);
	insert(16, &head);
	insert(100, &head);
	insert(0, &head);

	/*
................................3..............
..........................2.........4..........
....................1..................8.......
.....................................7...27....
.......................................17.100..
......................................12.......
........................................16.....
	*/

	cout << "The linked list is: \n";
	displayRecursive(head);

	int level = 0;
	cout << "\nfind:" << find(6, head, &level);
	cout << "\nlevel:" << level;


	return 0;
}