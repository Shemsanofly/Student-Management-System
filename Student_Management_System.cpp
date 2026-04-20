#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure
struct Student {
    string name;
    int age;
    float grade;
};

// Function Prototypes
bool login();
void menu();
void addStudent(vector<Student>& students);
void displayStudents(const vector<Student>& students);
void calculateAverage(const vector<Student>& students);
void searchStudent(const vector<Student>& students);
void updateStudent(vector<Student>& students);
void deleteStudent(vector<Student>& students);
void displayUsingPointers(const vector<Student>& students);
int getValidInt();
float getValidFloat();


// ?? LOGIN SYSTEM
bool login() {
    const string ADMIN_USER = "admin";
    const string ADMIN_PASS = "1234";

    string username, password;
    int attempts = 3;

    while (attempts > 0) {
        cout << "\n===== ADMIN LOGIN =====\n";

        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;

        if (username == ADMIN_USER && password == ADMIN_PASS) {
            cout << "\n? Login successful!\n";
            return true;
        } else {
            attempts--;
            cout << "? Invalid credentials. Attempts left: " << attempts << endl;
        }
    }

    cout << "\n?? Too many failed attempts. Access denied.\n";
    return false;
}


// Add Student
void addStudent(vector<Student>& students) {
    Student s;

    cin.ignore(1000, '\n');

    cout << "Enter Name: ";
    getline(cin, s.name);

    cout << "Enter Age: ";
    s.age = getValidInt();

    cout << "Enter Grade: ";
    s.grade = getValidFloat();

    students.push_back(s);

    cout << "? Student added successfully!\n";
}


// Display Students
void displayStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << i + 1 << ". "
             << "Name: " << students[i].name
             << " | Age: " << students[i].age
             << " | Grade: " << students[i].grade << endl;
    }
}


// Average Grade
void calculateAverage(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No data available.\n";
        return;
    }

    float total = 0;
    for (size_t i = 0; i < students.size(); i++) {
        total += students[i].grade;
    }

    cout << "Average Grade: "
         << fixed << setprecision(2)
         << total / students.size() << endl;
}


// Search Student
void searchStudent(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    cin.ignore(1000, '\n');

    string name;
    cout << "Enter name to search: ";
    getline(cin, name);

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            cout << "Found: " << students[i].name
                 << " | Age: " << students[i].age
                 << " | Grade: " << students[i].grade << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}


// Update Student
void updateStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    cin.ignore(1000, '\n');

    string name;
    cout << "Enter name to update: ";
    getline(cin, name);

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            cout << "Enter new age: ";
            students[i].age = getValidInt();

            cout << "Enter new grade: ";
            students[i].grade = getValidFloat();

            cout << "? Updated successfully!\n";
            return;
        }
    }

    cout << "Student not found.\n";
}


// Delete Student
void deleteStudent(vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    cin.ignore(1000, '\n');

    string name;
    cout << "Enter name to delete: ";
    getline(cin, name);

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            students.erase(students.begin() + i);
            cout << "??? Student deleted.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}


// Pointer Display
void displayUsingPointers(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    const Student* ptr = &students[0];

    cout << "\n--- Using Pointers ---\n";
    for (size_t i = 0; i < students.size(); i++) {
        cout << (ptr + i)->name << " | "
             << (ptr + i)->age << " | "
             << (ptr + i)->grade << endl;
    }
}


// Input Validation
int getValidInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a number: ";
    }
    return value;
}

float getValidFloat() {
    float value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a valid grade: ";
    }
    return value;
}


// Menu
void menu() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Average Grade\n";
        cout << "4. Search Student\n";
        cout << "5. Update Student\n";
        cout << "6. Delete Student\n";
        cout << "7. Display (Pointers)\n";
        cout << "8. Exit\n";
        cout << "Choose: ";

        choice = getValidInt();

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: displayStudents(students); break;
            case 3: calculateAverage(students); break;
            case 4: searchStudent(students); break;
            case 5: updateStudent(students); break;
            case 6: deleteStudent(students); break;
            case 7: displayUsingPointers(students); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 8);
}


// MAIN
int main() {
    if (login()) {
        menu(); 
    }
    return 0;
}
