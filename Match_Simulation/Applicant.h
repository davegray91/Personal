/*
 * Applicant.h
 *
 *  Created on: Oct 29, 2016
 *      Author: Dave
 */

#ifndef APPLICANT_H_
#define APPLICANT_H_

#include <vector>
using namespace std;

class Applicant {
	int AppID;
	vector<int> RankList;
	int Assignment;
public:
	Applicant();
	Applicant(int);
	int getID();
	void setID(int);
	void initRankList(int);
	int getRank(int);
	void setAssignment(int);
	int getAssignment();
	void printRankList();
	void printAssignment();
};

#endif //APPLICANT_H_
