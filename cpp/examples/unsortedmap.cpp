#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>
#include <map> 

#include <algorithm>


using namespace std;

void printList(map<int, string> g) {

	// printing map gquiz1 
	map<int, string>::iterator itr;
	cout << "\tKEY\tELEMENT\n";
	for (itr = g.begin(); itr != g.end(); ++itr) {
		cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}
	cout << endl;
}

int main()
{
	// empty map container 
	map<int, string> gquiz1;

	// insert elements in random order 
	gquiz1.insert(pair<int, string>(1, "trevor"));
	gquiz1.insert(pair<int, string>(2, "tf"));
	gquiz1.insert(pair<int, string>(3, "tf"));
	gquiz1.insert(pair<int, string>(4, "tf2"));
	gquiz1.insert(pair<int, string>(5, "tf"));
	gquiz1.insert(pair<int, string>(6, "tf"));
	gquiz1.insert(pair<int, string>(7, "tf"));

	printList(gquiz1);

	// assigning the elements from gquiz1 to gquiz2 
	map<int, string> gquiz2(gquiz1.begin(), gquiz1.end());

	// print all elements of the map gquiz2 
	cout << "\nThe map gquiz2 after"
		<< " assign from gquiz1 is : \n";

	printList(gquiz2);
	cout << endl;

	// remove all elements up to 
	// element with key=3 in gquiz2 
	cout << "\ngquiz2 after removal of"
		" elements less than key=3 : \n";

	gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
	printList(gquiz2);
	cout << endl;



	// remove all elements with key = 4 
	int num;
	num = gquiz2.erase(4);

	printList(gquiz2);
	cout << endl;

	return 0;
}
