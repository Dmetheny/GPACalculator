#include <iostream>
#include <fstream>
using namespace std;

// functions
float gpa(const char grade[], const int hours[], int n);
float semester_gpa(const string time[], const char grade[], const int hours[],
		   int n, string * sem);
int D_rule(char grade[], int hours[], int n);
void listing(string name[], string time[], string number[], char grade[],
	     int hours[], int n);
void get_course(string * name, string * time, string * number, char *grade,
		int *hours, int n);
char menu();
bool reading(const char filename[], string name[], string
	     time[], string number[], char grade[], int hours[], int &n,
	     int capacity);
bool writing(const char filename[], const string name[],
	     const string time[], const string number[], const char
	     grade[], const int hours[], int n);

int main()
{
	// Declaring variables
	int credits[10];
	char grade[10];
	int n = 0;
	string courseName[10], courseSem[10], courseId[10];

	// Ask to enter courses manually or read from  a ile
	cout << "Welcome to PFI GPA calculator" << endl;
	int choice;
	while (true) {
		cout <<
		    "Enter 1 to enter courses manually or 2 to read from file: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1 || choice == 2)
			break;
		else
			cout << "Invalid choice. Try again!" << endl;
	}
	// Ask for how many classes
	if (choice == 1) {
		while (true) {
			cout <<
			    "Enter the number of classes for GPA calculation: ";
			cin >> n;
			// Error Checking for valid input
			if (!cin) {
				cout << "BAD INPUT " << endl <<
				    "Sorry, it is fatal, terminating..." <<
				    endl;
				return 0;
			} else if (n <= 0)
				cout <<
				    "The number of class should not be 0 or negative"
				    << endl;
			else if (n > 10)

				cout <<
				    "The number of class should not be more than 10"
				    << endl;
			else
				break;
		}

		cin.ignore();
		
		// Asking user for course name, semester, and ID
		for (int i = 0; i < n; i++) {
			cout << "Enter name for course " << (i + 1) << ": ";
			getline(cin, courseName[i]);
			cout << "Enter course semester " << (i + 1) << ": ";
			getline(cin, courseSem[i]);
			cout << "Enter courseid for course " << (i + 1) << ": ";
			getline(cin, courseId[i]);

			//looping until a valid grade is entered by user
			while (true) {

				cout << "Enter course grade for course " << (i +
									     1)
				    << ": ";
				cin >> grade[i];
				cin.ignore();

				//checking if grade[i] is valid
				if (grade[i] == 'A' || grade[i] == 'B'
				    || grade[i] == 'C' || grade[i] == 'D'
				    || grade[i] == 'F' || grade[i] == 'W'
				    || grade[i] == 'I')
					break;
				else
					cout <<
					    "Invalid grade! Please try again "
					    << endl;
			}

			//looping until a valid credit hours is entered by user
			while (true) {
				cout << "Enter credit hour for course " << (i +
									    1)
				    << ": ";
				cin >> credits[i];
				cin.ignore();

				//checking if credits is valid
				if (credits[i] < 1 || credits[i] > 4)
					cout <<
					    "Invalid credits! Credits should be between 1 and 4 Please try again "
					    << endl;
				else
					break;
			}
		}
	// Asking user for course file
	} else {
		string filename;
		cout <<
		    "Enter the file to read from(Press enter to read from default file): ";
		getline(cin, filename);
		if (filename == "") {
			filename = "courses.txt";
		}

		reading(filename.c_str(), courseName, courseSem, courseId,
			grade, credits, n, 10);
	}
	// Regarding option A
	while (true) {
		char option;
		option = menu();
		if (option == 'A' || option == 'a') {
			float GPA = gpa(grade, credits, n);

			//calculating GPA
			cout << "GPA Is: " << GPA << " / ";

			if (GPA >= 4)
				cout << "A";
			else if (GPA >= 3)
				cout << "B";
			else if (GPA >= 2)
				cout << "C";
			else if (GPA >= 1)
				cout << "D";
			else
				cout << "F";
			cout << endl;
			
		// Regarding option B
		} else if (option == 'B' || option == 'b') {
			listing(courseName, courseSem, courseId, grade, credits,
				n);
		// Regarding option C
		} else if (option == 'C' || option == 'c') {
			cout <<
			    "total credit hours of the courses with grade D: "
			    << D_rule(grade, credits, n) << endl;
		// Regarding option D
		} else if (option == 'D' || option == 'd') {
			string sem;
			float GPA =
			    semester_gpa(courseSem, grade, credits, n, &sem);

			//calculating GPA
			cout << "GPA for " << sem << "is : " << GPA << " / ";

			if (GPA >= 4)
				cout << "A";
			else if (GPA >= 3)
				cout << "B";
			else if (GPA >= 2)
				cout << "C";
			else if (GPA >= 1)
				cout << "D";
			else
				cout << "F";
			cout << endl;
		// Regarding option E
		} else if (option == 'E' || option == 'e') {
			get_course(courseName, courseSem, courseId, grade,
				   credits, n);
			n++;
		// Regarding option F
		} else if (option == 'F' || option == 'f') {
			string courseid, option;
			cout << "Enter course id to delete: ";
			getline(cin, courseid);
			bool found = false;
			// Deleting user selected course
			for (int i = 0; i < n; i++) {
				if (courseId[i] == courseid) {
					found = true;
					cout <<
					    "Are you sure you want to delete below course"
					    << endl;
					cout << "Course Name: " << courseName[i]
					    << endl;
					cout << "Course Semester: " <<
					    courseSem[i] << endl;
					cout << "Course Id: " << courseId[i] <<
					    endl;
					cout << "Course Grade: " << grade[i] <<
					    endl;
					cout << "Credit hours: " << credits[i]
					    << endl;
					cout << "Enter y/n: ";
					getline(cin, option);
					if (option == "y") {
						for (int j = i; j < n - 1; j++) {
							courseName[j] =
							    courseName[j + 1];
							courseSem[j] =
							    courseSem[j + 1];
							courseId[j] =
							    courseId[j + 1];
							grade[j] = grade[j + 1];
							credits[j] =
							    credits[j + 1];
						}
						cout <<
						    "Successfully delete course with course id "
						    << courseid << endl;
						n--;
					}

					break;

				}
			}
			if (!found)
				cout << "course is not in course list" << endl;
		} else if (option == 'q' || option == 'Q')
			break;
		else
			cout << "Invalid option. Try again!" << endl;
	}
	// Writing any new courses added to default file
	string filename;
	cout <<
	    "Writing courses to file (Press Enter to write to default file): ";
	getline(cin, filename);
	if (filename == "")
		filename = "courses.txt";
	writing(filename.c_str(), courseName, courseSem, courseId, grade,
		credits, n);
	return 0;
}

