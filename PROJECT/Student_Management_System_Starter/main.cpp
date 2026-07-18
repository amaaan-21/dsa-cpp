#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student{
    int id;
    string name;
    string course;
    int marks;
};

// TODO
void addStudent(vector<Student>& students){
    // Implement
}

void displayStudents(const vector<Student>& students){
    // Implement
}

void searchStudent(const vector<Student>& students){
    // Implement
}

void updateMarks(vector<Student>& students){
    // Implement
}

void deleteStudent(vector<Student>& students){
    // Implement
}

void topStudent(const vector<Student>& students){
    // Implement
}

int main(){
    vector<Student> students;
    int choice;

    do{
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Marks\n";
        cout << "5. Delete Student\n";
        cout << "6. Top Student\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch(choice){
            case 1: addStudent(students); break;
            case 2: displayStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: updateMarks(students); break;
            case 5: deleteStudent(students); break;
            case 6: topStudent(students); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    }while(choice != 0);

    return 0;
}
