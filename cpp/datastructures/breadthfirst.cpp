#include "pch.h"
#include <iostream>
#include <vector> 
#include <list> 

using namespace std;

struct Node {
	int data;
	struct Node *a;
	struct Node *b;
};

void insert(int newData, struct Node **parent) {
	if (*parent == NULL) {
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->data = newData;
		newNode->a = NULL;
		newNode->b = NULL;
		*parent = newNode;
	}
	else {
		if ((*parent)->data < newData) {
			insert(newData, &((*parent)->b));
		}
		else {
			insert(newData, &((*parent)->a));
		}
	}
}

void displayInOrderRecursive(struct Node *parent) {
	if (parent != NULL) {
		displayInOrderRecursive(((parent)->a));

		cout << (parent)->data << ' ';
		displayInOrderRecursive(((parent)->b));

	}
}

void printStructure(struct Node * head, int levels) {
	cout << "\nStructure:\n";
	int count = 0;
	vector<struct Node *> vec;
	vec.push_back(head);
	count++;

	levels--;
	int curr = 0;
	int max_level = (1 << levels) - 1;

	while (curr < count) {
		if (vec[curr] == NULL) {
			if (curr < max_level) {

				vec.push_back(NULL);
				count++;
			}
			if (curr < max_level) {

				vec.push_back(NULL);
				count++;
			}
		}
		else {
			if (vec[curr]->a != NULL) {
				vec.push_back(vec[curr]->a);
				count++;
			}
			else {
				if (curr < max_level) {

					vec.push_back(NULL);
					count++;
				}
			}
			if (vec[curr]->b != NULL) {
				vec.push_back(vec[curr]->b);
				count++;
			}
			else {
				if (curr < max_level) {
					vec.push_back(NULL);
					count++;
				}
			}
		}
		curr++;
	}

	curr = 0;
	int rowsquared = 2;
	int row = 1;
	int space = 8;
	while (curr < count) {

		//spaceing
		int p = (levels + 1 - row);
		if (p > -1) {
			p = 1 << p;
			if (p > 0 && p < 128) {
				for (int i = 0; i < p; i++) {
					cout << "..";
				}
			}
		}// end spacing

		if (vec[curr] == NULL) {
			if (space-- > 0) {
				cout << "";
			}
		}
		else {
			cout << vec[curr]->data;
		}

		//spaceing
		p = (levels + 1 - row);
		if (p > -1) {
			p = 1 << p;
			if (p > 0 && p < 128) {
				for (int i = 0; i < p; i++) {
					cout << "..";
				}
			}
		}// end spacing


		curr++;
		if (curr == rowsquared - 1) {
			cout << "\n";
			space = 8;
			rowsquared = rowsquared * 2;
			row++;
		}
	}
	cout << "\n\n";
}

void breathFirst(struct Node * head) { // print level by level

	list <struct Node *> queue;
	queue.push_back(head);

	while (queue.size() != 0) {

		if (queue.front()->a != NULL) {
			queue.push_back(queue.front()->a);
		}
		if (queue.front()->b != NULL) {
			queue.push_back(queue.front()->b);
		}

		cout << queue.front()->data << " ";
		queue.pop_front();
	}

	return;
}

int main() {

	struct Node* head = NULL;

	insert(30, &head);
	insert(60, &head);
	insert(50, &head);
	insert(40, &head);
	insert(80, &head);
	insert(70, &head);
	insert(98, &head);
	insert(92, &head);
	insert(20, &head);
	insert(10, &head);
	insert(99, &head);
	insert(5, &head);
	insert(3, &head);
	insert(6, &head);
	insert(45, &head);

	/*
................................30.............
..........................20........60.........
....................10...........50....80......
...............5.............40......70...98...
.............3...6.............45........92..99
	*/

	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	cout << "structure:\n";
	printStructure(head, 5);
	cout << "\n";

	cout << "Breath First\n";
	breathFirst(head);
	cout << "\nEnd Breath First\n";

	return 0;
}