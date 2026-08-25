#include <iostream>
using namespace std;

class Teacher {
private:
    string Name;
    int Age;
    string Institute;

public:
    void setName(string name){ 
		Name = name; 
	}
    string getName(){ 
		return Name; 
	}

    void setAge(int age){ 
		Age = age; 
	}
    int getAge(){ 
		return Age; 
	}

    void setInstitute(string institute){ 
		Institute = institute; 
	}
    string getInstitute(){ 
		return Institute; 
	}
};

class HumanitiesTeacher : public Teacher{
private:
    string Department = "Humanities";
    string CourseName;
    string Designation;

public:
    void setCourseName(string course) { CourseName = course; }
    string getCourseName() { return CourseName; }

    void setDesignation(string designation) { Designation = designation; }
    string getDesignation() { return Designation; }

    string getDepartment() { return Department; }
};

class ScienceTeacher : public Teacher{
private:
    string Department = "Science";
    string CourseName;
    string Designation;

public:
    void setCourseName(string course) { CourseName = course; }
    string getCourseName() { return CourseName; }

    void setDesignation(string designation) { Designation = designation; }
    string getDesignation() { return Designation; }

    string getDepartment() { return Department; }
};

class MathsTeacher : public Teacher{
private:
    string Department = "Maths";
    string CourseName;
    string Designation;

public:
    void setCourseName(string course) { CourseName = course; }
    string getCourseName() { return CourseName; }

    void setDesignation(string designation) { Designation = designation; }
    string getDesignation() { return Designation; }

    string getDepartment() { return Department; }
};

int main(void) {
    HumanitiesTeacher h;
    ScienceTeacher s;
    MathsTeacher m;

    string name, institute, course, designation;
    int age;

    cout << "Enter Humanities Teacher Details:\n";
    cout << "Name: "; cin >> ws; getline(cin, name); h.setName(name);
    cout << "Age: "; cin >> age; h.setAge(age);
    cout << "Institute: "; cin >> ws; getline(cin, institute); h.setInstitute(institute);
    cout << "Course Name: "; getline(cin, course); h.setCourseName(course);
    cout << "Designation: "; getline(cin, designation); h.setDesignation(designation);

    cout << "\nEnter Science Teacher Details:\n";
    cout << "Name: "; cin >> ws; getline(cin, name); s.setName(name);
    cout << "Age: "; cin >> age; s.setAge(age);
    cout << "Institute: "; cin >> ws; getline(cin, institute); s.setInstitute(institute);
    cout << "Course Name: "; getline(cin, course); s.setCourseName(course);
    cout << "Designation: "; getline(cin, designation); s.setDesignation(designation);

    cout << "\nEnter Maths Teacher Details:\n";
    cout << "Name: "; cin >> ws; getline(cin, name); m.setName(name);
    cout << "Age: "; cin >> age; m.setAge(age);
    cout << "Institute: "; cin >> ws; getline(cin, institute); m.setInstitute(institute);
    cout << "Course Name: "; getline(cin, course); m.setCourseName(course);
    cout << "Designation: "; getline(cin, designation); m.setDesignation(designation);

    cout << "\nHumanities Teacher:\n";
    cout << "Name: " << h.getName() << "\nAge: " << h.getAge() 
         << "\nInstitute: " << h.getInstitute() 
         << "\nDepartment: " << h.getDepartment() 
         << "\nCourse Name: " << h.getCourseName() 
         << "\nDesignation: " << h.getDesignation() << endl;

    cout << "\nScience Teacher:\n";
    cout << "Name: " << s.getName() << "\nAge: " << s.getAge() 
         << "\nInstitute: " << s.getInstitute() 
         << "\nDepartment: " << s.getDepartment() 
         << "\nCourse Name: " << s.getCourseName() 
         << "\nDesignation: " << s.getDesignation() << endl;

    cout << "\nMaths Teacher:\n";
    cout << "Name: " << m.getName() << "\nAge: " << m.getAge() 
         << "\nInstitute: " << m.getInstitute() 
         << "\nDepartment: " << m.getDepartment() 
         << "\nCourse Name: " << m.getCourseName() 
         << "\nDesignation: " << m.getDesignation() << endl;

    return 0;
}
