#include <iostream>

struct Name {
    std::string fname;
    std::string lname;
};

struct Student {
    Name name;
    unsigned long long sNum;
    std::string major;
};

struct Id {
    std::pair<std::string, std::string> name;
    unsigned long long sNum;
    std::string major;
};

Student createStudent(Name, Student);
Id createId(Name, Student);

int main(int, char**){
    Name sName {"Ethan", "Levesque"};
    Student s1 {sName, 2692340, "Computer Science"};

    createStudent(sName, s1);
}

Student createStudent(Name name, Student s1) {
    std::cout << s1.name.fname << " " << s1.name.lname << " " << s1.sNum << " " << s1.major << std::endl;
    return s1;
}