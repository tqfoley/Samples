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

void  mergesort(int *a, int *b) {
	if (a == b) {
		return;
	}
	else {
		int g = b - a;
		g /= 2;
		mergesort(a, a + g);
		mergesort(a + g + 1, b);

		int *curra=a;
		int *currb=a+g+1;

		while (curra != currb) {
			cout << *curra << " ";
			curra++;
		}
		cout << "\n";
		cout << *curra << " ";
		while (curra != b) {
			curra++;
			cout << *curra << " ";
		}
		cout << "\n";
		cout << "\n";

		curra = a;
		currb = a + g + 1;

		int extenda = 0;
		while (curra<= a+g+extenda && currb <= b) {
			if (*curra > *currb) {
				myswap(curra, currb);
				int * curr2b = currb;
				while (curr2b!=curra+1)
				{
					myswap(curr2b,curr2b-1);
					curr2b--;
				}
				currb++;
				extenda++;// = sizeof(int);
			}
			else {
				curra++;
			}
		}
	}
}

int main() {

	vector<int> g = { 10, 22, 9, 35, 6, 7, 100, 4, 33, 99, 20, 66, 11, 34, 12, 78, 55, 98, 27, 1};
	int * h = &(g[2]);

	mergesort(&g[0], &g[g.size()-1]);

	for (int t : g) {
		cout << t << "\n";
	}

	return 0;
}