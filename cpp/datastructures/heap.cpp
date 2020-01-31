#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>
#include <map> 

#include <algorithm>

using namespace std;

// properties and methods to the class.
class ContinuousMedianHandler {
public:
	double median;

	int single = -999999;
	vector<int> *mins = NULL;
	vector<int> *maxs = NULL;

	void insert(int number) {
		// Write your code here.

		if (mins == NULL) {
			mins = new vector<int>();
			maxs = new vector<int>();
			single = -999999;
		}
		if ((*mins).size() == 0 && single == -999999) {
			single = number;
			median = single * 1.0;
		}
		else if (single == -999999) {
			single = number;
			if (number < (*mins)[0]) {
				int t = heapPop(mins, false);
				heapAdd(mins, number, false);
				single = t;
			}
			if (number > (*maxs)[0]) {
				int t = heapPop(maxs, true);
				heapAdd(maxs, number, true);
				single = t;
			}
			median = single * 1.0;
		}
		else {
			if (number > single) {
				heapAdd(mins, single, false);
				heapAdd(maxs, number, true);
			}
			if (number < single) {
				heapAdd(mins, number, false);
				heapAdd(maxs, single, true);
			}
			median = (*mins)[0] + (*maxs)[0];
			median /= 2.0;
			single = -999999;
		}


		//if(min->size() == )
	}

	double getMedian() { return median; }

private:
	void swap(vector<int> *a, int index1, int index2) {

		int temp = (*a)[index1];
		(*a)[index1] = (*a)[index2];
		(*a)[index2] = temp;
	}

	bool heapAdd(vector<int> *a, int value, bool minHeap) {

		(*a).push_back(value);

		int currentIndex = (*a).size() - 1;

		if (minHeap) {
			int parentIndex = (currentIndex - 1) / 2;
			while (parentIndex >= 0) {
				if ((*a)[currentIndex] < (*a)[parentIndex])
				{
					swap(a, currentIndex, parentIndex);
				}
				else {
					return true;
				}
				currentIndex = parentIndex;
				parentIndex = (currentIndex - 1) / 2;
			}
		}
		else {// max heap
			int parentIndex = (currentIndex - 1) / 2;
			while (parentIndex >= 0) {
				if ((*a)[currentIndex] > (*a)[parentIndex])
				{
					swap(a, currentIndex, parentIndex);
				}
				else {
					return true;
				}
				currentIndex = parentIndex;
				parentIndex = (currentIndex - 1) / 2;
			}
		}


		return true;

	}

	int heapPop(vector<int> *a, bool minHeap) {

		int ret = (*a)[0];

		int debug = (*a).size();

		int last = (*a)[(*a).size() - 1];
		(*a).pop_back();

		int size = (*a).size();
		if (size == 0)
			return ret;

		(*a)[0] = last;

		if (minHeap) {
			int currentPos = 0;
			while (currentPos * 2 + 2 < size) {

				int left = currentPos * 2 + 1;
				int right = currentPos * 2 + 2;
				if ((*a)[currentPos] < (*a)[left] && (*a)[currentPos] < (*a)[right]) {
					return ret;
				}

				if ((*a)[left] < (*a)[right]) {
					swap(a, currentPos, left);
					currentPos = left;
				}
				else {
					swap(a, currentPos, right);
					currentPos = right;
				}
			}
			if (currentPos * 2 + 1 < size) {


				int left = currentPos * 2 + 1;

				if ((*a)[currentPos] < (*a)[left]) {
					return ret;
				}

				swap(a, currentPos, left);
			}
		}


		else {
			int currentPos = 0;
			while (currentPos * 2 + 2 < size) {

				int left = currentPos * 2 + 1;
				int right = currentPos * 2 + 2;
				if ((*a)[currentPos] > (*a)[left] && (*a)[currentPos] > (*a)[right]) {
					return ret;
				}

				if ((*a)[left] > (*a)[right]) {
					swap(a, currentPos, left);
					currentPos = left;
				}
				else {
					swap(a, currentPos, right);
					currentPos = right;
				}
			}
			if (currentPos * 2 + 1 < size) {


				int left = currentPos * 2 + 1;

				if ((*a)[currentPos] > (*a)[left]) {
					return ret;
				}

				swap(a, currentPos, left);
			}
		}

		return ret;

	}

};


void swap(vector<int> *a, int index1, int index2) {

	int temp = (*a)[index1];
	(*a)[index1] = (*a)[index2];
	(*a)[index2] = temp;
}

