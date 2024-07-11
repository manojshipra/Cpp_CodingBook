// A simple Student Management System done using Singly Linked List
#include <iostream>
#include<string>
using namespace std;

class Student{
    public:
    int id;
    string name;
    int age;
    char grade;
    Student(int id, string name, int age, char grade){
        this->id = id;
        this->name=name;
        this->age= age;
        this->grade = grade;
    }
    
}
;

class Node{
    public:
    Student* student ;
    Node* next;
    Node(Student* student){
        this->student = student;
        this->next = NULL;
        
    }
    
};


class StudentList{
    private:
    Node* head;
    public :
    StudentList(){
        head = NULL;
    }
    void addStudent(Student*);
    void printList();
    void findStudent(int);
    void removeStudent(int);
};

void StudentList::addStudent(Student* student){
    Node* newStudent = new Node(student);
    if(head == NULL){
        head=newStudent;
        return ;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = newStudent;
}

void StudentList::findStudent(int id){
    if(head == NULL){
        cout<<"The list is empty";
        return ;
    }
    
    Node* temp = head;
    while(temp!=NULL){
        if(temp->student->id == id){
            cout<<"name = " << temp->student->name<<endl;
            return ;
        }
        temp=temp->next;
    }
    cout<< "Student with id "<<id<<" not found"<<endl;
    return ;
    
}

void StudentList::removeStudent(int id){
    Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->student->id == id) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->student->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            std::cout << "Student with ID " << id << " not found." << std::endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
}

void StudentList::printList(){
    Node* temp = head;
        while (temp != nullptr) {
            std::cout << "ID: " << temp->student->id
                      << ", Name: " << temp->student->name
                      << ", Age: " << temp->student->age
                      << ", Grade: " << temp->student->grade << std::endl;
            temp = temp->next;
        }
}

int main(){
    StudentList st1;
    st1.addStudent(new Student(1, "Alice", 20, 'A'));
    st1.addStudent(new Student(21, "Bob", 20, 'B'));
    st1.addStudent(new Student(3, "Adam", 20, 'S'));
    st1.printList();
    st1.findStudent(3);
    st1.findStudent(5);
    st1.removeStudent(3);
    st1.findStudent(3);
    st1.printList();
    return 0;
}
