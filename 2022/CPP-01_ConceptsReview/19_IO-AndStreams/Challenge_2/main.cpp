// Section 19
// Challenge 2
// Automated Grader

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

static std::string ruler {"123456789012345678901234567890"};
static int ruler_length = ruler.length();

int calculate_grade (std::string answers, std::string correct_answers) {
    int grade {0};
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i]==correct_answers[i]) {
            grade+=1;
        }
    }
    return grade;
}

int main() {
    // Student vector
    std::vector<std::pair<std::map<std::string, std::string>,int>> student;
    std::string correct_answers;

    std::ifstream infile;
    std::string name;
    std::string answers;

    infile.open("responses.txt");
    if (!infile){
        std::cerr<<"Error opening file"<<std::endl;
        exit(1);
    }

    // get responses
    infile>>correct_answers;

    // Loop through students answers
    while (infile>>name) {
        infile>>answers;
        int grade = calculate_grade(answers, correct_answers);
        student.push_back(std::make_pair(std::map<std::string, std::string>{{name, answers}}, grade));
    }
    
    // Print Ruler
    // std::cout<<ruler<<std::endl;

    std::cout<<std::setw(ruler_length/2)<<std::left<<"Student"
             <<std::setw(ruler_length/2)<<std::right<<"Score"
             <<std::endl;
    std::cout<<std::setw(ruler_length)<<std::setfill('-')<<'-'<<std::endl;    
    
    for (auto name: student) {
        std::cout<<std::setw(ruler_length/2)<<std::left<<std::setfill(' ')<<name.first.begin()->first
                 <<std::setw(ruler_length/2)<<std::right<<name.second<<std::endl;
    }

    std::cout<<std::setw(ruler_length)<<std::setfill('-')<<'-'<<std::endl;

    infile.close();
    return 0;
}

