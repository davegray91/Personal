/*
 * Applicant.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: Dave
 */

#include "Applicant.h"
#include <algorithm>
#include <iostream>

Applicant::Applicant() {
	AppID = 0;
	Assignment = 0;
}

Applicant::Applicant(int ID) {
	AppID = ID;
	Assignment = 0;
}

int Applicant::getID(void) {
	return AppID;
}

void Applicant::setID(int ID) {
	AppID = ID;
}

void Applicant::initRankList(int num) {
	for(int i=0; i<num; i++) {RankList.push_back(i+1);}	//initialize RankList with all Program IDs (num should be numRes)
	random_shuffle(RankList.begin(), RankList.end());	//shuffle the Program IDs to randomize the rank list
}

int Applicant::getRank(int rank) {
	return RankList[rank];
}

void Applicant::setAssignment(int Program) {
	Assignment = Program;
}

int Applicant::getAssignment(void) {
	return Assignment;
}

void Applicant::printRankList() {
	cout<<endl<<"Applicant: "<<AppID<<" RANK LIST"<<endl;

	for(vector<int>::iterator it=RankList.begin(); it!=RankList.end(); it++){
		cout<<*it<<endl;
	}
}

void Applicant::printAssignment() {
	cout<<endl<<"Applicant: "<<AppID<<" Assignment: "<<Assignment<<endl;
}
