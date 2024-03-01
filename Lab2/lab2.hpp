#ifndef MY_HEADER_H
#define MY_HEADER_H

#include<bits/stdc++.h>

class List_Of_Students {
private:
    std::vector<std::string> names;
    std::vector<float> scores;
public:
    void insert(std::string, float);
    void bestStudents();
    void display();
};

class StudentManagementMenu {
private:
    List_Of_Students list;
public:
    StudentManagementMenu();
    void addStudent(std::string, float);
    void display();
    void displayBestStudents();
};

#endif // MY_HEADER_H