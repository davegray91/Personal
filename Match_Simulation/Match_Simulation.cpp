//============================================================================
// Name        : Match_Simulation.cpp
// Author      : David Grayson
// Version     : 1.0
// Description : Simulates the USMLE Match algorithm and provides statistical analysis
//============================================================================

#include <iostream>
#include "Applicant.h"
#include "ResProgram.h"
using namespace std;

void updateAssignments(int, int);
int numApplicants = 6; //define number of applicants
int numRes = 2; //define number of residence programs
int numPositions = 2; //2 positions per program
Applicant * Applicants = new Applicant[numApplicants]; //create pointer to array of applicants
ResProgram * ResPrograms = new ResProgram[numRes]; //create pointer to array of resicence programs

int main() {

	//TODO initialize applicant and ResProgram data

	for(int i=0; i<numApplicants; i++){
		Applicants[i].setID(i+1); //assign IDs to each applicant (1 to numApplicants)
		Applicants[i].initRankList(numRes); //initialize each applicant's rank list
	}

	for(int i=0; i<numRes; i++){
		ResPrograms[i].setID(i+1); //assign IDs to each program (1 to numRes)
		ResPrograms[i].setNumPositions(numPositions); //each program has 2 positions for now //TODO give each program random numPositions
		ResPrograms[i].initRankList(numApplicants); //initialize each applicant's rank list
	}

	for(int i=0; i<numRes; i++){
		ResPrograms[i].printRankList();
	}

	for(int i=0; i<numApplicants; i++){
		Applicants[i].printRankList();
	}

	//TODO implement Match Algorithm
	//iterate over applicants
	//look at top program on app rank list
	//check if programs accept list is full
	//add if not full
	//if full, check rank list (from last to first) and compare with accepted list and current applicant
	//if applicant comes up first, do nothing and move on
	//if accepted list member comes up first, erase it from list and push back current applicant
	//if applicant was not placed, repeat with 2nd program, 3rd, ...
	//end when complete cycle and nothing changes

	bool changed = true;

	while(changed == true){
		changed = false;

		for(int i=0; i<numApplicants; i++){
			for(int k=0; k<numRes; k++){
				int tempResID = Applicants[i].getRank(k);

				if(Applicants[i].getAssignment() == tempResID){
					break;
				}
				else if(!ResPrograms[tempResID-1].isfull()){
					ResPrograms[tempResID-1].updateAcceptedList(Applicants[i].getID(), 0);
					updateAssignments(Applicants[i].getID(), tempResID);
					changed = true;
					break;
				}
				else if(ResPrograms[tempResID-1].scanRankList(Applicants[i].getID())){
					updateAssignments(Applicants[i].getID(), tempResID);
					changed = true;
					break;
				}
			}
		}
	}

	for(int i=0; i<numRes; i++){
		ResPrograms[i].printAcceptedList();
	}

	for(int i=0; i<numApplicants; i++){
		Applicants[i].printAssignment();
	}

	//TODO export data

	char quit;
	cout<<endl<<"Press any key to exit"<<endl;
	cin>>quit;
	return 0;
}

void updateAssignments(int AppID, int ResID) {
	int oldResID = Applicants[AppID-1].getAssignment();
	if(oldResID!=0)
		ResPrograms[oldResID-1].removeApplicant(AppID); //remove AppID from previous assignment
	Applicants[AppID-1].setAssignment(ResID); //update assignment for AppID

	for(int i=0; i<numApplicants; i++){
		if(Applicants[i].getAssignment()==ResID){
			if(!ResPrograms[ResID-1].isAccepted(Applicants[i].getID())){
				Applicants[i].setAssignment(0); //clear assignment if not on accepted list
			}
		}
	}
}
