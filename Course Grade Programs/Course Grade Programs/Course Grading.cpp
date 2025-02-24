#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

//This program accesses a TXT file, including the name, student ID, and grades. Along with the the number of students and the number of grades each student has. It parses the data and stores the information into an array of structs. It averages the grades
//and compares the average to a grade scale to find the letter grade each student earned. All data gets printed to console. 

//creates a structure for a student including what data needs to be stored.
struct student {

	std::string name;
	int id;
	int* grades;
	float average;
	std::string grade;

};

//prototype of a function that will parse the data from the txt file. precondition is that it takes in the data file, number of students, and number of grades for each student. post conditions is that it returns an array of structures with information.
student* getData(std::ifstream& file, int& studentCnt, int& testsCnt);
//prototype of a function that will calculate the average of each student. pre condition is it takes in a structure along with the number of students and grades and post condition is it supplies the structs with the averages of the student's grades.
void calcAverage(student students[], int studentCnt, int testsCnt);
//prototype of a function that will compare the average to a gradescale to find the letter grade of the student. Pre condition is it takes in the average of the students, and the post condition is it outputs a grade letter as a string.
std::string gradeScale(float gradeAverage);
//prototype of a function that will print everything out. pre condition is it requires a struct with all of the student's data along with the amount of students. the post condition is it runs through each struct's data to print everything out to console.
void print(student students[], int studentCnt);

int main() {
	//accesses the txt.
	std::ifstream data;
	data.open("student with id and grades.txt", std::ios::in);
	
	if (!data) { //checks if the txt was opened

		std::cout << "Improper File Path"; //it will print out to console that something went wrong.

	}

	else {
		//runs through a stream of data to access the first line of the text which contains the number of students, and the number of grades.
		std::string line;
		std::getline(data, line);
		std::istringstream numbers(line);
		
		int numOfStudents;
		numbers >> numOfStudents;

		int numOfGrades;
		numbers >> numOfGrades;
		
		student* studentData = getData(data, numOfStudents, numOfGrades);
		
		calcAverage(studentData, numOfStudents, numOfGrades);

		for (int i = 0; i < numOfStudents; i++) {

			studentData[i].grade = gradeScale(studentData[i].average);

		}

		print(studentData, numOfStudents);

		//std::cout << studentData[1].average;
		delete[] studentData; //no data leaks!

	}

	data.close();
	return 0;


}
//function parses the data from the file and stores into an array of structs stored into heap memory. Returns a pointer to the array of structs in heap memory.
student* getData(std::ifstream& file, int& studentCnt, int& testsCnt) {

		student* students = new student[studentCnt];

		for (int i = 0; i < studentCnt; i++) {

			std::string line; //creates an empty string variable to feed data into for parsing

			std::getline(file, line); //goes through the first line and stores to the string variable.

			std::istringstream namesAndGrades(line);
			
			namesAndGrades >> students[i].name;

			namesAndGrades >> students[i].id;

			students[i].grades = new int[testsCnt];

				for (int j = 0; j < testsCnt; j++) {

					namesAndGrades >> students[i].grades[j];

				}

		}

		return students;

}
//function that calculates the average of each student and stores into the array of structs. 
void calcAverage(student students[], int studentCnt, int testsCnt) {

	for (int i = 0; i < studentCnt; i++) {

		float gradesSum = 0;

		for (int j = 0; j < testsCnt; j++) {

			gradesSum += students[i].grades[j];

		}

		students[i].average = gradesSum / testsCnt;

	}
}
//function that compares the average to a gradescale to assign a letter grade to the student.
std::string gradeScale(float gradeAverage) { 

	std::string gradeLetter; 

	if (gradeAverage >= 90 && gradeAverage < 100) { 
		gradeLetter = "A";
	}
	else if (gradeAverage >= 80 && gradeAverage < 90) {
		gradeLetter = "B";
	}
	else if (gradeAverage >= 70 && gradeAverage < 80) {
		gradeLetter = "C";
	}
	else if (gradeAverage >= 60 && gradeAverage < 70) {
		gradeLetter = "D";
	}
	else {
		gradeLetter = "F";
	}
	return gradeLetter; //returns grade letter.
}
//function that prints everything.
void print(student students[], int studentCnt) {

	std::cout << "Student" << "  " << "ID" << "  " << "Score" << "  " << "Grade" << '\n';

	for (int i = 0; i < studentCnt; i++) {

		std::cout << students[i].name << "  " << students[i].id << "  " << students[i].average << "  " << students[i].grade << '\n';

	}

}