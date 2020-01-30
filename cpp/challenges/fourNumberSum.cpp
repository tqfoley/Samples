#include "pch.h"
#include <iostream>
#include <vector> 
#include <list>
#include <string>
#include <map> 

#include <algorithm>


using namespace std;

vector<vector<int>> fourNumberSum(vector<int> a, int target)
{
	if (a.size() < 4) {
		return {};
	}

	int min = 0;
	int max = -999;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}

	//min -= target;
	//max += target;

	min *= 4;
	max *= 4;
	int total = max - min;

	vector<vector<int>> answer = {};

	vector<vector<int>> hash;
	for (int i = 0; i < total; i++) {
		hash.push_back({});
	}

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size(); j++) {
			if (i == j) {

			}
			if (j < i) {
				int myhash = a[i] + a[j] - min;

				if (myhash >= 0 && myhash < total) {
					hash[myhash].push_back(a[i]);
					hash[myhash].push_back(a[j]);
				}
			}
			if (j > i) {
				int myhash2 = target - a[i] - a[j] - min;

				if (myhash2 >= 0 && myhash2 < total) {
					if (hash[myhash2].size() != 0) {
						for (int k = 0; k < hash[myhash2].size() / 2; k++) {

							if (hash[myhash2][k * 2] != a[i] && hash[myhash2][k * 2 + 1] != a[i]) {
								vector<int> ans = vector<int>(4, -9999);
								ans[0] = hash[myhash2][k * 2];
								ans[1] = hash[myhash2][k * 2 + 1];
								ans[2] = a[i];
								ans[3] = a[j];
								answer.push_back(ans);
							}
						}
					}
				}

			}
		}
	}

	return answer;

}

int main()
{

	vector<int> t = { 1,2,3,4,5,6,7 };
	vector<vector<int>> a = fourNumberSum(t, 10);


	for (int i = 0; i < a.size(); i++) {
		cout << a[i][0] << " " << a[i][1] << " " << a[i][2] << " " << a[i][3] << "\n";
	}cout << "\n";

	return 0;
}

