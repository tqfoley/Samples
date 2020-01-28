#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>

#include <algorithm>

using namespace std;

bool compareInteger(int i1, int i2)
{
	return (i1 > i2);
}

int main() {
	vector<int> f = { 4,6,7 };

	sort(f.begin(), f.end(), compareInteger);

	for (int i = 0; i < f.size(); i++) {
		cout << f[i] << " ";
	}
	cout << "\n\n";
	return 0;
}