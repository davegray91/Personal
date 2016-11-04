/*
 * ResProgram.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: Dave
 */

#include "ResProgram.h"
#include <iostream>
#include <algorithm>

ResProgram::ResProgram() {
	ProgramID = 0;
	numPositions = 0;
}

ResProgram::ResProgram(int ID, int num) {
	ProgramID = ID;
	numPositions = num;
}

int ResProgram::getID(void) {
	return ProgramID;
}

void ResProgram::setID(int ID) {
	ProgramID = ID;
}

int ResProgram::getNumPositions(void) {
	return numPositions;
}

void ResProgram::setNumPositions(int num) {
	numPositions = num;
}

void ResProgram::initRankList(int num) {
	for(int i=0; i<num; i++) {RankList.push_back(i+1);}	//initialize RankList with all app IDs (num should be numApplicants)
	random_shuffle(RankList.begin(), RankList.end());	//shuffle the app IDs to randomize the rank list
}

void ResProgram::updateAcceptedList(int IDadd, int IDerase) {
	if(IDerase == 0){
		AcceptedList.push_back(IDadd);
	}
	else{
		for(int i=0; i<AcceptedList.size(); i++){
			if(AcceptedList[i] == IDerase){
				AcceptedList.erase(AcceptedList.begin()+i);
				AcceptedList.push_back(IDadd);
			}
		}
	}
}

bool ResProgram::scanRankList(int AppID) {
	for(vector<int>::reverse_iterator rit=RankList.rbegin(); rit!=RankList.rend(); rit++) {
		if(*rit == AppID){
			return false;
		}
		else{
			for(vector<int>::iterator it=AcceptedList.begin(); it!=AcceptedList.end(); it++) {
				if(*rit == *it){
					this->updateAcceptedList(AppID, *it);
					return true;
				}
			}
		}
	}
	return false;
}

bool ResProgram::isfull() {
	if(AcceptedList.size() < numPositions) {
		return false;
	}
	else{
		return true;
	}
}

void ResProgram::removeApplicant(int ID) {
	for(vector<int>::iterator it=AcceptedList.begin(); it!=AcceptedList.end(); it++) {
		if(*it == ID)
			AcceptedList.erase(it);
	}
}

bool ResProgram::isAccepted(int ID) {
	for(vector<int>::iterator it=AcceptedList.begin(); it!=AcceptedList.end(); it++) {
		if(*it == ID)
			return true;
	}
	return false;
}

void ResProgram::printRankList() {
	cout<<endl<<"ResProgram: "<<ProgramID<<" RANK LIST"<<endl;

	for(vector<int>::iterator it=RankList.begin(); it!=RankList.end(); it++){
		cout<<*it<<endl;
	}
}

void ResProgram::printAcceptedList() {
	cout<<endl<<"ResProgram: "<<ProgramID<<" ACCEPTED LIST"<<endl;

		for(vector<int>::iterator it=AcceptedList.begin(); it!=AcceptedList.end(); it++){
			cout<<*it<<endl;
		}
}
