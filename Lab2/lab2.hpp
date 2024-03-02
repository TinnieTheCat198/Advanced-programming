#ifndef MY_HEADER_H
#define MY_HEADER_H

#include<bits/stdc++.h>
using namespace std;

class List_Of_Students {
private:
    std::string* names;
    float* scores;
    int count = 0;
public:
    List_Of_Students(int);
    void insert(std::string, float);
    void bestStudents();
    void display();
    ~List_Of_Students();
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

float bestScores(float *, int);

#endif // MY_HEADER_H