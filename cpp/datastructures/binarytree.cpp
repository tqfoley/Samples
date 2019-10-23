#include "pch.h"
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *a;
	struct Node *b;
};

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
			insert(new_data, &((*parent)->b));
		}
		else {
			insert(new_data, &((*parent)->a));
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
			return find(data, parent->b, level);
		}
		else {
			return find(data, parent->a, level);
		}
	}
	return false;
}

void find_lowest_common_parent(int data_a, int data_b, struct Node *parent, int * level) {
	if (parent == NULL) {
		return;
	}
	if (data_a < parent->data && data_b < parent->data) {
		(*level)++;
		return find_lowest_common_parent(data_a, data_b, parent->a, level);
	}
	if (data_a > parent->data && data_b > parent->data) {
		(*level)++;
		return find_lowest_common_parent(data_a, data_b, parent->b, level);
	}
	return;
}

int distance_between_two_leafs(int data_a, int data_b, struct Node *parent)
{
	int level_a = 0;
	int level_b = 0;

	if (find(data_a, parent, &level_a) && find(data_b, parent, &level_b)) {
		int level = 0;
		find_lowest_common_parent(data_a, data_b, parent, &level);

		return level_a + level_b - 2 * level;
	}

	return -1;
}

int main() {

	struct Node* head = NULL;

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
	cout << "\nfind:" << find(8, head, &level);
	cout << "\nlevel:" << level;


	level = 0;
	find_lowest_common_parent(17, 27, head, &level);
	cout << "\nlevel:" << level << "\n";

	cout << "\ndistance 4 27 :" << distance_between_two_leafs(4, 27, head) << "\n";

	cout << "\ndistance 4 16 :" << distance_between_two_leafs(4, 16, head) << "\n";

	cout << "\ndistance 17 27 :" << distance_between_two_leafs(17, 27, head) << "\n";

	cout << "\ndistance 0 4 :" << distance_between_two_leafs(4, 0, head) << "\n";

	cout << "\ndistance 4 3 :" << distance_between_two_leafs(4, 3, head) << "\n";

	cout << "\ndistance 16 100 :" << distance_between_two_leafs(16, 100, head) << "\n";

	cout << "\ndistance 8 100 :" << distance_between_two_leafs(8, 100, head) << "\n";

	cout << "\ndistance 12 100 :" << distance_between_two_leafs(12, 100, head) << "\n";

	cout << "\ndistance 4 2 :" << distance_between_two_leafs(4, 2, head) << "\n";

	cout << "\ndistance 16 0 :" << distance_between_two_leafs(16, 0, head) << "\n";

	cout << "\ndistance 27 7 :" << distance_between_two_leafs(7, 27, head) << "\n";

	cout << "\ndistance 127 7 :" << distance_between_two_leafs(7, 127, head) << "\n";

	cout << "\ndistance 27 117 :" << distance_between_two_leafs(117, 27, head) << "\n";



	return 0;
}