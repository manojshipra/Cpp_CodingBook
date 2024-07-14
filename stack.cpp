#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node(int data){
      this->data = data;
      this->next = nullptr;
  }
};

class Stack{
  private:
  Node* top;
  public:
  Stack(){
      top=nullptr;
  }
  
  void push(int data){
      Node* newNode = new Node(data);
      if(top==nullptr){
          top = newNode;
      }
      else{
          newNode->next = top;
          top = newNode;
      }
      cout<<data<<"Pushed to Stack \n";
  }
  
  void pop(){
      if(top==nullptr){
          cout<<"The Stack is empty"<<endl;
      }
      else{
          Node* temp=top;
          top=top->next;
          cout<<temp->data<<" is popped\n";
          delete temp;
      }
  }
  
  int peek(){
      if(top==nullptr){
          cout<<"The stack is empty"<<endl;
          return -1;
      }
      else{
         return top->data;
      }
    
  }
  
  bool isEmpty(){
      return top==nullptr;
  }
  
  void display(){
      if(top == nullptr){
          cout<<"The stack is empty"<<endl;
      }
      else{
          Node* temp = top;
          while(temp!=nullptr){
              cout<<temp->data<<" ";
              temp = temp->next;
          }
          cout<<endl;
      }
  }
};

int main(){
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element is: " << stack.peek() << endl;

    stack.display();

    stack.pop();
    stack.pop();

    stack.display();

    if (stack.isEmpty()) {
        cout << "Stack is empty\n";
    } else {
        cout << "Stack is not empty\n";
    }

    return 0;
}
