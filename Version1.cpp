#include <iostream>
using namespace std;

int main()
{
    	//Declare variables and set equal to 0
	float grade, credits, GPA = 0, totalCredits = 0;

    	{
	//Grades and credits
        cout << "Enter credit number for course one.\n";
        cin >> credits;
        totalCredits =totalCredits + credits;

        cout << "Enter grade for course one.\n";
        cin >> grade;
        GPA =GPA+grade*credits;

	cout << "\nEnter credit number for course two.\n";
        cin >> credits;
        totalCredits =totalCredits + credits;

        cout << "\nEnter the grade for course two.\n";
        cin >> grade;
        GPA =GPA+grade*credits;

	cout << "\nEnter the credit number for course three.\n";
        cin >> credits;
        totalCredits =totalCredits + credits;

        cout << "\nEnter the grade for course three\n";
        cin >> grade;
        GPA =GPA+grade*credits;

	cout << "\nEnter the credit number for course four\n";
        cin >> credits;
        totalCredits =totalCredits + credits;

        cout << "\nEnter the grade for course four\n";
        cin >> grade;
        GPA =GPA+grade*credits;
	}

    	GPA /= totalCredits;

   	//Calculating GPA
    	cout << "GPA Is: " << GPA << " / ";
    	
	if(GPA >=0)
        cout << "F";
    	else if(GPA >= 1)
        cout << "D";
    	else if(GPA >= 2)
        cout << "C";
    	else if(GPA >= 3)
        cout << "B";
    	else if(GPA == 4)
        cout << "A\n";
  
	return 0;
}