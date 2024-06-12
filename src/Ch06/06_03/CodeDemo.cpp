// Learning C++ 
// Challenge 06_03
// Upgrade to work with files, by Eduardo Corpeño 

#include <iostream>
#include <vector>
#include "records.h"

void initialize(StudentRecords&);
void Retrieve_StudentInfo(StudentRecords&);
void Retrieve_Courses(StudentRecords&);
void Retrieve_Grades(StudentRecords&);

int main(){
    int id;
    StudentRecords SR;
    
    initialize(SR);

    std::cout << "Enter a student ID: " << std::flush;
    std::cin >> id;

    SR.Generate_records();
    
    std::cout << std::endl << std::endl;
    return (0);
}

void initialize(StudentRecords& srec){
 
    Retrieve_StudentInfo(srec);
    Retrieve_Courses(srec);
    Retrieve_Grades(srec);
}

void Retrieve_StudentInfo(StudentRecords& srec)
{
    std::ifstream inFile;
    int sid;
    std::string studentName;
    std::string line;
    
    inFile.open("students.txt");

    if(inFile.fail())
        std::cout << "File not found! " << std::endl;
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, line);
            sid = stoi(line);
            getline(inFile, studentName);
            srec.add_student(sid, studentName);
        }

        inFile.close();
    }
}

void Retrieve_Courses(StudentRecords& srec)
{
    std::ifstream inFile;
    int cid;
    std::string courseName;
    std::string line;
    unsigned char credits;
    
    inFile.open("courses.txt");

    if(inFile.fail())
        std::cout << "File not found! " << std::endl;
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, line);
            cid = stoi(line);
            getline(inFile, courseName);
            getline(inFile, line);
            credits = line[0];
            srec.add_course(cid, courseName, credits);
        }
        inFile.close();
    }
}

void Retrieve_Grades(StudentRecords& srec)
{
    std::ifstream inFile;
    int sid, cid;
    std::string line;
    char grade;
    
    inFile.open("grades.txt");

    if(inFile.fail())
        std::cout << "File not found! " << std::endl;
    else
    {
        while(!inFile.eof())
        {
            getline(inFile, line);
            sid = stoi(line);
            getline(inFile, line);
            cid = stoi(line);
            getline(inFile, line);
            grade = line[0];
            
            srec.add_grade(sid, cid, grade);
        }

        inFile.close();
    }
}