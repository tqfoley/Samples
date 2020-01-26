
#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>

#include <algorithm>    // std::sort


using namespace std;


class suffixTreeNode {
public:
	vector <suffixTreeNode *> myHashTable;


};

void add(int start, string a, suffixTreeNode **tree) {
	suffixTreeNode ** currNode = tree;


	if ((*currNode) == NULL) {
		(*currNode) = new suffixTreeNode();
		(*currNode)->myHashTable = vector<suffixTreeNode *>(5, NULL);
	}

	for (int i = start; i < a.length() + 1; i++) {

		int index = a[i] - 'a';
		if (index < 0 || index >= 4) {
			index = 4;
		}
		(currNode) = &((*currNode)->myHashTable[index]);

		if ((*currNode) == NULL) {
			(*currNode) = new suffixTreeNode();
			(*currNode)->myHashTable = vector<suffixTreeNode *>(5, NULL);
		}


	}
}

bool stringExists(string s, suffixTreeNode head) {

	suffixTreeNode *currNode = &head;

	for (int i = 0; i < s.length() + 1; i++) {

		if (s[i] == '\0') {

			return true;
		}

		currNode = currNode->myHashTable[s[i] - 'a'];
		if (currNode == NULL) {
			return false;
		}
	}
	return true;
}


int main() {


	suffixTreeNode * t = NULL;
	add(0, "abacaabcb", &t);
	add(1, "abacaabcb", &t);
	add(2, "abacaabcb", &t);
	add(3, "abacaabcb", &t);
	add(4, "abacaabcb", &t);
	add(5, "abacaabcb", &t);
	add(6, "abacaabcb", &t);
	add(7, "abacaabcb", &t);
	add(8, "abacaabcb", &t);

	cout << "\nexists" << stringExists("acaa", *t);
	cout << "\nexists" << stringExists("abc", *t);
	cout << "\nexists" << stringExists("abac", *t);
	cout << "\nexists" << stringExists("caab", *t);
	cout << "\nexists" << stringExists("ab", *t);
	cout << "\nexists" << stringExists("abacab", *t);
	cout << "\nexists" << stringExists("abca", *t);
	cout << "\nexists" << stringExists("caac", *t);
	cout << "\nexists" << stringExists("bcba", *t);
	return 0;
}