// Menu input function
char menu()
{
	char option;
	do {
		cout << endl;
		cout <<
		    "Welcome to the GPA and Course storage program menu. Please enter the character next to the choice"
		    << endl;
		cout << "you wish to pick. Here are your options:" << endl;
		cout << "A. Compute the GPA of all courses" << endl;
		cout << "B. List all courses" << endl;
		cout <<
		    "C. Compute the total credit hours of the courses with grade D"
		    << endl;
		cout << "D. Compute the GPA for a particular semester" << endl;
		cout << "E. Add another course to the course list." << endl;
		cout << "F. Delete course from the course list." << endl;
		cout << "Q. Quit the program." << endl;
		cout << "Please choose one of the above: ";
		cin >> option;
		cin.ignore();
		cout << endl;
	} while (option != 'A' && option != 'a' && option != 'B'
		 && option != 'b' && option != 'C' && option != 'c'
		 && option != 'D' && option != 'd' && option != 'E'
		 && option != 'e' && option != 'F' && option != 'f'
		 && option != 'Q' && option != 'q');

	return option;
}

// Calculating total gpa function
float gpa(const char grade[], const int hours[], int n)
{
	float GPA = 0, totalCredits = 0, WeightedGrades = 0;
	int temp;

	//looping all the courses
	for (int i = 0; i < n; i++) {

		//skip processing if grade is W or I
		if (grade[i] == 'W' || grade[i] == 'I')
			continue;
		totalCredits = totalCredits + hours[i];
		temp = 4 - (grade[i] - 'A');
		if (temp < 0)
			temp = 0;
		WeightedGrades = WeightedGrades + hours[i] * temp;
		GPA = WeightedGrades / totalCredits;
	}

	return GPA;
}

