#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Course
{
private:
    string courseCode;
    string courseName;
    int creditHours;

public:
    Course(const string& code, const string& name, int creditHours)
        : courseCode(code), courseName(name), creditHours(creditHours) {}

    string getCourseCode() const
    {
        return courseCode;
    }

    string getCourseName() const
    {
        return courseName;
    }

    int getCreditHours() const
    {
        return creditHours;
    }

    void displayCourseInfo() const
    {
        cout << "Course Code: " << courseCode << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credit Hours: " << creditHours << endl;
    }
};

class Student
{
private:
    string name;
    int age;
    int studentId;
    vector<Course*> enrolledCourses;

public:
    Student(const string& name, int age, int studentId)
        : name(name), age(age), studentId(studentId) {}

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    int getStudentId() const
    {
        return studentId;
    }

    void addCourse(Course* course)
    {
        enrolledCourses.push_back(course);
    }

    void displayDetails() const
    {
        cout << "Student Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentId << endl;

        cout << "Enrolled Courses: " << endl;
        for (const auto& course : enrolledCourses)
        {
            cout << "-------------------------------------" << endl;
            course->displayCourseInfo();
        }
        cout << "-------------------------------------" << endl;
    }
};

class Faculty
{
private:
    string name;
    int age;
    int facultyId;
    string department;
    vector<Course*> coursesTaught;

public:
    Faculty(const string& name, int age, int facultyId, const string& department)
        : name(name), age(age), facultyId(facultyId), department(department) {}

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }

    int getFacultyId() const
    {
        return facultyId;
    }

    void addCourseTaught(Course* course)
    {
        coursesTaught.push_back(course);
    }

    void displayDetails() const
    {
        cout << "Faculty Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Faculty ID: " << facultyId << endl;
        cout << "Department: " << department << endl;

        cout << "Courses Taught: " << endl;
        for (const auto& course : coursesTaught)
        {
            cout << "-------------------------------------" << endl;
            course->displayCourseInfo();
        }
        cout << "-------------------------------------" << endl;
    }
};

class University
{
private:
    vector<Student> students;
    vector<Faculty> faculties;
    vector<Course> courses;

public:
    void addStudent(const string& name, int age, int studentId)
    {
        students.emplace_back(name, age, studentId);
    }

    void addFaculty(const string& name, int age, int facultyId, const string& department)
    {
        faculties.emplace_back(name, age, facultyId, department);
    }

    void addCourse(const string& code, const string& name, int creditHours)
    {
        courses.emplace_back(code, name, creditHours);
    }

    void enrollStudent(int studentId, const string& courseCode)
    {
        Student* student = findStudent(studentId);
        Course* course = findCourse(courseCode);

        if (student && course)
        {
            student->addCourse(course);
            cout << "Course enrolled successfully." << endl;
        }
        else
        {
            cout << "Invalid student ID or course code." << endl;
        }
    }

    void assignCourse(int facultyId, const string& courseCode)
    {
        Faculty* faculty = findFaculty(facultyId);
        Course* course = findCourse(courseCode);

        if (faculty && course)
        {
            faculty->addCourseTaught(course);
            cout << "Course assigned successfully." << endl;
        }
        else
        {
            cout << "Invalid faculty ID or course code." << endl;
        }
    }

    void displayAllDetails() const
    {
        cout << "Student Details:" << endl;
        for (const auto& student : students)
        {
            student.displayDetails();
            cout << endl;
        }

        cout << "Faculty Details:" << endl;
        for (const auto& faculty : faculties)
        {
            faculty.displayDetails();
            cout << endl;
        }
    }

private:
    Student* findStudent(int studentId)
    {
        for (auto& student : students)
        {
            if (student.getStudentId() == studentId)
            {
                return &student;
            }
        }
        return nullptr;
    }

    Faculty* findFaculty(int facultyId)
    {
        for (auto& faculty : faculties)
        {
            if (faculty.getFacultyId() == facultyId)
            {
                return &faculty;
            }
        }
        return nullptr;
    }

    Course* findCourse(const string& courseCode)
    {
        for (auto& course : courses)
        {
            if (course.getCourseCode() == courseCode)
            {
                return &course;
            }
        }
        return nullptr;
    }
};

void displayMenu()
{
    cout << "************ University Management System ************" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Add Faculty" << endl;
    cout << "3. Add Course" << endl;
    cout << "4. Enroll Student in a Course" << endl;
    cout << "5. Assign Course to Faculty" << endl;
    cout << "6. Display All Details" << endl;
    cout << "0. Exit" << endl;
    cout << "******************************************************" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    University university;
    int choice;

    do
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting..." << endl;
            break;
        case 1:
        {
            string name;
            int age, studentId;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter student age: ";
            cin >> age;
            cout << "Enter student ID: ";
            cin >> studentId;

            university.addStudent(name, age, studentId);
            cout << "Student added successfully." << endl;
            break;
        }
        case 2:
        {
            string name, department;
            int age, facultyId;
            cout << "Enter faculty name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter faculty age: ";
            cin >> age;
            cout << "Enter faculty ID: ";
            cin >> facultyId;
            cout << "Enter faculty department: ";
            cin.ignore();
            getline(cin, department);

            university.addFaculty(name, age, facultyId, department);
            cout << "Faculty added successfully." << endl;
            break;
        }
        case 3:
        {
            string code, name;
            int creditHours;
            cout << "Enter course code: ";
            cin.ignore();
            getline(cin, code);
            cout << "Enter course name: ";
            getline(cin, name);
            cout << "Enter credit hours: ";
            cin >> creditHours;

            university.addCourse(code, name, creditHours);
            cout << "Course added successfully." << endl;
            break;
        }
        case 4:
        {
            int studentId;
            string courseCode;
            cout << "Enter student ID: ";
            cin >> studentId;
            cout << "Enter course code: ";
            cin.ignore();
            getline(cin, courseCode);

            university.enrollStudent(studentId, courseCode);
            break;
        }
        case 5:
        {
            int facultyId;
            string courseCode;
            cout << "Enter faculty ID: ";
            cin >> facultyId;
            cout << "Enter course code: ";
            cin.ignore();
            getline(cin, courseCode);

            university.assignCourse(facultyId, courseCode);
            break;
        }
        case 6:
            university.displayAllDetails();
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << endl;
    } while (choice != 0);

    return 0;
}
