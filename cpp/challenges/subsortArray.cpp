#include <vector>
using namespace std;



vector<int> subarraySort(vector<int> array) {
	// Write your code here.

	if (array.size() < 2) {
		return { -1,-1 };
	}
	int firstDiscrepency = -9999;
	int lastDiscrepency = -9999;

	//int localMinIndex = -9999;
	int localMinValue = 9999;
	//int localMaxIndex = -9999;
	int localMaxValue = -9999;


	for (int i = 1; i < array.size() && firstDiscrepency == -9999; i++) {
		if (array[i - 1] > array[i]) {
			firstDiscrepency = i - 1;
		}
	}


	for (int i = array.size() - 1; i >= 1 && lastDiscrepency == -9999; i--) {
		if (array[i - 1] > array[i]) {
			lastDiscrepency = i;
		}
	}



	for (int i = firstDiscrepency; i < array.size(); i++) {
		if (localMinValue > array[i]) {
			localMinValue = array[i];
		}
	}


	for (int i = lastDiscrepency; i >= 0; i--) {
		if (localMaxValue < array[i]) {
			localMaxValue = array[i];
		}
	}

	int answer1 = -1;
	if (localMinValue < 9999) {
		for (int i = 0; i < array.size() && answer1 == -1; i++) {
			if (localMinValue < array[i]) {
				answer1 = i;
			}
		}
	}

	int answer2 = -1;
	if (localMaxValue > -9999) {
		for (int i = array.size() - 1; i >= 0 && answer2 == -1; i--) {
			if (localMaxValue > array[i]) {
				answer2 = i;
			}
		}
	}


	return { answer1,answer2 };
}

