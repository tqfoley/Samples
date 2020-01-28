#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>
#include <map> 

#include <algorithm>

#define MAX 255

using namespace std;

class prefixTree {
public:
	prefixTree * hashTable[MAX];

};

unsigned char getHash(char a) {

	unsigned char hash = a - 'A';;
	if (a == ' ') {
		hash = MAX - 1;
	}
	if (hash < 0)
	{
		hash = 0;
	}if (hash > 254) {
		hash = 0;
	}
	return hash;
}


void addString(string s, prefixTree * tree) {

	prefixTree *current = tree;

	for (int i = 0; i < s.length(); i++) {
		int hash = getHash(s[i]);

		if (current->hashTable[hash] == NULL) {
			current->hashTable[hash] = new prefixTree();
			for (int i = 0; i < MAX; i++) {
				current->hashTable[hash]->hashTable[i] = NULL;
			}
		}

		current = current->hashTable[hash];

	}


}

bool exists(string s, prefixTree * tree) {


	prefixTree *current = tree;

	for (int i = 0; i < s.length(); i++) {
		int hash = getHash(s[i]);
		if (current->hashTable[hash] == NULL) {
			return false;
		}
		current = current->hashTable[hash];
	}

	return true;

}

vector<bool> multiStringSearch(string bigString, vector<string> smallStrings) {

	string s = bigString;
	vector<string> strings = smallStrings;
	// Write your code here.
	prefixTree t;
	for (int i = 0; i < MAX; i++) {
		t.hashTable[i] = NULL;
	}

	for (int i = 0; i < s.length(); i++) {
		addString(s.substr(i, s.length() - i), &t);
	}

	vector<bool> answer = {};

	for (int i = 0; i < strings.size(); i++) {


		answer.push_back(exists(strings[i], &t));
	}

	return answer;
}

int main()
{
	string d = "Asdsd asdf";
	vector<string> strings = { "asdf", "Asdefsadf" };

	vector <bool> g = multiStringSearch(d, strings);



	for (int i = 0; i < g.size(); i++) {
		cout << g[i] << " ";
	}cout << "\n\n";


	return 0;
}
