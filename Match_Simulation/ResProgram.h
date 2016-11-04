/*
 * ResProgram.h
 *
 *  Created on: Oct 29, 2016
 *      Author: Dave
 */

#ifndef RESPROGRAM_H_
#define RESPROGRAM_H_

#include <vector>
using namespace std;

class ResProgram {
	int ProgramID;
	int numPositions;
	vector<int> RankList;
	vector<int> AcceptedList;
public:
	ResProgram();
	ResProgram(int,int);
	int getID();
	void setID(int);
	int getNumPositions();
	void setNumPositions(int);
	void initRankList(int);
	void updateAcceptedList(int, int);
	bool scanRankList(int);
	bool isfull();
	void removeApplicant(int);
	bool isAccepted(int);
	void printRankList();
	void printAcceptedList();
};

#endif /* RESPROGRAM_H_ */
