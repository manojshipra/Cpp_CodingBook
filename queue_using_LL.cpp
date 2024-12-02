#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Queue{
    private:
        Node* front;
        Node* rear;
    public:
        Queue():front(NULL),rear(NULL){}
        
        void enqueue(int value){
            Node* temp = new Node(value);
            if(rear==NULL){
                front=rear=temp;
                return;
            }
            rear->next=temp;
            rear=temp;
        }

        int dequeue(){
            if(front==NULL){
                cout<<"Queue is empty"<<endl;
                return -1;
            }
            Node* temp = front;
            front=front->next;
            if(front==NULL) rear=NULL;
            int data = temp->data;
            delete temp;
            return data;
        }

        bool isEmpty() const{
            return front==NULL;
        }
         
        int peek() const{
            if(front==NULL) return -1;
            return front->data;
        }
};


