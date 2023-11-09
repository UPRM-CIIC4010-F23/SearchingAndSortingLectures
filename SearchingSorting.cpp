#include <algorithm>
#include <functional>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

class Student {

private:
    int id;
    string name;
    int age;
    float gpa;

public:
    Student(int id, string name, int age, float gpa) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
    int getID() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    float getGPA() const { return gpa; }

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGPA(float gpa) { this->gpa = gpa; }

    bool operator==(const Student &s) const { return this->getID() == s.getID(); }
    bool operator<(const Student &s) const { return this->getID() < s.getID(); }

    static int linearSearch(vector<Student> students, Student key);
    static int binarySearch(vector<Student> students, Student key);

    static int selectionSort(vector<Student> &students);
    static int insertionSort(vector<Student> &students);
    static void mergeSort(vector<Student> &students);

};

int Student::linearSearch(vector<Student> students, Student key) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i] == key)
            return i;
    }
    return -1;
}

int binarySearchHelper(vector<Student> students, Student key, int start, int end) {

    if ((start == end) && (students[start] == key)) {
        return start;
    } else if (start == end) {
        return -1;
    }
    int mid = (start + end) / 2;
    if (students[mid] < key) {
        // Search on right half
        return binarySearchHelper(students, key, mid + 1, end);
    } else {
        // Search on left half
        return binarySearchHelper(students, key, start,mid);
    }

}

int Student::binarySearch(vector<Student> students, Student key) {
    return binarySearchHelper(students, key, 0, students.size() - 1);
}

int Student::selectionSort(vector<Student> &students) {

    for (int i=0; i<students.size(); i++) {
        int minPos = i;
        for (int j=i+1; j < students.size(); j++) {
            if (students[j] < students[minPos]) {
                minPos = j;
            }
        }
        // At this point minPos is the position of the next minimun
        swap(students[i],students[minPos]);
        // Student temp = students[i];
        // students[i] = students[minPos];
        // students[minPos] = temp;
    }
    
    return 0;
}

int Student::insertionSort(vector<Student> &students) {

    return 0;
}

void merge(vector<Student> left, vector<Student> right, vector<Student> &result) {

    // TO DO

}

void Student::mergeSort(vector<Student> &students) {

    if (students.size() <= 1) {
        return;
    }
    int mid = students.size() / 2;
    vector<Student> leftSide;
    for (int i=0; i<mid; i++){
        leftSide.push_back(students[i]);
    }
    mergeSort(leftSide);
    vector<Student> rightSide;
    for (int i=mid; i<students.size(); i++) {
        rightSide.push_back(students[i]);
    }
    mergeSort(rightSide);
    merge(leftSide, rightSide, students);

}

int main() {

    Student s1(1, "Ana", 19, 4.0);
    Student s2(2, "José", 20, 3.8);
    Student s3(3, "Juan", 18, 3.1);
    Student s4(4, "María", 21, 3.9);
    Student s5(5, "Carmen", 19, 3.2);

    vector<Student> allStudents{s1, s2, s3, s4, s5};
    vector<Student> maleStudents{s2, s3};
    vector<Student> femaleStudents{s1, s4, s5};
    vector<Student> allReversed{s5, s4, s3, s2, s1};

    Student key(4, "María", 21, 3.9);

    cout << "Position for Maria among all: " << Student::linearSearch(allStudents, key) << endl;
    cout << "Position for Maria among males: " << Student::linearSearch(maleStudents, key) << endl;

    cout << "Position for Maria among all: " << Student::binarySearch(allStudents, key) << endl;
    cout << "Position for Maria among males: " << Student::binarySearch(maleStudents, key) << endl;

    // cout << "Total comparisons for insertionSort on allReversed: " << Student::insertionSort(allReversed);
    // cout << "Total comparisons for mergeSort on allReversed: " << Student::mergeSort(allReversed);

    // sort(allReversed.begin(), allReversed.end());

    // sort(allReversed.begin(), allReversed.end(), decreasingComparator);

    // // Using a lambda expression
    // sort(allReversed.begin(), allReversed.end(),
    //      [](const Student &s1, const Student &s2) {
    //          return s1.getID() < s2.getID();
    //      });

    // int honorStudentCount = count_if(allReversed.begin(), allReversed.end(),
    //                                  [](const Student &s) { return s.getGPA() >= 3.0; });

    // cout << "Integral of x^2 from 0 to 1 is: " << integrate(0, 1,`) << endl;
    // ;

    // cout << "Integral of e^x from 0 to 1 is: " << integrate(-M_PI / 2, M_PI / 2, [](double x) { return cos(x); }) << endl;

    exit(0);
}