#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>


bool existsInSubString(char * s, char letter, int start, int end)
{
	int len = strlen(s);

	for (int i = start; i < len && i < end; i++)
	{
		if (s[i] == letter) {
			return true;
		}
	}
	return false;
}

int shortestSubstringThatContainsAllCharacters(char* s)
{
	int len = strlen(s);
	char *uniqueCharacters;
	uniqueCharacters = (char *)malloc(len+1);
	for (int i = 0; i < len + 1; i++)
	{
		uniqueCharacters[i] = '\0';
	}

	//find unique chars
	for (int i = 0; i < len; i++) {
		if (!existsInSubString(uniqueCharacters, s[i], 0, len)) {
			uniqueCharacters[strlen(uniqueCharacters)] = s[i];
		}
	}

	for (int i = strlen(uniqueCharacters); i <= strlen(s); i++) {
		for (int j = 0; j <= len - i; j++) {
			bool allLettersExist = true;
			for (int k = j; k < i; k++) {
				if (!existsInSubString(uniqueCharacters, s[k], 0, len)) {
					allLettersExist = false;
				}
			}
			if (allLettersExist == true) {

				bool found = true;
				// ensure we used every letter in uniqueCharacters
				for (int l = 0; l < strlen(uniqueCharacters); l++) {
					if (!existsInSubString(s, uniqueCharacters[l], j, j+i)) {
						found = false;
					}
				}
				if (found) {
					return i;
				}
			}
		}
	}
	return -1;
}

int main() {

	char t[7] = "aabcce";

	printf("Expected 5 got %d. \n\n", shortestSubstringThatContainsAllCharacters(t));

	// other tests
	{
		char test[] = "bab";
		int expected = 2;

		if (shortestSubstringThatContainsAllCharacters(test) != expected) {
			printf("Test 1 Failed Expected %d got %d\n", expected, shortestSubstringThatContainsAllCharacters(test));
		}
	}
	{
		char test[] = "accccb";
		int expected = 6;

		if (shortestSubstringThatContainsAllCharacters(test) != expected) {
			printf("Test 1 Failed Expected %d got %d\n", expected, shortestSubstringThatContainsAllCharacters(test));
			printf("Test 1 Failed Expected %d got %d\n", expected, shortestSubstringThatContainsAllCharacters(test));
		}
	}
	{
		char test[] = "asdhjfgads";
		int expected = 7;

		if (shortestSubstringThatContainsAllCharacters(test) != expected) {
			printf("Test 1 Failed Expected %d got %d\n", expected, shortestSubstringThatContainsAllCharacters(test));
		}
	}
	{
		char test[] = "babaacbaacababaacaab";
		int expected = 3;

		if (shortestSubstringThatContainsAllCharacters(test) != expected) {
			printf("Test 1 Failed Expected %d got %d\n", expected, shortestSubstringThatContainsAllCharacters(test));
		}
	}
	{
		char test[] = "sbabaacbaacababaacaab";
		int expected = 7;

		if (shortestSubstringThatContainsAllCharacters(test) != expected) {
			printf("Test 1 Failed Expected %d got %d\n", expected, shortestSubstringThatContainsAllCharacters(test));
		}
	}
	{
		char test[] = "babaacbaacababaacaabs";
		int expected = 5;

		if (shortestSubstringThatContainsAllCharacters(test) != expected) {
			printf("Test 1 Failed Expected %d got %d\n", expected, shortestSubstringThatContainsAllCharacters(test));
		}
	}
}