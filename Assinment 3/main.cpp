/*
 COP3014: Programmming II
 Assignment 3 - Creating a loan calculator, which calculates the monthly payments and interest of a loan, using user-defiend and library functions
 Duha Iqbal
 02/09/2024
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int NUM_STUDENTS = 10;
const int TOTAL_QUIZZES = 10;

int num_quizzes_taken();
int quiz_score();
void input_file(ifstream& studentNames, ofstream& inFile, int& total_score);
double calculate_average(int& total_score);
void output_file(double average, int& total_grade, ofstream& outFile);

int main() {
    srand((int)time(NULL));
    int total_grade = 0;
    double average = 0;
    ifstream studentNames;
    ofstream inputFile, outputFile;
    studentNames.open("Students_Names.txt");
    inputFile.open("Students_Results.txt");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        input_file(studentNames, inputFile, total_grade);
        output_file(average, total_grade, inputFile);
        total_grade = 0;
        inputFile << "\n";
        cout << "\n";
    }
    return 0;
}

int num_quizzes_taken(){
     return rand() % 11;
}

int quiz_score(){
    return rand() % 21;
}

void input_file(ifstream& studentNames, ofstream& inFile, int& total_score){
    int n, score;
    string name;
    getline(studentNames, name);
    n = num_quizzes_taken();
    inFile << name << " ";
    for(int i = 0; i < n; i++){
        score = quiz_score();
        inFile << " " << score;
        total_score += score;
    }
}

double calculate_average(int& total_score){
    return (double)total_score / (double)TOTAL_QUIZZES;
}

void output_file(double average, int& total_score, ofstream& inFile){
    average = calculate_average(total_score);
    inFile << ": " << average;
}

