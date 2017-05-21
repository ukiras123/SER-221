//
//  grading_kgautam1.cpp
//  SER-221
//
//  Created by Kiran Gautam on 5/21/17.
//  Copyright © 2017 Kiran Gautam. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    string instructorName, courseName;
    int noOfAssignments, assignPointsMax, examPointsMax, midPointsMax;
    int weights[3];
    cout << "----------------------------------" << endl;
    cout << "Welcome to our grading calculator!" << endl;
    cout << "----------------------------------" << endl;
    
    // Ask for user input
    cout << "Please provide the grading calculator with some course data." << endl;
    cout << "Instructor name: " << endl;
    cin >> instructorName;
    cout << "Course name: " << endl;
    cin >> courseName;
    cout << "Please enter the number of assignments (1-7): " << endl;
    cin >> noOfAssignments;
    cout << "Points of assignment (1-100): " << endl;
    cin >> assignPointsMax;
    cout << "Points of final exam (1-100): " << endl;
    cin >> examPointsMax;
    cout << "Points of midterm (1-100): " << endl;
    cin >> midPointsMax;
    cout << "Please enter the percentage weight of the assignments: " << endl;
    cin >> weights[0];
    cout << "Please enter the percentage weight of the final exam: " << endl;
    cin >> weights[1];
    cout << "Please enter the percentage weight of the midterm: " << endl;
    cin >> weights[2];
    
    // User Input summary
    cout << "The instructor of the course "+courseName+" is "+instructorName << endl
    << "The course has " << noOfAssignments << " assignments and each assignment has " << assignPointsMax << "points." << endl
    << "The course has one final exam with " << examPointsMax <<" points and one midterm with " << midPointsMax << " points." << endl
    << "The assignment is worth " << weights[0] << "%, the final is worth " << weights[1] << "%, the midterm is worth " << weights[2] << "% of the final grade." << endl;
    return 0;
}


int calcAssignPercent(){
    return 0;
}

int calculateFinalGrade(){
    return 0;
}
