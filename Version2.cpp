#include <iostream>
using namespace std;

int main()
{
    float credits, GPA = 0, totalCredits = 0, WeightedGrades = 0;
    char grade;
    int temp, n;
    string courseName,courseId;

    //getting the number of grades to process from user
    cout << "Enter number of courses to process: ";
    cin >> n;
    cin.ignore();


    //looping user all the courses
    for(int i = 1 ;i <= n; i++)
    {

        cout << "Enter name for course "<< i << ": ";
        getline(cin,courseName);
        cout << "Enter course id for course " << i <<": ";
        getline(cin,courseId);
        //looping until a valid grade is entered by user
        while(true){
            cout << "Enter grade for course " << i <<": ";
            cin >> grade; cin.ignore();
            //checking if grade is valid 
            //if it is then we break else we ask the user to re-enter
            if(grade == 'A' || grade == 'B'|| grade == 'C'|| grade == 'D'|| grade == 'F'|| grade == 'W'|| grade == 'I')
                break;
            else
                cout << "Invalid grade! Please try again " << endl;
        }

        //looping until a valid credit hours is entered by user
        while(true) {
            cout << "Enter credit hour for course " << i <<": ";
            cin >> credits; cin.ignore();
            //checking if credits is valid
            //if it is then we break else we ask the user to re-enter
            if(credits <1 || credits >10)
                cout << "Invalid credits! Credits should be b/w 1 and 10 Please try again " << endl;
            else
                break;
        }

        //skip processing if grade is W or I
        if(grade == 'W' || grade == 'I') 
            continue;

        totalCredits = totalCredits + credits;
        temp = 4 - (grade - 'A');
        if(temp < 0)
            temp = 0;
        WeightedGrades = WeightedGrades + credits*temp;
    }

    GPA = WeightedGrades / totalCredits;

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
