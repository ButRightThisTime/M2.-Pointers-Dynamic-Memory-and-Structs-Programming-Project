// CourseGradeProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Takes a file containing student data expected format:Name Id grade1 grade2 gradeN\n singe space between each item no space at end of line new line for new student
// expected input for file path example . C:\\Users\\b7ers\\Downloads\\StudentGrades.txt
//Stores student data across student class objects and outputs data in a table
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;
/// <summary>
/// Student class
/// </summary>
class student {
public:
    string name;
    int idNum;
    int* tests;
    int numOfTests;
    float average;
    char grade;
};
student* getData(ifstream& file, int& studentCnt, int& testsCnt);
void calcAverage(student students[], int studentCnt, int testsCnt);
char makeLetter(int num);
void displayStudents(student students[],int studentCnt);
void print(int const arr[], int size);
int main()
{
    cout << "enter full path to file with double slashes: "; // (eg. C:\\Users\\b7ers\\Downloads\\StudentGrades.txt)
    string path;
    cin >> path;
    ifstream myf(path);
    if (!myf.is_open()) {
        cout << "Couldn't open that file try running the program again and entering a valid path";
        return(1);
    }
    else {
        int studentCnt = 0;
        int testsCnt = 0;
        student* students = getData(myf, studentCnt, testsCnt);
        cout << endl;
        calcAverage(students, studentCnt, testsCnt);
        displayStudents(students, studentCnt);
        for (int i = 0; i < studentCnt; i++) delete[] students[i].tests;
        delete[] students;
        return(0);
    }
        
        
}
/// <summary>
/// Takes a file containing student data expected format: Name Id grade1 grade2 gradeN\n singe space between each item no space at end of line new line for new student
/// updates reference variables for student count and total test count in file
/// returns a new array of student objects with initialized variables for idNum Name tests and num of tests. "average" and "grade" variables still not set
/// Dont forget to delete arrays for students!!
/// </summary>
/// <param name="file">ifstream to student data</param>
/// <param name="studentCnt">student count variable to be updated expected 0 when called</param>
/// <param name="testsCnt">test count variable to be updated expected 0 when called</param>
/// <returns>returns a new array of student objects with initialized variables for idNum Name tests and num of tests. "average" and "grade" variables still not set</returns>
///
student* getData(ifstream& file, int& studentCnt, int& testsCnt) {
    string line;
    while (getline(file, line)) studentCnt++; // gets student count by counting the lines in the file
    file.clear(); file.seekg(0); // resets flags and puts getline counter back at start of file
    student* students = new student[studentCnt];
    for (int i = 0; i < studentCnt; i++) {
        getline(file, line);
        students[i].name = line.substr(0, line.find(" ")); //set student name to all characters before first space
        line.erase(0, line.find(" ") + 1); // remove name from string including space
        students[i].idNum = stoi(line.substr(0, line.find(" "))); // set student id num to all character before first space
        line.erase(0, line.find(" ") + 1); //remove id num from string including space
        int numOfGrades = count(line.begin(), line.end(), ' ')+1; // gets number of grades by counting spaces
        students[i].numOfTests = numOfGrades;
        students[i].tests = new int[numOfGrades];
        testsCnt += numOfGrades;
        int j = 0;
        while (line.find(" ") != string::npos) { //stores all but final grade in new student tests array
            students[i].tests[j] = stoi(line.substr(0, line.find(" ")));
            line.erase(0, line.find(" ") + 1);
            j++;
        }
        students[i].tests[j] = stoi(line.substr(0, line.find(" "))); // stores final grade
    }
    return  students;
}
/// <summary>
/// Takes a list of student objets, the total num of students, and testsCnt
/// sets average and grade values for student objects in list
/// </summary>
/// <param name="students">list of students that needs average and grade values</param>
/// <param name="studentCnt">total count of students</param>
/// <param name="testsCnt">total count of tests</param>
void calcAverage(student students[], int studentCnt, int testsCnt) {
    for (int i = 0; i < studentCnt; i++) {
        float tempTot = 0.0;
        for (int j = 0; j < students[i].numOfTests; j++) {
            tempTot += students[i].tests[j];
        }
        students[i].average = tempTot / students[i].numOfTests;
        students[i].grade = makeLetter(students[i].average);
    }
}
/// <summary>
/// Takes an int grade and returns corresponding letter grade
/// </summary>
/// <param name="num">integer version of students grade</param>
/// <returns>grade as a character</returns>
char makeLetter(int num) {
    if (num > 89) return'A';
    if (num > 79)  return'B';
    if (num > 69)  return'C';
    if (num > 59) return'D';
    else return 'F';
}
/// <summary>
/// Takes list of students and total number of students
/// Displays student data in a table
/// </summary>
/// <param name="students">list of student objects</param>
/// <param name="studentCnt">total number of student objects in list</param>
void displayStudents(student students[], int studentCnt) {
    cout << left <<setw(12) << "Student" << "\t" << "ID\t" << "Score\t" << "Grade\n";
    for (int i = 0; i < studentCnt; i ++) {
        cout << left << setw(12) << students[i].name << "\t" << students[i].idNum << "\t" << students[i].average << "\t" << students[i].grade;
        cout << endl;
    }
}
/// <summary>
/// displays an array
/// </summary>
/// <param name="arr">array to be displayed</param>
/// <param name="size">size of array to be displayed</param>
void print(int const arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}