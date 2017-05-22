//  Program to compute the final grade for a class.
//
//  Compiler Used: Xcode
//  grading_kgautam1.cpp
//  SER-221
//
//  Created by Kiran Gautam on 5/21/17.
//  Copyright © 2017 Kiran Gautam. All rights reserved.
//

#include<iostream>

using namespace std;

double calcAssignPercent(int numberOfAssignments, int assignMaxPoints, int extraPoints);
// Calculates the assignment percentage
double calculateFinalGrade(double assignPerc, double examPerc, double midPerc, int weights[]);
// Calculates the final grade perentage for the given input
string finalGrade(double finalPerc);
// Calculates the final grade for the given percentage


int main(int argc, const char * argv[]) {
    
    string instructorName, courseName, studentName, finalGrd;
    int numberOfAssignments, assignPointsMax, examPointsMax, midPointsMax, examPoints, midPoints, extraPoints;
    double midPerc, examPerc, assignPerc, finalPerc;
    int weights[3];  // 0,1,2 -> assignment, final, midterm
    
    bool valid = true;
    
    cout << "----------------------------------" << endl;
    cout << "Welcome to our grading calculator!" << endl;
    cout << "----------------------------------" << endl;
    
    // Ask for user input
    cout << "Please provide the grading calculator with some course data." << endl;
    
    // Course Info
    cout << "Instructor name: ";
    getline(cin, instructorName);
    cout << "Course name: ";
    getline(cin, courseName);
    
    do{
        valid = true;
        cout << "Please enter the number of assignments (1-7): " << flush;
        cin >> numberOfAssignments;
        if (numberOfAssignments < 1 || numberOfAssignments > 7 || cin.fail()) {
            valid = false;
            // reset the buffer and empty it
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while(!valid);
    
    
    do{
        valid = true;
        cout << "Points of assignment (10-100): " << flush;
        cin >> assignPointsMax;
        if (assignPointsMax < 10 || assignPointsMax > 100 || cin.fail()) {
            valid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while(!valid);
    
    
    do{
        valid = true;
        cout << "Points of final exam (10-100): ";
        cin >> examPointsMax;
        if (examPointsMax < 10 || examPointsMax > 100 || cin.fail()) {
            valid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while(!valid);
    
    do{
        valid = true;
        cout << "Points of midterm (10-100): ";
        cin >> midPointsMax;
        if (midPointsMax < 10 || midPointsMax > 100 || cin.fail()) {
            valid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while(!valid);
    
    
    do{
        cout << "Please enter the percentage weight of the assignments: ";
        cin >> weights[0];
        
        cout << "Please enter the percentage weight of the final exam: ";
        cin >> weights[1];
        
        cout << "Please enter the percentage weight of the midterm: ";
        cin >> weights[2];
        if (weights[0]+weights[1]+weights[2] != 100) {
            cout << "All the percentage weight should total 100%. Try Again! \n";
        }
    }while (weights[0]+weights[1]+weights[2] != 100);
    
    
    // Print user input course summary
    cout << "\nThe instructor of the course "+courseName+" is "+instructorName+"."<< endl
    << "The course has " << numberOfAssignments << " assignments and each assignment has " << assignPointsMax << " points." << endl
    << "The course has one final exam with " << examPointsMax <<" points and one midterm with " << midPointsMax << " points." << endl
    << "The assignment is worth " << weights[0] << "%, the final is worth " << weights[1] << "%, the midterm is worth " << weights[2] << "% of the final grade.\n" << endl;
    
    // Get Student Info
    cin.get();
    cout << "Student name: ";
    getline(cin, studentName);
    
    do{
        valid = true;
        cout << "Please enter the points the student received for the final exam: ";
        cin >> examPoints;
        if (cin.fail() || (examPoints > examPointsMax)) {
            valid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while(!valid);
    
    do{
        valid = true;
        cout << "Please enter the points the student received for the midterm: ";
        cin >> midPoints;
        if (cin.fail() || (midPoints > midPointsMax)) {
            valid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while(!valid);
    
    
    do{
        valid = true;
        cout << "Please enter the points the student received for the midterm: ";
        cin >> extraPoints;
        if (cin.fail() || extraPoints < 1 || extraPoints > 200) {
            valid = false;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }while(!valid);
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    midPerc = (double) midPoints / (double) midPointsMax * 100.00 ;
    examPerc = (double) examPoints / (double) examPointsMax * 100.00 ;
    
    cout << "\nThe student " << studentName << " received " << midPoints << " points in midterm, " << examPoints
    <<" points in final exam and " << extraPoints<< " points for extra credit.\n"
    <<"The student received " << examPerc << "% in the final exam and " << midPerc
    << "% in the midterm\n\n";
    
    
    assignPerc = calcAssignPercent(numberOfAssignments,assignPointsMax,examPointsMax);
    cout << "The student " << studentName <<" received " << assignPerc << "% in the assignments" << endl <<endl;
    
    finalPerc = calculateFinalGrade(assignPerc,examPerc, midPerc, weights);
    cout << "The student " << studentName << " received " << finalPerc << "% in " << courseName << endl;
    
    finalGrd = finalGrade(finalPerc);
    cout << "This leads to an " << finalGrd << " in this course." << endl;
    
    return 0;
}



double calcAssignPercent(int numberOfAssignments, int assignMaxPoints, int extraPoints){
    
    double eachAssignPoints[numberOfAssignments];
    double totalAssignedPoints = 0.0;
    
    double assignPerc;
    for (int i =0;i<numberOfAssignments;i++){
        cout << "Please enter the points the student received for assignment "<< i+1 <<":" << endl;
        cin >> eachAssignPoints[i];
        totalAssignedPoints+=eachAssignPoints[i];
    }
    
    assignPerc = (totalAssignedPoints + extraPoints)/(assignMaxPoints * numberOfAssignments) * 100;
    return assignPerc;
}

double calculateFinalGrade(double assignPerc, double examPerc, double midPerc, int weights[]){
    double finalPerc;
    finalPerc = (assignPerc * weights[0] + examPerc * weights[1] + midPerc * weights[2])/100.00;
    return finalPerc;
}


string finalGrade(double finalPerc){
    if(finalPerc >= 97) {
        return "A+";
    } else if (finalPerc >=94){
        return "A";
    } else if (finalPerc >=90){
        return "A-";
    } else if (finalPerc >=87){
        return "B+";
    } else if (finalPerc >=84){
        return "B";
    } else if (finalPerc >=80){
        return "B-";
    } else if (finalPerc >=77){
        return "C+";
    } else if (finalPerc >=70){
        return "C";
    } else if (finalPerc >=60){
        return "D";
    } else if (finalPerc < 60){
        return "E/F";
    } else {
        return "Invalid Grade!!";
    }
    
}








