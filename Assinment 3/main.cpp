/*
 COP3014: Programmming II
 Assignment 3 - creating a program that randomly generates random score up between 1-20 for up to 10 quizzes,this is the imput file. Then the program calculates the average and adds it to the output file.
 Duha Iqbal
 02/23/2024
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_STUDENTS = 10; // used to set the for loop
const int TOTAL_QUIZZES = 10; // used to divide the total score of the quizzes by 10

int num_quizzes_taken();
//generates a random int between 0 and 10 for the number of quizzes taken by each student

int quiz_score();
//generates a random integer between 1 and 20 for the score of each quiz

void input_file(ifstream& studentNames, ofstream& inFile, int& total_score);
//creates the input file by taking the students names and then adding their scores to the names in the file

double calculate_average(int& total_score);
//calculates the average score of the quizzes

void output_file(double average, int& total_grade, ofstream& outFile);
//add the calculated average to the input file, creating the output file

int main() {
    srand((int)time(NULL));//sets the starting point to time for producing pseudo-random integers
    int total_grade = 0;
    double average = 0;
    ifstream studentNames;
    ofstream inputFile, outputFile;
    studentNames.open("Students_Names.txt");
    inputFile.open("Students_Results.txt");
    for (int i = 0; i < NUM_STUDENTS; i++) {
        input_file(studentNames, inputFile, total_grade);
        output_file(average, total_grade, inputFile);
        total_grade = 0;//resets total grade to 0 for the next student calculation
        inputFile << "\n";
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
    getline(studentNames, name);//reads the name from the list of student names file
    n = num_quizzes_taken();// number of quizzes taken for each student
    inFile << name; // prints the student name in the input file
    for(int i = 0; i < n; i++){
        score = quiz_score(); // generates scores for each quiz taken
        inFile << " " << score; // prints the score for each quiz taken in the input file
        total_score += score; // adds each score to the total score
    }
}

double calculate_average(int& total_score){
    return (double)total_score / (double)TOTAL_QUIZZES;
}

void output_file(double average, int& total_score, ofstream& inFile){
    average = calculate_average(total_score);//calculates the average
    inFile << ": " << average;//prints the average score to the output file
}

