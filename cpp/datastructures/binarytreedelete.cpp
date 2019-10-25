#include "pch.h"
#include <iostream>
#include <vector> 

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

struct Node ** get_parents_a_of_smallest_node(struct Node **ptr) {
	if ((*ptr) == NULL) {
		throw new exception("Did not expect null ptr");
	}
	else {
		if ((*ptr)->a == NULL) {
			return ptr;
		}
		else {
			return get_parents_a_of_smallest_node(&((*ptr)->a));
		}
	}
	return NULL;
}

void delete_root(struct Node **root) {

	struct Node * to_delete = *root;
	struct Node ** temp = NULL;

	if ((*root)->a == NULL && (*root)->b == NULL) { // if no children
		free(to_delete);
		*root = NULL;
		return;
	}
	else if ((*root)->b != NULL) {
		temp = get_parents_a_of_smallest_node(&((*root)->b));
		if ((*temp) == (*root)->b) {
			temp = &((*root)->b);
			(*temp)->a = (*root)->a;
			*root = *temp;
		}
		else {
			struct Node * larger_nodes = (*temp)->b;

			*root = *temp;
			(*temp)->a = to_delete->a;
			(*temp)->b = to_delete->b;

			*temp = larger_nodes;
		}
	}
	else if ((*root)->a != NULL) { // if only one child
		temp = &((*root)->a);
		*root = *temp;
	}

	free(to_delete);
	return;
}

bool delete_value(int data, struct Node **root) {

	if (root == NULL) {
		throw new exception("null pinter");
		return false;
	}
	if (*root == NULL) {
		throw new exception("couldn't find value");
		return false;
	}

	if (data == (*root)->data) {
		delete_root(root);
		return true;
	}
	else {
		if (data < (*root)->data) {
			return delete_value(data, &((*root)->a));
		}
		else if (data > (*root)->data) {
			return delete_value(data, &((*root)->b));
		}
	}
	return false;

}

void displayInOrderRecursive(struct Node *parent) {
	if (parent != NULL) {
		displayInOrderRecursive(((parent)->a));

		cout << (parent)->data << ' ';
		displayInOrderRecursive(((parent)->b));

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

void print_structure(struct Node * head, int levels) {
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
		int p = (levels + 2 - row);
		if (p > 0) {
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
		p = (levels + 2 - row);
		if (p > 0) {
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

	int level = 0;
	cout << "\nfind:" << find(8, head, &level);
	cout << "\nlevel:" << level;


	cout << "\ndistance 40 80 :" << distance_between_two_leafs(40, 80, head) << "\n";
	cout << "\ndistance 45 80 :" << distance_between_two_leafs(45, 80, head) << "\n";
	cout << "\ndistance 45 60 :" << distance_between_two_leafs(45, 60, head) << "\n";
	cout << "\ndistance 3  70 :" << distance_between_two_leafs(3, 70, head) << "\n";
	cout << "\ndistance 45 92 :" << distance_between_two_leafs(45, 92, head) << "\n";
	cout << "\ndistance 92 45 :" << distance_between_two_leafs(92, 45, head) << "\n";
	cout << "\ndistance 20 98 :" << distance_between_two_leafs(20, 98, head) << "\n";
	cout << "\ndistance 50 98 :" << distance_between_two_leafs(50, 98, head) << "\n";


	/*
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	delete_root(&head);

	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";
	*/

	cout << "The linked list is: \n";
	displayInOrderRecursive(head);

	print_structure(head, 5);
	delete_value(70, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(98, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(92, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(10, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(99, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(5, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(3, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(6, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(45, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(60, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(50, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(20, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(30, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(40, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";

	print_structure(head, 5);
	delete_value(80, &head);
	cout << "The linked list is: \n";
	displayInOrderRecursive(head);
	cout << "\n";


	print_structure(head, 5);


	return 0;
}