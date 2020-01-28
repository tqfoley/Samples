#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>
#include <algorithm>

using namespace std;


vector <int> range(vector <int>array) {

	sort(array.begin(), array.end());

	vector <int> * answer = new vector<int>();

	int first = 0;
	int longestFirst = 0;
	int howManyInLongest = 0;

	int i = 1;
	for (i = 1; i < array.size(); i++) {
		if (array[first] + i - first == array[i]) {

		}
		else
		{
			if (i - first > howManyInLongest) {
				howManyInLongest = i - first - 1;
				longestFirst = first;
			}
			first = i;
		}
	}
	if (i - first > howManyInLongest) {
		howManyInLongest = i - first - 1;
		longestFirst = first;
	}

	//for (int i = longestFirst; i < howManyInLongest + longestFirst; i++) {
	(*answer).push_back(array[longestFirst]);
	(*answer).push_back(array[longestFirst + howManyInLongest]);

	//}

	return *answer;
}

vector <int> rangeHash(vector <int>array) {

	int min = 999999;
	int max = -999999;
	int entireSizeOfHash = 0;


	for (int i = 0; i < array.size(); i++) {
		if (array[i] < min) {
			min = array[i];
		}
		if (array[i] > max) {
			max = array[i];
		}
	}
	entireSizeOfHash = max - min + 2;
	int *hash = (int *)malloc(sizeof(int)*(entireSizeOfHash));
	//memset(hash, 0, sizeof(int)*entireSizeOfHash);

	for (int i = 0; i < entireSizeOfHash; i++) {
		hash[i] = 0;
	}

	for (int i = 0; i < array.size(); i++) {
		hash[array[i] - min] = 1;

	}


	for (int i = 0; i < entireSizeOfHash; i++) {
		//cout << hash[i];

	}


	vector <int> * answer = new vector<int>();


	int first = 0;
	int longestFirst = 0;
	int howManyInLongest = 1;

	int i = 1;
	for (i = 1; i < entireSizeOfHash; i++) {

		if (hash[i] == 0 && first != -9999) {
			if (i - first > howManyInLongest) {
				howManyInLongest = i - first;
				longestFirst = first;
			}
			first = -9999;
		}
		if (hash[i] == 1) {
			if (first == -9999) {
				first = i;
			}
		}
	}

	//for (int i = longestFirst; i < howManyInLongest + longestFirst; i++) {
	(*answer).push_back(longestFirst + min);
	(*answer).push_back(longestFirst + howManyInLongest + min - 1);

	//}

	return *answer;
}

int main() {

	vector <int> j = { 1,11,3,0,15,5,2,4,10,7,12,6 };
	cout << rangeHash(j)[0] << " " << rangeHash(j)[1] << "\n";
	cout << range(j)[0] << " " << range(j)[1] << "\n";

	j = { 4,2,1,3 };
	cout << rangeHash(j)[0] << " " << rangeHash(j)[1] << "\n";
	cout << range(j)[0] << " " << range(j)[1] << "\n";

	j = { 4,2,1,3,6 };
	cout << rangeHash(j)[0] << " " << rangeHash(j)[1] << "\n";
	cout << range(j)[0] << " " << range(j)[1] << "\n";

	j = { 19,-1,18,17,2,10,3,5,16,4,11,8,7,6,15,12,2,1,6,13,14 };
	cout << rangeHash(j)[0] << " " << rangeHash(j)[1] << "\n";
	cout << range(j)[0] << " " << range(j)[1] << "\n";

	j = { 5,6,2,-1,-4,9,8,10, 19, 22 };
	cout << rangeHash(j)[0] << " " << rangeHash(j)[1] << "\n";
	cout << range(j)[0] << " " << range(j)[1] << "\n";

	return 0;

}