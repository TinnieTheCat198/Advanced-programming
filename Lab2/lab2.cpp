#include "lab2.hpp"

void List_Of_Students::insert(std::string name, float score){
    names.push_back(name);
    scores.push_back(score);
}

void List_Of_Students::bestStudents(){
    std::vector<int> index;
    std::vector<float> copy_scores = scores;
    std::sort(copy_scores.begin(), copy_scores.end(), std::greater<float>());
    for(int i = 0; i < scores.size(); i++)
    {
        if (scores[i] == copy_scores[0])
            index.push_back(i);
    }

    if (index.size())
    {
        std::cout << "Best students:\n";
        for(auto i : index)
        {
            std::cout << names[i] << ' ' << scores[i] << '\n';
        }
    }
    else std::cout << "No students found!\n";
}

void List_Of_Students::display(){
    int size = names.size();
    if (size)
    {
        for(int i = 0; i< size; i++)
        {
            std::cout << names[i] << ' ' << scores[i] << '\n';
        }
    }
    else std::cout << "No students found!\n";
}