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

class OrgChart {
public:
	char name;
	vector<OrgChart *> directReports;

	OrgChart(char name) {
		this->name = name;
		this->directReports = {};
	}

	void addDirectReports(vector<OrgChart *> *directReports) {
		//directReports = vector<OrgChart *>(directReports.begin(), directReports.end());
		//this->directReports = vector<OrgChart *>;

		if (directReports == NULL) {
			return;
		}
		for (int i = 0; i < directReports->size(); i++) {
			this->directReports.push_back((*directReports)[i]);
		}
	}
};


int count(OrgChart *topManager, OrgChart *reportOne,
	OrgChart *reportTwo, OrgChart ** answer)
{

	if (topManager == NULL) {
		return 0;
	}

	int c = 0;

	for (int i = 0; i < topManager->directReports.size(); i++) {
		c += count(topManager->directReports[i], reportOne, reportTwo, answer);
	}

	if (reportOne->name == topManager->name ||
		reportTwo->name == topManager->name)
	{
		c += 1;
	}
	if (c == 2 && *answer == NULL) {
		*answer = topManager;
	}

	return c;
}

OrgChart *getLowestCommonManager(OrgChart *topManager, OrgChart *reportOne,
	OrgChart *reportTwo) {
	// Write your code here.

	OrgChart * answer = NULL;

	count(topManager, reportOne, reportTwo, &answer);

	return answer;
}






int main()
{



	vector <OrgChart*> *no = NULL;;

	OrgChart g = OrgChart('g');

	OrgChart h = OrgChart('h');

	/*OrgChart *g =(OrgChart*)malloc(sizeof(OrgChart));
	g->name = 'g';
	g->addDirectReports(NULL);

	OrgChart *h = (OrgChart*)malloc(sizeof(OrgChart));
	h->name = 'h';
	h->addDirectReports(NULL);
	*/


	vector <OrgChart*> reports;
	reports.push_back(&g);
	reports.push_back(&h);

	OrgChart a = OrgChart('a');
	a.addDirectReports(&reports);


	getLowestCommonManager(&a, &a, &h);

	return 0;
}
