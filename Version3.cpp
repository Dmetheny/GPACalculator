#include <iostream>
using namespace std;

int main()
{
    float credits[10];
    char grade[10];
    int temp, n = 0;
    string courseName[10],courseSem[10],courseId[10];
    cout <<"Welcome to PFI GPA calculator"<<endl;
    while(true)
    {
        cout<<"Enter the number of classes for GPA calculation: ";
        cin >> n;
        if(!cin){
            cout << "BAD INPUT " << endl << "Sorry, it is fatal, terminating..."<<endl;
            return 0;
        }
        else if(n<=0)
            cout<<"The number of class should not be 0 or negative"<<endl;
        else if(n>10)

            cout<<"The number of class should not be more than 10"<<endl;
        else
            break;
    }

    cin.ignore();

    for(int i=0;i<n;i++){
        cout << "Enter name for course "<<(i+1)<<": ";
        getline(cin,courseName[i]);
        cout << "Enter course semester "<<(i+1)<<": ";
        getline(cin,courseSem[i]);
        cout << "Enter courseid for course "<<(i+1)<<": ";
        getline(cin,courseId[i]);

        //looping until a valid grade is entered by user
        while(true){


            cout << "Enter course grade for course "<<(i+1)<<": ";
            cin >> grade[i]; cin.ignore();

            //checking if grade[i] is valid
            if(grade[i] == 'A' || grade[i] == 'B'|| grade[i] == 'C'|| grade[i] 	== 'D'|| grade[i] == 'F'|| grade[i] == 'W'|| grade[i] == 'I')
                break;
            else
                cout << "Invalid grade! Please try again " << endl;
        }

        //looping until a valid credit hours is entered by user
        while(true) {
            cout << "Enter credit hour for course "<<(i+1)<<": ";
            cin >> credits[i]; cin.ignore();

            //checking if credits is valid
            if(credits[i] <1 || credits[i] >4)
                cout << "Invalid credits! Credits should be between 1 and 4 Please try again " << endl;
            else
                break;
        }
    }
    while(true)
    {
        cout << endl;
        cout << "Welcome to the GPA and Course storage program menu. Please enter the character next to the choice" <<endl;
        cout << "you wish to pick. Here are your options:" <<endl;
        cout << "A. Compute the GPA of all courses" <<endl;
        cout << "B. List all courses" <<endl;
        cout << "C. Compute the total credit hours of the courses with grade D" <<endl;
        cout << "D. Compute the GPA for a particular semester" <<endl;
        cout << "E. Add another course to the course list." <<endl;
        cout << "Q. Quit the program." <<endl;
        cout << "Please choose one of the above: ";
        string option;
        cin >> option; cin.ignore();
        cout << endl;
        if(option == "A" || option == "a")
        {

            float GPA = 0, totalCredits = 0, WeightedGrades = 0;
            //looping all the courses
            for(int i = 0 ;i < n; i++)
            {

                //skip processing if grade is W or I
                if(grade[i] == 'W' || grade[i] == 'I') 
                    continue;
                totalCredits = totalCredits + credits[i];
                temp = 4 - (grade[i] - 'A');
                if(temp < 0)
                    temp = 0;
                WeightedGrades = WeightedGrades + credits[i]*temp;
                GPA = WeightedGrades / totalCredits;
            }

            //calculating GPA
            cout << "GPA Is: " << GPA << " / ";


            if(GPA >= 4)
                cout << "A";
            else if(GPA >= 3)
                cout << "B";
            else if(GPA >= 2)
                cout << "C";
            else if(GPA >= 1)
                cout << "D";
            else
                cout << "F";
            cout << endl;
        }
        else if(option == "B" || option == "b" )
        {
            cout << "Currently there are " << n << " courses in list."<<endl;
            for(int i = 0 ;i < n; i++)
            {
                cout << "Course Name: " << courseName[i] << endl;
                cout << "Course Semester: " << courseSem[i] << endl;
                cout << "Course Id: " << courseId[i] << endl;
                cout << "Course Grade: " << grade[i] << endl;
                cout << "Credit hours: " << credits[i] << endl;
            }

        }
        else if(option == "C" || option == "c" )
        {
            float totalCredits  = 0;
            for(int i = 0 ;i < n; i++)
                if(grade[i] == 'D')
                    totalCredits += credits[i];

            cout << "total credit hours of the courses with grade D: " << totalCredits << endl;

        }
        else if(option == "D" || option == "d" )
        {
            string sem;
            while(true)
            {
                cout << "Enter semester (ex. Fall 2015): ";
                getline(cin,sem);
                int count =0;
                for(int i = 0 ;i < n; i++)
                {
                    if(sem == courseSem[i]) 
                        count++;
                }
                if(count == 0)
                {
                    cout << "No course was taken in " << sem << endl;
                }
                else
                    break;
            }

            float GPA = 0, totalCredits = 0, WeightedGrades = 0;
            //looping all the courses
            for(int i = 0 ;i < n; i++)
            {
                if(sem != courseSem[i]) 
                    continue;

                //skip processing if grade is W or I
                if(grade[i] == 'W' || grade[i] == 'I') 
                    continue;
                totalCredits = totalCredits + credits[i];
                temp = 4 - (grade[i] - 'A');
                if(temp < 0)
                    temp = 0;
                WeightedGrades = WeightedGrades + credits[i]*temp;
                GPA = WeightedGrades / totalCredits;
            }

            //calculating GPA
            cout << "GPA for "<< sem << "is : " << GPA << " / ";

            if(GPA >= 4)
                cout << "A";
            else if(GPA >= 3)
                cout << "B";
            else if(GPA >= 2)
                cout << "C";
            else if(GPA >= 1)
                cout << "D";
            else
                cout << "F";
            cout << endl;
        }
        else if(option == "E" || option == "e")
        {

            if(n==10)
                cout << "Cannot add new course. List is full!"<<endl;
            else
            {
                cout << "Enter name for course: ";
                getline(cin,courseName[n]);
                cout << "Enter course semester: ";
                getline(cin,courseSem[n]);
                cout << "Enter courseid : ";
                getline(cin,courseId[n]);

                //looping until a valid grade is entered by user
                while(true){


                    cout << "Enter course grade: ";
                    cin >> grade[n]; cin.ignore();

                    //checking if grade[n] is valid
                    if(grade[n] == 'A' || grade[n] == 'B'|| grade[n] == 'C'|| grade[n] 	== 'D'|| grade[n] == 'F'|| grade[n] == 'W'|| grade[n] == 'I')
                        break;
                    else
                        cout << "Invalid grade! Please try again " << endl;
                }

                //looping until a valid credit hours is entered by user
                while(true) {
                    cout << "Enter credit hour for course : ";
                    cin >> credits[n]; cin.ignore();

                    //checking if credits is valid
                    if(credits[n] <1 || credits[n] >4)
                        cout << "Invalid credits! Credits should be between 1 and 4 Please try again " << endl;
                    else
                        break;
                }
                n++;
            }
        }
        else if(option == "q" || option == "Q")
            break;
        else
            cout << "Invalid option. Try again!" << endl;
    }
    return 0;
}