// List all course function
void listing(string name[], string time[], string number[], char grade[],
	     int hours[], int n)
{
	cout << "\nCurrently there are " << n << " courses in list." << endl;
	for (int i = 0; i < n; i++) {
		cout << "Course Name: " << name[i] << endl;
		cout << "Course Semester: " << time[i] << endl;
		cout << "Course Id: " << number[i] << endl;
		cout << "Course Grade: " << grade[i] << endl;
		cout << "Credit hours: " << hours[i] << endl;
	}
	cout << endl << endl;
}

//Display total credit hours for classes with a D function
int D_rule(char grade[], int hours[], int n)
{
	int totalCredits = 0;
	for (int i = 0; i < n; i++)
		if (grade[i] == 'D')
			totalCredits += hours[i];

	return totalCredits;
}

// Calculating semester gpa function
float semester_gpa(const string time[], const char grade[], const int hours[],
		   int n, string * sem)
{
	float temp;
	float GPA = 0;
	string semester;
	cout << "Enter semester (ex. Fall 2015): ";
	getline(cin, semester);
	*sem = semester;

	while (true) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (*sem == time[i])
				count++;
		}
		if (count == 0)
			cout << "No course was taken in " << *sem << endl;
		else
			break;
	}
	float totalCredits = 0, WeightedGrades = 0;

	//looping all the courses
	for (int i = 0; i < n; i++) {
		if (*sem != time[i])
			continue;

		//skip processing if grade is W or I
		if (grade[i] == 'W' || grade[i] == 'I')
			continue;
		totalCredits = totalCredits + hours[i];
		temp = 4 - (grade[i] - 'A');
		if (temp < 0)
			temp = 0;
		WeightedGrades = WeightedGrades + hours[i] * temp;
		GPA = WeightedGrades / totalCredits;
	}

	return GPA;
}

//Adding a course function
void get_course(string * name, string * time, string * number, char *grade,
		int *hours, int n)
{
	if (n == 10)
		cout << "Cannot add new course. List is full!" << endl;
	else {
		cout << "Enter name for course: ";
		getline(cin, name[n]);
		cout << "Enter course semester: ";
		getline(cin, time[n]);
		cout << "Enter courseid : ";
		getline(cin, number[n]);

		//looping until a valid grade is entered by user
		while (true) {
			cout << "Enter course grade: ";
			cin >> grade[n];
			cin.ignore();

			//checking if grade[n] is valid
			if (grade[n] == 'A' || grade[n] == 'B'
			    || grade[n] == 'C' || grade[n] == 'D'
			    || grade[n] == 'F' || grade[n] == 'W'
			    || grade[n] == 'I')
				break;
			else
				cout << "Invalid grade! Please try again " <<
				    endl;
		}

		//looping until a valid credit hours is entered by user
		while (true) {
			cout << "Enter credit hour for course : ";
			cin >> hours[n];
			cin.ignore();

			//checking if credits is valid
			if (hours[n] < 1 || hours[n] > 4)
				cout <<
				    "Invalid credits! Credits should be between 1 and 4 Please try again "
				    << endl;
			else
				break;
		}
		n++;
	}
}

bool reading(const char filename[], string name[], string
	     time[], string number[], char grade[], int hours[], int &n,
	     int capacity)
{
	// If user enters an incorrect file name
	ifstream file;
	file.open(filename);
	if (file.fail()) {
		cout << "failed to open file named: " << filename << endl;
		return false;
	}
	// Reading input from course file
	file >> n;
	file.ignore();
	string line;
	for (int i = 0; i < n; i++) {
		getline(file, name[i]);
		getline(file, time[i]);
		getline(file, number[i]);
		file >> grade[i];
		file.ignore();
		file >> hours[i];
		file.ignore();
		if (!file) {
			cout << "Read " << i << " courses from file" << endl;
			n = i;
			return false;
		}
	}
	cout << "Read " << n << " courses from file" << endl;
	return true;
}

bool writing(const char filename[], const string name[],
	     const string time[], const string number[], const char
	     grade[], const int hours[], int n)
{
	// Cannot find valid file name
	ofstream file;
	file.open(filename);
	if (file.fail()) {
		cout << "failed to open file named: " << filename << endl;
		return false;
	}
	file << n << endl;
	for (int i = 0; i < n; i++) {
		file << name[i] << endl;
		file << time[i] << endl;
		file << number[i] << endl;
		file << grade[i] << endl;
		file << hours[i] << endl;
	}
	return true;
}