bool heapAdd(vector<int> *a, int value, bool minHeap) {

	(*a).push_back(value);

	int currentIndex = (*a).size() - 1;

	if (minHeap) {
		int parentIndex = (currentIndex - 1) / 2;
		while (parentIndex >= 0) {
			if ((*a)[currentIndex] < (*a)[parentIndex])
			{
				swap(a, currentIndex, parentIndex);
			}
			else {
				return true;
			}
			currentIndex = parentIndex;
			parentIndex = (currentIndex - 1) / 2;
		}
	}
	else {// max heap
		int parentIndex = (currentIndex - 1) / 2;
		while (parentIndex >= 0) {
			if ((*a)[currentIndex] > (*a)[parentIndex])
			{
				swap(a, currentIndex, parentIndex);
			}
			else {
				return true;
			}
			currentIndex = parentIndex;
			parentIndex = (currentIndex - 1) / 2;
		}
	}


	return true;

}

int heapPop(vector<int> *a, bool minHeap) {

	int ret = (*a)[0];

	int debug = (*a).size();

	int last = (*a)[(*a).size() - 1];
	(*a).pop_back();

	int size = (*a).size();

	(*a)[0] = last;

	if (minHeap) {
		int currentPos = 0;
		while (currentPos * 2 + 2 < size) {

			int left = currentPos * 2 + 1;
			int right = currentPos * 2 + 2;
			if ((*a)[currentPos] < (*a)[left] && (*a)[currentPos] < (*a)[right]) {
				return ret;
			}

			if ((*a)[left] < (*a)[right]) {
				swap(a, currentPos, left);
				currentPos = left;
			}
			else {
				swap(a, currentPos, right);
				currentPos = right;
			}
		}
		if (currentPos * 2 + 1 < size) {


			int left = currentPos * 2 + 1;

			if ((*a)[currentPos] < (*a)[left]) {
				return ret;
			}

			swap(a, currentPos, left);
		}
	}


	else {
		int currentPos = 0;
		while (currentPos * 2 + 2 < size) {

			int left = currentPos * 2 + 1;
			int right = currentPos * 2 + 2;
			if ((*a)[currentPos] > (*a)[left] && (*a)[currentPos] > (*a)[right]) {
				return ret;
			}

			if ((*a)[left] > (*a)[right]) {
				swap(a, currentPos, left);
				currentPos = left;
			}
			else {
				swap(a, currentPos, right);
				currentPos = right;
			}
		}
		if (currentPos * 2 + 1 < size) {


			int left = currentPos * 2 + 1;

			if ((*a)[currentPos] > (*a)[left]) {
				return ret;
			}

			swap(a, currentPos, left);
		}
	}

	return ret;

}


int main()
{


	//Demo Heap


	bool heapType = false;
	vector<int> k;
	k.push_back(99);

	heapAdd(&k, 215, heapType);
	heapAdd(&k, 225, heapType);
	heapAdd(&k, 23, heapType);
	heapAdd(&k, 22, heapType);
	heapAdd(&k, 21, heapType);
	heapAdd(&k, 27, heapType);
	heapAdd(&k, 2125, heapType);
	heapAdd(&k, 24, heapType);
	heapAdd(&k, 20, heapType);
	heapAdd(&k, 29, heapType);
	heapAdd(&k, 28, heapType);
	heapAdd(&k, 216, heapType);
	heapAdd(&k, 219, heapType);
	heapAdd(&k, 214, heapType);
	heapAdd(&k, 277, heapType);
	heapAdd(&k, 211, heapType);
	heapAdd(&k, 224, heapType);
	heapAdd(&k, 223, heapType);

	heapAdd(&k, 3, heapType);
	heapAdd(&k, 1, heapType);
	heapAdd(&k, 7, heapType);
	heapAdd(&k, 0, heapType);
	heapAdd(&k, 31, heapType);
	heapAdd(&k, 37, heapType);

	heapAdd(&k, 43, heapType);
	heapAdd(&k, 41, heapType);
	heapAdd(&k, 2, heapType);

	heapAdd(&k, 55, heapType);
	heapAdd(&k, 9, heapType);
	heapAdd(&k, 8, heapType);



	int total2 = k.size() - 1;
	for (int i = 0; i < total2; i++) {
		cout << heapPop(&k, heapType) << " ";

		/*cout << "\n";
		cout << "\n";
		int total = k.size();
		int g = 2;
		for (int i = 0; i < total; i++) {

			cout << k[i] << "     ";
			if (i + 2 == g) {
				g *= 2;
				cout << "\n";
			}
		}*/

	}




	cout << "\n\nContinuous Median\n";
	ContinuousMedianHandler h;
	h.insert(5);
	cout << h.getMedian() << "\n";
	h.insert(10);
	cout << h.getMedian() << "\n";
	h.insert(20);
	cout << h.getMedian() << "\n";
	h.insert(25);
	cout << h.getMedian() << "\n";
	h.insert(11);
	cout << h.getMedian() << "\n";
	h.insert(19);
	cout << h.getMedian() << "\n";


	return 0;
}

