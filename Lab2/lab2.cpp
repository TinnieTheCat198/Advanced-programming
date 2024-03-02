#include "lab2.hpp"

List_Of_Students::List_Of_Students(int size = 1000){
    names = new std::string[size];
    scores = new float[size];    
}

void List_Of_Students::insert(std::string name, float score){
    *(names+count) = name;
    *(scores+count) = score;
    ++count;
}

void List_Of_Students::bestStudents(){
    float best = bestScores(scores, count);
    if (best < 0){
        std::cout << "No students found!\n";
        return;
    }

    std::cout << "Best students:\n";
    for(int i = 0; i < count; i++)
    {
        if (scores[i] == best){
            std::cout << names[i] << ' ' << scores[i] << '\n';
        }
    }

}

void List_Of_Students::display(){
    if (count)
    {
        for(int i = 0; i< count; i++)
        {
            std::cout << names[i] << ' ' << scores[i] << '\n';
        }
    }
    else std::cout << "No students found!\n";
}

List_Of_Students::~List_Of_Students(){
    delete [] names;
    delete [] scores;
}

StudentManagementMenu::StudentManagementMenu(){
    while(1){
        std::cout << "--------------------Student Management System--------------------\n" 
                  << "(1) Add new student\n"
                  << "(2) Display the list of all students\n"
                  << "(3) Display the list of all best students\n"
                  << "(0) Exit the program\n\n"
                  << "Choose an option: ";
        int op;
        std::cin >> op;

        cout << "\n";

        switch(op)
        {
        case 1:
        {
            std::cout << "(1) Add new student\n"
                      << "Student's name: ";
            string Name;
            cin.ignore();  
            getline(cin, Name);
             
            cout << "Student's score: ";
            float score;
            cin >> score;

            addStudent(Name, score);
            break;
        }
        case 2:
            std::cout << "(2) Display the list of all students\n";
            display();
            break;
        case 3:
            std::cout << "(3) Display the list of all best students\n";
            displayBestStudents();
            break;
        case 0:
            std::cout << "Exit the program\n";
            exit(1);
            break;
        }
    }
}

void StudentManagementMenu::addStudent(string name, float score){
    list.insert(name, score);
}

void StudentManagementMenu::display(){
    list.display();
}

void StudentManagementMenu::displayBestStudents(){
    list.bestStudents();
}

float bestScores(float *scores, int size){
    if (size == 0)
        return -1;
    float best = scores[0];
    for(int i = 1; i < size; i++){
        if (best < *(scores+i))
            best = *(scores+i);
    }
    return best;  
}

int main(){
    StudentManagementMenu *menu = new StudentManagementMenu();
    delete menu;
    return 0;
}
