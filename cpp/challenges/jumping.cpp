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


	vector <int> g = vector<int>(18, 1);

	g[0] = 3;
	g[1] = 4;
	g[2] = 2;
	g[4] = 2;
	g[5] = 3;
	g[6] = 7;
	g[10] = 3;
	g[11] = 2;
	g[12] = 6;
	g[13] = 2;

	for (int k = 0; k < g.size(); k++) {

		cout << " " << g[k];
	}
	cout << "\n";
	cout << "\n";
	cout << "\n";

	int current = 0;

	vector <int> d = vector<int>(g.size(), 999999);
	d[0] = 0;

	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i] && i + j < g.size(); j++) {

			if (i + j + 1 < g.size()) {
				if (d[i + j + 1] > d[i] + 1) {
					d[i + j + 1] = d[i] + 1;
				}
			}
		}

		for (int k = 0; k < g.size(); k++) {

			cout << " " << d[k];
		}
		cout << "\n";

	}

	return d[g.size() - 1];
}
