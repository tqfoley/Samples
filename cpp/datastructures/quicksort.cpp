#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>

using namespace std;

void myswap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void  quicksort(int *a, int *b) {
	if (a >= b) {
		return;
	}
	else {

		int pivot = *b;

		int* curr = a;
		int* currswap = curr + 1;

		int count = 0;
		while (curr != b) {
			if (*curr < pivot) {
				count++;
			}
			if (*curr >= pivot) {
				bool found = false;
				if (currswap <= curr) {
					currswap = curr + 1;
				}
				while (currswap != b && found == false) {
					if (*currswap < pivot) {
						found = true;
					}
					else {
						currswap++;
					}
				}
				if (found) {
					myswap(curr, currswap);
					count++;
					currswap++;
				}

			}
			curr++;

		}

		myswap(a + count, b);

		quicksort(a, a + count - 1);
		quicksort(a + count + 1, b);
	}

}

int main() {

	vector<int> g = { 10, 77, 9, 35, 16, 17, 4, 9, 74, 20, 66, 11, 34, 9, 12, 78, 55, 98, 27, 51, 86, 99, 44, 33, 6, 7, 9 };

	/*
	for (int i = 0; i < 100; i++) {
		g.push_back((i*113) % 67);
	}

	for (int i = 0; i < 300; i++) {
		g.push_back((i * 53) % 113);
	}

	for (int i = 0; i < 100; i++) {
		g.push_back((i * 127) % 59);
	}
	*/

	int * h = &(g[2]);

	quicksort(&g[0], &g[g.size() - 1]);

	int prev = -1;
	for (int t : g) {

		if (prev != t) {
			cout << "\n";
		}
		cout << t << " ";
		if (prev > t) {
			cout << "error";
		}
		prev = t;
	}

	return 0;
}