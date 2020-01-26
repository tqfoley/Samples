#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>

#include <algorithm>    // std::sort


using namespace std;


void print(vector<int> *copy) {

	for (int i = 0; i < copy->size(); i++) {
		cout << (*copy)[i] << "\n";

	}
}

void create(vector<int> **copy) {


	vector<int> *a = new vector<int>(5, 1);
	(*a)[2] = 9;

	for (int i = 0; i < a->size(); i++) {
		cout << (*a)[i] << "\n";

	}

	(*copy) = a;

}


int main() {




	vector<int> *copy;
	//= &a;// (a.begin(), a.end());
	create(&copy);

	//a[3] = 19;

	print(copy);

	return 0;

}