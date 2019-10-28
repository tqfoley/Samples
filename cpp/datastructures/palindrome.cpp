#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>

using namespace std;

void printLongestPalindrome(string mystring) {

	int pos = 0;
	int offset = 0;
	int maxPalindromePos = 0;
	int maxPalindromeSize = 0;
	bool maxPalindromeEven = false;

	while (pos < mystring.length()) {

		offset = 0;
		while (pos - offset > 0 && pos + offset < mystring.length() && mystring[pos - offset] == mystring[pos + offset]) {
			// check for palindrome with odd characters and single character in center

			char left = mystring[pos - offset];
			char right = mystring[pos + offset];

			offset++;
			if (pos == 18) {
				pos = 18;
			}
		}
		if (maxPalindromeSize < offset) {
			maxPalindromePos = pos;
			maxPalindromeSize = offset;
			maxPalindromeEven = false;
		}

		offset = 0;
		while (pos - offset > 0 && pos + offset + 1 < mystring.length() && mystring[pos - offset] == mystring[pos + offset + 1]) {
			offset++;
		}
		if (maxPalindromeSize < offset) {
			maxPalindromePos = pos;
			maxPalindromeSize = offset;
			maxPalindromeEven = true;
		}


		while (offset-- > 0) {
			//cout << mystring[pos - offset];
		}
		//cout << endl;

		pos++;
	}

	cout << endl;
	for (int i = 0; i <= maxPalindromePos - maxPalindromeSize; i++) {
		cout << " ";
	}
	int temp = maxPalindromeSize;
	while (maxPalindromeSize-- > 0) {
		cout << mystring[maxPalindromePos - maxPalindromeSize];
	}
	if (maxPalindromeEven) {
		temp++;
	}

	while (maxPalindromeSize++ < temp - 2) {
		if (maxPalindromeEven) {
			cout << mystring[maxPalindromePos + 1 + maxPalindromeSize];
		}
		else
		{
			cout << mystring[maxPalindromePos + 1 + maxPalindromeSize];
		}
	}
}

int main() {

	string mystring = "eoisadvfnlnfsdfkvnlfdgytgffdssdff";
	cout << mystring;
	printLongestPalindrome(mystring);
	cout << endl;

	string mystring2 = "eoisadvfnlnfsdfkvnlnvkffdgytgfdff";
	cout << mystring2;
	printLongestPalindrome(mystring2);

	return 0;
}