#include "records.h"


Student::Student(int the_id, std::string the_name){
    id = the_id;
    name = the_name;
}
int Student::get_id() const{
    return id;
}
std::string Student::get_name() const{
    return name;
}

Course::Course(int the_id, std::string the_name, unsigned char the_credits){
    id = the_id;
    name = the_name;
    credits = the_credits;
}
int Course::get_id() const{
    return id;
}
std::string Course::get_name() const{
    return name;
}
int Course::get_credits() const{
    return credits;
}

Grade::Grade(int sid, int cid, char grd){
    student_id = sid;
    course_id = cid;
    grade = grd;
}
int Grade::get_student_id() const{
    return student_id;
}
int Grade::get_course_id() const{
    return course_id;
}
char Grade::get_grade() const{
    return grade;
}

float StudentRecords::get_numeric_grade(char letter)
{
    float numericGrade = 0.0f;

    switch(letter)
    {
        case 'A':
            numericGrade = 4.0f; break;
        case 'B':
            numericGrade = 3.0f; break;
        case 'C':
            numericGrade = 2.0f; break;
        case 'D':
            numericGrade = 1.0f; break;
        default:
            numericGrade = 0.0f; break;
    }

    return numericGrade;
}

void StudentRecords::add_student(int the_id, std::string the_name)
{
    students.push_back(Student(the_id, the_name));
}

void StudentRecords::add_course(int the_id, std::string the_name, unsigned char the_credits)
{
    courses.push_back(Course(the_id, the_name, the_credits));
}

void StudentRecords::add_grade(int sid, int cid, char grd)
{
    grades.push_back(Grade(sid, cid, grd));
}

float StudentRecords::calculateGPA(int &the_id)
{
    float credits = 0.0f;
    float points = 0.0f;
    float totalCredits = 0.0f;

    for(auto grade : grades)
    {
        if(grade.get_student_id() == the_id)
            {
                credits = courses[grade.get_course_id() - 1].get_credits();
                points += get_numeric_grade(grade.get_grade()) * credits; 
                totalCredits += credits;         
            }
    }

    return points/totalCredits;
}

std::string StudentRecords::get_student_name(int sid) const{
    int i = 0;
    while (i < students.size() && students[i].get_id() != sid)
        i++;
    return students[i].get_name();
}

unsigned char StudentRecords::get_course_credits(int cid) const{
    int j = 0;
    while (j < courses.size() && courses[j].get_id() != cid)
        j++;
    return courses[j].get_credits();
}