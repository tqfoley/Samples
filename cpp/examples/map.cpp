#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>
#include <map> 

#include <algorithm>
#include <unordered_map>
#include <sstream>      

using namespace std;

string numToString(int num) {
	
	string ret = "";

	while (num > 1) {
		if (num % 2 == 0) {
			ret += '0';
		}
		else {
			ret += '1';
		}
		num /= 2;
	}
	if (num % 2 == 0) {
		ret += '0';
	}
	else {
		ret += '1';
	}
	while (ret.length() < 30) {
		ret += '0';
	}
	return ret;
}

unordered_map<string, int> makeMap()
{
	
	unordered_map<string, int> dictionary_unordered = unordered_map<string, int>();

	for (int i = 0; i < 64; i++) {
		int numb = i * 7;
		string g = numToString(numb % 64);
		dictionary_unordered[g] = numb %64;
	}

	return dictionary_unordered;
}

bool exists(unordered_map<string, int> map, string sdf) {
	if (map.find(sdf) == map.end())
	{
		return false;
	}
	return true;
}

int main() {

	unordered_map<string, int> dictionary_unordered = makeMap();
	string sdf = "sdf";
	dictionary_unordered[sdf] = 5;
	dictionary_unordered["Sdfg"] = 6;


	for (pair<string, int> element : dictionary_unordered)
	{
		cout << element.first << " :: " << element.second << std::endl;
	}
	cout << "trevor" << "\n\n";
	


	map<string, int> dictionary_ordered;
	dictionary_ordered["zdsfg"] = 6;
	dictionary_ordered["rt"] = 8;
	dictionary_ordered["zdsfg"] = 9;
	dictionary_ordered["atyu"] = 7;


	for (pair<string, int> element : dictionary_ordered)
	{
		cout << element.first << " :: " << element.second << std::endl;
	}
	cout << "trevor" << "\n\n";





	

	return 0;
}