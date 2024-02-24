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
void input_file(ifstream& studentNames, ofstream& inFile);
double calculate_average(int total_score);
void output_file(double average, int total_grade, ofstream& outFile);

int main() {
    srand(time(0));
    ifstream studentNames;
    ofstream inputFile, outputFile;
    studentNames.open("Students_Names.txt");
    inputFile.open("Students_Results.txt");
    input_file(studentNames, inputFile);
    return 0;
}

int num_quizzes_taken(){
     return rand() % 11;
}

int quiz_score(){
    return rand() % 21;
}

void input_file(ifstream& studentNames, ofstream& inFile){
    int n, score, total_grade = 0;
    double average = 0;
    string name;
    
    for (int i = 0; i < NUM_STUDENTS; i++) {
        getline(studentNames, name);
        n = num_quizzes_taken();
        inFile << name << " ";
        for(int i = 0; i < n; i++){
            score = quiz_score();
            inFile << " " << score;
            total_grade += score;
        }
        output_file(average, total_grade, inFile);
        total_grade = 0;
        inFile << "\n";
    }
}

double calculate_average(int total_score){
    return (double)total_score / (double)TOTAL_QUIZZES;
}

void output_file(double average, int total_score, ofstream& inFile){
    average = calculate_average(total_score);
    inFile << ": " << average;
}
