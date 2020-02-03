#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>
#include <map> 

#include <algorithm>
#include <unordered_map>

using namespace std;

int apartmentHunting(vector<unordered_map<string, bool>> blocks,
	vector<string> reqs) {
	// Write your code here;

	int s = reqs.size();

	vector<vector<int>> l;
	vector<vector<int>> r;

	for (int i = 0; i < s; i++) {
		l.push_back({});
		r.push_back({});
	}

	for (int j = 0; j < reqs.size(); j++) {
		int c = 9999999;
		for (int i = 0; i < blocks.size(); i++) {
			if (blocks[i][reqs[j]]) {
				l[j].push_back(0);
				c = 0;
			}
			else {
				l[j].push_back(c);
			}
			c++;
		}
	}


	for (int j = 0; j < reqs.size(); j++) {
		int c = 9999999;
		r[j] = vector<int>(blocks.size(), 9999999);

		for (int i = blocks.size() - 1; i >= 0; i--) {
			if (blocks[i][reqs[j]]) {
				r[j][i] = 0;
				c = 0;
			}
			else {
				r[j][i] = c;
			}
			c++;
		}
	}


	for (int j = 0; j < reqs.size(); j++) {
		for (int i = 0; i < blocks.size(); i++) {
			if (l[j][i] > r[j][i]) {
				l[j][i] = r[j][i];
			}

		}
	}

	int lowest = 9999999;
	int lowestIndex = 0;

	for (int i = 0; i < blocks.size(); i++) {
		int largest = 0;
		for (int j = 0; j < reqs.size(); j++) {
			if (largest < l[j][i])
			{
				largest = l[j][i];
			}
		}
		if (lowest > largest) {
			lowest = largest;
			lowestIndex = i;
		}
	}

	/*
	unordered_map<int, char> example = { {1,'a'},{2,'b'} };

		unordered_map<int, char>::const_iterator got = example.find(3);

		if (got == example.end())
			cout << "not found";
		else
			cout << " found";
	*/


	return lowestIndex;
}



int main()
{

	//vector<vector<int>> g;

	vector<unordered_map<string, bool>> u = {

			 {
	   {"gym",false},
	   {"school",true},
	   {"store",false}
	},

			 {
	   {"gym",true},
	   {"school",false},
	   {"store",false}
	},

		 {
	   {"gym",true},
	   {"school",true},
	   {"store",false}
	},

			 {
	   {"gym",false},
	   {"school",true},
	   {"store",false}
	},

		 {
	   {"gym",false},
	   {"school",true},
	   {"store",true}
	}
	};

	vector <string> reqs = { "gym", "school", "store" };

	//int answer = countParks(g[0].size(), g.size(), g);

	int answer = apartmentHunting(u, reqs);

	cout << "\n\n";
	cout << answer << "\n\n";

}

