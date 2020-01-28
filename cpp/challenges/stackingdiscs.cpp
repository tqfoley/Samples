#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>
#include <map> 

#include <algorithm>


using namespace std;


bool compareRing(vector<int> i1, vector<int> i2)
{
	return (i1[2] < i2[2]);
}

int maxHeight(vector<vector<int>> g) {

	sort(g.begin(), g.end(), compareRing);

	vector<int> heights = vector<int>(g.size(), 0);


	for (int i = 0; i < g.size(); i++) {
		heights[i] = g[i][2];
	}

	for (int i = 1; i < g.size(); i++) {
		int max = -9999;
		int maxIndex = -1;
		for (int j = i; j >= 0; j--) {
			if (g[i][0] > g[j][0] &&
				g[i][1] > g[j][1] &&
				g[i][2] > g[j][2]) {

				if (heights[j] > max) {
					max = heights[j];
					maxIndex = j;
				}
			}
		}
		if (maxIndex != -1)
			heights[i] += heights[maxIndex];
	}
	int maxHeight = 0;
	for (int i = 0; i < g.size(); i++) {
		if (maxHeight < heights[i]) {
			maxHeight = heights[i];
		}
	}


	return maxHeight;
}

vector<vector<int>> maxHeightList(vector<vector<int>> g) {

	sort(g.begin(), g.end(), compareRing);

	vector<int> heights = vector<int>(g.size(), 0);

	vector<vector<int>> answer;

	for (int i = 0; i < g.size(); i++) {
		heights[i] = g[i][2];
		answer.push_back(vector<int>(1, i));

	}

	for (int i = 1; i < g.size(); i++) {
		int max = -9999;
		int maxIndex = -1;
		for (int j = i; j >= 0; j--) {
			if (g[i][0] > g[j][0] &&
				g[i][1] > g[j][1] &&
				g[i][2] > g[j][2]) {

				if (heights[j] > max) {
					max = heights[j];
					maxIndex = j;
				}
			}
		}
		if (maxIndex != -1) {
			heights[i] += heights[maxIndex];
			for (int l = 0; l < answer[maxIndex].size(); l++)
			{
				answer[i].push_back(answer[maxIndex][l]);
			}
		}
	}
	int maxHeight = 0;

	int answerIndex = -1;

	for (int i = 0; i < g.size(); i++) {
		if (maxHeight < heights[i]) {
			maxHeight = heights[i];
			answerIndex = i;
		}
	}

	vector<vector<int>> finalAnswer;
	for (int i = answer[answerIndex].size() - 1; i >= 0; i--) {
		finalAnswer.push_back(vector<int>(g[answer[answerIndex][i]].begin(), g[answer[answerIndex][i]].end()));

	}

	return finalAnswer;
}

int main()
{
	vector<vector<int>> g = { {1,3,1}, {2,1,2}, {3,2,3}, {2,3,4}, {4,4,5}, {2,2,8} };

	//vector<vector<int>> g = { {2,1,2}, {3,2,3} };

	vector<vector<int>> a = maxHeightList(g);
	return 0;
}
