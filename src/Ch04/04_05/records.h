#pragma once

#include <string>
#include <vector>

class Student{
private:
    int id;
    std::string name;

public:
    Student(int the_id, std::string the_name);
    int get_id() const;
    std::string get_name() const;
};

class Course{
private:
    int id;
    std::string name;
    unsigned char credits;

public:
    Course(int the_id, std::string the_name, unsigned char the_credits);
    int get_id() const;
    std::string get_name() const;
    int get_credits() const;
};

class Grade{
private:
    int student_id;
    int course_id;
    char grade;

public:
    Grade(int sid, int cid, char grd);
    int get_student_id() const;
    int get_course_id() const;
    char get_grade() const;
};

class StudentRecords{
    private:
    std::vector<Student> students;
    std::vector<Course> courses;
    std::vector<Grade> grades;

    public:
    void add_student(int the_id, std::string the_name);
    void add_course(int the_id, std::string the_name, unsigned char the_credits);
    void add_grade(int sid, int cid, char grd);
    std::string get_student_name(int sid) const;
    unsigned char get_course_credits(int cid) const;

    float get_numeric_grade(char letter);
    float calculateGPA(int &the_id);
};
